#pragma once

#include "Events/Event.h"
#include "Events/WindowEvent.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"
#include "Renderer/GraphicsContext.h"

namespace Helios {

	struct WindowProps
	{
		std::string Title;
		uint16_t Width, Height;

		WindowProps(const std::string& title = "Helios", uint16_t width = 1280, uint16_t height = 720)
			: Title(title), Width(width), Height(height) {}
	};


	class Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		static Window* Create(const WindowProps& props = WindowProps());

		Window(const WindowProps& props);
		~Window();

		void OnUpdate();

		inline uint16_t GetWidth() const { return m_Data.Width; }
		inline uint16_t GetHeight() const { return m_Data.Height; }

		void SetVSync(bool enabled);
		bool IsVSync() const { return m_Data.VSync; }

		inline void SetEventCallback(const EventCallbackFn& callback) { m_Data.EventCallback = callback; }

		inline GLFWwindow* Get() const { return m_Window; }

	private:
		void Init(const WindowProps& props);
		void Shutdown();

	private:
		GLFWwindow* m_Window;
		GraphicsContext* m_Context;

		struct WindowData
		{
			std::string Title;
			uint16_t Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};
		WindowData m_Data;
	};

}