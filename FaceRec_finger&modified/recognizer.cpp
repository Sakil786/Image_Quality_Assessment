#include "recognizer.h"
#include <QDebug>

string facerecAlgorithm;
vector<Mat> preprocessedFaces;
vector<int> faceLabels;
const int faceWidth = 80;
const bool preprocessLeftAndRightSeparately = true;

int CORRECTION_CONSTANT = 1;    // THE RIGHT VALUE YET TO BE FOUND OUT - may vary for different algorithms
int THRESHOLD = 4000;  // THE RIGHT VALUE YET TO BE FOUND OUT - may vary for different algorithms

void setThreshold(const int &value){
    THRESHOLD = value;
}

void setRecognizer(const string &algorithm){
    facerecAlgorithm = algorithm;
}


void getImagesForRecognizer(Mat faceImage, int faceLabel){
    Mat mirroredFace;
    flip(faceImage, mirroredFace, 1);

    preprocessedFaces.push_back(faceImage);
    preprocessedFaces.push_back(mirroredFace);
    faceLabels.push_back(faceLabel);
    faceLabels.push_back(faceLabel);
}


void trainRecognizer(Ptr<FaceRecognizer> &model){
    bool haveEnoughData = true;

    if (preprocessedFaces.size() <= 0 || preprocessedFaces.size() != faceLabels.size()) {
        cout << "ERROR: Need more faces or for training. Could not train recognizer." << endl;
        haveEnoughData = false;
    }

    if (haveEnoughData) {
        model = Algorithm::create<FaceRecognizer>(facerecAlgorithm);
        if (model.empty()) {
            cerr << "ERROR: The FaceRecognizer algorithm [" << facerecAlgorithm << "] could not be created." << endl;
            exit(1);
        }
        model->set("threshold", THRESHOLD);
        model->train(preprocessedFaces, faceLabels);
        cout << "Face recognizer model is ready." << endl;
    }
}


void saveRecognizer(Ptr<FaceRecognizer> &model, const string &ModelFileName){
    model->save(ModelFileName);
}


void loadRecognizer(Ptr<FaceRecognizer> &model, const string &ModelFileName){
    model = Algorithm::create<FaceRecognizer>(facerecAlgorithm);
//    model = createFisherFaceRecognizer();
    model->set("threshold", THRESHOLD);

    try {
        model->load(ModelFileName);
    } catch (cv::Exception &e) {
        cerr << "ERROR: Could not load the model.\n";
    }
}

Mat runRecognizer(Mat cameraFrame, Mat &processedImage, const Ptr<FaceRecognizer> model, int &identity, double &similarity, CascadeClassifier &faceCascade, CascadeClassifier &eyeCascade1, CascadeClassifier &eyeCascade2){
    Mat displayedFrame;
    cameraFrame.copyTo(displayedFrame);

    Rect faceRect;  // Position of detected face.
    Rect searchedLeftEye, searchedRightEye; // top-left and top-right regions of the face, where eyes were searched.
    Point leftEye, rightEye;    // Position of the detected eyes.
    Mat preprocessedFace = getPreprocessedFace(displayedFrame, faceWidth, faceCascade, eyeCascade1, eyeCascade2, preprocessLeftAndRightSeparately, &faceRect, &leftEye, &rightEye, &searchedLeftEye, &searchedRightEye);

    bool gotFaceAndEyes = false;
    if (preprocessedFace.data)
        gotFaceAndEyes = true;

    if (faceRect.width > 0) { // Draw an anti-aliased rectangle around the detected face.
        rectangle(displayedFrame, faceRect, CV_RGB(255, 255, 0), 2, CV_AA);
    }

    if (gotFaceAndEyes) {
        identity = 0;
        double diff;
        int label;
        model->predict(preprocessedFace, label, diff);
//        model->predict(preprocessedFace);
        double relativeDif = CORRECTION_CONSTANT*(double)diff/(double)(preprocessedFace.rows * preprocessedFace.cols);
        similarity = 1.0 - min(max(relativeDif, 0.0), 1.0);
        if(label > 0)
        {
            identity = label;
            qDebug()<<"Recognised label";
        }
        else
        {
            qDebug()<<"UnRecognized label";
            save_unrecognized_images(preprocessedFace);
        }

        cout << "Identity: " << identity << ". Similarity: " << similarity << endl;
        if(similarity < 0.60)
        {
            qDebug()<<"wrong face";
        }

        // Copy the preprocessed face to processed Image to be shown in GUI
        Mat srcBGR = Mat(preprocessedFace.size(), CV_8UC3);
        cvtColor(preprocessedFace, srcBGR, CV_GRAY2BGR);
        processedImage = srcBGR;
    }
    return displayedFrame;
}
