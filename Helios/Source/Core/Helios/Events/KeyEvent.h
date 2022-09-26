#pragma once

#include "Event.h"

namespace Helios {

	class KeyEvent : public Event
	{
	public:
		inline uint32_t GetKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	
	protected:
		KeyEvent(uint32_t keyCode)
			: m_KeyCode(keyCode) {}

		uint32_t m_KeyCode;
	};


	class KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(uint32_t keyCode, bool isRepeat)
			: KeyEvent(keyCode), m_IsRepeat(isRepeat) {}

		inline bool IsRepeated() const { return m_IsRepeat; }

#ifndef HELIOS_DISTRIBUTION
		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressed: " << GetKeyCode();
			if (IsRepeated())
				ss << " (repeated)";
			return ss.str();
		}
#endif

		EVENT_CLASS_TYPE(KeyPressed)

	private:
		bool m_IsRepeat;
	};


	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(uint32_t keyCode)
			: KeyEvent(keyCode) {}

#ifndef HELIOS_DISTRIBUTION
		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleased: " << GetKeyCode();
			return ss.str();
		}
#endif

		EVENT_CLASS_TYPE(KeyReleased)
	};


	class KeyTypedEvent : public KeyEvent
	{
	public:
		KeyTypedEvent(uint32_t keyCode)
			: KeyEvent(keyCode) {}

#ifndef HELIOS_DISTRIBUTION
		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyTyped: " << GetKeyCode();
			return ss.str();
		}
#endif

		EVENT_CLASS_TYPE(KeyTyped)
	};

}