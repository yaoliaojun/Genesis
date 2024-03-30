#include "hzpch.h"
#include "Application.h"

#include "Genesis/Events/ApplicationEvent.h"
#include "Genesis/Log.h"
namespace Genesis {
	Application::Application()
	{
	}

	Application::~Application()
	{

	}


	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			GN_TRACE(e);
		}
		while (true);
	}
}
