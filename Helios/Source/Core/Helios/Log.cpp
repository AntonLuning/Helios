#include "HeliosPCH.h"
#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace Helios {

	Log::Logger Log::s_CoreLogger;
	Log::Logger Log::s_AppLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^%T [%n]: %v%$");

		s_CoreLogger = spdlog::stderr_color_mt("HELIOS");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_AppLogger = spdlog::stderr_color_mt("APP");
		s_AppLogger->set_level(spdlog::level::trace);
	}

	void Log::Shutdown()
	{
		s_CoreLogger.reset();
		s_AppLogger.reset();
	}

}