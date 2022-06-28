// draw.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "draw2.h"
#include <vector>
#include <cstdio>

#define MAX_LOADSTRING 100
#define TMR_1 1

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

INT value;

// buttons
HWND hwndButton;

// sent data
std::vector<Point> data;
RECT drawArea1 = { 0, 0, 150, 200 };
RECT drawArea2 = { 50, 400, 650, 422};
int l1 = 150;
int l2 = 120;
double angle1 = - 75 * (atan(1) * 4) / 180;
double angle2 = - 60 * (atan(1) * 4) / 180;
int x = 0;
int y = 0;
double p = 10;
int pick = 0;
int shape = 0;
int drop[6] = { 0, 0, 0, 0, 0, 0 };
int i = 0;


// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	Buttons(HWND, UINT, WPARAM, LPARAM);


void MyOnPaint(HDC hdc)
{
	Graphics graphics(hdc);
	Pen pen(Color(255, 0, 0, 255));
	Pen pen1(Color(255, 255 - drop[0], 255 - drop[0], 255));
	Pen pen2(Color(255, 255 - drop[1], 255 - drop[1], 255));
	Pen pen3(Color(255, 255 - drop[2], 255 - drop[2], 255));
	Pen pen4(Color(255, 255 - drop[3], 255 - drop[3], 255));
	Pen pen5(Color(255, 255 - drop[4], 255 - drop[4], 255));
	Pen pen6(Color(255, 255 - drop[5], 255 - drop[5], 255));


	PointF trianglePoints[3];
	trianglePoints[0] = PointF(20.0F, 230.0F);
	trianglePoints[1] = PointF(70.0F, 230.0F);
	trianglePoints[2] = PointF(45.0F, 180.0F);

	graphics.DrawLine(&pen, 150, 300, 250, 300);
	int c1 = 200 + cos(angle1) * l1;
	int d1 = 300 + sin(angle1) * l1;
	graphics.DrawLine(&pen, 200, 300, c1, d1);
	x = c1 + cos(angle2) * l2;
	y = d1 + sin(angle2) * l2;
	graphics.DrawLine(&pen, c1, d1, x, y);

	graphics.DrawRectangle(&pen, 20, 60, 50, 50);
	graphics.DrawEllipse(&pen, 20, 120, 50, 50);
	graphics.DrawPolygon(&pen, trianglePoints, 3);
	graphics.DrawRectangle(&pen, 10, 240, 70, 50);

	if (pick == 1)
		graphics.DrawRectangle(&pen, x - 15, y - 15, 30, 30);
	else if (pick == 10)
		graphics.DrawEllipse(&pen, x - 15, y - 15, 30, 30);
	else if (pick == 100)
	{
		PointF triangleMoving[3];
		triangleMoving[0] = PointF(x - 15, y + 10);
		triangleMoving[1] = PointF(x + 15, y + 10);
		triangleMoving[2] = PointF(x, y - 20);

		graphics.DrawPolygon(&pen, triangleMoving, 3);
	}
	else if (pick == 1000 )
		graphics.DrawRectangle(&pen, x - 20, y - 15, 40, 30);

	

	graphics.DrawLine(&pen, 340, 300, 390, 300);

	if (shape == 1)
	{
		graphics.DrawRectangle(&pen6, 350, 70, 30, 30);
		graphics.DrawRectangle(&pen5, 350, 110, 30, 30);
		graphics.DrawRectangle(&pen4, 350, 150, 30, 30);
		graphics.DrawRectangle(&pen3, 350, 190, 30, 30);
		graphics.DrawRectangle(&pen2, 350, 230, 30, 30);
		graphics.DrawRectangle(&pen1, 350, 270, 30, 30);
	}
	else if (shape == 10)
	{
		graphics.DrawEllipse(&pen6, 350, 70, 30, 30);
		graphics.DrawEllipse(&pen5, 350, 110, 30, 30);
		graphics.DrawEllipse(&pen4, 350, 150, 30, 30);
		graphics.DrawEllipse(&pen3, 350, 190, 30, 30);
		graphics.DrawEllipse(&pen2, 350, 230, 30, 30);
		graphics.DrawEllipse(&pen1, 350, 270, 30, 30);
	}
	else if (shape == 1000)
	{
		graphics.DrawRectangle(&pen6, 345, 70, 40, 30);
		graphics.DrawRectangle(&pen5, 345, 110, 40, 30);
		graphics.DrawRectangle(&pen4, 345, 150, 40, 30);
		graphics.DrawRectangle(&pen3, 345, 190, 40, 30);
		graphics.DrawRectangle(&pen2, 345, 230, 40, 30);
		graphics.DrawRectangle(&pen1, 345, 270, 40, 30);
	}
	else if (shape == 100)
	{
		PointF triangleTower[6][3];
		triangleTower[0][0] = PointF(350, 300);
		triangleTower[0][1] = PointF(380, 300);
		triangleTower[0][2] = PointF(365, 270);
		triangleTower[1][0] = PointF(350, 260);
		triangleTower[1][1] = PointF(380, 260);
		triangleTower[1][2] = PointF(365, 230);
		triangleTower[2][0] = PointF(350, 220);
		triangleTower[2][1] = PointF(380, 220);
		triangleTower[2][2] = PointF(365, 190);
		triangleTower[3][0] = PointF(350, 180);
		triangleTower[3][1] = PointF(380, 180);
		triangleTower[3][2] = PointF(365, 150);
		triangleTower[4][0] = PointF(350, 140);
		triangleTower[4][1] = PointF(380, 140);
		triangleTower[4][2] = PointF(365, 110);
		triangleTower[5][0] = PointF(350, 100);
		triangleTower[5][1] = PointF(380, 100);
		triangleTower[5][2] = PointF(365, 70);

		graphics.DrawPolygon(&pen6, triangleTower[5], 3);
		graphics.DrawPolygon(&pen5, triangleTower[4], 3);
		graphics.DrawPolygon(&pen4, triangleTower[3], 3);
		graphics.DrawPolygon(&pen3, triangleTower[2], 3);
		graphics.DrawPolygon(&pen2, triangleTower[1], 3);
		graphics.DrawPolygon(&pen1, triangleTower[0], 3);
	}


}

void repaintWindow(HWND hWnd, HDC &hdc, PAINTSTRUCT &ps, RECT *drawArea)
{
	if (drawArea==NULL)
		InvalidateRect(hWnd, NULL, TRUE); // repaint all
	else
		InvalidateRect(hWnd, drawArea, TRUE); //repaint drawArea
	hdc = BeginPaint(hWnd, &ps);
	MyOnPaint(hdc);
	EndPaint(hWnd, &ps);
}

void inputData()
{	
	
}


int OnCreate(HWND window)
{
	inputData();
	return 0;
}


// main function (exe hInstance)
int APIENTRY _tWinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR    lpCmdLine,
	int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	MSG msg;
	HACCEL hAccelTable;

	value = 0;

	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR           gdiplusToken;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_DRAW, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);



	// Perform application initialization:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_DRAW));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	GdiplusShutdown(gdiplusToken);

	return (int)msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage are only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. It is important to call this function
//    so that the application will get 'well formed' small icons associated
//    with it.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_DRAW));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCE(IDC_DRAW);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
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
	HWND hWnd;


	hInst = hInstance; // Store instance handle (of exe) in our global variable

	// main window
	hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

	// create button and store the handle                                                       
	
		hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("Draw"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		0, 0,                                  // the left and top co-ordinates
		80, 50,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON1,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);                               // extra bits you dont really need

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("Angle1 -"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		700, 0,                                  // the left and top co-ordinates
		80, 50,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTONA1,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);                               // extra bits you dont really need

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("Angle1 +"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		790, 0,                                  // the left and top co-ordinates
		80, 50,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTONA2,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);                               // extra bits you dont really need

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("Angle2 -"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		700, 60,                                  // the left and top co-ordinates
		80, 50,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTONA3,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);                               // extra bits you dont really need

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("Angle2 +"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		790, 60,                                  // the left and top co-ordinates
		80, 50,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTONA4,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);                               // extra bits you dont really need

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("Speed +"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		700, 120,                                  // the left and top co-ordinates
		80, 50,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTONS1,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);                               // extra bits you dont really need

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("Speed -"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		790, 120,                                  // the left and top co-ordinates
		80, 50,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTONS2,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);                               // extra bits you dont really need

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("Pick"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		700, 180,                                  // the left and top co-ordinates
		80, 50,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTONP,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);                               // extra bits you dont really need

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("Drop"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		790, 180,                                  // the left and top co-ordinates
		80, 50,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTOND,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);                               // extra bits you dont really need

	OnCreate(hWnd);

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
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window (low priority)
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);

		// MENU & BUTTON messages
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		case ID_BUTTON1 :
			repaintWindow(hWnd, hdc, ps, NULL);
			break;
		case ID_BUTTONA1:
		{
			angle1 += p * (atan(1) * 4) / 180;
			repaintWindow(hWnd, hdc, ps, NULL);
			break;
		}
		case ID_BUTTONA2:
		{
			angle1 -= p * (atan(1) * 4) / 180;
			repaintWindow(hWnd, hdc, ps, NULL);
			break;
		}
		case ID_BUTTONA3:
		{
			angle2 += p * (atan(1) * 4) / 180;
			repaintWindow(hWnd, hdc, ps, NULL);
			break;
		}
		case ID_BUTTONA4:
		{
			angle2 -= p * (atan(1) * 4) / 180;
			repaintWindow(hWnd, hdc, ps, NULL);
			break;
		}
		case ID_BUTTONS1:
		{
			p += 1;
			break;
		}
		case ID_BUTTONS2:
		{
			if (p != 1)
				p -= 1;
			break;
		}
		case ID_BUTTONP:
		{

			if ((x >= 0 && x <= 60) && (y >= 60 && y <= 110))
			{
				pick = 1;
				shape = 1;
			}
			else if ((x >= 0 && x <= 60) && (y >= 120 && y <= 170))
			{
				pick = 10;
				shape = 10;
			}
			else if ((x >= 0 && x <= 60) && (y >= 180 && y <= 230))
			{
				pick = 100;
				shape = 100;
			}
			else if ((x >= 0 && x <= 60) && (y >= 240 && y <= 290))
			{
				pick = 1000;
				shape = 1000;
			}
			break;
		}
		case ID_BUTTOND:
		{
			drop[i] = 255;
			i++;
			if (i == 6)
				i = 0;
			pick = 0;
			break;
		}
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code here (not depend on timer, buttons)
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_TIMER:
		switch (wParam)
		{
		case TMR_1:
			//force window to repaint
			repaintWindow(hWnd, hdc, ps, &drawArea2);
			value++;
			break;
		}

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

