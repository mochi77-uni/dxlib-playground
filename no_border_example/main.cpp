
#include <iostream>
#include <print>

#define DX_NON_USING_NAMESPACE_DXLIB
#include <DxLib.h>

#include "dxlib_wrapper.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	int ret = 0;

	DxLib::SetWindowStyleMode(2);
	DxLibWrapper::ChangeWindowMode(DxWindowMode::Windowed);
	DxLib::SetUseBackBufferTransColorFlag(TRUE);

	if ((ret = DxLib::DxLib_Init()) == DxLibWrapper::DxFailure) {
		std::println(std::cerr,"Failed to initialize dxlib");
		return EXIT_FAILURE;
	}

	glm::vec2 windowSize{};
	DxLibWrapper::GetWindowSize(windowSize);

	while (DxLib::ProcessMessage() == DxLibWrapper::DxSuccess) {
		const auto halfWindowSize = windowSize / 2.f;
		const auto redColor = DxLib::GetColor(255, 0, 0);
		DxLib::DrawCircleAA(halfWindowSize.x, halfWindowSize.y, 20, 32, redColor);

		DxLib::ScreenFlip();
	}

	DxLib::DxLib_End();
	return EXIT_SUCCESS;
}
