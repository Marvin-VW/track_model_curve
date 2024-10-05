#pragma once

#include <opencv2/opencv.hpp>

void drawArcs(cv::Mat& image, double radius, double step_distance1, double step_distance2, double angle_start, double angle_end, bool dashed);