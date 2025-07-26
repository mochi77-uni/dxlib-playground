//
// Created by Yuta on 2025-07-25.
//

#include "dxlib_wrapper.h"

#include <stdexcept>
#include <DxLib.h>

DxLibWrapper::DxLibWrapper() {
	if (DxLib_Init() == DxFailure)
		throw std::runtime_error("DxLib initialize failed");
}

DxLibWrapper::~DxLibWrapper() {
	DxLib_End();
}