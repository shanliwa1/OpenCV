cmake_minimum_required( VERSION 2.8 )
project( read_Video )

find_package( OpenCV REQUIRED )
add_executable( readVideo read_video.cpp )
target_link_libraries( readVideo ${OpenCV_LIBS} )

