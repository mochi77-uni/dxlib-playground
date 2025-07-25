//
// Created by Yuta_Chen on 2025-07-25.
//

#ifndef DXLIB_WRAPPER_H
#define DXLIB_WRAPPER_H

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
};



#endif //DXLIB_WRAPPER_H
