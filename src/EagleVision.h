///*
// * EagleVision.h
// *
// *  Created on: Feb 24, 2016
// *      Author: Miles
// */
//
//#ifndef SRC_EAGLEVISION_H_
//#define SRC_EAGLEVISION_H_
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <opencv2/opencv.hpp>
//#include <string>
//#include <ctime>
//#include <iostream>
//#include <iomanip>
//#include <sstream>
//#include <unistd.h>
//#include <pthread.h>
//#include <math.h>
//#include <ctime>
//#include "Robot.h"
//
//using namespace cv;
//using namespace std;
//
//
//class EagleVision {
//public:
//	EagleVision();
//	virtual ~EagleVision();
//	void processImage();
//	double normalizeAngle(double angle);
//	bool processVision;
//
//private:
//	//	constants for the color rbg values
//		const cv::Scalar RED = cv::Scalar(0, 0, 255),
//		BLUE = cv::Scalar(255, 0, 0),
//		GREEN = cv::Scalar(0, 255, 0),
//		BLACK = cv::Scalar(0,0,0),
//		YELLOW = cv::Scalar(0, 255, 255);
//
//	Scalar LOWER_BOUNDS = Scalar(58,0,109);
//	Scalar UPPER_BOUNDS = Scalar(93,255,240);
//
//	const cv::Size resize = cv::Size(320,240);
//
//	Mat matOriginal, matHSV, matThresh, clusters, matHeirarchy;
//
//	//camera info
//	const static int CAMERA_HEIGHT = 10;
//	constexpr static double VERTICAL_FOV  = 51;
//	constexpr static double HORIZONTAL_FOV  = 67;
//	constexpr static double CAMERA_ANGLE = 10;
//	cv::VideoCapture videoCapture;
//
//	 int biggestArea = 0;
//	 int biggestAreaIndex = 0;
//	 std::vector<std::vector<cv::Point>> contours;
//	 std::vector<std::vector<cv::Point>> selected;
//
//	 //top target height in stronghold is 97in
//	const int TOP_TARGET_HEIGHT = 97;
//
//};
//
//
//#endif /* SRC_EAGLEVISION_H_ */
