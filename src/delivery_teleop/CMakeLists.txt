cmake_minimum_required(VERSION 3.0.2)
project(delivery_teleop)


find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  rospy
)

catkin_python_setup()

catkin_package(
  CATKIN_DEPENDS geometry_msgs rospy
)

catkin_install_python(PROGRAMS
  nodes/delivery_teleop_key
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(DIRECTORY launch
	DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)


