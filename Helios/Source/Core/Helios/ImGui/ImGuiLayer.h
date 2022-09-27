#pragma once

#include "Core/Helios/Base.h"
#include "Core/Helios/Layer.h"
#include "Core/Helios/Events/WindowEvent.h"
#include "Core/Helios/Events/KeyEvent.h"
#include "Core/Helios/Events/MouseEvent.h"

namespace Helios {

	class ImGuiLayer : public Layer
	{
	public:
#ifdef HELIOS_DISTRIBUTION
		ImGuiLayer() {}
#else
		ImGuiLayer()
			: Layer("ImGuiLayer") {}
#endif // HELIOS_DISTRIBUTION
		~ImGuiLayer() {}

		virtual void OnAttach() override;
		virtual void OnDetach() override;

		void Begin();
		void End();

	private:
		float m_Time = 0.0f;
	};

}