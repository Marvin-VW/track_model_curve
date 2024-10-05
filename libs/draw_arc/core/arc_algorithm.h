#pragma once

#include <opencv2/opencv.hpp>

void drawArcs(cv::Mat& image, double inner_radius, double outer_radius, double step_distance1, double step_distance2, double angle_start, double angle_end);
