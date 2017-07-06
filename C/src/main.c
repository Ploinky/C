/*
 * main.c
 *
 *  Created on: 06.07.2017
 *      Author: johannes.litger
 */

#include "main.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine,
        int CmdShow)
{
	MSG msg;
	WNDCLASSW wc =
	{ 0 };

	wc.lpszClassName = L"Window";
	wc.hInstance = hInstance;
	wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
	wc.lpfnWndProc = WndProc;
	wc.hCursor = LoadCursor(0, IDC_ARROW);

	RegisterClassW(&wc);

	hwnd = CreateWindowW(wc.lpszClassName, L"Window",
	        WS_OVERLAPPEDWINDOW | WS_VISIBLE,
	        100, 100, 250, 150, 0, 0, hInstance, 0);

	while (TRUE)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				break;
			}
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			draw();
		}
	}

	return (int) msg.wParam;
}

void draw()
{
	HDC hdcTotalArtist = GetDC(hwnd);

	RECT rect;
	if (GetWindowRect(hwnd, &rect))
	{
		int width = rect.right - rect.left;
		int height = rect.bottom - rect.top;
		Rectangle(hdcTotalArtist, 0, 0, width, height);
	}

	Rectangle(hdcTotalArtist, xPos - 5, yPos - 5, xPos + 5, yPos + 5);

	ReleaseDC(hwnd, hdcTotalArtist);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
		case WM_KEYDOWN:
			if (wParam == VK_ESCAPE)
			{

				int ret = MessageBoxW(hwnd, L"Are you sure to quit?",
				        L"Message", MB_OKCANCEL);

				if (ret == IDOK)
				{

					SendMessage(hwnd, WM_CLOSE, 0, 0);
				}
			}

			break;

		case WM_CREATE:
			CenterWindow(hwnd);
			RegisterRedPanelClass();
			break;

		case WM_MOUSEMOVE:
			;
			xPos = GET_X_LPARAM(lParam);
			yPos = GET_Y_LPARAM(lParam);
			break;

		case WM_DESTROY:
			PostQuitMessage(0);
			break;
	}

	return DefWindowProcW(hwnd, msg, wParam, lParam);
}

void CenterWindow(HWND hwnd)
{
	RECT rc =
	{ 0 };

	GetWindowRect(hwnd, &rc);
	int win_w = rc.right - rc.left;
	int win_h = rc.bottom - rc.top;

	int screen_w = GetSystemMetrics(SM_CXSCREEN);
	int screen_h = GetSystemMetrics(SM_CYSCREEN);

	SetWindowPos(hwnd, HWND_TOP, (screen_w - win_w) / 2, (screen_h - win_h) / 2,
	        0, 0, SWP_NOSIZE);
}

LRESULT CALLBACK PanelProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{

	switch (msg)
	{
		case WM_LBUTTONUP:

			break;
	}

	return DefWindowProcW(hwnd, msg, wParam, lParam);
}

void RegisterRedPanelClass(void)
{

	HBRUSH hbrush = CreateSolidBrush(RGB(255, 0, 0));

	WNDCLASSW rwc =
	{ 0 };

	rwc.lpszClassName = L"RedPanelClass";
	rwc.hbrBackground = hbrush;
	rwc.lpfnWndProc = PanelProc;
	rwc.hCursor = LoadCursor(0, IDC_ARROW);
	RegisterClassW(&rwc);
}

void RegisterBluePanelClass(void)
{

	HBRUSH hbrush = CreateSolidBrush(RGB(0, 0, 255));

	WNDCLASSW rwc =
	{ 0 };

	rwc.lpszClassName = L"BluePanelClass";
	rwc.hbrBackground = hbrush;
	rwc.lpfnWndProc = PanelProc;
	rwc.hCursor = LoadCursor(0, IDC_ARROW);

	RegisterClassW(&rwc);
}
