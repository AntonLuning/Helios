#pragma once

#include "Core.h"

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Helios {

	class HELIOS_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetAppLogger() { return s_AppLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_AppLogger;
	};

}

// Core logger
#define HL_CORE_TRACE(...)     ::Helios::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HL_CORE_INFO(...)      ::Helios::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HL_CORE_WARN(...)      ::Helios::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HL_CORE_ERROR(...)     ::Helios::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HL_CORE_CRITICAL(...)  ::Helios::Log::GetCoreLogger()->critical(__VA_ARGS__)

// App logger
#define HL_TRACE(...)          ::Helios::Log::GetAppLogger()->trace(__VA_ARGS__)
#define HL_INFO(...)           ::Helios::Log::GetAppLogger()->info(__VA_ARGS__)
#define HL_WARN(...)           ::Helios::Log::GetAppLogger()->warn(__VA_ARGS__)
#define HL_ERROR(...)          ::Helios::Log::GetAppLogger()->error(__VA_ARGS__)
#define HL_CRITICAL(...)       ::Helios::Log::GetAppLogger()->critical(__VA_ARGS__)

// TODO: Do not include in dist build