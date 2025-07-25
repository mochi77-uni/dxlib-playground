
#include <iostream>
#include <DxLib.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	if (DxLib_Init() == -1) return EXIT_FAILURE;

	DxLib_End();
	return EXIT_SUCCESS;
}