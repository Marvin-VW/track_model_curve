#pragma once

#include <opencv2/opencv.hpp>
#include <string>

void createWindowAndShowImage(const cv::Mat& image, const std::string& window_name, int width, int height);
