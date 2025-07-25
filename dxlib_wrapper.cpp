//
// Created by Yuta_Chen on 2025-07-25.
//

#include <DxLib.h>

#include "dxlib_wrapper.h"

#include <stdexcept>

DxLibWrapper::DxLibWrapper() {
	if (DxLib_Init() == DxFailure)
		throw std::runtime_error("DxLib initialize failed");
}

DxLibWrapper::~DxLibWrapper() {
	DxLib_End();
}