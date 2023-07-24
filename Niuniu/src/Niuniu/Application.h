#pragma once
#include "Core.h"
#include "Events/Event.h"
#include "Window.h"
#include "LayerStack.h"
namespace Niuniu {

	class NN_API Application
	{
	public:
		Application();

		virtual ~Application();

		void Run();
		void PushLayer(class Layer* layer);
		void PushOverlay(class Layer* layer);

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

		void OnEvent(Event& e);

		bool OnWindowClose(class WindowCloseEvent& e);

		LayerStack m_LayerStack;
	private:
		static Application* s_Instance;
	};

	Application* CreateApplication();
}


