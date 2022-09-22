#pragma once

#include "Core/Helios/Core.h"
#include "Core/Helios/Layer.h"
#include "Core/Helios/Events/WindowEvent.h"
#include "Core/Helios/Events/KeyEvent.h"
#include "Core/Helios/Events/MouseEvent.h"

namespace Helios {

	class HELIOS_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach() override;
		void OnDetach() override;
		void OnUpdate() override;
		void OnEvent(Event& event) override;

	private:
		bool OnWindowResizeEvent(WindowResizeEvent& e);
		bool OnWindowMovedEvent(WindowMovedEvent& e);			// Remove?
		bool OnWindowFocusEvent(WindowFocusEvent& e);			// Remove?
		bool OnWindowLostFocusEvent(WindowLostFocusEvent& e);	// Remove?
		
		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);
		bool OnKeyTypedEvent(KeyTypedEvent& e);
		
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		bool OnMouseMovedEvent(MouseMovedEvent& e);
		bool OnMouseScrolledEvent(MouseScrolledEvent& e);

	private:
		float m_Time = 0.0f;
	};

}