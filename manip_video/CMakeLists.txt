cmake_minimum_required( VERSION 2.8 )
project( manip_video )
find_package( OpenCV REQUIRED )
add_executable( manipVideo manip_video.cpp )
target_link_libraries( manipVideo ${OpenCV_LIBS})

