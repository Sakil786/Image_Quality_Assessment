/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCascade_classifiers;
    QAction *actionEdit_names;
    QAction *actionSaving_options;
    QAction *actionDelete_data;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *Collecting;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *imageLabel;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QComboBox *ChoosePerson;
    QHBoxLayout *horizontalLayout_4;
    QPlainTextEdit *AddNameLine;
    QPushButton *AddNameBtn;
    QLabel *miniatureLabel;
    QLCDNumber *lcdNPhotos;
    QSpacerItem *verticalSpacer;
    QPushButton *enrole;
    QLabel *status;
    QCheckBox *saveImages_checkBox;
    QCheckBox *readyForTraining_checkBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *CollectBtn;
    QPushButton *StopBtn;
    QWidget *Training;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QComboBox *personsName_training;
    QPushButton *personsFileBtn;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *TrainerBtnLayout;
    QComboBox *comboBox_FR_algorithm;
    QPushButton *trainBtn;
    QPushButton *saveModelBtn;
    QPushButton *loadModelBtn;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_2;
    QSpinBox *spinBox;
    QWidget *Recognition;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *recognitionImageLabel;
    QVBoxLayout *verticalLayout_5;
    QLabel *miniatureLabel_recognition;
    QLabel *identityText;
    QLabel *identityLabel;
    QLabel *confidenceText;
    QProgressBar *confidenceBar;
    QPushButton *verify;
    QLabel *status1;
    QHBoxLayout *Rec_RunStopLayout;
    QPushButton *runRecBtn;
    QPushButton *stopRecBtn;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QMenu *menuSettings;
    QMenu *menuExit;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1042, 608);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(900, 600));
        actionCascade_classifiers = new QAction(MainWindow);
        actionCascade_classifiers->setObjectName(QString::fromUtf8("actionCascade_classifiers"));
        actionEdit_names = new QAction(MainWindow);
        actionEdit_names->setObjectName(QString::fromUtf8("actionEdit_names"));
        actionSaving_options = new QAction(MainWindow);
        actionSaving_options->setObjectName(QString::fromUtf8("actionSaving_options"));
        actionDelete_data = new QAction(MainWindow);
        actionDelete_data->setObjectName(QString::fromUtf8("actionDelete_data"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 1471, 771));
        tabWidget->setMinimumSize(QSize(880, 530));
        Collecting = new QWidget();
        Collecting->setObjectName(QString::fromUtf8("Collecting"));
        sizePolicy.setHeightForWidth(Collecting->sizePolicy().hasHeightForWidth());
        Collecting->setSizePolicy(sizePolicy);
        horizontalLayoutWidget_4 = new QWidget(Collecting);
        horizontalLayoutWidget_4->setObjectName(QString::fromUtf8("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(0, 0, 991, 521));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_3->setSpacing(10);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(10, 10, 0, 10);
        imageLabel = new QLabel(horizontalLayoutWidget_4);
        imageLabel->setObjectName(QString::fromUtf8("imageLabel"));
        sizePolicy.setHeightForWidth(imageLabel->sizePolicy().hasHeightForWidth());
        imageLabel->setSizePolicy(sizePolicy);
        imageLabel->setMinimumSize(QSize(640, 480));
        imageLabel->setMaximumSize(QSize(16777215, 720));
        imageLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_3->addWidget(imageLabel);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(10);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setSizeConstraint(QLayout::SetFixedSize);
        verticalLayout_4->setContentsMargins(10, 10, 10, 10);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        ChoosePerson = new QComboBox(horizontalLayoutWidget_4);
        ChoosePerson->setObjectName(QString::fromUtf8("ChoosePerson"));
        ChoosePerson->setMaximumSize(QSize(200, 16777215));

        verticalLayout->addWidget(ChoosePerson);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        AddNameLine = new QPlainTextEdit(horizontalLayoutWidget_4);
        AddNameLine->setObjectName(QString::fromUtf8("AddNameLine"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(AddNameLine->sizePolicy().hasHeightForWidth());
        AddNameLine->setSizePolicy(sizePolicy1);
        AddNameLine->setMaximumSize(QSize(150, 30));

        horizontalLayout_4->addWidget(AddNameLine);

        AddNameBtn = new QPushButton(horizontalLayoutWidget_4);
        AddNameBtn->setObjectName(QString::fromUtf8("AddNameBtn"));
        AddNameBtn->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_4->addWidget(AddNameBtn);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_4->addLayout(verticalLayout);

        miniatureLabel = new QLabel(horizontalLayoutWidget_4);
        miniatureLabel->setObjectName(QString::fromUtf8("miniatureLabel"));
        miniatureLabel->setMinimumSize(QSize(80, 80));
        miniatureLabel->setMaximumSize(QSize(80, 80));
        miniatureLabel->setStyleSheet(QString::fromUtf8("border-color: rgb(77, 77, 77);\n"
"background-color: rgb(255, 255, 255);"));

        verticalLayout_4->addWidget(miniatureLabel, 0, Qt::AlignHCenter);

        lcdNPhotos = new QLCDNumber(horizontalLayoutWidget_4);
        lcdNPhotos->setObjectName(QString::fromUtf8("lcdNPhotos"));
        QPalette palette;
        QBrush brush(QColor(34, 34, 34, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush2(QColor(48, 48, 48, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::HighlightedText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush2);
        QBrush brush3(QColor(159, 158, 158, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush2);
        lcdNPhotos->setPalette(palette);
        lcdNPhotos->setStyleSheet(QString::fromUtf8("font: 75 11pt \"Ubuntu\";\n"
"background-color: rgb(255, 255, 255);\n"
"selection-color: rgb(48, 48, 48);"));
        lcdNPhotos->setSegmentStyle(QLCDNumber::Flat);

        verticalLayout_4->addWidget(lcdNPhotos, 0, Qt::AlignHCenter);

        verticalSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_4->addItem(verticalSpacer);

        enrole = new QPushButton(horizontalLayoutWidget_4);
        enrole->setObjectName(QString::fromUtf8("enrole"));

        verticalLayout_4->addWidget(enrole);

        status = new QLabel(horizontalLayoutWidget_4);
        status->setObjectName(QString::fromUtf8("status"));

        verticalLayout_4->addWidget(status);

        saveImages_checkBox = new QCheckBox(horizontalLayoutWidget_4);
        saveImages_checkBox->setObjectName(QString::fromUtf8("saveImages_checkBox"));
        saveImages_checkBox->setChecked(false);

        verticalLayout_4->addWidget(saveImages_checkBox);

        readyForTraining_checkBox = new QCheckBox(horizontalLayoutWidget_4);
        readyForTraining_checkBox->setObjectName(QString::fromUtf8("readyForTraining_checkBox"));
        readyForTraining_checkBox->setChecked(true);

        verticalLayout_4->addWidget(readyForTraining_checkBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        CollectBtn = new QPushButton(horizontalLayoutWidget_4);
        CollectBtn->setObjectName(QString::fromUtf8("CollectBtn"));
        CollectBtn->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(CollectBtn);

        StopBtn = new QPushButton(horizontalLayoutWidget_4);
        StopBtn->setObjectName(QString::fromUtf8("StopBtn"));
        StopBtn->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(StopBtn);


        verticalLayout_4->addLayout(horizontalLayout);


        horizontalLayout_3->addLayout(verticalLayout_4);

        tabWidget->addTab(Collecting, QString());
        Training = new QWidget();
        Training->setObjectName(QString::fromUtf8("Training"));
        sizePolicy.setHeightForWidth(Training->sizePolicy().hasHeightForWidth());
        Training->setSizePolicy(sizePolicy);
        horizontalLayoutWidget_3 = new QWidget(Training);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(100, 60, 601, 281));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(10, 10, 10, 10);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(10);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(10, 10, 10, 10);
        label = new QLabel(horizontalLayoutWidget_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 12pt \"Ubuntu\";\n"
"border-color: rgb(136, 136, 136);"));

        verticalLayout_3->addWidget(label);

        personsName_training = new QComboBox(horizontalLayoutWidget_3);
        personsName_training->setObjectName(QString::fromUtf8("personsName_training"));
        personsName_training->setMaximumSize(QSize(220, 16777215));

        verticalLayout_3->addWidget(personsName_training);

        personsFileBtn = new QPushButton(horizontalLayoutWidget_3);
        personsFileBtn->setObjectName(QString::fromUtf8("personsFileBtn"));
        personsFileBtn->setMaximumSize(QSize(220, 16777215));

        verticalLayout_3->addWidget(personsFileBtn);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_7);


        horizontalLayout_2->addLayout(verticalLayout_3);

        horizontalSpacer = new QSpacerItem(100, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        TrainerBtnLayout = new QVBoxLayout();
        TrainerBtnLayout->setSpacing(10);
        TrainerBtnLayout->setObjectName(QString::fromUtf8("TrainerBtnLayout"));
        TrainerBtnLayout->setContentsMargins(10, 10, 10, 10);
        comboBox_FR_algorithm = new QComboBox(horizontalLayoutWidget_3);
        comboBox_FR_algorithm->setObjectName(QString::fromUtf8("comboBox_FR_algorithm"));
        comboBox_FR_algorithm->setMinimumSize(QSize(200, 0));

        TrainerBtnLayout->addWidget(comboBox_FR_algorithm);

        trainBtn = new QPushButton(horizontalLayoutWidget_3);
        trainBtn->setObjectName(QString::fromUtf8("trainBtn"));

        TrainerBtnLayout->addWidget(trainBtn);

        saveModelBtn = new QPushButton(horizontalLayoutWidget_3);
        saveModelBtn->setObjectName(QString::fromUtf8("saveModelBtn"));

        TrainerBtnLayout->addWidget(saveModelBtn);

        loadModelBtn = new QPushButton(horizontalLayoutWidget_3);
        loadModelBtn->setObjectName(QString::fromUtf8("loadModelBtn"));

        TrainerBtnLayout->addWidget(loadModelBtn);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        TrainerBtnLayout->addItem(verticalSpacer_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_2 = new QLabel(horizontalLayoutWidget_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_7->addWidget(label_2);

        spinBox = new QSpinBox(horizontalLayoutWidget_3);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMaximum(10000);
        spinBox->setValue(4000);

        horizontalLayout_7->addWidget(spinBox);


        TrainerBtnLayout->addLayout(horizontalLayout_7);


        horizontalLayout_2->addLayout(TrainerBtnLayout);

        tabWidget->addTab(Training, QString());
        Recognition = new QWidget();
        Recognition->setObjectName(QString::fromUtf8("Recognition"));
        sizePolicy.setHeightForWidth(Recognition->sizePolicy().hasHeightForWidth());
        Recognition->setSizePolicy(sizePolicy);
        horizontalLayoutWidget_5 = new QWidget(Recognition);
        horizontalLayoutWidget_5->setObjectName(QString::fromUtf8("horizontalLayoutWidget_5"));
        horizontalLayoutWidget_5->setGeometry(QRect(0, 0, 961, 585));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_5->setSpacing(10);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(10, 10, 0, 10);
        recognitionImageLabel = new QLabel(horizontalLayoutWidget_5);
        recognitionImageLabel->setObjectName(QString::fromUtf8("recognitionImageLabel"));
        sizePolicy.setHeightForWidth(recognitionImageLabel->sizePolicy().hasHeightForWidth());
        recognitionImageLabel->setSizePolicy(sizePolicy);
        recognitionImageLabel->setMinimumSize(QSize(640, 480));
        recognitionImageLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_5->addWidget(recognitionImageLabel);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(10);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setSizeConstraint(QLayout::SetFixedSize);
        verticalLayout_5->setContentsMargins(10, 100, 10, 100);
        miniatureLabel_recognition = new QLabel(horizontalLayoutWidget_5);
        miniatureLabel_recognition->setObjectName(QString::fromUtf8("miniatureLabel_recognition"));
        miniatureLabel_recognition->setMinimumSize(QSize(80, 80));
        miniatureLabel_recognition->setMaximumSize(QSize(80, 80));
        miniatureLabel_recognition->setStyleSheet(QString::fromUtf8("border-color: rgb(77, 77, 77);\n"
"background-color: rgb(255, 255, 255);"));

        verticalLayout_5->addWidget(miniatureLabel_recognition, 0, Qt::AlignHCenter);

        identityText = new QLabel(horizontalLayoutWidget_5);
        identityText->setObjectName(QString::fromUtf8("identityText"));

        verticalLayout_5->addWidget(identityText, 0, Qt::AlignHCenter);

        identityLabel = new QLabel(horizontalLayoutWidget_5);
        identityLabel->setObjectName(QString::fromUtf8("identityLabel"));
        identityLabel->setMinimumSize(QSize(50, 40));
        identityLabel->setMaximumSize(QSize(150, 40));
        identityLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-color: rgb(0, 0, 0);"));

        verticalLayout_5->addWidget(identityLabel);

        confidenceText = new QLabel(horizontalLayoutWidget_5);
        confidenceText->setObjectName(QString::fromUtf8("confidenceText"));

        verticalLayout_5->addWidget(confidenceText, 0, Qt::AlignHCenter);

        confidenceBar = new QProgressBar(horizontalLayoutWidget_5);
        confidenceBar->setObjectName(QString::fromUtf8("confidenceBar"));
        sizePolicy1.setHeightForWidth(confidenceBar->sizePolicy().hasHeightForWidth());
        confidenceBar->setSizePolicy(sizePolicy1);
        confidenceBar->setMaximumSize(QSize(150, 30));
        confidenceBar->setValue(1);

        verticalLayout_5->addWidget(confidenceBar);

        verify = new QPushButton(horizontalLayoutWidget_5);
        verify->setObjectName(QString::fromUtf8("verify"));

        verticalLayout_5->addWidget(verify);

        status1 = new QLabel(horizontalLayoutWidget_5);
        status1->setObjectName(QString::fromUtf8("status1"));

        verticalLayout_5->addWidget(status1);

        Rec_RunStopLayout = new QHBoxLayout();
        Rec_RunStopLayout->setSpacing(6);
        Rec_RunStopLayout->setObjectName(QString::fromUtf8("Rec_RunStopLayout"));
        runRecBtn = new QPushButton(horizontalLayoutWidget_5);
        runRecBtn->setObjectName(QString::fromUtf8("runRecBtn"));
        runRecBtn->setMaximumSize(QSize(70, 16777215));

        Rec_RunStopLayout->addWidget(runRecBtn);

        stopRecBtn = new QPushButton(horizontalLayoutWidget_5);
        stopRecBtn->setObjectName(QString::fromUtf8("stopRecBtn"));
        stopRecBtn->setMaximumSize(QSize(70, 16777215));

        Rec_RunStopLayout->addWidget(stopRecBtn);


        verticalLayout_5->addLayout(Rec_RunStopLayout);


        horizontalLayout_5->addLayout(verticalLayout_5);

        tabWidget->addTab(Recognition, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1042, 27));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        menuSettings = new QMenu(menuBar);
        menuSettings->setObjectName(QString::fromUtf8("menuSettings"));
        menuExit = new QMenu(menuBar);
        menuExit->setObjectName(QString::fromUtf8("menuExit"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuMenu->menuAction());
        menuBar->addAction(menuSettings->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuBar->addAction(menuExit->menuAction());
        menuSettings->addAction(actionCascade_classifiers);
        menuSettings->addAction(actionEdit_names);
        menuSettings->addAction(actionSaving_options);
        menuSettings->addAction(actionDelete_data);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "FaceRec", 0, QApplication::UnicodeUTF8));
        actionCascade_classifiers->setText(QApplication::translate("MainWindow", "Cascade classifiers", 0, QApplication::UnicodeUTF8));
        actionEdit_names->setText(QApplication::translate("MainWindow", "Edit names", 0, QApplication::UnicodeUTF8));
        actionSaving_options->setText(QApplication::translate("MainWindow", "Saving options", 0, QApplication::UnicodeUTF8));
        actionDelete_data->setText(QApplication::translate("MainWindow", "Delete data", 0, QApplication::UnicodeUTF8));
        imageLabel->setText(QString());
        ChoosePerson->clear();
        ChoosePerson->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Choose person", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_TOOLTIP
        AddNameLine->setToolTip(QApplication::translate("MainWindow", "Enter name of the person to be added.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        AddNameBtn->setText(QApplication::translate("MainWindow", "Add", 0, QApplication::UnicodeUTF8));
        miniatureLabel->setText(QString());
        enrole->setText(QApplication::translate("MainWindow", " Enrole ", 0, QApplication::UnicodeUTF8));
        status->setText(QString());
        saveImages_checkBox->setText(QApplication::translate("MainWindow", "Keep saving images", 0, QApplication::UnicodeUTF8));
        readyForTraining_checkBox->setText(QApplication::translate("MainWindow", "Prepare for training", 0, QApplication::UnicodeUTF8));
        CollectBtn->setText(QApplication::translate("MainWindow", "Collect", 0, QApplication::UnicodeUTF8));
        StopBtn->setText(QApplication::translate("MainWindow", "Stop", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(Collecting), QApplication::translate("MainWindow", "Collecting Faces", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt;\">Define names in the previous</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt;\">window and then choose the</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt;\">name of the person whose</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; t"
                        "ext-indent:0px;\"><span style=\" font-size:11pt;\">photos you want to upload.</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        personsName_training->clear();
        personsName_training->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Choose person", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_TOOLTIP
        personsName_training->setToolTip(QApplication::translate("MainWindow", "Add pictures from a file", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        personsFileBtn->setText(QApplication::translate("MainWindow", "Choose photos to upload", 0, QApplication::UnicodeUTF8));
        comboBox_FR_algorithm->clear();
        comboBox_FR_algorithm->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Eigenfaces", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Fisherfaces", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "LBPH", 0, QApplication::UnicodeUTF8)
        );
        trainBtn->setText(QApplication::translate("MainWindow", "Train", 0, QApplication::UnicodeUTF8));
        saveModelBtn->setText(QApplication::translate("MainWindow", "Save model to a file", 0, QApplication::UnicodeUTF8));
        loadModelBtn->setText(QApplication::translate("MainWindow", "Load model from a file", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Threshold", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(Training), QApplication::translate("MainWindow", "Training Recognizer", 0, QApplication::UnicodeUTF8));
        recognitionImageLabel->setText(QString());
        miniatureLabel_recognition->setText(QString());
        identityText->setText(QApplication::translate("MainWindow", "Identity", 0, QApplication::UnicodeUTF8));
        identityLabel->setText(QString());
        confidenceText->setText(QApplication::translate("MainWindow", "Similarity", 0, QApplication::UnicodeUTF8));
        verify->setText(QApplication::translate("MainWindow", "Verify", 0, QApplication::UnicodeUTF8));
        status1->setText(QString());
        runRecBtn->setText(QApplication::translate("MainWindow", "Run", 0, QApplication::UnicodeUTF8));
        stopRecBtn->setText(QApplication::translate("MainWindow", "Stop", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(Recognition), QApplication::translate("MainWindow", "Face Recognition", 0, QApplication::UnicodeUTF8));
        menuMenu->setTitle(QApplication::translate("MainWindow", "Menu", 0, QApplication::UnicodeUTF8));
        menuSettings->setTitle(QApplication::translate("MainWindow", "Settings", 0, QApplication::UnicodeUTF8));
        menuExit->setTitle(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
