#include "draw_arc/core/window.h"
#include "draw_arc/core/arc_algorithm.h"

int main() {
    //parameters for curve
    double inner_radius = 200;
    double outer_radius = 250;
    double step_distance1 = 35;
    double step_distance2 = 20;
    double angle_start = 0;
    double angle_end = 90;

    int width = 800, height = 800;

    //create image
    cv::Mat image = cv::Mat::zeros(height, width, CV_8UC3);

    drawArcs(image, inner_radius, outer_radius, step_distance1, step_distance2, angle_start, angle_end);

    //show image
    createWindowAndShowImage(image, "Circle Points with Arcs and Outer Radius", width, height);

    return 0;
}
