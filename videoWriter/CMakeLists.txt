cmake_minimum_required( VERSION 2.8 )
project( videoWiter )
find_package( OpenCV REQUIRED )

add_executable( videoWriter videoWriter.cpp )
target_link_libraries( videoWriter ${OpenCV_LIBS} )

