# CMakeList.txt : CMake project for RISCDecoder, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)
set (CMAKE_CXX_STANDARD 17)
# Add source to this project's executable.
add_executable (RISCDecoder "RISCDecoder.cpp" "RISCDecoder.h" "LineDecoder/BaseDecoder.h" "LineDecoder/BaseDecoder.cpp" "LineDecoder/AddDecoder.h" "LineDecoder/AddDecoder.cpp" "LineDecoder/AddIDecoder.cpp" "LineDecoder/AddIDecoder.h" "DecodedInformation.h" "DecodedInformation.cpp" "LineDecoder/SubDecoder.h" "LineDecoder/SubIDecoder.h" "LineDecoder/SubDecoder.cpp" "LineDecoder/SubIDecoder.cpp" "LineDecoder/LaDecoder.cpp" "LineDecoder/LaDecoder.h" "LineDecoder/LiDecoder.h" "LineDecoder/LiDecoder.cpp" "LineDecoder/EcallDecoder.h" "LineDecoder/EcallDecoder.cpp")

# TODO: Add tests and install targets if needed.
