// Copyright (C) 2024 Marvin-VW
#pragma once

#include <opencv2/opencv.hpp>

void drawArcs(cv::Mat& image, double positionX, double positionY, double radius, double line_width, double step_distance1, double step_distance2, double angle_start, double angle_end, bool dashed, int subdivisions);
void drawSubdivisionPoints(cv::Mat&image, std::vector<cv::Point2d> arcPoints);
std::vector<cv::Point2d> subdivisionPoints(double center_x, double center_y, double startAngle, double endAngle,  double radius, int subdivisions);