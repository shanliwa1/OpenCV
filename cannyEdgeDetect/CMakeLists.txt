cmake_minimum_required( VERSION 2.8 )
project( cannyDetect )
find_package( OpenCV REQUIRED )

add_executable( cannyDetect cannyDetect.cpp )
target_link_libraries( cannyDetect ${OpenCV_LIBS} )

