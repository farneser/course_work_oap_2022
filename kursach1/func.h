#pragma once
#include "framework.h"
#include <string>

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

// length of the string  
int len(std::string strEAXCSAE) {
	int length = 0;
	for (int i = 0; strEAXCSAE[i] != '\0'; i++)
	{
		length++;
	}
	return length;
}
using namespace std;
// custom split() function  
string* split(string str, char *seperator)
{
	string* array = new string[6];
	int currIndex = 0, i = 0;
	int startIndex = 0, endIndex = 0;
	while (i <= len(str)-4)
	{
		if (str[i] == str[i] == seperator[0] || seperator[1]|| str[i] == seperator[2] || str[i] == seperator[3] || i == len(str))
		{
			endIndex = i;
			string subStr = "";
			subStr.append(str, startIndex, endIndex - startIndex);
			array[currIndex] = subStr;
			currIndex += 1;
			startIndex = endIndex + 1;
		}
		i++;
	}
	return array;
}


