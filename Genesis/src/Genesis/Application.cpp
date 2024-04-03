#include "hzpch.h"
#include "Application.h"

#include "Genesis/Log.h"

#include <GLFW/glfw3.h>

namespace Genesis {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)//�����к���

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());//����ָ��ָ��new��window�ṹ��
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	Application::~Application()
	{

	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);//�����¼�e��dispatcher
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));//�����WCE��ִ��OnWindowClose

		GN_CORE_TRACE("{0}", e);
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
	bool Application::OnWindowClose(WindowCloseEvent& e)//���ڹرմ�����
	{
		m_Running = false;//�˳�ѭ��
		return true;
	}
}
