#pragma once

#ifdef HELIOS_DEBUG
	#define HELIOS_ENABLE_ASSERTS
#endif // HELIOS_DEBUG


#ifdef HELIOS_BUILD_DLL
	#define HELIOS_API __declspec(dllexport)
#else
	#define HELIOS_API __declspec(dllimport)
#endif // HELIOS_BUILD_DLL


#ifdef HELIOS_ENABLE_ASSERTS
	#define HELIOS_ASSERT(x, ...) { if(!(x)) { HELIOS_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define HELIOS_CORE_ASSERT(x, ...) { if(!(x)) { HELIOS_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define HELIOS_ASSERT(x, ...)
	#define HELIOS_CORE_ASSERT(x, ...)
#endif // HELIOS_ENABLE_ASSERTS


#define BIT(x) (1 << x)