#define _CRT_SECURE_NO_WARNINGS
#include "framework.h"


int  WINAPI WinMain(HINSTANCE  hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	TCHAR szFile[260] = { 0 };
	for (int i = 0; i < 155; i++)
	{
		LIIIIIIIIIIIIIINE[i] = '-';
	}
	memset(&w, 0, sizeof(WNDCLASS));
	w.style = CS_HREDRAW | CS_VREDRAW;
	w.lpfnWndProc = WndProc;
	w.hInstance = hInstance;
	w.hbrBackground = CreateSolidBrush(0x00FFFFFF);
	w.lpszClassName = "MyClass";
	RegisterClass(&w);

	hwnd = CreateWindow("MyClass", "Налоговый инспектор", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, 630, 380, NULL, NULL, hInstance, NULL);
	//string titleP = path;
	//string titleA = "Налоговый инспектор\t";
	//string title = titleA + titleP;
	//SetWindowTextA(hwnd, title.c_str());

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}


using namespace std;
LONG WINAPI WndProc(HWND hwnd, UINT Message, WPARAM wparam, LPARAM lparam) {
	setlocale(LC_ALL, "ru");
	//char path[256] = "C:\\Users\\farneser\\Desktop\\kurs.txt";
	IFileOpenDialog* pFileOpen;
	root = CreateMenu();
	hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
	hr = CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_ALL, IID_IFileOpenDialog, reinterpret_cast<void**>(&pFileOpen));
	switch (Message) {
	case WM_CREATE:
		hInst = ((LPCREATESTRUCT)lparam)->hInstance;

		btnAddOK = CreateWindow("button", "Добавить", WS_CHILD | WS_VISIBLE | WS_BORDER,
			645, 360, 160, 30, hwnd, 0, hInst, NULL);
		btnDeleteOK = CreateWindow("button", "Удалить", WS_CHILD | WS_VISIBLE | WS_BORDER,
			685, 10, 120, 30, hwnd, 0, hInst, NULL);
		btnEditOK = CreateWindow("button", "Редактировать", WS_CHILD | WS_VISIBLE | WS_BORDER,
			645, 360, 160, 30, hwnd, 0, hInst, NULL);
		btnBack = CreateWindow("button", "Назад", WS_CHILD | WS_VISIBLE | WS_BORDER,
			645, 400, 160, 30, hwnd, 0, hInst, NULL);
		hStat = CreateWindow("static", "", WS_CHILD | WS_VISIBLE | WS_BORDER,
			10, 10, 625, 385, hwnd, 0, hInst, NULL);
		hStatSEARCH = CreateWindow("static", "Отбор записей", WS_CHILD | WS_VISIBLE,
			645, 50, 160, 20, hwnd, 0, hInst, NULL);
		btnShow = CreateWindow("button", "Отображение данных", WS_CHILD | WS_VISIBLE | WS_BORDER,
			235, 135, 345, 50, hwnd, 0, hInst, NULL);
		hStatMAIN = CreateWindow("static", mainTXT, WS_CHILD | WS_VISIBLE,
			235, 30, 345, 80, hwnd, 0, hInst, NULL);
		btnFile = CreateWindow("button", "Выбрать файл", WS_CHILD | WS_VISIBLE | WS_BORDER,
			235, 360, 345, 50, hwnd, 0, hInst, NULL);
		btnDelete = CreateWindow("button", "Удалить строку", WS_CHILD | WS_VISIBLE | WS_BORDER,
			10, 50, 160, 30, hwnd, 0, hInst, NULL);
		btnAdd = CreateWindow("button", "Добавить строку", WS_CHILD | WS_VISIBLE | WS_BORDER,
			235, 285, 345, 50, hwnd, 0, hInst, NULL);
		btnEdit = CreateWindow("button", "Редактировать строку", WS_CHILD | WS_VISIBLE | WS_BORDER,
			235, 210, 345, 50, hwnd, 0, hInst, NULL);
		btnSearch = CreateWindow("button", "Поиск", WS_CHILD | WS_VISIBLE | WS_BORDER,
			645, 110, 160, 30, hwnd, 0, hInst, NULL);

		Edit1 = CreateWindow("edit", "", WS_CHILD | WS_VISIBLE | WS_BORDER, 10,	 405, 55,  25, hwnd, 0, hInst, NULL);
		Edit2 = CreateWindow("edit", "", WS_CHILD | WS_VISIBLE | WS_BORDER, 70,  405, 105, 25, hwnd, 0, hInst, NULL);
		Edit3 = CreateWindow("edit", "", WS_CHILD | WS_VISIBLE | WS_BORDER, 180, 405, 105, 25, hwnd, 0, hInst, NULL);
		Edit4 = CreateWindow("edit", "", WS_CHILD | WS_VISIBLE | WS_BORDER, 290, 405, 105, 25, hwnd, 0, hInst, NULL);
		Edit5 = CreateWindow("edit", "", WS_CHILD | WS_VISIBLE | WS_BORDER, 400, 405, 160, 25, hwnd, 0, hInst, NULL);
		Edit6 = CreateWindow("edit", "", WS_CHILD | WS_VISIBLE | WS_BORDER, 565, 405, 55,  25, hwnd, 0, hInst, NULL);

		deleteEdit = CreateWindow("edit", "", WS_CHILD | WS_VISIBLE | WS_BORDER, 645, 10, 30, 30, hwnd, 0, hInst, NULL);
		searchEdit = CreateWindow("edit", searchEditBase, WS_CHILD | WS_VISIBLE | WS_BORDER, 645, 70, 160, 30, hwnd, 0, hInst, NULL);

		AppendMenu(root, MF_STRING, On_Menu_ClickedFILE, "Выбрать Файл");
		AppendMenu(root, MF_STRING, On_Menu_ClickedSHOW, "Обображение данных");
		AppendMenu(root, MF_STRING, On_Menu_ClickedADD, "Добавить строку");
		AppendMenu(root, MF_STRING, On_Menu_ClickedEDIT, "Изменить строку");
		AppendMenu(root, MF_STRING, On_Menu_ClickedEXIT, "Выход");
		SetMenu(hwnd, root);

		//ShowWindow(Edit1, SW_HIDE);
		//ShowWindow(Edit2, SW_HIDE);
		//ShowWindow(Edit3, SW_HIDE);
		//ShowWindow(Edit4, SW_HIDE);
		//ShowWindow(Edit5, SW_HIDE);
		//ShowWindow(Edit6, SW_HIDE);
		ShowWindow(btnFile, SW_SHOWNORMAL);
		ShowWindow(btnSearch, SW_HIDE);
		ShowWindow(hStatSEARCH, SW_HIDE);
		ShowWindow(searchEdit, SW_HIDE);
		ShowWindow(deleteEdit, SW_HIDE);
		ShowWindow(btnAddOK, SW_HIDE);
		ShowWindow(btnEditOK, SW_HIDE);
		ShowWindow(btnDeleteOK, SW_HIDE);
		ShowWindow(btnBack, SW_HIDE);
		ShowWindow(btnDelete, SW_HIDE);
		ShowWindow(btnShow, SW_SHOWNORMAL);
		ShowWindow(hStat, SW_HIDE);
		break;

	case WM_COMMAND:
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

		if (lparam == (LPARAM)btnFile)
		{
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
			string titleP = path;
			string titleA = "Налоговый инспектор\t";
			string title = titleA + titleP;
			SetWindowTextA(hwnd, title.c_str());
		}
		if (lparam == (LPARAM)btnSearch)
		{

			GetWindowText(searchEdit, Edit1TXT, 64);
			searchSTR = Edit1TXT;
			lparam = (LPARAM)btnShow;
		}
		if (lparam == (LPARAM)btnAddOK)
		{
			GetWindowText(Edit1, Edit1TXT, 20);
			GetWindowText(Edit2, Edit2TXT, 20);
			GetWindowText(Edit3, Edit3TXT, 20);
			GetWindowText(Edit4, Edit4TXT, 20);
			GetWindowText(Edit5, Edit5TXT, 20);
			GetWindowText(Edit6, Edit6TXT, 20);

			to_add_2 = Edit2TXT;
			to_add_3 = Edit3TXT;
			to_add_4 = Edit4TXT;
			to_add_5 = Edit5TXT;
			to_add_6 = Edit6TXT;

			if (len(to_add_2) < 7) {
				to_add_2 += "\t";
			}
			if (len(to_add_3) < 7) {
				to_add_3 += "\t";
			}
			if (len(to_add_4) < 7) {
				to_add_4 += "\t";
			}
			if (len(to_add_5) < 12) {
				to_add_5 += "\t";
				if (len(to_add_5) <= 7) {
					to_add_5 += "\t";
				}
			}

			ofstream out;
			out.open(path, std::ios::app);
			out << to_add_2 << "\t|" << to_add_3 << "\t|" << to_add_4 << "\t|" << to_add_5 << "\t|" << to_add_6 << "\t|" << endl;
			out.close();
			lparam = (LPARAM)btnShow;
		}
		if (lparam == (LPARAM)btnEditOK)
		{

			GetWindowText(Edit1, Edit1TXT, 64);
			GetWindowText(Edit2, Edit2TXT, 64);
			GetWindowText(Edit3, Edit3TXT, 64);
			GetWindowText(Edit4, Edit4TXT, 64);
			GetWindowText(Edit5, Edit5TXT, 64);
			GetWindowText(Edit6, Edit6TXT, 64);

			fstream in(path);
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

			to_add_2 = Edit2TXT;
			to_add_3 = Edit3TXT;
			to_add_4 = Edit4TXT;
			to_add_5 = Edit5TXT;
			to_add_6 = Edit6TXT;

			if (len(to_add_2) < 7) {
				to_add_2 += "\t";
			}
			if (len(to_add_3) < 7) {
				to_add_3 += "\t";
			}
			if (len(to_add_4) < 7) {
				to_add_4 += "\t";
			}
			if (len(to_add_5) < 12) {
				to_add_5 += "\t";
				if (len(to_add_5) <= 7) {
					to_add_5 += "\t";
				}
			}
			mass[StrToInt(Edit1TXT) - 1] = to_add_2 + "\t|" + to_add_3 + "\t|" + to_add_4 + "\t|" + to_add_5 + "\t|" + to_add_6 + "\t|";
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

			lparam = (LPARAM)btnShow;
		}
		if (lparam == (LPARAM)btnDeleteOK)
		{
			GetWindowText(deleteEdit, lineToDel, 64);
			lineNToDel = StrToInt(lineToDel) - 1;

			fl = 0;
			fl1 = 0;
			countOfLinesInFile = 0;

			fstream in(path);
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
		if (lparam == (LPARAM)btnAdd)
		{

			ShowWindow(btnShow, SW_HIDE);
			ShowWindow(btnFile, SW_HIDE);
			ShowWindow(btnAdd, SW_HIDE);
			ShowWindow(btnEdit, SW_HIDE);
			ShowWindow(btnDelete, SW_HIDE);
			ShowWindow(btnEditOK, SW_HIDE);
			SetWindowText(Edit1, "");
			SetWindowText(Edit2, "Фамилия");
			SetWindowText(Edit3, "Имя");
			SetWindowText(Edit4, "Город");
			SetWindowText(Edit5, "Улица");
			SetWindowText(Edit6, "№Дом");
			countOfLinesInFile = 0;
			ifstream in(path);
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
			ShowWindow(Edit1, SW_HIDE);
			ShowWindow(Edit2, SW_SHOWNORMAL);
			ShowWindow(Edit3, SW_SHOWNORMAL);
			ShowWindow(Edit4, SW_SHOWNORMAL);
			ShowWindow(Edit5, SW_SHOWNORMAL);
			ShowWindow(Edit6, SW_SHOWNORMAL);
		}
		if (lparam == (LPARAM)btnEdit)
		{
			ShowWindow(btnShow, SW_HIDE);
			ShowWindow(btnFile, SW_HIDE);
			ShowWindow(btnEdit, SW_HIDE);
			ShowWindow(btnAdd, SW_HIDE);
			ShowWindow(btnAddOK, SW_HIDE);
			ShowWindow(btnDelete, SW_HIDE);
			SetWindowText(Edit1, "");
			SetWindowText(Edit2, "");
			SetWindowText(Edit3, "");
			SetWindowText(Edit4, "");
			SetWindowText(Edit5, "");
			SetWindowText(Edit6, "");
			countOfLinesInFile = 0;
			ifstream in(path);
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
		if (lparam == (LPARAM)btnShow)
		{
			ShowWindow(btnShow, SW_HIDE);
			ShowWindow(btnFile, SW_HIDE);
			ShowWindow(btnAdd, SW_HIDE);
			ShowWindow(btnEdit, SW_HIDE);
			ShowWindow(btnDelete, SW_HIDE);
			ShowWindow(hStatMAIN, SW_HIDE);
			ShowWindow(hStat, SW_SHOWNORMAL);
			ShowWindow(searchEdit, SW_SHOWNORMAL);
			ShowWindow(btnSearch, SW_SHOWNORMAL);
			ShowWindow(hStatSEARCH, SW_SHOWNORMAL);
			ShowWindow(btnBack, SW_SHOWNORMAL);
			ShowWindow(btnDeleteOK, SW_SHOWNORMAL);
			ShowWindow(deleteEdit, SW_SHOWNORMAL);
			strcpy(strExit, "");
			int fl = 0;
			ifstream in(path);
			if (in.is_open())
			{
				strcat(strExit, "№\t|Фамилия\t|Имя\t\t|Назв.города\t|Назв.улицы\t\t|№Дом\t|");
				strcat(strExit, "\n");
				strcat(strExit, LIIIIIIIIIIIIIINE);
				strcat(strExit, "\n");
				while (getline(in, line))
				{
					++fl;
					if (isStrInLine(line, searchSTR)) {
						strcat(strExit, IntToStr(fl));
						strcat(strExit, "\t|");
						strcat(strExit, line.c_str());
						strcat(strExit, "\n");
					}
				}
			}
			in.close();
			SetWindowTextA(hStat, strExit);
		}
		if (lparam == (LPARAM)btnBack)
		{
			ShowWindow(btnShow, SW_SHOWNORMAL);
			ShowWindow(btnFile, SW_SHOWNORMAL);
			ShowWindow(btnAdd, SW_SHOWNORMAL);
			ShowWindow(btnEdit, SW_SHOWNORMAL);

			ShowWindow(hStat, SW_HIDE);
			ShowWindow(btnBack, SW_HIDE);
			ShowWindow(btnAddOK, SW_HIDE);
			ShowWindow(btnEditOK, SW_HIDE);
			ShowWindow(btnDeleteOK, SW_HIDE);
			ShowWindow(deleteEdit, SW_HIDE);
			ShowWindow(btnSearch, SW_HIDE);
			ShowWindow(hStatSEARCH, SW_HIDE);
			ShowWindow(searchEdit, SW_HIDE);
			ShowWindow(Edit1, SW_HIDE);
			ShowWindow(Edit2, SW_HIDE);
			ShowWindow(Edit3, SW_HIDE);
			ShowWindow(Edit4, SW_HIDE);
			ShowWindow(Edit5, SW_HIDE);
			ShowWindow(Edit6, SW_HIDE);
		}

		break;
	case WM_DESTROY:
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
	default:
		return DefWindowProc(hwnd, Message, wparam, lparam);
	}
	return 0;
}
