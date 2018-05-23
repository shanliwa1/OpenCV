cmake_minimum_required( VERSION 2.8 )
project( read_image )
find_package( OpenCV REQUIRED )

add_executable( readImage read_image.cpp )
target_link_libraries( readImage ${OpenCV_LIBS} )

