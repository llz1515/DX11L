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
	 * @brief ������Ϣ��������Window Procedure/WndProc��
	 *
	 * ���� Windows Ӧ�ó���ĺ��Ļص����������ڴ����͵����ڵ�������Ϣ��
	 * ϵͳ���ڴ����¼�����������롢����ƶ������ڻ��Ƶȣ�����ʱ�Զ����ô˺�����
	 *
	 * @param hwnd   ���ھ����Handle to the Window������ʶ������Ϣ�Ĵ���
	 * @param umsg   ��Ϣ���ͣ�Unsigned Integer�������� WM_KEYDOWN��WM_PAINT ��
	 * @param wparam ������Ϣ������Word Parameter����ͨ�����ڴ��ݼ�ֵ������롢��־λ��
	 * @param lparam ������Ϣ������Long Parameter����ͨ�����ڴ��ݸ������ݣ������ꡢ�ṹ��ָ�룩
	 *
	 * @return LRESULT ��Ϣ��������ͨ������ 0 ��ʾ�Ѵ�������ֵ��������������Ϣ
	 *
	 * @note 1. ���������δ�������Ϣ���� DefWindowProc()�����򴰿��޷�������Ӧϵͳ����
	 *       2. �� 64 λϵͳ�У�WPARAM �� LPARAM ��Ϊ 64 λ����ʷ�������ƣ�
	 *       3. �����÷�ʾ����
	 *          - WM_KEYDOWN: wparam = ������루�� VK_SPACE��
	 *          - WM_MOUSEMOVE: LOWORD(lparam)=x����, HIWORD(lparam)=y����
	 *
	 * @see Microsoft Docs:
	 *       - Window Procedures: https://learn.microsoft.com/en-us/windows/win32/winmsg/window-procedures
	 *       - Message Types: https://learn.microsoft.com/en-us/windows/win32/winmsg/about-messages-and-message-queues
	 */
	LRESULT CALLBACK MessageHandler(
		HWND hwnd,      // [in] ������Ϣ�Ĵ��ھ������ CreateWindow ���أ�
		UINT umsg,      // [in] ��Ϣ��ʶ����WM_* ϵ�г�����
		WPARAM wparam,  // [in] ��Ϣ���Ӳ���������ȡ���� umsg��
		LPARAM lparam   // [in] ��Ϣ���Ӳ���������ȡ���� umsg��
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