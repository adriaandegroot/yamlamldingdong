add_executable( yddy
    main.cpp 
)

target_include_directories( yddy
    PRIVATE
    ..
    ${YAMLCPP_INCLUDE_DIR}
    )
target_link_libraries( yddy
    libydd
    Qt5::Core
    ${YAMLCPP_LIBRARY}
    )
