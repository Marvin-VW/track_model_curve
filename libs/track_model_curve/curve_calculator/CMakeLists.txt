#Copyright (C) 2024 Marvin-VW
set(NAMESPACE track_model_curve)
set(MODULE curve_calculator)

set(TARGET_NAME "${NAMESPACE}_${MODULE}")

#
# find packages
#
find_package(fmt REQUIRED)
find_package(Boost COMPONENTS REQUIRED system)
find_package(OpenCV REQUIRED)

#
# add source files to target
#
add_library(${TARGET_NAME}
    arc_algorithm.h
    arc_algorithm.cc
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
    fmt::fmt
    Boost::system
    ${OpenCV_LIBS}
)

#
# add parent folder to targets include directories
#
target_include_directories(${TARGET_NAME}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../
    PUBLIC ${OpenCV_INCLUDE_DIRS}
    
)