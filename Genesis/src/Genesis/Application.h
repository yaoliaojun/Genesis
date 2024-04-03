#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Genesis/Events/ApplicationEvent.h"
#include "Window.h"

namespace Genesis {
	class GENESIS_API Application
	{
	public:
		Application();
		virtual ~Application();


		void Run();

		void OnEvent(Event& e);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;//窗口示例指针
		bool m_Running = true;//循环判断
	};


	//客户端定义
	Application* CreateApplication();
}

