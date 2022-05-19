// kursach1.cpp : Определяет точку входа для приложения.
//
#define _CRT_SECURE_NO_WARNINGS

#include "framework.h"
#include "kursach1.h"
#include <string>
#include <fstream>
#include <windows.h>
#include <string>

#define MAX_LOADSTRING 100
#define windowSizeX 630
#define windowSizeY 380

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
//каким образом примерно должна выглядить минимальная программа

LONG WINAPI WndProc(HWND, UINT, WPARAM, LPARAM); // функция обработки сообщений окна
// Функция преобразования строки в число
using namespace std;


int StrToInt(char* s)
{
	int temp = 0; // число
	int i = 0;
	int sign = 0; // знак числа 0- положительное, 1 - отрицательное
	if (s[i] == '-')
	{
		sign = 1;
		i++;
	}
	while (s[i] >= 0x30 && s[i] <= 0x39)
	{
		temp = temp + (s[i] & 0x0F);
		temp = temp * 10;
		i++;
	}
	temp = temp / 10;
	if (sign == 1)
		temp = -temp;
	return(temp);
}
// Функция преобразования числа в строку
char* IntToStr(int n)
{
	char s[40], t, * temp;
	int i, k;
	int sign = 0;
	i = 0;
	k = n;
	if (k < 0)
	{
		sign = 1;
		k = -k;
	}
	do {
		t = k % 10;
		k = k / 10;
		s[i] = t | 0x30;
		i++;
	} while (k > 0);
	if (sign == 1)
	{
		s[i] = '-';
		i++;
	}
	temp = new char[i];
	k = 0;
	i--;
	while (i >= 0) {
		temp[k] = s[i];
		i--; k++;
	}
	temp[k] = '\0';
	return(temp);
}
// Стартовая функция
int  WINAPI  WinMain(HINSTANCE  hInstance,
	HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	HWND hwnd; // дескриптор окна
	MSG msg;   // структура сообщения
	WNDCLASS w; // структура класса окна
	memset(&w, 0, sizeof(WNDCLASS)); // очистка памяти для структуры
	w.style = CS_HREDRAW | CS_VREDRAW;
	w.lpfnWndProc = WndProc;
	w.hInstance = hInstance;
	w.hbrBackground = CreateSolidBrush(0x00FFFFFF);
	w.lpszClassName = "MyClass";
	RegisterClass(&w); // регистрация класса окна
	// Создание окна
	hwnd = CreateWindow("MyClass", "Инкосация", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, 630, 380, NULL, NULL, hInstance, NULL);
	ShowWindow(hwnd, nCmdShow); // отображение окна
	UpdateWindow(hwnd);         // перерисовка окна
	// Цикл обработки сообщений
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}



using namespace std;
// Функция обработки сообщений
LONG WINAPI WndProc(HWND hwnd, UINT Message, WPARAM wparam, LPARAM lparam) {
	setlocale(LC_ALL, "ru");
	HDC hdc;
	HINSTANCE hInst;
	PAINTSTRUCT ps;
	static HWND hEdt1, hEdt2; // дескрипторы полей редактирования
	static HWND hStat; // дескриптор статического текста
	static HWND hstat2;
	static HWND hList;
	char* str1 = new char[150];
	char* str10 = new char[10000];
	TCHAR StrA[20];
	string line;
	LPCTSTR lstr;
	int a, b, sum, Len;
	switch (Message) {
	case WM_CREATE: // сообщение создания окна
		hInst = ((LPCREATESTRUCT)lparam)->hInstance; // дескриптор приложения
		ShowWindow(hEdt1, SW_SHOWNORMAL);

		static HWND btnBack = CreateWindow("button", "Назад", WS_CHILD | WS_VISIBLE | WS_BORDER, 450, 240, 120, 30, hwnd, 0, hInst, NULL);
		static HWND btnShow = CreateWindow("button", "Отображение данных", WS_CHILD | WS_VISIBLE | WS_BORDER, 230, 20, 160, 30, hwnd, 0, hInst, NULL);
		static HWND btnFile = CreateWindow("button", "Выбрать файл", WS_CHILD | WS_VISIBLE | WS_BORDER, 230, 60, 160, 30, hwnd, 0, hInst, NULL);

		hStat = CreateWindow("static", "", WS_CHILD | WS_VISIBLE, 10, 10, 400, 300, hwnd, 0, hInst, NULL);
		ShowWindow(btnBack, SW_HIDE);
		ShowWindow(btnShow, SW_SHOWNORMAL);
		ShowWindow(hStat, SW_HIDE);
		break;
	case WM_COMMAND:  // сообщение о команде
		if (lparam == (LPARAM)btnBack)    // если нажали на кнопку
		{
			ShowWindow(btnShow, SW_SHOWNORMAL);
			ShowWindow(btnFile, SW_SHOWNORMAL);
			ShowWindow(hStat, SW_HIDE);
			ShowWindow(btnBack, SW_HIDE);
		}
		if (lparam == (LPARAM)btnFile)    // если нажали на кнопку
		{
			ShowWindow(btnShow, SW_HIDE);

		}
		if (lparam == (LPARAM)btnShow)    // если нажали на кнопку
		{
			ShowWindow(btnShow, SW_HIDE);
			ShowWindow(btnFile, SW_HIDE);
			ShowWindow(hStat, SW_SHOWNORMAL);
			ShowWindow(btnBack, SW_SHOWNORMAL);
			strcpy(str10, "");

			ifstream in("C:\\Users\\farneser\\Desktop\\kurs.txt"); // окрываем файл для чтения
			if (in.is_open())
			{
				while (getline(in, line))
				{
					strcat(str10, line.c_str());
					strcat(str10, "\n");
				}
			}
			in.close();
			SetWindowTextA(hStat, str10);
		}
		break;
	case WM_PAINT: // перерисовка окна
		hdc = BeginPaint(hwnd, &ps); // начало перерисовки
		EndPaint(hwnd, &ps); // конец перерисовки
		break;
	case WM_DESTROY: // закрытие окна
		PostQuitMessage(0);
		break;
	case WM_GETMINMAXINFO:
	{
		LPMINMAXINFO lpMMI = (LPMINMAXINFO)lparam;
		lpMMI->ptMinTrackSize.x = windowSizeX;
		lpMMI->ptMinTrackSize.y = windowSizeY;
		lpMMI->ptMaxTrackSize.x = windowSizeX;
		lpMMI->ptMaxTrackSize.y = windowSizeY;
	}
	default: // обработка сообщения по умолчанию
		return DefWindowProc(hwnd, Message, wparam, lparam);
	}
	return 0;
}

