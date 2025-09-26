#pragma once

#define WIN32_LEAN_AND_MEAN

#include <windows.h>

#include "InputClass.h"
#include "ApplicationClass.h"

class SystemClass
{
public:
	SystemClass();
	SystemClass(const SystemClass&);
	~SystemClass();

	bool Initialize();
	void Shutdown();
	void Run();

	/**
	 * @brief 窗口消息处理函数（Window Procedure/WndProc）
	 *
	 * 这是 Windows 应用程序的核心回调函数，用于处理发送到窗口的所有消息。
	 * 系统会在窗口事件（如键盘输入、鼠标移动、窗口绘制等）发生时自动调用此函数。
	 *
	 * @param hwnd   窗口句柄（Handle to the Window），标识接收消息的窗口
	 * @param umsg   消息类型（Unsigned Integer），例如 WM_KEYDOWN、WM_PAINT 等
	 * @param wparam 附加消息参数（Word Parameter），通常用于传递简单值（如键码、标志位）
	 * @param lparam 附加消息参数（Long Parameter），通常用于传递复杂数据（如坐标、结构体指针）
	 *
	 * @return LRESULT 消息处理结果，通常返回 0 表示已处理，非零值可能用于特殊消息
	 *
	 * @note 1. 必须对所有未处理的消息调用 DefWindowProc()，否则窗口无法正常响应系统操作
	 *       2. 在 64 位系统中，WPARAM 和 LPARAM 均为 64 位宽（历史遗留名称）
	 *       3. 典型用法示例：
	 *          - WM_KEYDOWN: wparam = 虚拟键码（如 VK_SPACE）
	 *          - WM_MOUSEMOVE: LOWORD(lparam)=x坐标, HIWORD(lparam)=y坐标
	 *
	 * @see Microsoft Docs:
	 *       - Window Procedures: https://learn.microsoft.com/en-us/windows/win32/winmsg/window-procedures
	 *       - Message Types: https://learn.microsoft.com/en-us/windows/win32/winmsg/about-messages-and-message-queues
	 */
	LRESULT CALLBACK MessageHandler(
		HWND hwnd,      // [in] 接收消息的窗口句柄（由 CreateWindow 返回）
		UINT umsg,      // [in] 消息标识符（WM_* 系列常量）
		WPARAM wparam,  // [in] 消息附加参数（含义取决于 umsg）
		LPARAM lparam   // [in] 消息附加参数（含义取决于 umsg）
	);

private:
	bool Frame();
	void InitializeWindows(int&, int&);
	void ShutdownWindows();

private:
	LPCWSTR m_applicationName;
	HINSTANCE m_hinstance;
	HWND m_hwnd;

	InputClass* m_Input;
	ApplicationClass* m_Application;
};

static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

static SystemClass* ApplicationHandle = 0;