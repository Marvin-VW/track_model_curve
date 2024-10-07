// Copyright (C) 2024 Marvin-VW
#include "arc_algorithm.h"

#include <cmath>

#define DEG_TO_RAD(x) ((x) * (M_PI / 180.0))
#define RAD_TO_DEG(x) ((x) * (180.0 / M_PI))

cv::Point2d drawPoint(cv::Mat&image, double center_x, double center_y, double radius, double angle) {

    double line_x = radius * sin(angle);
    double line_y = radius * cos(angle);
    int line_img_x = static_cast<int>(center_x + line_x);
    int line_img_y = static_cast<int>(center_y - line_y);
    cv::Point2d point(line_img_x, line_img_y);
    cv::circle(image, point, 2, cv::Scalar(0, 255, 0), cv::FILLED);

    return point;

}

void drawArcs(cv::Mat& image, double positionX, double positionY, double radius, double line_width, double step_distance1, double step_distance2, double angle_start, double angle_end, bool dashed) {
    
    double start_radians = DEG_TO_RAD(angle_start);
    double end_radians = DEG_TO_RAD(angle_end);

    int center_x = (image.cols / 2)+positionX;
    int center_y = (image.rows / 2)+positionY;

    double current_angle = start_radians;
    int step_toggle = 0;

    double prev_angle;
    bool first_step = true;

    if (!dashed) {
        cv::Point2d point1 = drawPoint(image, center_x, center_y, radius, start_radians);
        cv::Point2d point2 = drawPoint(image, center_x, center_y, radius+line_width, start_radians);
        cv::line(image, point1, point2, cv::Scalar(255,0,0), 1);
        cv::ellipse(image, cv::Point(center_x, center_y), cv::Size(radius, radius), -90, RAD_TO_DEG(start_radians), RAD_TO_DEG(end_radians), cv::Scalar(255,0,0), 1);

        point1 = drawPoint(image, center_x, center_y, radius+line_width, end_radians);
        point2 = drawPoint(image, center_x, center_y, radius, end_radians);
        cv::line(image, point1, point2, cv::Scalar(255,0,0), 1);
        cv::ellipse(image, cv::Point(center_x, center_y), cv::Size(radius+line_width, radius+line_width), -90, RAD_TO_DEG(start_radians), RAD_TO_DEG(end_radians), cv::Scalar(255,0,0), 1);
    }
    else {
        if (end_radians < current_angle) {
            std::swap(end_radians, current_angle);
        }

        while (current_angle <= end_radians) {
            if (!first_step) {
                double step_distance = (step_toggle % 2 == 0) ? step_distance1 : step_distance2;
                step_toggle++;

                double arc_length = step_distance;
                current_angle += arc_length / radius;
            }

            bool second_step = (step_toggle % 2 != 0);

            if (current_angle > end_radians) {
                current_angle = end_radians;
            }

            cv::Point2d point1 = drawPoint(image, center_x, center_y, radius, current_angle);
            cv::Point2d point2 = drawPoint(image, center_x, center_y, radius+line_width, current_angle);

            cv::line(image, point1, point2, cv::Scalar(255,0,0), 1);

            if (second_step && !first_step) {
                cv::ellipse(image, cv::Point(center_x, center_y), cv::Size(radius, radius), -90, RAD_TO_DEG(prev_angle), RAD_TO_DEG(current_angle), cv::Scalar(255,0,0), 1);
                cv::ellipse(image, cv::Point(center_x, center_y), cv::Size(radius+line_width, radius+line_width), -90, RAD_TO_DEG(prev_angle), RAD_TO_DEG(current_angle), cv::Scalar(255,0,0), 1);
            }
            else {

                
            }

            if (current_angle >= end_radians) {
                break;
            }

            prev_angle = current_angle;
            first_step = false;
        }
    }
}