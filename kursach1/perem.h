#pragma once
#include "framework.h"


HINSTANCE hInst;
WCHAR szTitle[MAX_LOADSTRING];
WCHAR szWindowClass[MAX_LOADSTRING];

HWND hwnd;
MSG msg;
WNDCLASS w;
HRESULT hr;
HDC hdc;
PAINTSTRUCT ps;
HMENU root;

ATOM MyRegisterClass(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE, int);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

static HWND hEdt1, hEdt2, hStat, hStatMAIN, hStatSEARCH, hList, btnBack, btnAddOK,
btnDeleteOK, btnRefresh, btnAdd, btnShow, btnFile, btnDelete, btnEdit, btnSearch,
btnEditOK, Edit1, Edit2, Edit3, Edit4, Edit5, Edit6, deleteEdit, searchEdit;

string to_add_2, to_add_3, to_add_4, to_add_5, to_add_6, line, searchSTR = "|";

char* strIn = new char[8095];
char* strExit = new char[8095];

int fl = 0, fl1 = 0, strings = 0, maxLen = 0, lineNToDel, countOfLinesInFile;
char seperator[] = "&^)*", LIIIIIIIIIIIIIINE[155], path[256] = "";

TCHAR Edit1TXT[64], Edit2TXT[64], Edit3TXT[64], Edit4TXT[64], Edit5TXT[64], Edit6TXT[64], lineToDel[64];
char mainTXT[] = "Вас приветствует мастер работы налогового инспектора\ngithub.com/farneser\n(курсовая работа появистя там только после сдачи)";
TCHAR* searchEditBase = (TCHAR*)"";
