#pragma once
#include "Core.h"
#include "Log.h"

#ifdef NN_PLATFORM_WINDOWS
	extern Niuniu::Application* Niuniu::CreateApplication();

	int main(int argc, char** argv) {
		Niuniu::Log::InitLog();

		NN_CORE_WARN("引擎日志系统初始化");	
		NN_INFO("客户端打印日志");
		auto app=Niuniu::CreateApplication();
		app->Run();
		delete app;
	}
#else
	#error Niuniu only support windows!
#endif // NN_PLATFORM_WINDOWS