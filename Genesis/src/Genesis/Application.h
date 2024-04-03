#pragma once

#include "Core.h"

#include "Window.h"
#include "Genesis/LayerStack.h"
#include "Events/Event.h"
#include "Genesis/Events/ApplicationEvent.h"

namespace Genesis {
	class GENESIS_API Application
	{
	public:
		Application();
		virtual ~Application();


		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;//窗口示例指针
		bool m_Running = true;//循环判断
		LayerStack m_LayerStack;
	};


	//客户端定义
	Application* CreateApplication();
}

