#include <Helios.h>

class ExampleLayer : public Helios::Layer
{
public:
	ExampleLayer()
		: Layer("Example") {}

	void OnUpdate() override
	{
		HELIOS_INFO("ExampleLayer::Update");
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
	}

	~Ceres() {}
};

Helios::Application* Helios::CreateApplication()
{
	return new Ceres();
}