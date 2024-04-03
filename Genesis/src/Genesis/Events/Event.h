#pragma once

#include "hzpch.h"
#include "Genesis/Core.h"

namespace Genesis {

	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput		 = BIT(1),
		EventCategoryKeyboard	 = BIT(2),
		EventCategoryMouse		 = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};
	//宏重写函数，返回事件名id，返回事件类 
#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() {return EventType::##type;}\
							   virtual EventType GetEventType() const override {return GetStaticType();}\
							   virtual const char* GetName() const override {return #type;}

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override {return category;}

	class GENESIS_API Event
	{
		friend class EventDispatcher;
	public:
		virtual EventType GetEventType() const = 0;//必须继承后填充&this指向不能修改
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category)//利用与过滤事件
		{
			return GetCategoryFlags() & category;
		}
	protected:
		bool m_Handled = false;//是否已经被处理
	};

	class EvnetDispatcher //事件调度器，将事件调度到指定函数指针
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EvnetDispatcher(Event& event)
			:m_Event(event)
		{
		}

		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event, GetEventType() == T::GetStaticType())//将事件id与模板参数比较
			{
				m_Event.m_Handled = func(*(T*)&m_Event);//符合则调度相应模板
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}
}

