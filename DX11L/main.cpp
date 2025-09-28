#include "SystemClass.h"
#include <iostream>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pScmdline, int iCmdshow)
{
	// 创建调试用控制台窗口
	AllocConsole();
	FILE* stream;
	freopen_s(&stream, "CONOUT$", "w", stdout);

	SystemClass* System;
	bool result;
	// Create the system object.
	System = new SystemClass;
	if (!System)
	{
		return 0;
	}
	// Initialize and run the system object.
	result = System->Initialize();
	if (result)
	{
		System->Run();
	}
	// Shutdown and release the system object.
	System->Shutdown();
	delete System;
	System = 0;
	return 0;
}