#include "Application.h"
#include "Events\ApplicationEvent.h"
#include "Log.h"

namespace Niuniu {
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			NN_INFO(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			NN_INFO(e);
		}

		while (true);
	}

}

