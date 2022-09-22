#pragma once

#include "HeliosPCH.h"

#include "Core.h"
#include "Events/Event.h"

namespace Helios {

	class HELIOS_API Layer
	{
	public:
		Layer(const std::string& name = "Layer")
			: m_Name(name) {}
		virtual ~Layer() {}

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_Name; }

	private:
		std::string m_Name;
	};

}