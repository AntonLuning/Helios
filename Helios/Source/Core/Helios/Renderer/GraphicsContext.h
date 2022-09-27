#pragma once

namespace Helios {

	class GraphicsContext
	{
	public:
		GraphicsContext(GLFWwindow* windowHandle);
		~GraphicsContext() {}

		void Init();
		void SwapBuffers();

	private:
		GLFWwindow* m_WindowHandle;
	};

}