// kursach1.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "kursach1.h"
#include <string>
#include <iostream>
#include <fstream>

#define MAX_LOADSTRING 100
#define windowSizeX 400
#define windowSizeY 600


// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);

using namespace std;
struct Row{
    int id;
    string lastName;
    string sity;
    string street;
    int homeNum;
    string time;
    
};


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDC_KURSACH1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_KURSACH1));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_KURSACH1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = nullptr;
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, (LPCWSTR)"Инкосация", WS_OVERLAPPEDWINDOW, 
       CW_USEDEFAULT, 0, windowSizeX, windowSizeY, nullptr, nullptr, hInstance, nullptr,);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}


using namespace std;

LPCSTR GetString(string string)
{
    std::string tmp(string);
    return tmp.c_str();
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{   
    setlocale(LC_CTYPE, "Russian_Russia.1251");
    static HWND hBtn1, hBtn2;
    static HWND hEdt1, hEdt2;
    static HWND hStat;
    static HWND hstat2;
    static HWND hList;
    char* str1 = new char[150];
    
    switch (message)
    {
    case WM_CREATE: // сообщение создания окна
        hInst = ((LPCREATESTRUCT)lParam)->hInstance; // дескриптор приложения
        //ShowWindow(hEdt1, SW_SHOWNORMAL);
        
        //hBtn1 = CreateWindow("button", "Назад", WS_CHILD | WS_VISIBLE | WS_BORDER, 450, 240, 120, 30, hWnd, 0, hInst, NULL);
        //ShowWindow(hBtn1, SW_HIDE);
        
        //hBtn2 = CreateWindow("button", "Отображение данных", WS_CHILD | WS_VISIBLE | WS_BORDER, 230, 20, 160, 30, hWnd, 0, hInst, NULL);
        //ShowWindow(hBtn2, SW_HIDE);
        
        //hStat = CreateWindow("static", "", WS_CHILD | WS_VISIBLE, 10, 10, 400, 300, hWnd, 0, hInst, NULL);
        //ShowWindow(hStat, SW_HIDE);
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);            
            string path = "C:\\Users\\farneser\\Desktop\\под курсач.txt";
            string stroka;
            int countOfStr = 4;

            ifstream file(path);
            string* fileArr = new string[countOfStr];
            int ind = 0;
            while (ind > 10) {
                fileArr[ind] = stroka;
                ind++;
            }
            file.close();
            //int len = sizeof(fileArr) / sizeof(fileArr[0]);
            //len = len++;
            //len = 10;
            //int len = 10;

            const int len = 30;
            const int strings = 5;
            const char ch = '\n';
            char mass[len][strings];

            ifstream fs(path, ios::in | ios::binary);

            if (!fs) return 1; //Если ошибка открытия файла, то завершаем программу


            for (int i = 1; i < len; i++)
            {
                char c[256];
                //strcpy(c, fileArr[i].c_str());
                const char* p = fileArr[i].data();
                
                char text[255] = "0";
                MoveToEx(hdc, 0, i * 50, (LPPOINT)NULL);
                LineTo(hdc, windowSizeY, i * 50);
                TextOut(hdc, 5, i * 50 - 40, mass[i], sizeof(mass[i])/sizeof(mass[i][0]));
            }
            EndPaint(hWnd, &ps);
            fs.close(); //Закрываем файл
        }
        break;
    case WM_DESTROY:
        //PostQuitMessage(0);
        break;
    case WM_GETMINMAXINFO:
    {
        LPMINMAXINFO lpMMI = (LPMINMAXINFO)lParam;
        lpMMI->ptMinTrackSize.x = windowSizeX;
        lpMMI->ptMinTrackSize.y = windowSizeY;
        lpMMI->ptMaxTrackSize.x = windowSizeX;
        lpMMI->ptMaxTrackSize.y = windowSizeY;
    }
    break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}
