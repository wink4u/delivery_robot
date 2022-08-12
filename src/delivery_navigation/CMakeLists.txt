cmake_minimum_required(VERSION 3.0.2)
project(delivery_navigation)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)


catkin_package(

)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

 install(DIRECTORY launch maps param rviz
   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
)


