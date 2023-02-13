#pragma once
#include "Core.h"

#ifdef NN_PLATFORM_WINDOWS
	extern Niuniu::Application* Niuniu::CreateApplication();

	int main(int argc, char** argv) {
		auto app=Niuniu::CreateApplication();
		app->Run();
		delete app;
	}
#else
	#error Niuniu only support windows!
#endif // NN_PLATFORM_WINDOWS