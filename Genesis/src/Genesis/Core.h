#pragma once

#ifdef GN_PLATFORM_WINDOWS
	#ifdef GN_BUILD_DLL
		#define GENESIS_API __declspec(dllexport)
	#else
		#define GENESIS_API __declspec(dllimport)
	#endif
#else
	#error Genesis only support Windows
#endif

#ifdef GN_ENABLE_ASSERTS
	#define GN_ASSERT(x, ...) { if(!(x)) { GN_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define GN_CORE_ASSERT(x, ...) { if(!(x)) { GN_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define GN_ASSERT(x, ...)
	#define GN_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)