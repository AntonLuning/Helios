#pragma once

extern Helios::Application* Helios::CreateApplication();

namespace Helios {

	int Main(int argC, char** arg)
	{
		Helios::Log::Init();

		auto app = Helios::CreateApplication();
		app->Run();
		delete app;

		Helios::Log::Shutdown();

		return 0;
	}

}

#ifdef HELIOS_DISTRIBUTION
	int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)
	{
		return Helios::Main(__argc, __argv);
	}
#else
	int main(int argC, char** argV)
	{
		return Helios::Main(argC, argV);
	}
#endif // HELIOS_DISTRIBUTION