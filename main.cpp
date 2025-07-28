
#include <iostream>
#include <print>
#include <chrono>
#include <glm/glm.hpp>

#define DX_NON_USING_NAMESPACE_DXLIB
#include <deque>
#include <DxLib.h>
#include <numeric>
#include <queue>
#include <bits/this_thread_sleep.h>

#include "dxlib_wrapper.h"

class DxObject {
	glm::vec2 position;
public:
	DxObject() : position{} {}
	explicit DxObject(const glm::vec2& position) : position{position} {}
	virtual ~DxObject() = default;

	glm::vec2& GetPosition() { return position; }

	[[nodiscard]] const glm::vec2& GetPosition() const { return position; }
	void SetPosition(float x, float y) { position = { x, y }; }
	void SetPosition(const glm::vec2& position) { this->position = position; }

	virtual void Draw() const = 0;
};

class DxRect final : public DxObject {
	glm::vec2 size;
public:
	DxRect() : size{} {}
	DxRect(const glm::vec2& position, const glm::vec2& size)
		: DxObject{position}, size{size} {}

	void Draw() const override {
		const auto& position = GetPosition();
		const auto halfSize = size / 2.f;
		DxLib::DrawBoxAA(
			position.x - halfSize.x, position.y - halfSize.y,
			position.x + halfSize.x, position.y + halfSize.y,
			DxLib::GetColor(0, 100, 0), TRUE);
	}

	[[nodiscard]] glm::vec2 GetNearestPoint(const glm::vec2& point) const {
		const auto& position = GetPosition();
		const auto halfSize = size / 2.f;
		return {
			glm::clamp(point.x, position.x - halfSize.x, position.x + halfSize.x),
			glm::clamp(point.y, position.y - halfSize.y, position.y + halfSize.y)
		};
	}
};

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	int ret = 0;

	// セットアップ
	DxLibWrapper::ChangeWindowMode(DxWindowMode::Windowed);
	DxLib::SetWaitVSyncFlag(TRUE);

	if ((ret = DxLib::DxLib_Init()) == DxLibWrapper::DxFailure) {
		std::println(std::cerr,"Failed to initialize dxlib");
		return EXIT_FAILURE;
	}

	using DxClock = std::chrono::high_resolution_clock;

	glm::vec2 windowSize{};
	DxLibWrapper::GetWindowSize(windowSize);
	DxRect rect{windowSize / 2.f, {100, 100}};

	auto previousTime = DxClock::now();
	while (DxLib::ProcessMessage() == DxLibWrapper::DxSuccess) {
		// デルタタイム処理
		const auto startTime = DxClock::now();
		std::chrono::duration<float> deltaTime = startTime - previousTime;
		previousTime = startTime;

		// コントロール処理
		glm::vec2 mousePosition;
		DxLibWrapper::GetMousePoint(mousePosition);

		// 描画処理
		DxLib::ClearDrawScreen();

		const auto framerate = DxLib::GetFPS();
		DxLib::DrawBox(0, 0, windowSize.x, windowSize.y, DxLib::GetColor(30, 30, 30), TRUE);

		DxLib::DrawFormatString(0, 0, DxLib::GetColor(255, 0, 0), "Framerate: %f", framerate);
		DxLib::DrawFormatString(0, 30, DxLib::GetColor(255, 0, 0), "Width: %f", windowSize.x);
		DxLib::DrawFormatString(0, 60, DxLib::GetColor(255, 0, 0), "Height: %f", windowSize.y);

		rect.Draw();

		const auto nearestPoint = rect.GetNearestPoint(mousePosition);
		DxLib::DrawCircleAA(nearestPoint.x, nearestPoint.y, 2, 16, DxLib::GetColor(255, 0, 0));

		DxLib::ScreenFlip();
	}

	DxLib::DxLib_End();
	return EXIT_SUCCESS;
}