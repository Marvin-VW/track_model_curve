#include <iostream>
#include <cmath>
#include <opencv2/opencv.hpp>

#define DEG_TO_RAD(x) ((x) * (M_PI / 180.0))
#define RAD_TO_DEG(x) ((x) * (180.0 / M_PI))

int main() {
    double inner_radius = 200;
    double outer_radius = 250;
    double step_distance1 = 20;
    double step_distance2 = 40;
    double angle_start = 0;
    double angle_end = 90;

    double start_radians = DEG_TO_RAD(angle_start);
    double end_radians = DEG_TO_RAD(angle_end);

    int width = 800, height = 800;
    cv::Mat image = cv::Mat::zeros(height, width, CV_8UC3);

    int center_x = width / 2;
    int center_y = height / 2;

    double current_angle = start_radians;
    int step_toggle = 0;

    double prev_angle;
    bool first_step = true;

    bool dashed_left = true; 
    bool dashed_right = false;

    while (current_angle <= end_radians) {
        double step_distance = (step_toggle % 2 == 0) ? step_distance1 : step_distance2;
        bool second_step = (step_toggle % 2 != 0);
        step_toggle++;

        double arc_length = step_distance;
        current_angle += arc_length / inner_radius;

        if (current_angle > end_radians) {
            current_angle = end_radians;
        }


        if (second_step && !first_step) {
            double prev_angle_deg = RAD_TO_DEG(prev_angle);
            double current_angle_deg = RAD_TO_DEG(current_angle);

            if (dashed_left) {
                cv::ellipse(image, cv::Point(center_x, center_y), cv::Size(inner_radius, inner_radius), -90, prev_angle_deg, current_angle_deg, cv::Scalar(255, 0, 0), 2);
            } else {
                cv::ellipse(image, cv::Point(center_x, center_y), cv::Size(inner_radius, inner_radius), -90, RAD_TO_DEG(start_radians), RAD_TO_DEG(end_radians), cv::Scalar(255, 0, 0), 2);
            }

            if (dashed_right) {
                cv::ellipse(image, cv::Point(center_x, center_y), cv::Size(outer_radius, outer_radius), -90, prev_angle_deg, current_angle_deg, cv::Scalar(0, 255, 255), 2);
            } else {
                cv::ellipse(image, cv::Point(center_x, center_y), cv::Size(outer_radius, outer_radius), -90, RAD_TO_DEG(start_radians), RAD_TO_DEG(end_radians), cv::Scalar(0, 255, 255), 2);
            }
        }

        if (current_angle >= end_radians) {
            break;
        }


        prev_angle = current_angle;
        first_step = false;
    }

    cv::imshow("Circle Points with Arcs and Outer Radius", image);
    cv::waitKey(0);

    return 0;
}
