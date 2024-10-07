# Copyright (C) 2024 twyleg
cmake_minimum_required(VERSION 3.16.3)

project(track_model_curve)

# Externals
add_subdirectory(external/googletest/)

# Libs
add_subdirectory(libs/track_model_curve/core/)
add_subdirectory(libs/track_model_curve/ui/)
add_subdirectory(libs/track_model_curve/curve_calculator/)

# Apps
add_subdirectory(apps/track_model_curve)


# Unit-Test
add_subdirectory(unit_tests/)
