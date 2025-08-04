cmake_minimum_required(VERSION 3.31)
project(dxlib_playground)

set(CMAKE_CXX_STANDARD 26)

set(EXTERNAL_DIR "${CMAKE_SOURCE_DIR}/external")
set(DXLIB_INCLUDE_DIR "${EXTERNAL_DIR}/dxlib/include")
set(DXLIB_LIB_DIR "${EXTERNAL_DIR}/dxlib/lib")

set(DXLIB_LIBS
        DxLib
        DxUseCLib
        DxDrawFunc
        jpeg
        png
        zlib
        tiff
        theora_static
        vorbis_static
        vorbisfile_static
        ogg_static
        bulletdynamics
        bulletcollision
        bulletmath
        opusfile
        opus
        silk_common
        celt	# 静的にリンクするライブラリの指定
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static -static-libgcc -static-libstdc++")

set(COMMON_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/common")
file(GLOB COMMON_SRC "${COMMON_INCLUDE_DIR}/*.cpp")

function(add_dxlib_executable TARGET_NAME)
    add_executable(${TARGET_NAME} ${ARGN} ${COMMON_SRC})
    target_include_directories(${TARGET_NAME} PRIVATE ${DXLIB_INCLUDE_DIR} ${COMMON_INCLUDE_DIR})
    target_link_directories(${TARGET_NAME} PRIVATE ${DXLIB_LIB_DIR})
    target_link_libraries(${TARGET_NAME} PRIVATE
            ${DXLIB_LIBS}
            stdc++exp
    )
endfunction()

add_dxlib_executable(dxlib_playground main.cpp)
add_dxlib_executable(no_border_example no_border_example/main.cpp)