cmake_minimum_required(VERSION 3.1)

project(ydd LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


### CMake versioning, compatibility, and modules
#
#
cmake_minimum_required( VERSION 3.5 )
if( POLICY CMP0071 )
    cmake_policy( SET CMP0071 NEW )
endif()
set( CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMakeModules" )

### C++ versioning and standards
#
#
set( CMAKE_CXX_STANDARD 14 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )
set( CMAKE_C_STANDARD 99 )
set( CMAKE_C_STANDARD_REQUIRED ON )

### Dependencies
#
#
set( QT_VERSION 5.7.0 )
set( YAMLCPP_VERSION 0.5.1 )

find_package( Qt5 ${QT_VERSION} CONFIG REQUIRED Core Gui Widgets Qml)
find_package( YAMLCPP ${YAMLCPP_VERSION} REQUIRED  )



### YDD itself
#
#
add_executable( yddx
    main.cpp 
    ChoiceItem.cpp
    ChoiceGroup.cpp
    Job.cpp
    YamlUtils.cpp
    qml.qrc
    )
target_include_directories( yddx
    PRIVATE
    ${YAMLCPP_INCLUDE_DIR}
    )
target_link_libraries( yddx
    Qt5::Core
    Qt5::Gui
    Qt5::Qml
    ${YAMLCPP_LIBRARY}
    )

    
set(CMAKE_AUTOMOC ON)
