#pragma once

#include "Core.h"

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Helios {

	class HELIOS_API Log
	{
		using Logger = std::shared_ptr<spdlog::logger>;

	public:
		static void Init();
		static void Shutdown();

		inline static Logger& GetCoreLogger() { return s_CoreLogger; }
		inline static Logger& GetAppLogger() { return s_AppLogger; }

	private:
		static Logger s_CoreLogger;
		static Logger s_AppLogger;
	};

}

// Core logger
#define HELIOS_CORE_TRACE(...)     ::Helios::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HELIOS_CORE_INFO(...)      ::Helios::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HELIOS_CORE_WARN(...)      ::Helios::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HELIOS_CORE_ERROR(...)     ::Helios::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HELIOS_CORE_CRITICAL(...)  ::Helios::Log::GetCoreLogger()->critical(__VA_ARGS__)

// App logger
#define HELIOS_TRACE(...)          ::Helios::Log::GetAppLogger()->trace(__VA_ARGS__)
#define HELIOS_INFO(...)           ::Helios::Log::GetAppLogger()->info(__VA_ARGS__)
#define HELIOS_WARN(...)           ::Helios::Log::GetAppLogger()->warn(__VA_ARGS__)
#define HELIOS_ERROR(...)          ::Helios::Log::GetAppLogger()->error(__VA_ARGS__)
#define HELIOS_CRITICAL(...)       ::Helios::Log::GetAppLogger()->critical(__VA_ARGS__)

// TODO: Do not include in dist build