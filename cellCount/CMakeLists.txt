cmake_minimum_required( VERSION 2.8 )
project( cellCount )
find_package( OpenCV REQUIRED )
add_executable( cellCount cellCount.cpp )
target_link_libraries( cellCount ${OpenCV_LIBS} )

