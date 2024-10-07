// Copyright (C) 2024 twyleg, Marvin-VW
#include "image_processing.h"

#include <track_model_curve/curve_calculator/arc_algorithm.h>

#include <opencv2/opencv.hpp>
#include <fmt/core.h>

#include <optional>

namespace track_model_curve::core {

#define DEG_TO_RAD(x) ((x) * (M_PI / 180.0))

ImageProcessing::ImageProcessing(

	track_model_curve::ui::ImageModel& imageModel,
	track_model_curve::ui::ParameterModel& parameterModel,
		QObject* parent) :
	QThread(parent),
	mImageModel(imageModel),
	mParameterModel(parameterModel)
{}

ImageProcessing::~ImageProcessing() {}

void ImageProcessing::run() {

    int width = 1280, height = 960;
	
    bool running = true;

    while(running) {

		double positionX = mParameterModel.getPositionX()-10000;
		double positionY = mParameterModel.getPositionY()-10000;
		double curve_radius = mParameterModel.getCurve_radius();
		double track_width = mParameterModel.getTrack_width(); 
		double dashed_length = mParameterModel.getDashed_length();
		double dashed_space = mParameterModel.getDashed_space();
		double curved_angle_start = mParameterModel.getCurved_angle_start(); 
		double curved_angle_end = mParameterModel.getCurved_angle_end();
		double line_width = mParameterModel.getLine_width();
		bool dashed_left = mParameterModel.getDashed_left();
		bool dashed_right = mParameterModel.getDashed_right();

		cv::Mat image = cv::Mat::zeros(height, width, CV_8UC3);

		//left line
		drawArcs(image, positionX, positionY, curve_radius, -line_width, dashed_length, dashed_space , curved_angle_start, curved_angle_end, dashed_left);

		//right line
		drawArcs(image, positionX, positionY, curve_radius+track_width, line_width, dashed_length, dashed_space, curved_angle_start, curved_angle_end, dashed_right);

		QImage img((uchar*)image.data, image.cols, image.rows, QImage::Format_RGB888);
		mImageModel.setImage(QPixmap::fromImage(img));

		msleep(1000 / 60.0);

    }

}
}
