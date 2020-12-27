#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>
#include <QWidget>
#include <QMessageBox>

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include<fcntl.h>
#include<termios.h>
#include<stdio.h>
#include <unistd.h>
#include<QDebug>
#define BAUDRATE 9600

unsigned char enablefinger[]={0xEF,0x01,0xFF,0xFF,0xFF,0xFF,0x01,0x00,0x03,0x01,0x00,0x05};
unsigned char detectFinger[12] = {0xEF,0x01,0xFF,0xFF,0xFF,0xFF,0x01,0x00,0x03,0x01,0x00,0x05};
unsigned char registerFinger[15]= {0xEF,0x01,0xFF,0xFF,0xFF,0xFF,0x01,0x00,0x06,0x06,0x02,0x00,0x05,0x00,0x14};
unsigned char genChar[12] = {0xEF,0x01,0xFF,0xFF,0xFF,0xFF,0x01,0x04,0x02,0x02,0x00,0x09};
unsigned char buffer[30],ch;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    fd = open("/dev/ttyUSB0", O_RDWR | O_NONBLOCK);
            struct termios oldtio,newtio;
            struct termios tio;
            tcgetattr(fd,&oldtio); /* save current port settings */
            bzero(&newtio, sizeof(newtio));
                  newtio.c_cflag = CLOCAL | CREAD | BAUDRATE | CS8;
                  newtio.c_cflag &= ~PARENB;
                  newtio.c_cflag &= ~PARODD;
                  newtio.c_cflag &= ~CSTOPB;
                  newtio.c_iflag = IGNPAR;
                  newtio.c_oflag = 0;
                  newtio.c_lflag = 0;
                  newtio.c_cc[VMIN] = 0;
                  newtio.c_cc[VTIME] = 0;
                  tcflush( fd, TCIFLUSH);
                  tcsetattr( fd,TCSANOW,&newtio);
                  printf ("pid 1 :- %d\n",fd);

    m_timer.start(200);
    cameraOpen = false;
    initDetectors(faceCascade, eyeCascade1, eyeCascade2); // define the classifiers
    create_folders();
    setRecognizer("FaceRecognizer.Eigenfaces");

    allNames << "unknown"; pin = 0; similarity = 0;

    connect(&m_timer, SIGNAL(timeout()), this, SLOT(updateAndShowVideoFrame()));
    connect(ui->AddNameBtn, SIGNAL(clicked()), this, SLOT(addName()));
    connect(ui->CollectBtn, SIGNAL(clicked()), this, SLOT(modeCollecting()));
    connect(ui->StopBtn, SIGNAL(clicked()), this, SLOT(closeCamera()));
    connect(ui->ChoosePerson, SIGNAL(currentTextChanged(QString)), this, SLOT(nameChanged(QString)));

    connect(ui->runRecBtn, SIGNAL(clicked()), this, SLOT(modeRecognition()));
    connect(ui->stopRecBtn, SIGNAL(clicked()), this, SLOT(closeCamera()));
    connect(ui->saveModelBtn, SIGNAL(clicked()), this, SLOT(saveModel()));
    connect(ui->loadModelBtn, SIGNAL(clicked()), this, SLOT(loadModel()));
    connect(ui->personsFileBtn, SIGNAL(clicked()), this, SLOT(dialogOpen()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::modeCollecting(){
    mode = "collect";
    openCamera();
}

void MainWindow::modeRecognition(){
    mode = "recognize";
    openCamera();
}

void MainWindow::openCamera(){
    cameraOpen = true;
    m_cvCamera.open(0);

    m_cvCamera.set(CV_CAP_PROP_FOURCC ,CV_FOURCC('Y', 'U', 'Y', 'V') );
    m_cvCamera.set(CV_CAP_PROP_FRAME_WIDTH, 1280);
    m_cvCamera.set(CV_CAP_PROP_FRAME_HEIGHT, 720);
    qDebug("Camera opened.");
}

void MainWindow::closeCamera(){
    cameraOpen = false;
    //m_cvCamera.release();
    qDebug("Camera closed.");
}

void MainWindow::updateAndShowVideoFrame(){
    if(!cameraOpen)
        return;

    cv::Mat cameraFrame;
    m_cvCamera >> cameraFrame;

    if(cameraFrame.empty()){
        cout << "Camera frame is empty, check the camera." << endl;
        return;
    }

    if(mode == "collect"){
        cv::Mat processedImage;
        cv::Mat frame = detectAndCollect(cameraFrame, processedImage, pin, photoNum, name, faceCascade, eyeCascade1, eyeCascade2);
        cv::Mat cvRGBImage( frame.rows, frame.cols, frame.type() );
        cv::cvtColor( frame, cvRGBImage, CV_BGR2RGB );

        QImage image = QImage( (uchar*)cvRGBImage.data, cvRGBImage.cols, cvRGBImage.rows, cvRGBImage.step, QImage::Format_RGB888 );
        if(image.isNull())
            return;

        QPixmap pixmap = QPixmap::fromImage(image);
        ui->imageLabel->setPixmap( pixmap );

        if (processedImage.data){
            cv::Mat cvRGBprocessedImage( processedImage.rows, processedImage.cols, processedImage.type() );
            cv::cvtColor( processedImage, cvRGBprocessedImage, CV_BGR2RGB );

            QImage miniatura = QImage( (uchar*)cvRGBprocessedImage.data, cvRGBprocessedImage.cols, cvRGBprocessedImage.rows, cvRGBprocessedImage.step, QImage::Format_RGB888 );
            if(miniatura.isNull())
                return;

            QPixmap littlePixmap = QPixmap::fromImage(miniatura);
            ui->miniatureLabel->setPixmap(littlePixmap);

            ui->lcdNPhotos->display(photoNum);
        }
    }

    if(mode == "recognize"){
        if(model.empty()){
            cout << "Model is empty, cannot run recognizer." << endl;
            closeCamera();
            return;
        }
        cv::Mat processedImage;
        cv::Mat frame = runRecognizer(cameraFrame, processedImage, model, pin, similarity, faceCascade, eyeCascade1, eyeCascade2);
        qDebug()<<"Check for similarity"<<similarity;
        cv::Mat cvRGBImage( frame.rows, frame.cols, frame.type() );
        cv::cvtColor( frame, cvRGBImage, CV_BGR2RGB );

        QImage image = QImage( (uchar*)cvRGBImage.data, cvRGBImage.cols, cvRGBImage.rows, cvRGBImage.step, QImage::Format_RGB888 );
        if(image.isNull())
            return;

        QPixmap pixmap = QPixmap::fromImage(image);
        ui->recognitionImageLabel->setPixmap( pixmap );

        if (processedImage.data){
            cv::Mat cvRGBprocessedImage( processedImage.rows, processedImage.cols, processedImage.type() );
            cv::cvtColor( processedImage, cvRGBprocessedImage, CV_BGR2RGB );

            QImage miniatura = QImage( (uchar*)cvRGBprocessedImage.data, cvRGBprocessedImage.cols, cvRGBprocessedImage.rows, cvRGBprocessedImage.step, QImage::Format_RGB888 );
            if(miniatura.isNull())
                return;

            QPixmap littlePixmap = QPixmap::fromImage(miniatura);
            ui->miniatureLabel_recognition->setPixmap(littlePixmap);
        }

        QString personIdentified;
        if(pin == 0){
            ui->identityLabel->setText(" ");
            ui->confidenceBar->setValue(0);
        }
        else{
            if(similarity < 0.70)
            {
                ui->identityLabel->setText("Unrecognized fellow");

            }
            else
            {
                if(allNames.size()>pin){
                    personIdentified = allNames.at(pin);
                }
                else personIdentified = QString::number(pin);
                ui->identityLabel->setText(personIdentified);
                ui->confidenceBar->setValue((double)(100*similarity));

                //Run your functional code
                /**
                  Please write defination in FunctionToBeRun(); See last in this file
                 **/
                FunctionToBeRun();

            }
        }
    }
}

void MainWindow::nameChanged(const QString &currentName)
{
    name = currentName.toStdString();
    pin = allNames.indexOf(currentName);
}


void MainWindow::addName(){   
    QString newName = ui->AddNameLine->toPlainText();
    for (int i = 0; i < allNames.size(); ++i) {
        if (allNames[i] == newName){
            cout << "Name already exists, choose a different name." << endl;
            return;
        }
    }
    allNames << newName;
    ui->ChoosePerson->addItem(newName);
    ui->personsName_training->addItem(newName);
    ui->AddNameLine->clear();
}

void MainWindow::on_saveImages_checkBox_toggled(bool checked){
    saveImages_bool(checked);
}

void MainWindow::on_readyForTraining_checkBox_toggled(bool checked){
    prepareForTraining_bool(checked);
}


void MainWindow::on_trainBtn_clicked(){
    trainRecognizer(model);
}

void MainWindow::saveModel(){
    if(model.empty()){
        cout << "Model is empty, nothing can be saved." << endl;
        return;
    }

    QString fileName;
    QFileDialog dialog(this);
    dialog.setDirectory(QDir::currentPath());
    fileName = dialog.getSaveFileName(this, "Save file", "", "*.yaml");
    saveRecognizer(model, fileName.toStdString());
    cout << "Model saved." << endl;
}

void MainWindow::loadModel(){
    QMessageBox msgLoadModel;
    msgLoadModel.setText("The model must be of the same type as set in the above combo box, else the app will crash when executing recognition.");
    msgLoadModel.exec();

    QString fileName;
    QFileDialog dialog(this);
    dialog.setDirectory(QDir::currentPath());
    fileName = dialog.getOpenFileName(this, "Load file", "", "*.yaml");
    if(fileName.isEmpty())
        return;
    loadRecognizer(model, fileName.toStdString());
    std::string modelName = model->name();
    cout << "Model loaded, its expected type is " << modelName << "." << endl;
}

void MainWindow::dialogOpen(){
    QFileDialog dialog(this);
    dialog.setDirectory(QDir::currentPath());
    dialog.setFileMode(QFileDialog::ExistingFiles);
    QStringList fileNames;
    if(dialog.exec())
        fileNames = dialog.selectedFiles();

    QString currentName = ui->personsName_training->currentText();
    int currentLabel = allNames.indexOf(currentName);
    for(int i =0; i < fileNames.size(); ++i){
        getImagesForRecognizer(load_image(fileNames.at(i).toStdString()), currentLabel);
    }
}


void MainWindow::on_comboBox_FR_algorithm_currentTextChanged(const QString &arg1){
    string text = arg1.toStdString();
    string algorithm = "FaceRecognizer.";
    algorithm.append(text);
    setRecognizer(algorithm);
}

void MainWindow::on_spinBox_valueChanged(int arg1){
    setThreshold(arg1);
}


//Function after Face recognization

void FunctionToBeRun()
{
    // Write your Defination here

}

void MainWindow::on_verify_clicked()
{
    unsigned char searchTemplate[12] = {0xEF,0x01,0xFF,0xFF,0xFF,0xFF,0x01,0x00,0x03,0x11,0x00,0x15};

    int i;
   usleep(1000);
   ui->status1->setText("Please Place Your Finger ...");


   int len;
   usleep(10000);
   write(MainWindow::fd,searchTemplate,12);
   usleep(10000);
   len = read(MainWindow::fd, buffer, sizeof buffer -1);
   buffer[len] = '\0';
   qDebug()<<"buff0="<<buffer[0];
   qDebug()<<"buff1="<<buffer[1];
   qDebug()<<"buff2="<<buffer[2];
   qDebug()<<"buff3="<<buffer[3];
   qDebug()<<"buff4="<<buffer[4];
   qDebug()<<"buff5="<<buffer[5];
   qDebug()<<"buff6="<<buffer[6];
   qDebug()<<"buff7="<<buffer[7];
   qDebug()<<"buff8="<<buffer[8];
   qDebug()<<"buff9="<<buffer[9];
   qDebug()<<"buff10="<<buffer[10];
   qDebug()<<"buff11r="<<buffer[11];





   if(buffer[6] == 0x07 && buffer[7] == 0x00)
{

           if((buffer[9] == 0x00)  &&  (buffer[1] == 0x01))
       {
               ui->status1->setText("Authentication Success");


       }
       else
           ui->status1->setText("Authentication Failed");
   }
   else
   ui->status1->setText("Press Verify Again");
}

void MainWindow::on_enrole_clicked()
{
    registerFinger[12] = 0;
    write(MainWindow::fd,detectFinger,12);
            usleep(150000);
            int len = read(MainWindow::fd, buffer, sizeof buffer -1);
            buffer[len] = '\0';
    if((buffer[9] == 0x00) && (buffer[0] == 0xEF) && (buffer[6] == 0x07))
                    ui->status->setText("Finger Detection Success");
            else
                    ui->status->setText("Finger Detection Failed");

            usleep(500000);

            write(MainWindow::fd,genChar,12);
         usleep(150000);
         len = read(MainWindow::fd, buffer, sizeof buffer -1);
         buffer[len] = '\0';

            if((buffer[9] == 0x00) && (buffer[6] == 0x07))
                    ui->status->setText("Char File Gen Success");
            else
                    ui->status->setText("Char File Gen Failed");

            usleep(500000);

            registerFinger[14] = registerFinger[12]+0x0F;

        write(MainWindow::fd,registerFinger,15);
        usleep(150000);
            len = read(MainWindow::fd, buffer, sizeof buffer -1);
         buffer[len] = '\0';
         qDebug()<<"buff0="<<buffer[0];
         qDebug()<<"buff1="<<buffer[1];
         qDebug()<<"buff2="<<buffer[2];
         qDebug()<<"buff3="<<buffer[3];
         qDebug()<<"buff4="<<buffer[4];
         qDebug()<<"buff5="<<buffer[5];
         qDebug()<<"buff6="<<buffer[6];
         qDebug()<<"buff7="<<buffer[7];
         qDebug()<<"buff8="<<buffer[8];
         qDebug()<<"buff9="<<buffer[9];
         qDebug()<<"buff10="<<buffer[10];
         qDebug()<<"buff11r="<<buffer[11];


            if((buffer[9] == 0x00) && (buffer[0] == 0xEF) && (buffer[6] == 0x07))
                 ui->status->setText("Finger Registration Success");
        else  if(buffer[9] == 0x01)
                    ui->status->setText("Error When Receiving Packet");
        else  if(buffer[9] == 0x0B)
                ui->status->setText("Beyond Finger Library");
            else  if(buffer[9] == 0x18)
                ui->status->setText("Error When Writing Flash");

            usleep(3000000);

}
