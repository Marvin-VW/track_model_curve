# Copyright (C) 2024 twyleg
set(TARGET_NAME unit_tests)


#
# add source files to target
#
add_executable(${TARGET_NAME}
    main.cc
)


#
# set target properties
#
set_target_properties(${TARGET_NAME}
    PROPERTIES
	CXX_STANDARD 17
	INCLUDE_CURRENT_DIR ON
)


#
# link against libs
#
target_link_libraries(${TARGET_NAME}
    track_model_curve::core
    GTest::gmock
    GTest::gtest
    GTest::gmock_main
    GTest::gtest_main
)
