cmake_minimum_required( 3.5 )
project( image_proc )
find_package( OpenCV REQUIRED )
add_executable( image_proc image_proc.cpp )
target_link_libraries( image_proc ${OpenCV_LIBS} )


