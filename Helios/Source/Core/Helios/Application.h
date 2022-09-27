#pragma once

#include "Window.h"
#include "LayerStack.h"
#include "ImGui/ImGuiLayer.h"

namespace Helios {

	class Application
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
		LayerStack m_LayerStack;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;

		static Application* s_Instance;
	};

	// To be defined by the client
	Application* CreateApplication();

}