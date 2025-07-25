cmake_minimum_required(VERSION 3.31)
project(dxlib_playground)

set(CMAKE_CXX_STANDARD 26)

set(EXTERNAL_DIR "${CMAKE_SOURCE_DIR}/external")
set(DXLIB_INCLUDE_DIR "${EXTERNAL_DIR}/dxlib")
set(DXLIB_LIB_DIR "${EXTERNAL_DIR}/dxlib")

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

add_executable(dxlib_playground main.cpp
        dxlib_wrapper.cpp
        dxlib_wrapper.h)

target_include_directories(dxlib_playground PRIVATE ${DXLIB_INCLUDE_DIR})
target_link_directories(dxlib_playground PRIVATE ${DXLIB_LIB_DIR})

target_link_libraries(dxlib_playground PRIVATE
        ${DXLIB_LIBS}
        stdc++exp
)