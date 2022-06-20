#pragma once
#include "framework.h"


HINSTANCE hInst;
WCHAR szTitle[MAX_LOADSTRING];
WCHAR szWindowClass[MAX_LOADSTRING];
char path[256] = "C:\\Users\\farneser\\Desktop\\kurs.txt";

ATOM MyRegisterClass(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE, int);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

static HWND hEdt1;
static HWND hEdt2;
static HWND hStat;
static HWND hstat2;
static HWND hList;
static HWND btnBack;
static HWND btnAddOK;
static HWND btnRefresh;
static HWND btnDeleteOK;
static HWND btnAdd;
static HWND btnShow;
static HWND btnFile;
static HWND btnDelete;
static HWND btnEdit;
static HWND btnEditOK;

static HWND Edit1;
static HWND Edit2;
static HWND Edit3;
static HWND Edit4;
static HWND Edit5;
static HWND Edit6;

static HWND deleteEdit;

static HWND Show1;
static HWND Show2;
static HWND Show3;
static HWND Show4;
static HWND Show5;
static HWND Show6;


HDC hdc;
PAINTSTRUCT ps;
char* strIn = new char[8095];
char* strExit = new char[8095];
int countOfLinesInFile = 0;
int fl = 0;
int fl1 = 0;
int strings = 0;
int maxLen = 0;
char seperator[] = "&^)*";
const char LIIIIIIIIIIIIIINE[] = "----------------------------------------------------------------------------------------------------------------------------";
TCHAR lineToDel[64];
int lineNToDel;
