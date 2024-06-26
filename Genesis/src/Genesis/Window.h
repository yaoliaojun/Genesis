#pragma once

#include "hzpch.h"

#include "Genesis/Core.h"
#include "Genesis/Events/Event.h"

namespace Genesis {

	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Genesis Engine",
			unsigned int width = 1280,
			unsigned int height = 720)
			:Title(title), Width(width), Height(height)
		{
		}
	};

	//表示桌面系统的界面基于Window
	class GENESIS_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;//事件回调

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		//Window 属性
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());//创建Window结构体，在每个平台实现
	};
}