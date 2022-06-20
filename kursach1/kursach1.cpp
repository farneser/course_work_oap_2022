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
	hwnd = CreateWindow("MyClass", "Инкосация", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT,
		0, 630, 380, NULL, NULL, hInstance, NULL);


	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);



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
	TCHAR Edit1TXT[64];
	TCHAR Edit2TXT[64];
	TCHAR Edit3TXT[64];
	TCHAR Edit4TXT[64];
	TCHAR Edit5TXT[64];
	TCHAR Edit6TXT[64];
	string line;
	HINSTANCE hInst;

	HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
	IFileOpenDialog* pFileOpen;
	HMENU root = CreateMenu();
	bool NEEDTOOPENFILE = false;

	hr = CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_ALL, IID_IFileOpenDialog, reinterpret_cast<void**>(&pFileOpen));
	switch (Message) {
	case WM_CREATE: // сообщение создания окна
		hInst = ((LPCREATESTRUCT)lparam)->hInstance; // дескриптор приложения

		btnAddOK = CreateWindow("button", "Добавить", WS_CHILD | WS_VISIBLE | WS_BORDER,
			670, 200, 120, 30, hwnd, 0, hInst, NULL);
		btnDeleteOK = CreateWindow("button", "Удалить", WS_CHILD | WS_VISIBLE | WS_BORDER,
			685, 10, 120, 30, hwnd, 0, hInst, NULL);
		btnEditOK = CreateWindow("button", "Редактировать", WS_CHILD | WS_VISIBLE | WS_BORDER,
			670, 200, 120, 30, hwnd, 0, hInst, NULL);
		btnBack = CreateWindow("button", "Назад", WS_CHILD | WS_VISIBLE | WS_BORDER,
			670, 375, 120, 30, hwnd, 0, hInst, NULL);
		hStat = CreateWindow("static", "", WS_CHILD | WS_VISIBLE | WS_BORDER,
			10, 10, 625, 385, hwnd, 0, hInst, NULL);
		btnShow = CreateWindow("button", "Отображение данных", WS_CHILD | WS_VISIBLE | WS_BORDER,
			10, 10, 160, 30, hwnd, 0, hInst, NULL);
		btnFile = CreateWindow("button", "Выбрать файл", WS_CHILD | WS_VISIBLE | WS_BORDER,
			10, 50, 160, 30, hwnd, 0, hInst, NULL);
		btnDelete = CreateWindow("button", "Удалить строку", WS_CHILD | WS_VISIBLE | WS_BORDER,
			10, 50, 160, 30, hwnd, 0, hInst, NULL);
		btnAdd = CreateWindow("button", "Добавить строку", WS_CHILD | WS_VISIBLE | WS_BORDER,
			10, 90, 160, 30, hwnd, 0, hInst, NULL);
		btnEdit = CreateWindow("button", "Редактировать строку", WS_CHILD | WS_VISIBLE | WS_BORDER,
			10, 130, 160, 30, hwnd, 0, hInst, NULL);

		Edit1 = CreateWindow("edit", "", WS_CHILD | WS_VISIBLE | WS_BORDER, 10, 405, 30, 25, hwnd, 0, hInst, NULL);
		Edit2 = CreateWindow("edit", "", WS_CHILD | WS_VISIBLE | WS_BORDER, 50, 405, 75, 25, hwnd, 0, hInst, NULL);
		Edit3 = CreateWindow("edit", "", WS_CHILD | WS_VISIBLE | WS_BORDER, 135, 405, 75, 25, hwnd, 0, hInst, NULL);
		Edit4 = CreateWindow("edit", "", WS_CHILD | WS_VISIBLE | WS_BORDER, 220, 405, 75, 25, hwnd, 0, hInst, NULL);
		Edit5 = CreateWindow("edit", "", WS_CHILD | WS_VISIBLE | WS_BORDER, 300, 405, 75, 25, hwnd, 0, hInst, NULL);
		Edit6 = CreateWindow("edit", "", WS_CHILD | WS_VISIBLE | WS_BORDER, 385, 405, 75, 25, hwnd, 0, hInst, NULL);
		deleteEdit = CreateWindow("edit", "", WS_CHILD | WS_VISIBLE | WS_BORDER, 645, 10, 30, 30, hwnd, 0, hInst, NULL);

		AppendMenu(root, MF_STRING, On_Menu_ClickedFILE, "Выбрать Файл");
		AppendMenu(root, MF_STRING, On_Menu_ClickedSHOW, "Обображение данных / Обновить страницу");
		AppendMenu(root, MF_STRING, On_Menu_ClickedADD, "Добавить строку");
		AppendMenu(root, MF_STRING, On_Menu_ClickedEDIT, "Изменить строку");
		//RemoveMenu(root,On_Menu_Clicked1, );
		SetMenu(hwnd, root);
		//HWND** arrayToShowEDIT = new HWND * [countOfLinesInFile];
		//for (int i = 0; i < countOfLinesInFile; i++)
		//{
		//	arrayToShowEDIT[i] = new HWND[6];
		//}
		//for (int i = 0; i < countOfLinesInFile; i++)
		//{
		//	arrayToShowEDIT[i][1] = CreateWindow("edit", "", WS_CHILD | WS_VISIBLE | WS_BORDER, 10, (10 * (i + 1)) + 5, 30, 25, hwnd, 0, hInst, NULL);
		//	arrayToShowEDIT[i][2] = CreateWindow("edit", "", WS_CHILD | WS_VISIBLE | WS_BORDER, 50, (10 * (i + 1)) + 5, 75, 25, hwnd, 0, hInst, NULL);
		//	arrayToShowEDIT[i][3] = CreateWindow("edit", "", WS_CHILD | WS_VISIBLE | WS_BORDER, 135, (10 * (i + 1)) + 5, 75, 25, hwnd, 0, hInst, NULL);
		//	arrayToShowEDIT[i][4] = CreateWindow("edit", "", WS_CHILD | WS_VISIBLE | WS_BORDER, 220, (10 * (i + 1)) + 5, 75, 25, hwnd, 0, hInst, NULL);
		//	arrayToShowEDIT[i][5] = CreateWindow("edit", "", WS_CHILD | WS_VISIBLE | WS_BORDER, 300, (10 * (i + 1)) + 5, 75, 25, hwnd, 0, hInst, NULL);
		//	arrayToShowEDIT[i][6] = CreateWindow("edit", "", WS_CHILD | WS_VISIBLE | WS_BORDER, 385, (10 * (i + 1)) + 5, 75, 25, hwnd, 0, hInst, NULL);
		//}
		//for (int i = 0; i < countOfLinesInFile; i++)
		//{
		//	for (int j = 0; j < 6; j++)
		//	{
		//	ShowWindow(arrayToShowEDIT[i][j], SW_HIDE);
		//	}

		//}
		ShowWindow(Edit1, SW_HIDE);
		ShowWindow(Edit2, SW_HIDE);
		ShowWindow(Edit3, SW_HIDE);
		ShowWindow(Edit4, SW_HIDE);
		ShowWindow(Edit5, SW_HIDE);
		ShowWindow(Edit6, SW_HIDE);
		ShowWindow(btnFile, SW_HIDE);
		ShowWindow(deleteEdit, SW_HIDE);

		ShowWindow(btnAddOK, SW_HIDE);
		ShowWindow(btnEditOK, SW_HIDE);
		ShowWindow(btnDeleteOK, SW_HIDE);
		ShowWindow(btnBack, SW_HIDE);
		ShowWindow(btnDelete, SW_HIDE);
		ShowWindow(btnShow, SW_SHOWNORMAL);
		ShowWindow(hStat, SW_HIDE);
		break;
	case WM_COMMAND:  // сообщение о команде
		switch (wparam)
		{
		case On_Menu_ClickedFILE:
			lparam = (LPARAM)btnFile;
			break;
		case On_Menu_ClickedSHOW:
			lparam = (LPARAM)btnShow;
			break;
		case On_Menu_ClickedEXIT:
			PostQuitMessage(0);
			break;
		case On_Menu_ClickedADD:
			lparam = (LPARAM)btnAdd;
			break;
		case On_Menu_ClickedEDIT:
			lparam = (LPARAM)btnEdit;
			break;
		default:
			break;
		}
		if (lparam == (LPARAM)btnAddOK)
		{
			GetWindowText(Edit1, Edit1TXT, 20);
			GetWindowText(Edit2, Edit2TXT, 20);
			GetWindowText(Edit3, Edit3TXT, 20);
			GetWindowText(Edit4, Edit4TXT, 20);
			GetWindowText(Edit5, Edit5TXT, 20);
			GetWindowText(Edit6, Edit6TXT, 20);

			ofstream out;
			out.open(path, std::ios::app);
			out << Edit2TXT << "\t|" << Edit3TXT << "\t|" << Edit4TXT << "\t|"
				<< Edit5TXT << "\t|" << Edit6TXT << "\t|" << endl;
			out.close();
			lparam == (LPARAM)btnShow;
		}
		if (lparam == (LPARAM)btnEditOK)
		{

			GetWindowText(Edit1, Edit1TXT, 64);
			GetWindowText(Edit2, Edit2TXT, 64);
			GetWindowText(Edit3, Edit3TXT, 64);
			GetWindowText(Edit4, Edit4TXT, 64);
			GetWindowText(Edit5, Edit5TXT, 64);
			GetWindowText(Edit6, Edit6TXT, 64);

			fstream in(path); // окрываем файл для чтения
			if (in.is_open())
			{
				while (getline(in, line))
				{
					strings++;
					if (maxLen < sizeof(line) / sizeof(line[0]))
					{
						maxLen = sizeof(line) / sizeof(line[0]);
					}
				}
			}
			in.close();

			string* mass = new string[strings];

			in.open(path);
			if (in.is_open())
			{

				while (getline(in, line))
				{
					mass[fl] = line;
					fl++;
				}
			}
			in.close();
			string Edit1STR = Edit1TXT;
			string Edit2STR = Edit2TXT;
			string Edit3STR = Edit3TXT;
			string Edit4STR = Edit4TXT;
			string Edit5STR = Edit5TXT;
			string Edit6STR = Edit6TXT;

			mass[StrToInt(Edit1TXT)] = Edit2STR + "\t|" + Edit3STR
				+ "\t|" + Edit4STR + "\t|" + Edit5STR + "\t|" + Edit6STR + "\t|";
			ofstream ofs;
			ofs.open(path, std::ofstream::out | std::ofstream::trunc);
			ofs.close();
			ofstream file(path, ofstream::app | ofstream::out);
			if (file.is_open())
			{
				for (int i = 0; i < strings; i++)
				{
					file << mass[i] << endl;
				}
			}
			file.close();

			lparam = (LPARAM)btnBack;
		}
		if (lparam == (LPARAM)btnDeleteOK)
		{

			GetWindowText(deleteEdit, lineToDel, 64);
			lineNToDel = StrToInt(lineToDel);

			fl = 0;
			fl1 = 0;
			countOfLinesInFile = 0;

			fstream in(path); // окрываем файл для чтения
			if (in.is_open())
			{
				while (getline(in, line))
				{
					countOfLinesInFile++;
				}
			}
			in.close();

			string* mass = new string[countOfLinesInFile];

			in.open(path);
			if (in.is_open())
			{

				while (getline(in, line))
				{
					if (fl1 != lineNToDel)
					{
						mass[fl] = line;
						fl++;
					}
					fl1++;

				}
			}
			in.close();

			ofstream ofs;
			ofs.open(path, std::ofstream::out | std::ofstream::trunc);
			ofs.close();
			ofstream file(path, ofstream::app | ofstream::out);
			if (file.is_open())
			{
				for (int i = 0; i < countOfLinesInFile - 1; i++)
				{
					file << mass[i] << endl;
				}
			}
			file.close();
			lparam = (LPARAM)btnShow;
		}
		if (lparam == (LPARAM)btnEdit)
		{
			ShowWindow(btnShow, SW_HIDE);
			ShowWindow(btnFile, SW_HIDE);
			ShowWindow(btnEdit, SW_HIDE);
			ShowWindow(btnAdd, SW_HIDE);
			ShowWindow(btnDelete, SW_HIDE);
			SetWindowText(Edit1, "");
			SetWindowText(Edit2, "");
			SetWindowText(Edit3, "");
			SetWindowText(Edit4, "");
			SetWindowText(Edit5, "");
			SetWindowText(Edit6, "");
			countOfLinesInFile = 0;
			ifstream in(path); // окрываем файл для чтения
			if (in.is_open())
			{
				while (getline(in, line))
				{
					++countOfLinesInFile;
				}
			}
			in.close();
			ShowWindow(btnEditOK, SW_SHOWNORMAL);
			ShowWindow(btnBack, SW_SHOWNORMAL);
			ShowWindow(Edit1, SW_SHOWNORMAL);
			ShowWindow(Edit2, SW_SHOWNORMAL);
			ShowWindow(Edit3, SW_SHOWNORMAL);
			ShowWindow(Edit4, SW_SHOWNORMAL);
			ShowWindow(Edit5, SW_SHOWNORMAL);
			ShowWindow(Edit6, SW_SHOWNORMAL);

			lparam = (LPARAM)btnShow;
		}
		if (lparam == (LPARAM)btnFile || NEEDTOOPENFILE)
		{
			NEEDTOOPENFILE = false;
			EnableWindow(hwnd, false);
			hr = pFileOpen->Show(NULL);

			if (SUCCEEDED(hr))
			{
				IShellItem* pItem;
				hr = pFileOpen->GetResult(&pItem);
				if (SUCCEEDED(hr))
				{
					PWSTR pszFilePath;
					hr = pItem->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath);
					wcstombs(path, pszFilePath, 256);
					pItem->Release();
				}
			}
			pFileOpen->Release();
			EnableWindow(hwnd, true);
			SetForegroundWindow(hwnd);
			lparam = (LPARAM)btnShow;
		}
		if (lparam == (LPARAM)btnAdd)
		{

			ShowWindow(btnShow, SW_HIDE);
			ShowWindow(btnFile, SW_HIDE);
			ShowWindow(btnAdd, SW_HIDE);
			ShowWindow(btnEdit, SW_HIDE);
			ShowWindow(btnDelete, SW_HIDE);
			SetWindowText(Edit1, "");
			SetWindowText(Edit2, "Фамилия");
			SetWindowText(Edit3, "Имя");
			SetWindowText(Edit4, "Город");
			SetWindowText(Edit5, "Улица");
			SetWindowText(Edit6, "№Дома");
			countOfLinesInFile = 0;
			ifstream in(path); // окрываем файл для чтения
			if (in.is_open())
			{
				while (getline(in, line))
				{
					++countOfLinesInFile;
				}
			}
			in.close();
			lparam = (LPARAM)btnShow;
			ShowWindow(btnAddOK, SW_SHOWNORMAL);
			ShowWindow(btnBack, SW_SHOWNORMAL);
			//ShowWindow(Edit1, SW_SHOWNORMAL);
			ShowWindow(Edit2, SW_SHOWNORMAL);
			ShowWindow(Edit3, SW_SHOWNORMAL);
			ShowWindow(Edit4, SW_SHOWNORMAL);
			ShowWindow(Edit5, SW_SHOWNORMAL);
			ShowWindow(Edit6, SW_SHOWNORMAL);
			SetWindowText(Edit1, IntToStr(countOfLinesInFile));
		}
		if (lparam == (LPARAM)btnShow)
		{
			ShowWindow(btnShow, SW_HIDE);
			ShowWindow(btnFile, SW_HIDE);
			ShowWindow(btnAdd, SW_HIDE);
			ShowWindow(btnEdit, SW_HIDE);
			ShowWindow(btnDelete, SW_HIDE);
			ShowWindow(hStat, SW_SHOWNORMAL);
			ShowWindow(btnBack, SW_SHOWNORMAL);
			ShowWindow(btnDeleteOK, SW_SHOWNORMAL);
			ShowWindow(deleteEdit, SW_SHOWNORMAL);


			strcpy(strExit, "");

			//string strings[MAX_COUNT_OF_SPLITS];
			//string** arrayToShow = new string * [countOfLinesInFile];
			//for (int i = 0; i < countOfLinesInFile; i++)
			//{
			//	arrayToShow[i] = new string[6];
			//}

			//int someCounter = 0;
			//ifstream in(path); // окрываем файл для чтения
			//if (in.is_open())
			//{
			//	while (getline(in, line))
			//	{
			//		arrayToShow[someCounter] = split(line, seperator);
			//		++someCounter;
			//		strcat(strExit, line.c_str());
			//		strcat(strExit, "\n");
			//	}
			//}
			//in.close();

			string* lines = nullptr;
			int fl = 0;
			ifstream in(path); // окрываем файл для чтения
			if (in.is_open())
			{
				getline(in, line);
				strcat(strExit, "№\t|");
				strcat(strExit, line.c_str());
				strcat(strExit, "\n");
				strcat(strExit, LIIIIIIIIIIIIIINE);
				strcat(strExit, "\n");
				while (getline(in, line))
				{
					++fl;
					strcat(strExit, IntToStr(fl));
					strcat(strExit, "\t|");
					strcat(strExit, line.c_str());
					strcat(strExit, "\n");
				}
			}
			in.close();
			//for (int i = 0; i < sizeof(lines) / sizeof(lines[0]); i++)
			//{
				//strcat(strExit, lines[i].c_str());
				//strcat(strExit, "\n");
			//}

			SetWindowTextA(hStat, strExit);
		}
		if (lparam == (LPARAM)btnBack)
		{
			ShowWindow(btnShow, SW_SHOWNORMAL);
			//ShowWindow(btnFile, SW_SHOWNORMAL);
			ShowWindow(btnAdd, SW_SHOWNORMAL);
			ShowWindow(btnEdit, SW_SHOWNORMAL);
			//ShowWindow(btnDelete, SW_SHOWNORMAL);

			ShowWindow(hStat, SW_HIDE);
			ShowWindow(btnBack, SW_HIDE);
			ShowWindow(btnAddOK, SW_HIDE);
			ShowWindow(btnEditOK, SW_HIDE);
			ShowWindow(btnDeleteOK, SW_HIDE);
			ShowWindow(deleteEdit, SW_HIDE);

			ShowWindow(Edit1, SW_HIDE);
			ShowWindow(Edit2, SW_HIDE);
			ShowWindow(Edit3, SW_HIDE);
			ShowWindow(Edit4, SW_HIDE);
			ShowWindow(Edit5, SW_HIDE);
			ShowWindow(Edit6, SW_HIDE);
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
