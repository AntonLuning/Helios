#include "hlpch.h"
#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace Helios {

	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_AppLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^%T [%n]: %v%$");

		s_CoreLogger = spdlog::stderr_color_mt("HELIOS");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_AppLogger = spdlog::stderr_color_mt("APP");
		s_AppLogger->set_level(spdlog::level::trace);
	}

}