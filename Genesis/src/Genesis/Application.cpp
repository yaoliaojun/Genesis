#include "hzpch.h"
#include "Application.h"

#include "Genesis/Log.h"

#include <GLFW/glfw3.h>

namespace Genesis {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)//绑定已有函数

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());//智能指针指向new的window结构体
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	Application::~Application()
	{

	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);//创建事件e的dispatcher
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));//如果是WCE则执行OnWindowClose

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
		{
			(*--it)->OnEvent(e);
			if (e.Handled)
				break;
		}
	}
	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();

			m_Window->OnUpdate();

			
		}
	}
	bool Application::OnWindowClose(WindowCloseEvent& e)//窗口关闭处理函数
	{
		m_Running = false;//退出循环
		return true;
	}
}
