project( yamlamldingdong C CXX )

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

find_package( Qt5 ${QT_VERSION} CONFIG REQUIRED Core Gui Widgets )
find_package( YAMLCPP ${YAMLCPP_VERSION} REQUIRED )

### YDD itself
#
#
add_executable( ydd 
    main.cpp 
    )
target_link_libraries( ydd
    Qt5::Core
    ${YAMLCPP_LIBRARY}
    )
    
