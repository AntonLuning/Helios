#pragma once

extern Helios::Application* Helios::CreateApplication();

int main(int argc, char** argv)
{
	Helios::Log::Init();

	auto app = Helios::CreateApplication();
	app->Run();
	delete app;

	return 0;
}