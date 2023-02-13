#pragma once
#include "Core.h"
namespace Niuniu{

	class NN_API Application
	{
	public:
		Application();

		virtual ~Application();
		
		void Run();
	};

	Application* CreateApplication();
}


