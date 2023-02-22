#pragma once
#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
namespace Niuniu {
	class NN_API Log
	{
	public:
		
		static void InitLog();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger(){ return s_CoreLogger;}

		inline static std::shared_ptr<spdlog::logger>& GetClientLogger(){ return s_ClientLogger;}

	private:
		
		static std::shared_ptr<spdlog::logger> s_CoreLogger;

		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}
//核心日志宏
#define NN_CORE_TRACE(...)   ::Niuniu::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define NN_CORE_INFO(...)	 ::Niuniu::Log::GetCoreLogger()->info(__VA_ARGS__)
#define NN_CORE_WARN(...)	 ::Niuniu::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define NN_CORE_ERROR(...)	 ::Niuniu::Log::GetCoreLogger()->error(__VA_ARGS__)
#define NN_CORE_FATAL(...)	 ::Niuniu::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//应用日志宏
#define NN_TRACE(...)	 ::Niuniu::Log::GetClientLogger()->trace(__VA_ARGS__)
#define NN_INFO(...)		 ::Niuniu::Log::GetClientLogger()->info(__VA_ARGS__)
#define NN_WARN(...)		 ::Niuniu::Log::GetClientLogger()->warn(__VA_ARGS__)
#define NN_ERROR(...)	 ::Niuniu::Log::GetClientLogger()->error(__VA_ARGS__)
#define NN_FATAL(...)	 ::Niuniu::Log::GetClientLogger()->fatal(__VA_ARGS__)