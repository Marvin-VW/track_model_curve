set(TARGET_NAME draw_curve)

add_executable(${TARGET_NAME}
    main.cc
)

set_target_properties(${TARGET_NAME}
    PROPERTIES
	CXX_STANDARD 17
        INCLUDE_CURRENT_DIR ON
)

target_link_libraries(${TARGET_NAME}
    draw_curve::core
)
