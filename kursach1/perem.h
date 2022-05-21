#pragma once
#include "framework.h"


HINSTANCE hInst;
WCHAR szTitle[MAX_LOADSTRING];
WCHAR szWindowClass[MAX_LOADSTRING];
char path[128] = "C:\\Users\\farneser\\Desktop\\kurs.txt";

ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);

static HWND hEdt1;
static HWND hEdt2;
static HWND hStat;
static HWND hstat2;
static HWND hList;
static HWND btnBack;
static HWND btnAdd;
static HWND btnShow;
static HWND btnFile;
static HWND btnEdit1;
static HWND btnEdit2;
static HWND btnEdit3;
static HWND btnEdit4;
static HWND btnEdit5;
static HWND btnEdit6;

HDC hdc;
PAINTSTRUCT ps;
char* strIn = new char[150];
char* strExit = new char[10000];