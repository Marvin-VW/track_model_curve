// Copyright (C) 2024 Marvin-VW
#pragma once

#include <opencv2/opencv.hpp>

void drawArcs(cv::Mat& image, double positionX, double positionY, double radius, double line_width, double step_distance1, double step_distance2, double angle_start, double angle_end, bool dashed);

cv::Point2d drawPoint(cv::Mat&image, double center_x, double center_y, double radius, double angle);