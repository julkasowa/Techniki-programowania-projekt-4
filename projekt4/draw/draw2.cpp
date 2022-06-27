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
int col = 0;
std::vector<Point> data;
RECT drawArea1 = { 0, 0, 150, 200 };
RECT drawArea2 = { 50, 400, 650, 422};
int l1 = 150;
int l2 = 120;
double angle1 = - 75 * (atan(1) * 4) / 180;
double angle2 = - 60 * (atan(1) * 4) / 180;
int x = 0;
int y = 0;
int wSquare = 30;
int wCircle = 20;
int wTriangle = 40;
int wRectangle = 50;
int maxweight = 70;
int minweight = 20;
int hSquare = 50;
int hCircle = 30;
int hTriangle = 70;
int hRectangle = 20;
double p = 10;
int task = 0;
int stage = 0;
int pick = 0;
int drop = 0;


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
	Pen pen2(Color(255, 25*col, 0, 255));

	PointF trianglePoints[3];
	trianglePoints[0] = PointF(240.0F, 230.0F);
	trianglePoints[1] = PointF(290.0F, 230.0F);
	trianglePoints[2] = PointF(265.0F, 180.0F);

	graphics.DrawLine(&pen, 375, 300, 475, 300);
	int c1 = 425 + cos(angle1) * l1;
	int d1 = 300 + sin(angle1) * l1;
	graphics.DrawLine(&pen, 425, 300, c1, d1);
	x = c1 + cos(angle2) * l2;
	y = d1 + sin(angle2) * l2;
	graphics.DrawLine(&pen, c1, d1, x, y);

	graphics.DrawRectangle(&pen, 240, 60, 50, 50);
	graphics.DrawEllipse(&pen, 240, 120, 50, 50);
	graphics.DrawPolygon(&pen, trianglePoints, 3);
	graphics.DrawRectangle(&pen, 230, 240, 70, 50);

	if (pick == 1 || pick == 2 || pick == 3)
		graphics.DrawRectangle(&pen, x - 15, y - 15, 30, 30);
	else if (pick == 10 || pick == 20 || pick == 30 || pick == 40 || pick == 50)
		graphics.DrawEllipse(&pen, x - 15, y - 15, 30, 30);
	else if (pick == 100 || pick == 200)
	{
		PointF triangleMoving[3];
		triangleMoving[0] = PointF(x - 15, y + 10);
		triangleMoving[1] = PointF(x + 15, y + 10);
		triangleMoving[2] = PointF(x, y - 20);

		graphics.DrawPolygon(&pen, triangleMoving, 3);
	}
	else if (pick == 1000 || pick == 2000)
		graphics.DrawRectangle(&pen, x - 20, y - 15, 40, 30);
	else if (pick == 11 || pick == 12 || pick == 21)
	{
		graphics.DrawRectangle(&pen, x - 15, y - 15, 30, 30);
		graphics.DrawEllipse(&pen, x - 15, y - 15, 30, 30);
	}
	else if (pick == 101 || pick == 102)
	{
		PointF triangleMoving[3];
		triangleMoving[0] = PointF(x - 15, y + 10);
		triangleMoving[1] = PointF(x + 15, y + 10);
		triangleMoving[2] = PointF(x, y - 20);

		graphics.DrawPolygon(&pen, triangleMoving, 3);
		graphics.DrawRectangle(&pen, x - 15, y - 15, 30, 30);
	}
	else if (pick == 1001)
	{
		graphics.DrawRectangle(&pen, x - 15, y - 15, 30, 30);
		graphics.DrawRectangle(&pen, x - 20, y - 15, 40, 30);
	}
	else if (pick == 110 || pick == 120 || pick == 210)
	{
		PointF triangleMoving[3];
		triangleMoving[0] = PointF(x - 15, y + 10);
		triangleMoving[1] = PointF(x + 15, y + 10);
		triangleMoving[2] = PointF(x, y - 20);

		graphics.DrawPolygon(&pen, triangleMoving, 3);
		graphics.DrawEllipse(&pen, x - 15, y - 15, 30, 30);
	}
	else if (pick == 1010 || pick == 1020)
	{
		graphics.DrawEllipse(&pen, x - 15, y - 15, 30, 30);
		graphics.DrawRectangle(&pen, x - 20, y - 15, 40, 30);
	}
	else if (pick == 1100)
	{
		PointF triangleMoving[3];
		triangleMoving[0] = PointF(x - 15, y + 10);
		triangleMoving[1] = PointF(x + 15, y + 10);
		triangleMoving[2] = PointF(x, y - 20);

		graphics.DrawPolygon(&pen, triangleMoving, 3);
		graphics.DrawRectangle(&pen, x - 20, y - 15, 40, 30);
	}
	else if (pick == 111)
	{
		PointF triangleMoving[3];
		triangleMoving[0] = PointF(x - 15, y + 10);
		triangleMoving[1] = PointF(x + 15, y + 10);
		triangleMoving[2] = PointF(x, y - 20);

		graphics.DrawPolygon(&pen, triangleMoving, 3);
		graphics.DrawEllipse(&pen, x - 15, y - 15, 30, 30);
		graphics.DrawRectangle(&pen, x - 15, y - 15, 30, 30);
	}
	else if (pick == 1011)
	{
		graphics.DrawEllipse(&pen, x - 15, y - 15, 30, 30);
		graphics.DrawRectangle(&pen, x - 15, y - 15, 30, 30);
		graphics.DrawRectangle(&pen, x - 20, y - 15, 40, 30);
	}

	if (task == 1)
	{
		if (stage == 1)
			graphics.DrawRectangle(&pen, x - 15, y - 15, 30, 30);
		else if (stage == 2)
			graphics.DrawRectangle(&pen, 560, 240, 30, 30);
		else if (stage == 3)
		{
			graphics.DrawRectangle(&pen, x - 15, y - 15, 30, 30);
			graphics.DrawRectangle(&pen, 560, 240, 30, 30);
		}
		else if (stage == 4)
		{
			graphics.DrawRectangle(&pen, 560, 205, 30, 30);
			graphics.DrawRectangle(&pen, 560, 240, 30, 30);
		}
		else if (stage == 5)
		{
			graphics.DrawRectangle(&pen, x - 15, y - 15, 30, 30);
			graphics.DrawRectangle(&pen, 560, 205, 30, 30);
			graphics.DrawRectangle(&pen, 560, 240, 30, 30);
		}
		else if (stage == 6)
		{
			graphics.DrawRectangle(&pen, 560, 170, 30, 30);
			graphics.DrawRectangle(&pen, 560, 205, 30, 30);
			graphics.DrawRectangle(&pen, 560, 240, 30, 30);
		}
		else if (stage == 7)
		{
			graphics.DrawRectangle(&pen, x - 15, y - 15, 30, 30);
			graphics.DrawRectangle(&pen, 560, 170, 30, 30);
			graphics.DrawRectangle(&pen, 560, 205, 30, 30);
			graphics.DrawRectangle(&pen, 560, 240, 30, 30);
		}
		else if (stage == 8)
		{
			graphics.DrawRectangle(&pen, 560, 135, 30, 30);
			graphics.DrawRectangle(&pen, 560, 170, 30, 30);
			graphics.DrawRectangle(&pen, 560, 205, 30, 30);
			graphics.DrawRectangle(&pen, 560, 240, 30, 30);
		}
		else if (stage == 9)
		{
			graphics.DrawRectangle(&pen, x - 15, y - 15, 30, 30);
			graphics.DrawRectangle(&pen, 560, 135, 30, 30);
			graphics.DrawRectangle(&pen, 560, 170, 30, 30);
			graphics.DrawRectangle(&pen, 560, 205, 30, 30);
			graphics.DrawRectangle(&pen, 560, 240, 30, 30);
		}
		else if (stage == 10)
		{
			graphics.DrawRectangle(&pen, 560, 100, 30, 30);
			graphics.DrawRectangle(&pen, 560, 135, 30, 30);
			graphics.DrawRectangle(&pen, 560, 170, 30, 30);
			graphics.DrawRectangle(&pen, 560, 205, 30, 30);
			graphics.DrawRectangle(&pen, 560, 240, 30, 30);
		}
		else if (stage == 11)
		{
			graphics.DrawRectangle(&pen, x - 15, y - 15, 30, 30);
			graphics.DrawRectangle(&pen, 560, 100, 30, 30);
			graphics.DrawRectangle(&pen, 560, 135, 30, 30);
			graphics.DrawRectangle(&pen, 560, 170, 30, 30);
			graphics.DrawRectangle(&pen, 560, 205, 30, 30);
			graphics.DrawRectangle(&pen, 560, 240, 30, 30);
		}
		else if (stage == 12)
		{
			graphics.DrawRectangle(&pen, 560, 65, 30, 30);
			graphics.DrawRectangle(&pen, 560, 100, 30, 30);
			graphics.DrawRectangle(&pen, 560, 135, 30, 30);
			graphics.DrawRectangle(&pen, 560, 170, 30, 30);
			graphics.DrawRectangle(&pen, 560, 205, 30, 30);
			graphics.DrawRectangle(&pen, 560, 240, 30, 30);
		}

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
	
	hwndButton = CreateWindow(TEXT("button"),                     // The class name required is button
		TEXT("Tower S"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		0, 60,                                  // the left and top co-ordinates
		80, 50,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON2,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);                               // extra bits you dont really need

	hwndButton = CreateWindow(TEXT("button"),                     // The class name required is button
		TEXT("Tower C"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		0, 120,                                  // the left and top co-ordinates
		80, 50,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON3,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);                               // extra bits you dont really need
	
	hwndButton = CreateWindow(TEXT("button"),                     // The class name required is button
		TEXT("Tower T"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		0, 180,                                  // the left and top co-ordinates
		80, 50,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON4,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);                               // extra bits you dont really need

	hwndButton = CreateWindow(TEXT("button"),                     // The class name required is button
		TEXT("Tower R"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		0, 240,                                  // the left and top co-ordinates
		80, 50,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON5,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);                               // extra bits you dont really need

	hwndButton = CreateWindow(TEXT("button"),                     // The class name required is button
		TEXT("30"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		90, 60,                                  // the left and top co-ordinates
		60, 50,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON6,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);                               // extra bits you dont really need

	hwndButton = CreateWindow(TEXT("button"),                     // The class name required is button
		TEXT("20"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		90, 120,                                  // the left and top co-ordinates
		60, 50,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON7,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);                               // extra bits you dont really need

	hwndButton = CreateWindow(TEXT("button"),                     // The class name required is button
		TEXT("40"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		90, 180,                                  // the left and top co-ordinates
		60, 50,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON8,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);                               // extra bits you dont really need

	hwndButton = CreateWindow(TEXT("button"),                     // The class name required is button
		TEXT("50"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		90, 240,                                  // the left and top co-ordinates
		60, 50,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON9,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);                               // extra bits you dont really need

	hwndButton = CreateWindow(TEXT("button"),                     // The class name required is button
		TEXT("50"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		160, 60,                                  // the left and top co-ordinates
		60, 50,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON18,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);                               // extra bits you dont really need

	hwndButton = CreateWindow(TEXT("button"),                     // The class name required is button
		TEXT("30"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		160, 120,                                  // the left and top co-ordinates
		60, 50,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON19,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);                               // extra bits you dont really need

	hwndButton = CreateWindow(TEXT("button"),                     // The class name required is button
		TEXT("70"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		160, 180,                                  // the left and top co-ordinates
		60, 50,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON20,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);                               // extra bits you dont really need

	hwndButton = CreateWindow(TEXT("button"),                     // The class name required is button
		TEXT("20"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		160, 240,                                  // the left and top co-ordinates
		60, 50,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON21,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("Weight:"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		90, 0,                                  // the left and top co-ordinates
		60, 50,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON10,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);                               // extra bits you dont really need

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("Height:"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		160, 0,                                  // the left and top co-ordinates
		60, 50,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON17,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);                               // extra bits you dont really need
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
		TEXT("Angle1 +"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		700, 0,                                  // the left and top co-ordinates
		80, 50,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON11,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);                               // extra bits you dont really need

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("Angle1 -"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		790, 0,                                  // the left and top co-ordinates
		80, 50,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON12,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);                               // extra bits you dont really need

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("Angle2 +"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		700, 60,                                  // the left and top co-ordinates
		80, 50,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON13,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);                               // extra bits you dont really need

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("Angle2 -"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		790, 60,                                  // the left and top co-ordinates
		80, 50,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON14,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);                               // extra bits you dont really need

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("Speed +"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		700, 120,                                  // the left and top co-ordinates
		80, 50,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON15,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);                               // extra bits you dont really need

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("Speed -"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		790, 120,                                  // the left and top co-ordinates
		80, 50,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON16,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);                               // extra bits you dont really need

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("Pick"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		700, 180,                                  // the left and top co-ordinates
		80, 50,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON22,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);                               // extra bits you dont really need

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("Drop"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		790, 180,                                  // the left and top co-ordinates
		80, 50,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON23,                   // the ID of your button
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
		case ID_BUTTON2:
		{
			task = 1;
			double a1 = - 120 * (atan(1) * 4) / 180;
			double a2 = - 134 * (atan(1) * 4) / 180;

			while (angle1 != a1 || angle2 != a2)
			{
				if (angle1 > a1)
					angle1 -= (atan(1) * 4) / 180;
				else
					angle1 += (atan(1) * 4) / 180;
				
				if (angle2 > a2)
					angle2 -= (atan(1) * 4) / 180;
				else
					angle2 += (atan(1) * 4) / 180;
				
				repaintWindow(hWnd, hdc, ps, NULL);
			}; 

			stage = 1;
			double a3 = -63 * (atan(1) * 4) / 180;
			double a4 = -133 * (atan(1) * 4) / 180;
			while (angle1 != a3 || angle2 != a4)
			{
				if (angle1 > a3)
					angle1 -= (atan(1) * 4) / 180;
				else
					angle1 += (atan(1) * 4) / 180;

				if (angle2 > a4)
					angle2 -= (atan(1) * 4) / 180;
				else
					angle2 += (atan(1) * 4) / 180;

				repaintWindow(hWnd, hdc, ps, NULL);
			};

			stage = 2; 
			while (angle1 != a1 || angle2 != a2)
			{
				if (angle1 > a1)
					angle1 -= (atan(1) * 4) / 180;
				else
					angle1 += (atan(1) * 4) / 180;

				if (angle2 > a2)
					angle2 -= (atan(1) * 4) / 180;
				else
					angle2 += (atan(1) * 4) / 180;

				repaintWindow(hWnd, hdc, ps, NULL);
			};

			stage = 3;
			a3 = -72 * (atan(1) * 4) / 180;
			a4 = -149 * (atan(1) * 4) / 180;
			while (angle1 != a3 || angle2 != a4)
			{
				if (angle1 > a3)
					angle1 -= (atan(1) * 4) / 180;
				else
					angle1 += (atan(1) * 4) / 180;

				if (angle2 > a4)
					angle2 -= (atan(1) * 4) / 180;
				else
					angle2 += (atan(1) * 4) / 180;
				
				repaintWindow(hWnd, hdc, ps, NULL);
			};

			stage = 4;
			while (angle1 != a1 || angle2 != a2)
			{
				if (angle1 > a1)
					angle1 -= (atan(1) * 4) / 180;
				else
					angle1 += (atan(1) * 4) / 180;

				if (angle2 > a2)
					angle2 -= (atan(1) * 4) / 180;
				else
					angle2 += (atan(1) * 4) / 180;

				repaintWindow(hWnd, hdc, ps, NULL);
			};

			stage = 5; 
			a3 = -77 * (atan(1) * 4) / 180;
			a4 = -165 * (atan(1) * 4) / 180;
			while (angle1 != a3 || angle2 != a4)
			{
				if (angle1 > a3)
					angle1 -= (atan(1) * 4) / 180;
				else
					angle1 += (atan(1) * 4) / 180;

				if (angle2 > a4)
					angle2 -= (atan(1) * 4) / 180;
				else
					angle2 += (atan(1) * 4) / 180;
				
				repaintWindow(hWnd, hdc, ps, NULL);
			};

			stage = 6; 
			while (angle1 != a1 || angle2 != a2)
			{
				if (angle1 > a1)
					angle1 -= (atan(1) * 4) / 180;
				else
					angle1 += (atan(1) * 4) / 180;

				if (angle2 > a2)
					angle2 -= (atan(1) * 4) / 180;
				else
					angle2 += (atan(1) * 4) / 180;

				repaintWindow(hWnd, hdc, ps, NULL);
			};

			stage = 7; 
			a3 = -78 * (atan(1) * 4) / 180;
			a4 = -181 * (atan(1) * 4) / 180;
			while (angle1 != a3 || angle2 != a4)
			{
				if (angle1 > a3)
					angle1 -= (atan(1) * 4) / 180;
				else
					angle1 += (atan(1) * 4) / 180;

				if (angle2 > a4)
					angle2 -= (atan(1) * 4) / 180;
				else
					angle2 += (atan(1) * 4) / 180;

				repaintWindow(hWnd, hdc, ps, NULL);
			};

			stage = 8;
			while (angle1 != a1 || angle2 != a2)
			{
				if (angle1 > a1)
					angle1 -= (atan(1) * 4) / 180;
				else
					angle1 += (atan(1) * 4) / 180;

				if (angle2 > a2)
					angle2 -= (atan(1) * 4) / 180;
				else
					angle2 += (atan(1) * 4) / 180;

				repaintWindow(hWnd, hdc, ps, NULL);
			};

			stage = 9; 
			a3 = -76 * (atan(1) * 4) / 180;
			a4 = -199 * (atan(1) * 4) / 180;
			while (angle1 != a3 || angle2 != a4)
			{
				if (angle1 > a3)
					angle1 -= (atan(1) * 4) / 180;
				else
					angle1 += (atan(1) * 4) / 180;

				if (angle2 > a4)
					angle2 -= (atan(1) * 4) / 180;
				else
					angle2 += (atan(1) * 4) / 180;

				repaintWindow(hWnd, hdc, ps, NULL);
			};

			stage = 10;
			while (angle1 != a1 || angle2 != a2)
			{
				if (angle1 > a1)
					angle1 -= (atan(1) * 4) / 180;
				else
					angle1 += (atan(1) * 4) / 180;

				if (angle2 > a2)
					angle2 -= (atan(1) * 4) / 180;
				else
					angle2 += (atan(1) * 4) / 180;

				repaintWindow(hWnd, hdc, ps, NULL);
			};

			stage = 11; 
			a3 = -64 * (atan(1) * 4) / 180;
			a4 = -225 * (atan(1) * 4) / 180;
			while (angle1 != a3 || angle2 != a4)
			{
				if (angle1 > a3)
					angle1 -= (atan(1) * 4) / 180;
				else
					angle1 += (atan(1) * 4) / 180;

				if (angle2 > a4)
					angle2 -= (atan(1) * 4) / 180;
				else
					angle2 += (atan(1) * 4) / 180;

				repaintWindow(hWnd, hdc, ps, NULL);
			};

			stage = 12;

			break; 
		}
		case ID_BUTTON3:
		{
			double a1 = -106 * (atan(1) * 4) / 180;
			double a2 = -174 * (atan(1) * 4) / 180;

			break;
		}
		case ID_BUTTON4:
		{
			double a1 = -110 * (atan(1) * 4) / 180;
			double a2 = -205 * (atan(1) * 4) / 180;

			break;
		}
		case ID_BUTTON5:
		{
			double a1 = -123 * (atan(1) * 4) / 180;
			double a2 = -229 * (atan(1) * 4) / 180;

			break;
		}
		case ID_BUTTON11:
		{
			angle1 += p * (atan(1) * 4) / 180;
			repaintWindow(hWnd, hdc, ps, NULL);
			break;
		}
		case ID_BUTTON12:
		{
			angle1 -= p * (atan(1) * 4) / 180;
			repaintWindow(hWnd, hdc, ps, NULL);
			break;
		}
		case ID_BUTTON13:
		{
			angle2 += p * (atan(1) * 4) / 180;
			repaintWindow(hWnd, hdc, ps, NULL);
			break;
		}
		case ID_BUTTON14:
		{
			angle2 -= p * (atan(1) * 4) / 180;
			repaintWindow(hWnd, hdc, ps, NULL);
			break;
		}
		case ID_BUTTON15:
		{
			p += 1;
			break;
		}
		case ID_BUTTON16:
		{
			if (p != 1)
				p -= 1;
			break;
		}
		case ID_BUTTON22:
		{
			int weight = 0;

			if ((x >= 240 && x <= 290) && (y >= 60 && y <= 110))
			{
				weight += wSquare;
				if (weight <= 100)
					pick += 1;
				else
				{
					weight -= wSquare;
				}
			}
			else if ((x >= 240 && x <= 290) && (y >= 120 && y <= 170))
			{
				weight += wCircle;
				if (weight <= 100)
					pick += 10;
				else
				{
					weight -= wCircle;

				}
			}
			else if ((x >= 240 && x <= 290) && (y >= 180 && y <= 230))
			{
				weight += wTriangle;
				if (weight <= 100)
					pick += 100;
				else
				{
					weight -= wTriangle;

				}
			}
			else if ((x >= 230 && x <= 300) && (y >= 240 && y <= 290))
			{
				weight += wRectangle;
				if (weight <= 100)
					pick += 1000;
				else
				{
					weight -= wRectangle;

				}
			}

			break;
		}
		case ID_BUTTON23:
		{


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

