#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Genesis {
	class GENESIS_API Application
	{
	public:
		Application();
		virtual ~Application();


		void Run();
	};


	//�ͻ��˶���
	Application* CreateApplication();
}

