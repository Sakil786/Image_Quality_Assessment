#ifndef COLLECTER_H
#define COLLECTER_H

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include "opencv2/opencv.hpp"
#include "detectObject.h"
#include "preprocessFace.h"
#include "loadSave.h"
#include "recognizer.h"


void initDetectors(CascadeClassifier &faceCascade, CascadeClassifier &eyeCascade1, CascadeClassifier &eyeCascade2);
Mat detectAndCollect(Mat videoCapture, Mat &processedImage, int pin, int &photoNum, string &name, CascadeClassifier &faceCascade, CascadeClassifier &eyeCascade1, CascadeClassifier &eyeCascade2);
int numPhotos_of_individual();

void saveImages_bool(bool set);
void prepareForTraining_bool(bool set);

#endif // COLLECTER_H
