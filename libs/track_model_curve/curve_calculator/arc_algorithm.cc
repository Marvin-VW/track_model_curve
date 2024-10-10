// Copyright (C) 2024 Marvin-VW
#include "arc_algorithm.h"

#include <cmath>

#define DEG_TO_RAD(x) ((x) * (M_PI / 180.0))
#define RAD_TO_DEG(x) ((x) * (180.0 / M_PI))

std::vector<cv::Point2d> subdivisionPoints(double center_x, double center_y, double startAngle, double endAngle,  double radius, int subdivisions) {
    std::vector<cv::Point2d> arcPoints;
    for (int i = 0; i <= subdivisions; i++) {
        double theta = startAngle + (endAngle - startAngle) * i / subdivisions;
        int x = static_cast<int>(center_x + radius * cos(theta));
        int y = static_cast<int>(center_y + radius * sin(theta));
        arcPoints.push_back(cv::Point2d(x, y));
    }
    return arcPoints;
}

void drawSubdivisionPoints(cv::Mat&image, std::vector<cv::Point2d> arcPoints) {
    for (size_t i = 0; i < arcPoints.size() - 1; i++) {
        cv::line(image, arcPoints[i], arcPoints[i+1], cv::Scalar(255, 0, 0), 1);
    }
}

void drawArcs(cv::Mat& image, double positionX, double positionY, double radius, double line_width, double step_distance1, double step_distance2, double angle_start, double angle_end, bool dashed, int subdivisions) {
    
    double start_radians = DEG_TO_RAD(angle_start);
    double end_radians = DEG_TO_RAD(angle_end);

    int center_x = (image.cols / 2)+positionX;
    int center_y = (image.rows / 2)+positionY;

    double current_angle = start_radians;
    int step_toggle = 0;

    double prev_angle = end_radians;
    bool first_step = true;

    if (!dashed) {

        std::vector<cv::Point2d> arcPoints_inner;
        std::vector<cv::Point2d> arcPoints_outer;

        arcPoints_inner = subdivisionPoints(center_x, center_y, -start_radians, -end_radians, radius, subdivisions);
        arcPoints_outer = subdivisionPoints(center_x, center_y, -start_radians, -end_radians, radius+line_width, subdivisions);

        drawSubdivisionPoints(image, arcPoints_inner);
        drawSubdivisionPoints(image, arcPoints_outer);
            
        cv::line(image, arcPoints_inner[0], arcPoints_outer[0], cv::Scalar(255,0,0), 1);
        cv::line(image, arcPoints_inner[arcPoints_inner.size()-1], arcPoints_outer[arcPoints_outer.size()-1], cv::Scalar(255,0,0), 1);
    
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

            std::vector<cv::Point2d> arcPoints_inner;
            std::vector<cv::Point2d> arcPoints_outer;
            arcPoints_inner = subdivisionPoints(center_x, center_y, -prev_angle, -current_angle, radius, subdivisions);
            arcPoints_outer = subdivisionPoints(center_x, center_y, -prev_angle, -current_angle, radius+line_width, subdivisions);

            if (second_step && !first_step) {

                drawSubdivisionPoints(image, arcPoints_inner);
                drawSubdivisionPoints(image, arcPoints_outer);

            }
            
            cv::line(image, arcPoints_inner[0], arcPoints_outer[0], cv::Scalar(255,0,0), 1);
            cv::line(image, arcPoints_inner[arcPoints_inner.size()-1], arcPoints_outer[arcPoints_outer.size()-1], cv::Scalar(255,0,0), 1);

            if (current_angle >= end_radians) {
                break;
            }

            prev_angle = current_angle;
            first_step = false;
        }
    }
}