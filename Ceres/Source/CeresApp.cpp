#include <Helios.h>

class ExampleLayer : public Helios::Layer
{
public:
	ExampleLayer()
		: Layer("Example") {}

	void OnUpdate() override
	{
		
	}

	void OnEvent(Helios::Event& event) override
	{
		HELIOS_TRACE("{0}", event);
	}
};

class Ceres : public Helios::Application
{
public:
	Ceres()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Helios::ImGuiLayer());
	}

	~Ceres() {}
};

Helios::Application* Helios::CreateApplication()
{
	return new Ceres();
}