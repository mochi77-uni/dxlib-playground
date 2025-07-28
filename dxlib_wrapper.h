//
// Created by Yuta on 2025-07-25.
//

#ifndef DXLIB_WRAPPER_H
#define DXLIB_WRAPPER_H

#include <windows.h>
#include <glm/glm.hpp>

#define DX_NON_USING_NAMESPACE_DXLIB
#include <DxLib.h>

enum class DxWindowMode : int {
	Windowed = TRUE,
	FullScreen = FALSE
};

enum class DxWindowModeResult : int {
	Ok = DX_CHANGESCREEN_OK,
	Return = DX_CHANGESCREEN_RETURN,
	Default = DX_CHANGESCREEN_DEFAULT
};

class DxLibWrapper {
	// シングルトンパターンのためコンストラクターは公開しない
	DxLibWrapper();
	~DxLibWrapper();
public:
	static DxLibWrapper& Instance() {
		static DxLibWrapper instance;
		return instance;
	}

	// コピー不可
	DxLibWrapper(const DxLibWrapper& wrapper) = delete;
	DxLibWrapper& operator=(const DxLibWrapper& wrapper) = delete;

	// ムーブ不可
	DxLibWrapper(DxLibWrapper&& wrapper) = delete;
	DxLibWrapper& operator=(DxLibWrapper&& wrapper) = delete;

	static constexpr int DxSuccess = 0;
	static constexpr int DxFailure = -1;

	static DxWindowModeResult ChangeWindowMode(DxWindowMode mode);
	static int GetWindowSize(glm::vec2& outSize);
	static int GetMousePoint(glm::vec2& outLocation);
};



#endif //DXLIB_WRAPPER_H
