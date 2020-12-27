#ifndef RECOGNIZER_H
#define RECOGNIZER_H

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include "opencv2/opencv.hpp"
#include "detectObject.h"
#include "preprocessFace.h"
#include "loadSave.h"

using namespace cv;
using namespace std;

void getImagesForRecognizer(Mat faceImage, int faceLabel);
void trainRecognizer(Ptr<FaceRecognizer> &model);
void saveRecognizer(Ptr<FaceRecognizer> &model, const string &ModelFileName);
void loadRecognizer(Ptr<FaceRecognizer> &model, const string &ModelFileName);
void setRecognizer(const string &algorithm);
Mat runRecognizer(Mat cameraFrame, Mat &processedImage, const Ptr<FaceRecognizer> model, int &identity, double &confidenceRatio ,CascadeClassifier &faceCascade, CascadeClassifier &eyeCascade1, CascadeClassifier &eyeCascade2);
void setThreshold(const int &value);

#endif // RECOGNIZER_H
