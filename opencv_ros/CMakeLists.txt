cmake_minimum_required(VERSION 2.8.3)
project(opencv_ros)


find_package(catkin REQUIRED COMPONENTS
  cv_bridge
  image_transport
  roscpp
  sensor_msgs
  nav_msgs
  std_msgs
)

find_package(OpenCV REQUIRED)

## Declare a catkin package
catkin_package()

## Declare ROS messages and services
#add_message_files(FILES Num.msg)
#add_service_files(FILES imageTopic.srv)

## Generate added messages and services
#generate_messages(DEPENDENCIES std_msgs)



include_directories(
  ${OpenCV_INCLUDE_DIRS}
  ${catkin_INCLUDE_DIRS}
)


 add_executable(imageProcess src/image.cpp)
 target_link_libraries(imageProcess
   ${OpenCV_LIBRARIES}
   ${catkin_LIBRARIES}
 )
 add_dependencies(imageProcess imageProcess_gencpp)

 add_executable(odometry src/odom.cpp)
 target_link_libraries(odometry
   ${OpenCV_LIBRARIES}
   ${catkin_LIBRARIES}
 )
 add_dependencies(odometry odometry_gencpp)




