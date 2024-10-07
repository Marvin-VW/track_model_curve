# Copyright (C) 2024 twyleg
set(NAMESPACE track_model_curve)
set(MODULE core)


set(TARGET_NAME "${NAMESPACE}_${MODULE}")

#
# find packages
#
find_package(fmt REQUIRED)
find_package(Boost COMPONENTS REQUIRED system)
find_package(Qt6 COMPONENTS REQUIRED Core)


#
# add source files to target
#
add_library(${TARGET_NAME}
    image_processing.cc
    image_processing.h
)

add_library("${NAMESPACE}::${MODULE}" ALIAS ${TARGET_NAME})


#
# set target properties
#
set_target_properties(${TARGET_NAME}
    PROPERTIES
        CXX_STANDARD 17
        INCLUDE_CURRENT_DIR ON
        AUTOMOC ON
        AUTORCC ON
)


#
# link against libs
#
target_link_libraries(${TARGET_NAME}
    track_model_curve::core
    track_model_curve::ui
    track_model_curve::curve_calculator
    fmt::fmt
    Boost::system
    Qt::Core
)


#
# add parent folder to targets include directories
#
target_include_directories(${TARGET_NAME}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../
)
