#pragma once
#include "Core.h"
#include "Events/Event.h"
namespace Niuniu {

	class NN_API Application
	{
	public:
		Application();

		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}


