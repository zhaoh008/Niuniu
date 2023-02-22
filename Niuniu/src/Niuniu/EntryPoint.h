#pragma once
#include "Core.h"
#include "Log.h"

#ifdef NN_PLATFORM_WINDOWS
	extern Niuniu::Application* Niuniu::CreateApplication();

	int main(int argc, char** argv) {
		Niuniu::Log::InitLog();

		NN_CORE_WARN("������־ϵͳ��ʼ��");	
		NN_INFO("�ͻ��˴�ӡ��־");
		auto app=Niuniu::CreateApplication();
		app->Run();
		delete app;
	}
#else
	#error Niuniu only support windows!
#endif // NN_PLATFORM_WINDOWS