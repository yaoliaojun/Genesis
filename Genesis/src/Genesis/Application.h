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

		std::unique_ptr<Window> m_Window;//����ʾ��ָ��
		bool m_Running = true;//ѭ���ж�
		LayerStack m_LayerStack;
	};


	//�ͻ��˶���
	Application* CreateApplication();
}

