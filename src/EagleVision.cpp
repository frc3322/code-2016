///*
// * EagleVision.cpp
// *
// *  Created on: Feb 24, 2016
// *      Author: Miles
// */
//
//#include <EagleVision.h>
//
//using namespace cv;
//using namespace std;
//
//#define PI 3.14159265
//
//EagleVision::EagleVision() {
//	// TODO Auto-generated constructor stub
//
//}
//
//void EagleVision::processImage(){
//	double x,y,targetX,distance,azimuth;
//	//frame count
//	int FrameNumber = 0;
//	while(FrameNumber<120){
//		contours.clear();
//		selected.clear();
//
//		videoCapture.read(matOriginal);
//		cv::imwrite("/home/lvuser/original.jpg",matOriginal);
//		cv::cvtColor(matOriginal,matHSV,cv::COLOR_BGR2HSV);
//		cv::inRange(matHSV,LOWER_BOUNDS,UPPER_BOUNDS,matThresh);
//		cv::findContours(matThresh,contours,matHeirarchy,cv::RETR_EXTERNAL,
//							cv::CHAIN_APPROX_SIMPLE);
//		std::cout <<"Size of detected contours: " <<contours.size() <<std::endl;
//		//make sure contours are valid.  Should be at least 20x20
//		//pixels, and have an area greater than 400 pixels^2,
//		//and an aspect ratio greater than 1
//		for(unsigned int i = 0; i<contours.size();i++){
//			cv::Rect rec = cv::boundingRect(contours[i]);
//			float aspectRatio = (float)rec.width / (float)rec.height;
//			if(aspectRatio > 1.0){
//				if(rec.area() > biggestArea){
//					biggestArea = rec.area();
//					selected.push_back(contours[i]);
//				}
//
//			}
//		}
//		//if only 1 target is selected, we have found our goal
//		if(selected.size() == 1){
//			std::cout << "We have found 1 target!" <<std::endl;
//			cv::Rect rec = boundingRect(selected[0]);
//		// "fun" math brought to you by miss daisy (team 341)
// 			y = rec.br().y + rec.height / 2;
// 			y= -((2 * (y / matOriginal.cols)) - 1);
// 			distance = (TOP_TARGET_HEIGHT - CAMERA_HEIGHT) /
// 					tan((y * VERTICAL_FOV / 2.0 + CAMERA_ANGLE) * PI / 180);
// //				angle to target...would not rely on this
// 			targetX = rec.tl().x + rec.width / 2;
// 			targetX = (2 * (targetX / matOriginal.rows)) - 1;
// 			azimuth = EagleVision::normalizeAngle(targetX * HORIZONTAL_FOV /2.0 + 0);
//
// 			cv::Point center =  cv::Point(rec.br().x-rec.width / 2 - 15,rec.br().y - rec.height / 2);
// 			cv::Point centerw =  cv::Point(rec.br().x-rec.width / 2 - 15,rec.br().y - rec.height / 2 - 20);
// 			cv::putText(matOriginal, ""+(int)distance, center, cv::FONT_HERSHEY_PLAIN, 1, BLACK);
// 			cv::putText(matOriginal, ""+(int)azimuth, centerw, cv::FONT_HERSHEY_PLAIN, 1, BLACK);
//		}
//		//debugging image output
//		cv::imwrite("/home/lvuser/output.jpg", matOriginal);
//	}
//
//}
//double EagleVision::normalizeAngle(double angle){
//	while(angle >= 360.0){
//		angle -=360;
//	}
//	while(angle <0.0){
//		angle +=360.0;
//	}
//	return angle;
//}
//
//EagleVision::~EagleVision() {
//	// TODO Auto-generated destructor stub
//}
//
