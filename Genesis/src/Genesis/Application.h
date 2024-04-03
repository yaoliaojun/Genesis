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

		std::unique_ptr<Window> m_Window;//����ʾ��ָ��
		bool m_Running = true;//ѭ���ж�
	};


	//�ͻ��˶���
	Application* CreateApplication();
}

