cmake_minimum_required( VERSION 2.8 )
project( accessPixel )
find_package( OpenCV REQUIRED )

add_executable( accessPixel accessPixel.cpp )
target_link_libraries( accessPixel ${OpenCV_LIBS} )

