#pragma once

#include "HeliosPCH.h"

#include "Core.h"
#include "Events/Event.h"

namespace Helios {

	class HELIOS_API Layer
	{
	public:
#ifdef HELIOS_DISTRIBUTION
		Layer() {}
#else
		Layer(const std::string& name = "Layer")
			: m_Name(name) {}

		inline const std::string& GetName() const { return m_Name; }

	private:
		std::string m_Name;
#endif // HELIOS_DISTRIBUTION

	public:
		virtual ~Layer() {}

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& event) {}

	};

}