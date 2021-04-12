#pragma once

#include <conio.h>

#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <string.h>
#include <windows.h>

#define Enter 13
//const int WHITE=15;
#define PASSWORD "abcdef"
//const int WHITE=15;

// đưa con trỏ tới vị trí(x,y)
void gotoxy(short x,short y)
{
        HANDLE hConsoleOutput;
        COORD Cursor_an_Pos = { x,y};
        hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}  
// xác định vị trí của x trên màn hình - x là chiều dài của màn hình
// đi từ trái sang phải
int wherex( void )
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    return screen_buffer_info.dwCursorPosition.X;
}
// xác định vị trí của con trỏ theo chiều rộng - y có chiều dương hướng từ
// trên xuống dưới
int wherey( void )
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    return screen_buffer_info.dwCursorPosition.Y;
}
// xóa màn hình theo điều kiện nào đó
void clreol() {
COORD coord;
DWORD written;
CONSOLE_SCREEN_BUFFER_INFO info;
GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
coord.X = info.dwCursorPosition.X;
coord.Y = info.dwCursorPosition.Y;
FillConsoleOutputCharacter (GetStdHandle(STD_OUTPUT_HANDLE), ' ',
  info.dwSize.X - info.dwCursorPosition.X * info.dwCursorPosition.Y, coord, &written);
gotoxy (info.dwCursorPosition.X , info.dwCursorPosition.Y );
}

// đặt màu cho chữ với color là giá trị từ 0 đến 255
void SetColor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
//đặt màu nền cũng với color từ 0 đến 255
void SetBGColor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    color <<= 4;
    wAttributes &= 0xff0f;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
// xóa hoàn toàn màn hình
void clearScreen() {
	system("cls");
}

// hien thi con tro hoac khong
void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}
// quy dinh kich co man hinh console
void SizeConsole(SHORT Width, SHORT height)
{
	SMALL_RECT SizeW = { 0,0,Width - 1,height - 1 };
	COORD sizebuff = { Width,height };
	BOOL BSize = SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, &SizeW);
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), sizebuff);
	if (!BSize) SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, &SizeW);
}

// Xóa toàn b? n?i dung c?a s? console - chôm t? MSDN
HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
void cls(HANDLE hConsole)
{
	COORD coordScreen = { 0, 0 };    // home for the cursor 
	DWORD cCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD dwConSize;

	// Get the number of character cells in the current buffer. 

	if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
		return;
	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

	// Fill the entire screen with blanks.

	if (!FillConsoleOutputCharacter(hConsole, (TCHAR) ' ',
		dwConSize, coordScreen, &cCharsWritten))
		return;

	// Get the current text attribute.

	if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
		return;

	// Set the buffer's attributes accordingly.

	if (!FillConsoleOutputAttribute(hConsole, csbi.wAttributes,
		dwConSize, coordScreen, &cCharsWritten))
		return;

	// Put the cursor at its home coordinates.

	SetConsoleCursorPosition(hConsole, coordScreen);
}
// Vi?t l?i hàm clrscr, không c?n cung du?c nhung d? nh́n vào code cho d?p m?t
void clrscr()
{
	cls(hCon);
}

BOOL NT_SetConsoleDisplayMode(HANDLE hOutputHandle, DWORD dwNewMode)
{
	typedef BOOL(WINAPI *SCDMProc_t) (HANDLE, DWORD, LPDWORD);
	SCDMProc_t SetConsoleDisplayMode;
	HMODULE hKernel32;
	BOOL bFreeLib = FALSE, ret;
	const char KERNEL32_NAME[] = "kernel32.dll";

	hKernel32 = GetModuleHandleA(KERNEL32_NAME);
	if (hKernel32 == NULL)
	{
		hKernel32 = LoadLibraryA(KERNEL32_NAME);
		if (hKernel32 == NULL)
			return FALSE;

		bFreeLib = true;
	}

	SetConsoleDisplayMode =
		(SCDMProc_t)GetProcAddress(hKernel32, "SetConsoleDisplayMode");
	if (SetConsoleDisplayMode == NULL)
	{
		SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
		ret = FALSE;
	}
	else
	{
		DWORD tmp;
		ret = SetConsoleDisplayMode(hOutputHandle, dwNewMode, &tmp);
	}

	if (bFreeLib)
		FreeLibrary(hKernel32);

	return ret;
}

void fullscreen()
{
	keybd_event(VK_MENU,0x38,0,0);
	keybd_event(VK_RETURN,0x1c,0,0);
	keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
	keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}

// Đ?t ch? d? FullScreen
void setFullScreen()
{
	NT_SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), 1);
}

// Thoát kh?i fullscreen
void exitFullScreen()
{
	NT_SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), 1);
}