#pragma once

#include "Core.h"
#include "Window.h"
#include "LayerStack.h"

namespace Helios {

	class HELIOS_API Application
	{
	public:
		Application();
		virtual ~Application() {}

		void Run();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		void OnEvent(Event& e);

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;

		static Application* s_Instance;
	};

	// To be defined by the client
	Application* CreateApplication();

}