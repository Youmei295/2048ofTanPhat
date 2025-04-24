#pragma once
#include <iostream>
#include <cstdio>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <fstream>
#include <string>
#include <mmsystem.h>


// Clear man hinh
void xoamh()
{
	CONSOLE_SCREEN_BUFFER_INFO	luubuffer;
	HANDLE	hOut;
	COORD	goc = {0,0};
	DWORD	rac;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hOut, &luubuffer);

	FillConsoleOutputCharacter(hOut, ' ', luubuffer.dwSize.X * luubuffer.dwSize.Y, goc, &rac);
	luubuffer.dwCursorPosition.X = 0;
	luubuffer.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hOut, luubuffer.dwCursorPosition);
}


// di chuyen con tro den vi tri nhat dinh;
void denXY(int col, int row)
{
	COORD toado;
	toado.X = col;
	toado.Y = row;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), toado);
}




// Doi mau chu
void mauchu(int mau)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), mau);
}

//thiet lap mau chu
void setColor(int songuyen)
{
	switch (songuyen) {
	case 2:mauchu(48); break;
	case 4:mauchu(49); break;
	case 8:mauchu(48); break;
	case 16:mauchu(52); break;
	case 32:mauchu(59); break;
	case 64:mauchu(54); break;
	case 128:mauchu(55); break;
	case 256:mauchu(57); break;
	case 512:mauchu(57); break;
	case 1024:mauchu(58); break;
	case 2048:mauchu(59); break;

	}
}

