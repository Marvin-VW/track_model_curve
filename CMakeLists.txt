cmake_minimum_required(VERSION 3.16.3)


project(draw_curve)

# Externals
add_subdirectory(external/googletest/)

# Libs
add_subdirectory(libs/draw_curve/core/)

# Apps
add_subdirectory(apps/draw_curve)

# Unit-Test
add_subdirectory(unit_tests/)
