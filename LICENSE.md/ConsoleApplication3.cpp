// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <windows.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <iostream>
int main(void)
{

	float num[10];
	printf("MoveDown: "); scanf("%f", &num[1]);
	printf("Delay: "); scanf("%f", &num[2]);
	bool test1 = false;
	bool click = false;

	while (true)
	{

		/*	POINT mouse,test;
			GetCursorPos(&mouse);
			system("CLS");
			std::cout << "mouse->x = " << mouse.x << "\nmouse->y = " << mouse.y << std::endl;*/

		if (GetAsyncKeyState(VK_END) & 1)
		{
			test1 = !test1;
		}
		if (GetAsyncKeyState(VK_HOME) & 1)
		{
			click = !click;
		}

		if (test1 == true)
			std::cout << "Mouse ON" << std::endl;
		else
			std::cout << "Mouse OFF Key END" << std::endl;

		if (click == true)
			std::cout << "click ON" << std::endl;
		else
			std::cout << "click OFF Key HOME" << std::endl;

		if (click)
		{
			if (GetAsyncKeyState(VK_LBUTTON))
			{
				mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
				mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
			}
		}
		if (test1)
		{
			if (GetAsyncKeyState(VK_LBUTTON))
			{
				Sleep(num[2]);
				mouse_event(MOUSEEVENTF_MOVE, 0, num[1], 0, 0);
			}
		}
	}
	return 0;
}