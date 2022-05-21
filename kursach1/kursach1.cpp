#define _CRT_SECURE_NO_WARNINGS
#include "framework.h"


// Стартовая функция
int  WINAPI WinMain(HINSTANCE  hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	HWND hwnd; // дескриптор окна
	MSG msg;   // структура сообщения
	WNDCLASS w; 
	TCHAR szFile[260] = { 0 };       // if using TCHAR macros

	memset(&w, 0, sizeof(WNDCLASS)); // очистка памяти для структуры
	w.style = CS_HREDRAW | CS_VREDRAW;
	w.lpfnWndProc = WndProc;
	w.hInstance = hInstance;
	w.hbrBackground = CreateSolidBrush(0x00FFFFFF);
	w.lpszClassName = "MyClass";
	RegisterClass(&w); // регистрация класса окна
	// Создание окна
	hwnd = CreateWindow("MyClass", "Инкосация", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, 630, 380, NULL, NULL, hInstance, NULL);
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);        

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}


LONG WINAPI WndProc(HWND, UINT, WPARAM, LPARAM); // функция обработки сообщений окна


using namespace std;
// Функция обработки сообщений
LONG WINAPI WndProc(HWND hwnd, UINT Message, WPARAM wparam, LPARAM lparam) {
	setlocale(LC_ALL, "ru");
	TCHAR StrA[20];
	string line;
	LPCTSTR lstr;
	int a, b, sum, Len;
	HINSTANCE hInst;

	HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
	IFileOpenDialog* pFileOpen;

	hr = CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_ALL, IID_IFileOpenDialog, reinterpret_cast<void**>(&pFileOpen));
	switch (Message) {
	case WM_CREATE: // сообщение создания окна
		hInst = ((LPCREATESTRUCT)lparam)->hInstance; // дескриптор приложения
		ShowWindow(hEdt1, SW_SHOWNORMAL);

		btnBack = CreateWindow("button", "Назад", WS_CHILD | WS_VISIBLE | WS_BORDER, 450, 240, 120, 30, hwnd, 0, hInst, NULL);
		btnShow = CreateWindow("button", "Отображение данных", WS_CHILD | WS_VISIBLE | WS_BORDER, 230, 20, 160, 30, hwnd, 0, hInst, NULL);
		btnFile = CreateWindow("button", "Выбрать файл", WS_CHILD | WS_VISIBLE | WS_BORDER, 230, 60, 160, 30, hwnd, 0, hInst, NULL);
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
			EnableWindow(hwnd, FALSE);
			// Show the Open dialog box.
			hr = pFileOpen->Show(NULL);

			// Get the file name from the dialog box.
			if (SUCCEEDED(hr))
			{
				IShellItem* pItem;
				hr = pFileOpen->GetResult(&pItem);
				if (SUCCEEDED(hr))
				{
					PWSTR pszFilePath;
					hr = pItem->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath);
					wcstombs(path, pszFilePath, 128);
					pItem->Release();
				}
			}
			pFileOpen->Release();
			EnableWindow(hwnd, true);
			SetForegroundWindow(hwnd);
		}
		if (lparam == (LPARAM)btnShow)    // если нажали на кнопку
		{
			ShowWindow(btnShow, SW_HIDE);
			ShowWindow(btnFile, SW_HIDE);
			ShowWindow(hStat, SW_SHOWNORMAL);
			ShowWindow(btnBack, SW_SHOWNORMAL);

			strcpy(strExit, "");

			ifstream in(path); // окрываем файл для чтения
			if (in.is_open())
			{
				while (getline(in, line))
				{
					strcat(strExit, line.c_str());
					strcat(strExit, "\n");
				}
			}
			in.close();
			SetWindowTextA(hStat, strExit);
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

