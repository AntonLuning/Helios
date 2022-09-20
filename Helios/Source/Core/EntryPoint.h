#pragma once

extern Helios::Application* Helios::CreateApplication();

int main(int argC, char** argV)
{
	Helios::Log::Init();

	auto app = Helios::CreateApplication();
	app->Run();
	delete app;

	Helios::Log::Shutdown();

	return 0;
}