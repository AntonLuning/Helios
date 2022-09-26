#include "HeliosPCH.h"
#include "Input.h"

#include "Core/Helios/Application.h"

namespace Helios {

	bool Input::IsKeyPressed(uint32_t keycode)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().Get());
		int state = glfwGetKey(window, keycode);

		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool Input::IsMouseButtonPressed(uint32_t button)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().Get());
		int state = glfwGetMouseButton(window, button);

		return state == GLFW_PRESS;
	}

	std::pair<float, float> Input::GetMousePosition()
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().Get());
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);

		return { (float)xpos, (float)ypos };
	}

	float Input::GetMouseX()
	{
		auto [xpos, ypos] = GetMousePosition();
		
		return xpos;
	}

	float Input::GetMouseY()
	{
		auto [xpos, ypos] = GetMousePosition();

		return ypos;
	}

}