#include "draw_curve/core/window.h"
#include "draw_curve/core/arc_algorithm.h"

int main() {
    //parameters for curve
    double inner_curve_radius, outer_curve_radius, dashed_length, dashed_space, curved_angle_start, curved_angle_end;

    std::cout << "Enter inner curve radius: ";
    std::cin >> inner_curve_radius;

    std::cout << "Enter outer curve radius: ";
    std::cin >> outer_curve_radius;

    std::cout << "Enter dashed line length: ";
    std::cin >> dashed_length;

    std::cout << "Enter dashed line space: ";
    std::cin >> dashed_space;

    std::cout << "Enter curve angle start: ";
    std::cin >> curved_angle_start;

    std::cout << "Enter curve angle end: ";
    std::cin >> curved_angle_end;

    int width = 800, height = 800;

    cv::Mat image = cv::Mat::zeros(height, width, CV_8UC3);

    //left line
    drawArcs(image, inner_curve_radius, dashed_length, dashed_space , curved_angle_start, curved_angle_end, true);

    //right line
    drawArcs(image, outer_curve_radius, dashed_length, dashed_space, curved_angle_start, curved_angle_end, false);

    //show image
    createWindowAndShowImage(image, "Curve", width, height);

    return 0;
}
