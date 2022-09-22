#pragma once

#include "Core.h"

namespace Helios {

	class HELIOS_API Input
	{
	public:
		static bool IsKeyPressed(uint32_t keycode);

		static bool IsMouseButtonPressed(uint32_t button);
		static std::pair<float, float> GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};

}