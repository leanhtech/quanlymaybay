#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <iostream>
using namespace std;

#define Enter 13
//const int WHITE=15;
#define PASSWORD "abcdef"
//const int WHITE=15;

HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

void FontSize(int a, int b){
	PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX();  
	lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);  
	GetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);  
	lpConsoleCurrentFontEx->dwFontSize.X = a;  
	lpConsoleCurrentFontEx->dwFontSize.Y = b;  
	SetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
	delete lpConsoleCurrentFontEx;
 } 

void resizeConsole(int width, int height) {
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void ShowCur(bool CursorVisibility) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}

char* Pwd () {
     char S[40]; int i=0;
     char *S_ptr = S;
     while ((S[i]= getch()) != Enter ) 
     { printf ("%c", '*') ; i++ ; 
     }
     S[i]='\0';
     return S_ptr;
}

int CheckPwd () {
    int dem =0; 
    for ( dem =1 ; dem <=3 ; dem++)
    { printf( "Password :"); 
      if (strcmp(Pwd(),PASSWORD) ==0)   return 1;
      else printf ( "\nPassword sai. Hay nhap lai\n")  ; 
    }
    return 0;  
}

void gotoxy(short x,short y)
{
        HANDLE hConsoleOutput;
        COORD Cursor_an_Pos = { x,y};
        hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}  

int wherex( void )
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    return screen_buffer_info.dwCursorPosition.X;
}

int wherey( void )
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    return screen_buffer_info.dwCursorPosition.Y;
}
void clreol( ) {
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
void clrscr() {
	system("cls");
}
