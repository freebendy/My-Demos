/*
* Cairo clock. Shows how to use Cairo with Windows.
* Made by Writser Cleveringa, based upon code from Owen Taylor.
*/

#include <cairo-win32.h>
#include <math.h>
#include <time.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


static void drawClock (HDC hdc, long width, long height) {
	/* create a new cairo context to draw on the Device Context from our application. */
	cairo_surface_t * surface = cairo_win32_surface_create (hdc);
	cairo_t * cr = cairo_create (surface);

	/* store the current time */
	time_t rawtime;
	time(&rawtime);
	struct tm * timeinfo;
	/* In newer versions of Visual Studio localtime(..) is deprecated. Use localtime_s instead. See MSDN. */
	timeinfo = localtime(&rawtime);

	/* compute the angles of the indicators of our clock */
	double minutes = timeinfo->tm_min * M_PI / 30;
	double hours = timeinfo->tm_hour * M_PI / 6;
	double seconds= timeinfo->tm_sec * M_PI / 30;

	/* Normalize our context to a (width, height) of (1.0, 1.0) by scaling by our window width and height. */
	cairo_scale (cr, width, height);

	/* draw the entire context white. */
	cairo_set_source_rgba (cr, 1, 1, 1, 1);
	cairo_paint(cr);

	/* who doesn't want all those nice line settings :) */
	cairo_set_line_cap  (cr, CAIRO_LINE_CAP_ROUND);
	cairo_set_line_width(cr, 0.1);

	/* translate to the center of the rendering context and draw a black clock outline */
	cairo_set_source_rgba (cr, 0, 0, 0, 1);
	cairo_translate(cr, 0.5, 0.5);
	cairo_arc(cr, 0, 0, 0.4, 0, M_PI * 2);
	cairo_stroke(cr);

	/* draw a white dot on the current second. */
	cairo_set_source_rgba (cr, 1, 1, 1, 0.6);
	cairo_arc(cr, sin(seconds) * 0.4, -cos(seconds) * 0.4, 0.05, 0, M_PI * 2);
	cairo_fill(cr);

	/* draw the minutes indicator */
	cairo_set_source_rgba (cr, 0.2, 0.2, 1, 0.6);
	cairo_move_to(cr, 0, 0);
	cairo_line_to(cr, sin(minutes) * 0.4, -cos(minutes) * 0.4);
	cairo_stroke (cr);

	/* draw the hours indicator      */
	cairo_move_to(cr, 0, 0);
	cairo_line_to(cr, sin(hours) * 0.2, -cos(hours) * 0.2);
	cairo_stroke (cr);

	/* clean up */
	cairo_destroy (cr);
	cairo_surface_destroy (surface);
}


/* Callback function for our window. See MSDN for more details. */
LRESULT CALLBACK WndProc (HWND window, UINT message, WPARAM wParam, LPARAM lParam) {
	/* Used to repaint parts of our window. */
	PAINTSTRUCT paintStruct;
	/* Bitmap buffer for double buffering! */
	HBITMAP buffer;
	/* Device context for our application, device context for our offscreen buffer. */
	HDC dc, bufferdc;
	/* A rectangle used to store the width and height of the drawable part of our window. */
	RECT clientRect;

	switch(message) {
				case WM_CHAR:
					if ((wParam == 'q') || (wParam == 'Q')) {
						PostQuitMessage (0);
						return 0;
					}
					break;

				case WM_TIMER:
					/* If we receive a timer event, we should redraw the clock.
					* Invalidating the entire window is the easiest way to do so.
					*/
					InvalidateRect(window, NULL, NULL);
					return 0;
					break;

				case WM_ERASEBKGND:
					/* Windows wants to redraw the window background everytime the window is resized.
					* We prevent that to avoid flickering during resizing.
					*/
					return 0;
					break;

				case WM_PAINT:
					/* Get the width and height of our window. We need that to normalize our Cairo context. */
					GetClientRect(window, &clientRect);
					dc = BeginPaint (window, &paintStruct);

					/* Create an offscreen buffer to draw our clock. We could also draw directly
					* to our window dc, and for static scenes that works just fine.
					* However, if you regularly redraw your window that causes significant flickering!
					*/
					bufferdc = CreateCompatibleDC(dc);
					buffer = CreateCompatibleBitmap(dc, clientRect.right, clientRect.bottom);
					/* Select our buffer and draw the clock in it! */
					SelectObject(bufferdc, buffer); 
					drawClock (bufferdc, clientRect.right, clientRect.bottom);
					/* Now we blit the buffer onto our real window: */
					BitBlt(dc, 0, 0, clientRect.right, clientRect.bottom, bufferdc, 0, 0, SRCCOPY); 
					/* Finally we delete our offscreen buffer. In a real application you probably would
					* store this buffer somewhere to use it repeatedly.
					*/
					DeleteDC(bufferdc); 
					DeleteObject(buffer);

					EndPaint (window, &paintStruct);
					return 0;
					break;

				case WM_DESTROY:
					/* The user has closed the window. So we shutdown our timer and quit the program. */
					KillTimer(window, 1); 
					PostQuitMessage (0);
					return 0;
					break;

				default:
					break;
	}

	/* All other events should be handled by the default event handler. */
	return DefWindowProc (window, message, wParam, lParam);
}


/* Application main function. See MSDN for more details about creating windows etc.
* Not much interesting code in here.
*/
INT WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, INT iCmdShow) {
	HWND window;
	MSG message;
	WNDCLASS window_class;
	RECT rect;

	DWORD windowStyle = WS_OVERLAPPEDWINDOW;
	const WCHAR * windowClassName = TEXT("Cairo Clock");

	window_class.style = CS_HREDRAW | CS_VREDRAW;
	window_class.lpfnWndProc = WndProc;
	window_class.cbClsExtra = 0;
	window_class.cbWndExtra = 0;
	window_class.hInstance = hInstance;
	window_class.hIcon = LoadIcon (NULL, IDI_APPLICATION);
	window_class.hCursor = LoadCursor (NULL, IDC_ARROW);
	window_class.hbrBackground = (HBRUSH)GetStockObject (WHITE_BRUSH);
	window_class.lpszMenuName = NULL;
	window_class.lpszClassName = windowClassName;

	RegisterClass (&window_class);

	/* Compute the window size needed for the desired client area. */
	rect.left = 0;
	rect.top = 0;
	rect.right = 400;
	rect.bottom = 400;
	AdjustWindowRect (&rect, windowStyle, FALSE /* no menu */);

	window = CreateWindow (windowClassName, /* Class name */
		TEXT("Cairo clock - Press Q to quit"), /* Window name */
		windowStyle,
		CW_USEDEFAULT, CW_USEDEFAULT, /* initial position */
		rect.right - rect.left, rect.bottom - rect.top, /* initial size */
		NULL,        /* Parent */
		NULL,        /* Menu */
		hInstance,
		NULL); /* WM_CREATE lpParam */

	ShowWindow (window, iCmdShow);
	UpdateWindow (window);

	/* Start a new timer (number 1) that fires WM_TIMER events every 100 milliseconds. */
	SetTimer(window, 1, 100, (TIMERPROC) NULL); 

	/* Main message loop */
	while (GetMessage (&message, NULL, 0, 0)) {
		TranslateMessage (&message);
		DispatchMessage (&message);
	}

	return (int) message.wParam;
}
