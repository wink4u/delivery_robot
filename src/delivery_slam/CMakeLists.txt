cmake_minimum_required(VERSION 3.0.2)
project(delivery_slam)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  sensor_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES delivery_slam
#  CATKIN_DEPENDS roscpp sensor_msgs
#  DEPENDS system_lib
)


include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

install(DIRECTORY include/${PROJECT_NAME}/
   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
 )

install(DIRECTORY
   config
   launch
   map
   rviz
   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
 )

