#include "window.h"

void createWindowAndShowImage(const cv::Mat& image, const std::string& window_name, int width, int height) {

    cv::namedWindow(window_name, cv::WINDOW_NORMAL);
    cv::resizeWindow(window_name, width, height);

    cv::imshow(window_name, image);

    cv::waitKey(0);
}
