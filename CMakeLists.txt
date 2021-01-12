cmake_minimum_required(VERSION 3.17)
project(SCZR)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread -lrt")
SET(ALLEGRO_ROOT allegro/)


find_package (Threads)
include_directories(include)
add_executable(SCZR src/main.cpp src/Station.cpp src/Stations.cpp src/SharedMemory.cpp
        include/AbstractProcess.h include/SharedMemory.h src/SharedQueue.cpp include/utilities.h src/ProcessB.cpp include/ProcessB.h src/ProcessA.cpp include/ProcessA.h src/ProcessC.cpp include/ProcessC.h)

find_library(LIBRT rt)
if(LIBRT)
    target_link_libraries(SCZR ${LIBRT})
endif()

INCLUDE_DIRECTORIES( ${ALLEGRO_ROOT}/include)
LINK_DIRECTORIES( /${ALLEGRO_ROOT}/lib )



TARGET_INCLUDE_DIRECTORIES(SCZR PUBLIC ${ALLEGRO_ROOT})
TARGET_LINK_LIBRARIES(SCZR allegro
        allegro_color
        allegro_main
        allegro_primitives
        allegro_ttf
        allegro_acodec
        allegro_audio
        allegro_font)