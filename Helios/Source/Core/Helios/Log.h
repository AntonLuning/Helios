#pragma once

#include "Base.h"

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Helios {

	class Log
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

#ifdef HELIOS_DISTRIBUTION
	// Core logger
	#define HELIOS_CORE_TRACE(...)     
	#define HELIOS_CORE_INFO(...)      
	#define HELIOS_CORE_WARN(...)      
	#define HELIOS_CORE_ERROR(...)     
	#define HELIOS_CORE_CRITICAL(...)  

	// App logger
	#define HELIOS_TRACE(...)          
	#define HELIOS_INFO(...)           
	#define HELIOS_WARN(...)           
	#define HELIOS_ERROR(...)          
	#define HELIOS_CRITICAL(...)       
#else
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
#endif