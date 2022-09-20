#pragma once

#include "Event.h"

namespace Helios {

	class HELIOS_API KeyEvent : public Event
	{
	public:
		inline uint32_t GetKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	
	protected:
		KeyEvent(uint32_t keyCode)
			: m_KeyCode(keyCode) {}

		uint32_t m_KeyCode;
	};


	class HELIOS_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(uint32_t keyCode, bool isRepeat)
			: KeyEvent(keyCode), m_IsRepeat(isRepeat) {}

		inline bool IsRepeated() const { return m_IsRepeat; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressed: " << GetKeyCode();
			if (IsRepeated())
				ss << " (repeated)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)

	private:
		bool m_IsRepeat;
	};


	class HELIOS_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(uint32_t keyCode)
			: KeyEvent(keyCode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleased: " << GetKeyCode();
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};

}