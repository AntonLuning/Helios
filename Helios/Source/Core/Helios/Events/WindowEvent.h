#pragma once

#include "Event.h"

namespace Helios {

	class HELIOS_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(uint16_t width, uint16_t height)
			: m_Width(width), m_Height(height) {}

		inline uint16_t GetWidth() const { return m_Width; }
		inline uint16_t GetHeight() const { return m_Height; }

#ifndef HELIOS_DISTRIBUTION
		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResize: " << GetWidth() << ", " << GetHeight();
			return ss.str();
		}
#endif

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	private:
		uint16_t m_Width, m_Height;
	};


	class HELIOS_API WindowMovedEvent : public Event
	{
	public:
		WindowMovedEvent(float xPos, float yPos)
			: m_X(xPos), m_Y(yPos) {}

		inline float GetX() const { return m_X; }
		inline float GetY() const { return m_Y; }

#ifndef HELIOS_DISTRIBUTION
		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowMoved: " << GetX() << ", " << GetY();
			return ss.str();
		}
#endif

		EVENT_CLASS_TYPE(WindowMoved)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	private:
		float m_X, m_Y;
	};


	class HELIOS_API WindowFocusEvent : public Event
	{
	public:
		WindowFocusEvent() {}

		EVENT_CLASS_TYPE(WindowFocus)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};


	class HELIOS_API WindowLostFocusEvent : public Event
	{
	public:
		WindowLostFocusEvent() {}

		EVENT_CLASS_TYPE(WindowLostFocus)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};


	class HELIOS_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {}

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

}