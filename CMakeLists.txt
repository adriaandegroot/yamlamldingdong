project( yamlamldingdong C CXX )

### CMake versioning, compatibility, and modules
#
#
cmake_minimum_required( VERSION 3.5 )
if( POLICY CMP0071 )
    cmake_policy( SET CMP0071 NEW )
endif()
set( CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMakeModules" )
set( CMAKE_AUTOMOC ON )

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

include_directories( ${YAMLCPP_INCLUDE_DIR} )

### YDD itself
#
#
add_library(libydd OBJECT ChoiceItem.cpp ChoiceGroup.cpp YamlUtils.cpp)
target_link_libraries( libydd
    Qt5::Core
    ${YAMLCPP_LIBRARY}
    )
add_executable( ydd 
    main.cpp 
    Job.cpp
    )
target_link_libraries( ydd
    libydd
    Qt5::Core
    ${YAMLCPP_LIBRARY}
    )
    
### Graphical applications
#
#
add_subdirectory( yddy )
