#include "HeliosPCH.h"
#include "GraphicsContext.h"

namespace Helios {

	GraphicsContext::GraphicsContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		HELIOS_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void GraphicsContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		HELIOS_CORE_ASSERT(status, "Failed to initialize glad!");

		HELIOS_CORE_INFO("OpenGL Info:");
		HELIOS_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		HELIOS_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		HELIOS_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));
	}

	void GraphicsContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}

}