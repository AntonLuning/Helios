#pragma once

#include "Event.h"

namespace Helios {

	class MouseButtonEvent : public Event
	{
	public:
		inline uint32_t GetMouseButton() const { return m_Button; }

		EVENT_CLASS_CATEGORY(EventCategoryMouseButton | EventCategoryMouse | EventCategoryInput)

	protected:
		MouseButtonEvent(uint32_t button)
			: m_Button(button) {}

		uint32_t m_Button;
	};


	class MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(uint32_t button)
			: MouseButtonEvent(button) {}

#ifndef HELIOS_DISTRIBUTION
		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressed: " << GetMouseButton();
			return ss.str();
		}
#endif

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};


	class MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(uint32_t button)
			: MouseButtonEvent(button) {}

#ifndef HELIOS_DISTRIBUTION
		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleased: " << GetMouseButton();
			return ss.str();
		}
#endif

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};


	class MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float xPos, float yPos)
			: m_X(xPos), m_Y(yPos) {}

		inline float GetX() const { return m_X; }
		inline float GetY() const { return m_Y; }

#ifndef HELIOS_DISTRIBUTION
		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMoved: " << GetX() << ", " << GetY();
			return ss.str();
		}
#endif

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		float m_X, m_Y;
	};


	class MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float xOffset, float yOffset)
			: m_XOffset(xOffset), m_YOffset(yOffset) {}

		inline float GetXOffset() const { return m_XOffset; }
		inline float GetYOffset() const { return m_YOffset; }

#ifndef HELIOS_DISTRIBUTION
		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolled: " << GetXOffset() << ", " << GetYOffset();
			return ss.str();
		}
#endif

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		float m_XOffset, m_YOffset;
	};

}