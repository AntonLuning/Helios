#include <Helios.h>

class ExampleLayer : public Helios::Layer
{
public:
#ifdef HELIOS_DISTRIBUTION
	ExampleLayer() {}
#else
	ExampleLayer()
		: Layer("Example") {}
#endif

	void OnUpdate() override
	{
		if (Helios::Input::IsKeyPressed(HELIOS_KEY_TAB))
			HELIOS_TRACE("Tab key is pressed (poll)");
	}

	virtual void OnImGuiRender() override
	{
	/*	ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();*/
	}

	void OnEvent(Helios::Event& event) override
	{
		if (event.GetEventType() == Helios::EventType::KeyPressed)
		{
			Helios::KeyPressedEvent& e = (Helios::KeyPressedEvent&)event;
			if (e.GetKeyCode() == HELIOS_KEY_TAB)
				HELIOS_TRACE("Tab key is pressed (event)");
		}
	}
};

class Ceres : public Helios::Application
{
public:
	Ceres()
	{
#ifdef HELIOS_DISTRIBUTION
		::ShowWindow(::GetConsoleWindow(), SW_HIDE);
#endif

		PushLayer(new ExampleLayer());
	}

	~Ceres() {}
};

Helios::Application* Helios::CreateApplication()
{
	return new Ceres();
}