#pragma once

#include "HeliosPCH.h"

#include "Core/Helios/Core.h"

namespace Helios {

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

	enum class EventType
	{
		None = 0,
		WindowResize, WindowMoved, WindowFocus, WindowLostFocus, WindowClose,
		KeyPressed, KeyReleased,
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


	class HELIOS_API Event
	{
		friend class EventDispatcher;

	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual std::string ToString() const { return GetName(); }
		virtual uint8_t GetCategoryFlags() const = 0;
		
		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}

	protected:
		bool m_Handled = false;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}

#define EVENT_CLASS_TYPE(type)  static EventType GetStaticType() { return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

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
				m_Event.m_Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}

	private:
		Event& m_Event;
	};

}