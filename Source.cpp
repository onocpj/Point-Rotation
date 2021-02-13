#include <math.h>
#include <thread>
#include <windows.h>
#include <iostream>

typedef struct {

	float x;
	float y;

} Point;

Point Rotate(Point& p1, float angle, Point& p2) {

	float s = sin(angle);
	float c = cos(angle);

	p2.x -= p1.x;
	p2.y -= p1.y;

	float xnew = p2.x * c - p2.y * s;
	float ynew = p2.x * s + p2.y * c;

	p2.x = xnew + p1.x;
	p2.y = ynew + p1.y;

	return p2;

}

int main(void) {
	HWND console = GetConsoleWindow();
	HDC hdc = GetDC(console);

	Point p1 = { 150.0f, 150.0f };
	Point p2 = { 200.0f, 150.0f };
	Point p3 = { 200.0f, 150.0f };

	while (true) {

		system("CLS");

		SetPixel(hdc, p1.x, p1.y, RGB(255, 255, 255));
		SetPixel(hdc, p2.x, p2.y, RGB(255, 255, 255));
		SetPixel(hdc, p3.x, p3.y, RGB(255, 255, 255));

		Rotate(p1, 0.1f, p2);
		Rotate(p2, 0.1f, p1);
		Rotate(p3, 0.1f, p1);
		Rotate(p3, 0.1f, p2);

		if ((rand() % 6) >= 3) {
			p3.x += (float)(rand() % 6);
			p3.y += (float)(rand() % 6);
		} else {
			p3.x -= (float)(rand() % 6);
			p3.y -= (float)(rand() % 6);
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(0));

	}

	return 0;

}
