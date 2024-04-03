#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"

namespace Genesis {
	class GENESIS_API Application
	{
	public:
		Application();
		virtual ~Application();


		void Run();
	private:
		std::unique_ptr<Window> m_Window;//窗口指针
		bool m_Running = true;//循环判断
	};


	//客户端定义
	Application* CreateApplication();
}

