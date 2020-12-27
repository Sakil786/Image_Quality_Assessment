#include "loadSave.h"

const string type = ".jpg";
const string folderCollected = "CollectedFaceImages";
const string folderCollected_create = "mkdir " + folderCollected;
const string folderUnrecognized = "UnrecognizedFaceImages";
const string folderUnrecognized_create = "mkdir " + folderUnrecognized;
int number;


void create_folders(){
    system(folderCollected_create.c_str());
    system(folderUnrecognized_create.c_str());
}

void save_collected_images(Mat image, string person, int numOfPhoto){
    stringstream ss;
    ss<<folderCollected<<"/"<<person<<numOfPhoto<<type;
    string fullPath = ss.str();
    ss.str("");
    imwrite(fullPath, image);
}

void save_unrecognized_images(Mat image){
    stringstream ss;
    ss<<folderUnrecognized<<"/"<<number<<type;
    string fullPath = ss.str();
    ss.str("");
    imwrite(fullPath, image);
    number ++;
}

Mat load_image(string fullPath){  
    Mat loaded_image;
    try {
        loaded_image = imread(fullPath, CV_LOAD_IMAGE_GRAYSCALE);
    } catch (cv::Exception &e) {}
    if (!loaded_image.data) {
        cerr << "ERROR: Could not load image [" << fullPath << "]!\n";
        exit(1);
    }
    return loaded_image;
}
