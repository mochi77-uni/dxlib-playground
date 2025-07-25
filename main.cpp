
#include <iostream>
#include <DxLib.h>
#include <print>

#include "dxlib_wrapper.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	try {
		auto& dxlib = DxLibWrapper::Instance();

	} catch (const std::exception& e) {
		std::print(std::cerr, "Error: {}", e.what());
	}

	return EXIT_SUCCESS;
}