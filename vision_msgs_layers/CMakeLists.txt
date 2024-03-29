cmake_minimum_required(VERSION 3.8)
project(vision_msgs_layers)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(ament_cmake_ros REQUIRED)
find_package(rqt_image_overlay_layer REQUIRED)
find_package(vision_msgs REQUIRED)

set(THIS_PACKAGE_INCLUDE_DEPENDS
  rqt_image_overlay_layer
  vision_msgs)

add_library(bounding_box_2d src/bounding_box_2d.cpp)
target_compile_features(bounding_box_2d PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17
target_include_directories(bounding_box_2d PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
ament_target_dependencies(bounding_box_2d ${THIS_PACKAGE_INCLUDE_DEPENDS})
pluginlib_export_plugin_description_file(rqt_image_overlay_layer plugins.xml)

# Causes the visibility macros to use dllexport rather than dllimport,
# which is appropriate when building the dll but not consuming it.
target_compile_definitions(bounding_box_2d PRIVATE "VISION_MSGS_LAYERS_BUILDING_LIBRARY")

install(
  DIRECTORY include/
  DESTINATION include
)
install(
  TARGETS bounding_box_2d
  EXPORT export_${PROJECT_NAME}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_export_include_directories(
  include
)
ament_export_libraries(
  bounding_box_2d
)
ament_export_targets(
  export_${PROJECT_NAME}
)
ament_export_dependencies(${THIS_PACKAGE_INCLUDE_DEPENDS})

ament_package()
