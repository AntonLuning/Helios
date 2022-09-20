#pragma once

#ifdef HL_BUILD_DLL
	#define HELIOS_API __declspec(dllexport)
#else
	#define HELIOS_API __declspec(dllimport)
#endif // HL_BUILD_DLL


#ifdef HL_ENABLE_ASSERTS
	#define HL_ASSERT(x, ...) { if(!x) HL_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); }
	#define HL_CORE_ASSERT(x, ...) { if(!x) HL_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); }
#else
	#define HL_ASSERT(x, ...)
	#define HL_CORE_ASSERT(x, ...)
#endif // HL_ENABLE_ASSERTS


#define BIT(x) (1 << x)