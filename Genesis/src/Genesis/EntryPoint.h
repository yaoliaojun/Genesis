#pragma once

#ifdef GN_PLATFORM_WINDOWS

extern Genesis::Application* Genesis::CreateApplication();//CreateApp客户端实现

int main(int argc, char** argv)
{
	Genesis::Log::Init();
	GN_CORE_WARN("Initialized Log!");
	int a = 5;
	GN_INFO("Hello! Var={0}", a);


	auto app = Genesis::CreateApplication();
	app->Run();
	delete app;
}

#endif

