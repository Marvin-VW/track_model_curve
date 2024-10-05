
set(TARGET_NAME draw_arc)

find_package(OpenCV REQUIRED)

add_executable(${TARGET_NAME}
    main.cc
)

set_target_properties(${TARGET_NAME}
    PROPERTIES
	CXX_STANDARD 17
	INCLUDE_CURRENT_DIR ON
        AUTOMOC ON
        AUTORCC ON
)

target_link_libraries(${TARGET_NAME}
    ${OpenCV_LIBS}
    #draw_arc::core
)
