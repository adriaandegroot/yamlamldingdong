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

### KDE/ECM includes for KDE Frameworks
#
#
find_package(ECM 1.0.0 REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${ECM_KDE_MODULE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
include(KDEInstallDirs)
include(KDECMakeSettings)
#include(KDECompilerSettings NO_POLICY_SCOPE)
include(FeatureSummary)


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
set( KF5_VERSION 5.49.0 )
set( YAMLCPP_VERSION 0.5.1 )


find_package( Qt5 ${QT_VERSION} CONFIG REQUIRED Core Gui Widgets Qml)
find_package( KF5 ${KF5_VERSION} REQUIRED COMPONENTS XmlGui )
find_package( YAMLCPP ${YAMLCPP_VERSION} OPTIONAL_COMPONENTS QUIET )

add_executable( yddx
    main.cpp 
    ChoiceItem.cpp
    ChoiceGroup.cpp
    Job.cpp
    YamlUtils.cpp
    )
target_include_directories( yddx
    PRIVATE
    ${YAMLCPP_INCLUDE_DIR}
    )
target_link_libraries( yddx
    Qt5::Core
    Qt5::Gui
    Qt5::Qml
    Qt5::Widgets
    KF5::XmlGui
    ${YAMLCPP_LIBRARY}
    )

feature_summary(WHAT ALL INCLUDE_QUIET_PACKAGES FATAL_ON_MISSING_REQUIRED_PACKAGES)
    
set(CMAKE_AUTOMOC ON)
