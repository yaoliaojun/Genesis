#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Genesis {
	class GENESIS_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log 宏定义
#define GN_CORE_TRACE(...)    ::Genesis::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define GN_CORE_INFO(...)     ::Genesis::Log::GetCoreLogger()->info(__VA_ARGS__)
#define GN_CORE_WARN(...)     ::Genesis::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define GN_CORE_ERROR(...)    ::Genesis::Log::GetCoreLogger()->error(__VA_ARGS__)
#define GN_CORE_FATAL(...)    ::Genesis::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log 宏定义
#define GN_TRACE(...)	      ::Genesis::Log::GetClientLogger()->trace(__VA_ARGS__)
#define GN_INFO(...)	      ::Genesis::Log::GetClientLogger()->info(__VA_ARGS__)
#define GN_WARN(...)	      ::Genesis::Log::GetClientLogger()->warn(__VA_ARGS__)
#define GN_ERROR(...)	      ::Genesis::Log::GetClientLogger()->error(__VA_ARGS__)
#define GN_FATAL(...)	      ::Genesis::Log::GetClientLogger()->fatal(__VA_ARGS__)
