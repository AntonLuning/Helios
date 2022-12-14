#pragma once

#include "HeliosPCH.h"

namespace Helios {

#define BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

	enum class EventType : uint8_t
	{
		None = 0,
		WindowResize, WindowMoved, WindowFocus, WindowLostFocus, WindowClose,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication    = BIT(0),
		EventCategoryInput          = BIT(1),
		EventCategoryKeyboard       = BIT(2),
		EventCategoryMouse          = BIT(3),
		EventCategoryMouseButton    = BIT(4)
	};


	class Event
	{
	public:
		bool Handled = false;

		virtual EventType GetEventType() const = 0;
		virtual uint8_t GetCategoryFlags() const = 0;

#ifndef HELIOS_DISTRIBUTION
		virtual const char* GetName() const = 0;
		virtual std::string ToString() const { return GetName(); }
#endif

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	};

#ifdef HELIOS_DISTRIBUTION
	#define EVENT_CLASS_TYPE(type)  static EventType GetStaticType() { return EventType::##type; }\
									virtual EventType GetEventType() const override { return GetStaticType(); }
#else
	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}

	#define EVENT_CLASS_TYPE(type)  static EventType GetStaticType() { return EventType::##type; }\
									virtual EventType GetEventType() const override { return GetStaticType(); }\
									virtual const char* GetName() const override { return #type; }
#endif

#define EVENT_CLASS_CATEGORY(category) virtual uint8_t GetCategoryFlags() const override { return category; }


	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;

	public:
		EventDispatcher(Event& event)
			: m_Event(event) {}

		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}

	private:
		Event& m_Event;
	};

}