#include "hzpch.h"
#include "Application.h"

#include "Genesis/Events/ApplicationEvent.h"
#include "Genesis/Log.h"

#include <GLFW/glfw3.h>

namespace Genesis {
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());//智能指针指向new的window结构体
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}
}
