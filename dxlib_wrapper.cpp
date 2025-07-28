//
// Created by Yuta on 2025-07-25.
//

#include "dxlib_wrapper.h"

#include <stdexcept>

DxLibWrapper::DxLibWrapper() {
	if (DxLib::DxLib_Init() == DxFailure)
		throw std::runtime_error("DxLib initialize failed");
}

DxLibWrapper::~DxLibWrapper() {
	DxLib::DxLib_End();
}

DxWindowModeResult DxLibWrapper::ChangeWindowMode(DxWindowMode mode) {
	return static_cast<DxWindowModeResult>(DxLib::ChangeWindowMode(static_cast<int>(mode)));
}

int DxLibWrapper::GetWindowSize(glm::vec2& outSize) {
	int width, height;
	const int ret = DxLib::GetWindowSize(&width, &height);
	outSize.x = width;
	outSize.y = height;
	return ret;
}

int DxLibWrapper::GetMousePoint(glm::vec2& outLocation) {
	int x, y;
	const int ret = DxLib::GetMousePoint(&x, &y);
	outLocation.x = x;
	outLocation.y = y;
	return ret;
}
