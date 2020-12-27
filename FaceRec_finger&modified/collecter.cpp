#include "collecter.h"
#include <QDebug>

using namespace cv;
using namespace std;


const char *faceCascadeFilename = "lbpcascade_frontalface.xml";     // LBP face detector.
//const char *faceCascadeFilename = "haarcascade_frontalface_alt_tree.xml";  // Haar face detector.
const char *eyeCascadeFilename1 = "haarcascade_lefteye_2splits.xml";   // Best eye detector for open-or-closed eyes.
const char *eyeCascadeFilename2 = "haarcascade_righteye_2splits.xml";   // Best eye detector for open-or-closed eyes.
//const char *eyeCascadeFilename1 = "haarcascade_mcs_lefteye.xml";       // Good eye detector for open-or-closed eyes.
//const char *eyeCascadeFilename2 = "haarcascade_mcs_righteye.xml";       // Good eye detector for open-or-closed eyes.
//const char *eyeCascadeFilename1 = "haarcascade_eye.xml";               // Basic eye detector for open eyes only.
//const char *eyeCascadeFilename2 = "haarcascade_eye_tree_eyeglasses.xml"; // Basic eye detector for open eyes if they might wear glasses.

const int faceWidth = 80;// Set the desired face dimensions.
const double CHANGE_IN_IMAGE_FOR_COLLECTION = 0.5; //0.3;      // How much the facial image should change before collecting a new face photo for training.
const double CHANGE_IN_SECONDS_FOR_COLLECTION = 0.5;//1.0;       // How much time must pass before collecting a new face photo for training.
const bool preprocessLeftAndRightSeparately = true;   // Preprocess left & right sides of the face separately, in case there is stronger light on one side.

vector<int> numPhotos_of_a_person(100); // Alocate vector which keeps a track on number of images of a person
Mat old_prepreprocessedFace;
double old_time = 0;
bool save_imgs = false;
bool train_recognizer = true;

//===================================================================================================================

void saveImages_bool(bool set){
    save_imgs = set;
}

void prepareForTraining_bool(bool set){
    train_recognizer = set;
}

void initDetectors(CascadeClassifier &faceCascade, CascadeClassifier &eyeCascade1, CascadeClassifier &eyeCascade2){
    try { faceCascade.load(faceCascadeFilename);
    } catch (cv::Exception &e) {}
    if ( faceCascade.empty() ) {
        cerr << "ERROR: Could not load Face Detection cascade classifier [" << faceCascadeFilename << "]!" << endl;
        cerr << "Copy the file from your OpenCV data folder (eg: 'C:\\OpenCV\\data\\lbpcascades') into this WebcamFaceRec folder." << endl;
        exit(1);
    }
    cout << "Loaded the Face Detection cascade classifier [" << faceCascadeFilename << "]." << endl;

    // Load the Eye Detection cascade classifier xml file.
    try { eyeCascade1.load(eyeCascadeFilename1);
    } catch (cv::Exception &e) {}
    if ( eyeCascade1.empty() ) {
        cerr << "ERROR: Could not load 1st Eye Detection cascade classifier [" << eyeCascadeFilename1 << "]!" << endl;
        cerr << "Copy the file from your OpenCV data folder (eg: 'C:\\OpenCV\\data\\haarcascades') into this WebcamFaceRec folder." << endl;
        exit(1);
    }
    cout << "Loaded the 1st Eye Detection cascade classifier [" << eyeCascadeFilename1 << "]." << endl;

    // Load the Eye Detection cascade classifier xml file.
    try { eyeCascade2.load(eyeCascadeFilename2);
    } catch (cv::Exception &e) {}
    if ( eyeCascade2.empty() ) {
        cerr << "Could not load 2nd Eye Detection cascade classifier [" << eyeCascadeFilename2 << "]." << endl;
        // Dont exit if the 2nd eye detector did not load, because we have the 1st eye detector at least.
        //exit(1);
    }
    else
        cout << "Loaded the 2nd Eye Detection cascade classifier [" << eyeCascadeFilename2 << "]." << endl;
}


Mat detectAndCollect(Mat cameraFrame, Mat &processedImage, int pin, int &photoNum, string &name, CascadeClassifier &faceCascade, CascadeClassifier &eyeCascade1, CascadeClassifier &eyeCascade2){
    Mat displayedFrame;
    cameraFrame.copyTo(displayedFrame);

    // Find a face and preprocess it to have a standard size and contrast & brightness.
    Rect faceRect;  // Position of detected face.
    Rect searchedLeftEye, searchedRightEye; // top-left and top-right regions of the face, where eyes were searched.
    Point leftEye, rightEye;    // Position of the detected eyes.
    Mat preprocessedFace = getPreprocessedFace(displayedFrame, faceWidth, faceCascade, eyeCascade1, eyeCascade2, preprocessLeftAndRightSeparately, &faceRect, &leftEye, &rightEye, &searchedLeftEye, &searchedRightEye);

    bool gotFaceAndEyes = false;
    if (preprocessedFace.data)
        gotFaceAndEyes = true;

    // Draw an anti-aliased rectangle around the detected face.
    if (faceRect.width > 0) {
        rectangle(displayedFrame, faceRect, CV_RGB(255, 255, 0), 2, CV_AA);
        // Draw light-blue anti-aliased circles for the 2 eyes.
        Scalar eyeColor = CV_RGB(0,255,255);
        if (leftEye.x >= 0) {   // Check if the eye was detected
            circle(displayedFrame, Point(faceRect.x + leftEye.x, faceRect.y + leftEye.y), 6, eyeColor, 1, CV_AA);
        }
        if (rightEye.x >= 0) {   // Check if the eye was detected
            circle(displayedFrame, Point(faceRect.x + rightEye.x, faceRect.y + rightEye.y), 6, eyeColor, 1, CV_AA);
        }
    }


    if (gotFaceAndEyes) {
        // Check if this face looks somewhat different from the previously collected face.
        double imageDiff = 10000000000.0;
        if (old_prepreprocessedFace.data) {
            imageDiff = norm(preprocessedFace, old_prepreprocessedFace, NORM_L2)/(double)(preprocessedFace.rows * preprocessedFace.cols);;
        }

        // Also record when it happened.
        double current_time = (double)getTickCount();
        double timeDiff_seconds = (current_time - old_time)/getTickFrequency();

        // Only process the face if it is noticeably different from the previous frame and there has been noticeable time gap.
        if ((imageDiff > CHANGE_IN_IMAGE_FOR_COLLECTION) && (timeDiff_seconds > CHANGE_IN_SECONDS_FOR_COLLECTION)) {
            numPhotos_of_a_person[pin] = numPhotos_of_a_person[pin] + 1; //counter of saved images

            if(train_recognizer){
                getImagesForRecognizer(preprocessedFace, pin);
            }
            if(save_imgs){
                save_collected_images(preprocessedFace, name, numPhotos_of_a_person[pin]);
            }

            photoNum = numPhotos_of_a_person[pin];
            cout << "Saved " << (numPhotos_of_a_person[pin]) << " photos of person " << pin << endl; // Show the number of collected faces.

            // Make a white flash on the face, so the user knows a photo has been taken.
            Mat displayedFaceRegion = displayedFrame(faceRect);
            displayedFaceRegion += CV_RGB(90,90,90);

            // Keep a copy of the processed face, to compare on next iteration.
            old_prepreprocessedFace = preprocessedFace.clone();
            old_time = current_time;

            // Copy the preprocessed face to processed Image to be shown in GUI
            Mat srcBGR = Mat(preprocessedFace.size(), CV_8UC3);
            cvtColor(preprocessedFace, srcBGR, CV_GRAY2BGR);
            processedImage = srcBGR;
        }
    }
    return displayedFrame;
}

