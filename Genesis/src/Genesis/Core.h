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

#define BIT(x) (1 << x)