#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/opencv.hpp>
#include <QTimer>
#include <QList>

#include "collecter.h"
#include "recognizer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
      int fd;

protected:
    cv::Mat m_cvImage;
    cv::VideoCapture m_cvCamera;
    QTimer m_timer;

protected slots:
    void updateAndShowVideoFrame();

private slots:
    void modeCollecting();
    void modeRecognition();
    void addName();
    void openCamera();
    void closeCamera();
    void nameChanged(const QString &currentName);
    void on_trainBtn_clicked();
    void saveModel();
    void loadModel();
    void dialogOpen();

    void on_saveImages_checkBox_toggled(bool checked);

    void on_readyForTraining_checkBox_toggled(bool checked);

    void on_comboBox_FR_algorithm_currentTextChanged(const QString &arg1);

    void on_spinBox_valueChanged(int arg1);

    void on_verify_clicked();

    void on_enrole_clicked();

private:
    Ui::MainWindow *ui;
    bool cameraOpen;
    cv::CascadeClassifier faceCascade;
    cv::CascadeClassifier eyeCascade1;
    cv::CascadeClassifier eyeCascade2;
    QString mode;
    int pin, photoNum;
    double similarity;
    std::string name;
    QList<QString> allNames;
    cv::Ptr<FaceRecognizer> model;
};

void FunctionToBeRun();

#endif // MAINWINDOW_H
