#ifndef LOADSAVE_H
#define LOADSAVE_H

#include <sstream>
#include <stdio.h>
#include <iostream>
#include <vector>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

void create_folders();
void save_collected_images(Mat image, string person, int numOfPhoto);
void save_unrecognized_images(Mat image);
Mat load_image(string fullPath);

#endif // LOADSAVE_h
