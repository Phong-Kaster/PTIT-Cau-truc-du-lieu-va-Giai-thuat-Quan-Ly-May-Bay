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


int CheckPwd();
void gotoxy(short x,short y);
int wherex( void );
int wherey( void );
void clreol();
void SetColor(WORD color);
void SetBGColor(WORD color);
void clearScreen();
void ShowCur(bool CursorVisibility);
void SizeConsole(SHORT Width, SHORT height);
void SizeConsole();
void cls(HANDLE hConsole);
void clrscr();
void fullscreen();
void setFullScreen();
void exitFullScreen();