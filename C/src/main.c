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
	WNDCLASSW wc = {0};

	wc.lpszClassName = L"Window";
	wc.hInstance = hInstance;
	wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
	wc.lpfnWndProc = WndProc;
	wc.hCursor = LoadCursor(0, IDC_ARROW);

	RegisterClassW(&wc);

	hwnd = CreateWindowW(wc.lpszClassName, L"Window",
	        WS_OVERLAPPEDWINDOW | WS_VISIBLE,
	        100, 100, 250, 150, 0, 0, hInstance, 0);

	return gameLoop();
}

int gameLoop()
{
	MSG msg;

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
			handleKey();

			Sleep(5);
		}
	}

	return 0;
}

void draw()
{
	HDC hdc = GetDC(hwnd);

	RECT rect;

	if (GetWindowRect(hwnd, &rect))
	{
		int width = rect.right - rect.left;
		int height = rect.bottom - rect.top;
		Rectangle(hdc, 0, 0, width, height);
	}
	else
	{
		PostQuitMessage(99);
	}

	Rectangle(hdc, xPos - 5, yPos - 5, xPos + 5, yPos + 5);

	ReleaseDC(hwnd, hdc);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
		case WM_CREATE:
			init(hwnd);
			break;

		case WM_DESTROY:
			PostQuitMessage(0);
			break;
	}

	return DefWindowProcW(hwnd, msg, wParam, lParam);
}

void handleKey()
{
	if(((1 << 15) & GetAsyncKeyState('W')) && yPos > 0)
	{
		yPos -= 1;
	}

	if(((1 << 15) & GetAsyncKeyState('S')) && yPos < screen_h)
	{
		yPos += 1;
	}

	if(((1 << 15) & GetAsyncKeyState('A')) && xPos > 0)
	{
		xPos -= 1;
	}

	if(((1 << 15) & GetAsyncKeyState('D')) && xPos < screen_w)
	{
		xPos += 1;
	}
}

void init(HWND hwnd)
{
	RECT rc;
	GetWindowRect(hwnd, &rc);
	int win_w = rc.right - rc.left;
	int win_h = rc.bottom - rc.top;
	screen_w = GetSystemMetrics(SM_CXSCREEN);
	screen_h = GetSystemMetrics(SM_CYSCREEN);
	SetWindowPos(hwnd, HWND_TOP, (screen_w - win_w) / 2, (screen_h - win_h) / 2,
	        0, 0, SWP_NOSIZE);
}
