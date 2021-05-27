// win_project_second.cpp : Defines the entry point for the application.
//
#define _USE_MATH_DEFINES
#include "framework.h"
#include "win_project_second.h"
#include <WinUser.h>
#include <math.h>
#include <string>
#include <cmath>
#define MAX_LOADSTRING 100
const int R = 200;


// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
LOGBRUSH LogBrush;


// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: Place code here.

	// Initialize global strings
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_WINPROJECTSECOND, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINPROJECTSECOND));

	MSG msg;

	// Main message loop:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINPROJECTSECOND));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WINPROJECTSECOND);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // Store instance handle in our global variable

	HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{


	PAINTSTRUCT ps;
	HDC hdc;
	static int sx, sy;
	int a, b, x, y, x_circle,  y_circle;
	double angle;
	static double t ;

	switch (message)
	{
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;
	case WM_SIZE:

		sx = LOWORD(lParam); 	//Ширина окна
		sy = HIWORD(lParam);	//Высота окна
		break;
	case WM_CREATE:
		SetTimer(hWnd, 1, 125, NULL);
		break;
	case WM_TIMER:

		t+= 0.025;
		if (t >= M_PI * 2) {
			KillTimer(hWnd,1);
		}
		InvalidateRect(hWnd, NULL, TRUE);
		break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;

		LogBrush.lbColor = RGB(30, 40, 170);
		LogBrush.lbStyle = BS_SOLID;
		HPEN hPen = ExtCreatePen(PS_GEOMETRIC | PS_DASH, 2, &LogBrush, 0, NULL);

		HPEN hPsol = CreatePen(PS_SOLID, 1, RGB(150, 100, 90));
		HDC hdc = BeginPaint(hWnd, &ps);
		a = sx / 2;  b = sy / 2;
		x = a;
		y = b;

		SelectObject(hdc, hPen);
		MoveToEx(hdc, 0, b, NULL);
		LineTo(hdc, sx, b);
		LineTo(hdc, sx - 10, b - 20);
		MoveToEx(hdc, sx, b, NULL);
		LineTo(hdc, sx - 10, b + 20);
		MoveToEx(hdc, a, sy, NULL);
		LineTo(hdc, a, 0);
		LineTo(hdc, a - 20, 10);
		MoveToEx(hdc, a, 0, NULL);
		LineTo(hdc, a + 20, 10);
		SelectObject(hdc, hPsol);
		for (int i = 10; i <= a; i += 10) {
			MoveToEx(hdc, a + i, b, NULL);
			LineTo(hdc, a + i, b + 3);
			LineTo(hdc, a + i, b - 6);
		}
		for (int i = 10; i <= a; i += 10) {
			MoveToEx(hdc, a - i, b, NULL);
			LineTo(hdc, a - i, b + 3);
			LineTo(hdc, a - i, b - 6);
		}
		for (int i = 10; i <= b; i += 10) {
			MoveToEx(hdc, a, b + i, NULL);
			LineTo(hdc, a + 4, b + i);
			LineTo(hdc, a - 6, b + i);
		}
		for (int i = 10; i <= b; i += 10) {
			MoveToEx(hdc, a, b - i, NULL);
			LineTo(hdc, a + 4, b - i);
			LineTo(hdc, a - 6, b - i);
		}
		DeleteObject(hPen);
		DeleteObject(hPsol);


		MoveToEx(hdc, a, b, NULL);/////rosa making

		for (angle= 0.025; angle <=  t; angle += 0.025)
		{
			x = a + R*sin(5 * angle) * cos(angle);
			y = b + R*sin(5* angle) * sin(angle);
			LineTo(hdc, x, y);
			MoveToEx(hdc, x, y, NULL);

	}
		x_circle = a + R * sin(5* t) * cos(t);
		y_circle = b + R * sin(5 * t) * sin(t);
		SelectObject(hdc, GetStockObject(DC_BRUSH));
		SetDCBrushColor(hdc, RGB(255, 125, 156));
		Ellipse(hdc, x_circle - 10, y_circle - 10, x_circle + 10, y_circle + 10);
		auto text = std::to_string(x_circle) + ", " + std::to_string(y_circle);
		auto rect = RECT{ 0, 0, 500, 500 };
		std::wstring stemp = std::wstring(text.begin(), text.end());
		LPCWSTR sw = stemp.c_str();
		SetTextColor(hdc, RGB(0, 255, 100));
		DrawText(hdc, sw, -1, &rect, DT_BOTTOM);
		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		
		KillTimer(hWnd, 1);
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
