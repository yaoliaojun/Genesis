#include <Genesis.h>


class ExampleLayer : public Genesis::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		GN_INFO("ExampleLayer::Update");
	}

	void OnEvent(Genesis::Event& event) override
	{
		GN_TRACE("{0}", event);
	}

};

class Sandbox :public Genesis::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}

};

Genesis::Application* Genesis::CreateApplication()
{
	return new Sandbox();
}