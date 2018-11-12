add_executable( yddy
    main.cpp 
    Application.cpp
    MainWindow.cpp
)

target_include_directories( yddy
    PRIVATE
    ..
    ${YAMLCPP_INCLUDE_DIR}
    )
target_link_libraries( yddy
    libydd
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
    ${YAMLCPP_LIBRARY}
    )
