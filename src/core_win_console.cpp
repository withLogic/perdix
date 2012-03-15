/*
==================================================================

						Perdix - Core Debug Console

==================================================================
*/

// -- NOTE --
// This debug code taken from BlackFyre game engine.
// Adapted into the Perdix engine.
// http://core1.saintjoe.edu/wiki/Blackfyre

#include "core.h"

#include <iostream>
#include <iomanip>

#ifdef CCONSOLE_H

CConsole CConsole::Console;

CConsole::CConsole() {
	in = NULL;
	out = NULL;
	writeChars = "\b \b\n > \r";
}

void CConsole::init() {
	AllocConsole();
	AttachConsole(ATTACH_PARENT_PROCESS);

	SetConsoleTitleA("Debug Console");

	in = GetStdHandle(STD_INPUT_HANDLE);
	out = GetStdHandle(STD_OUTPUT_HANDLE);

	bufferPos = 0;

	Print("CConsole::OnInit(): Console initialized", MSG_DIAG);
}

void CConsole::cleanUp() {
	FreeConsole();
}

void CConsole::Print(std::string message, unsigned messageType) {
	unsigned char color;
	switch(messageType) {
		case MSG_NORMAL:
			color = GREY;
			break;
		case MSG_DIAG:
			color = DARKCYAN;
			break;
		case MSG_ALERT:
			color = DARKYELLOW;
			break;
		case MSG_ERROR:
			color = DARKRED;
			break;
	}
	SetConsoleTextAttribute(out, color);

	std::stringstream messageStream;
	messageStream << '\r' << std::setw(2) << std::setfill('0') << SDL_GetTicks() / 1000 / 60 << ':' << std::setw(2) << std::setfill('0') << (SDL_GetTicks() / 1000)%60 << " - " << message;
	std::string newMessage = messageStream.str();

	DWORD numWritten;
	WriteConsoleA(out, newMessage.c_str(), newMessage.length(), &numWritten, NULL);

	SetConsoleTextAttribute(out, WHITE);
	WriteConsoleA(out, &writeChars[RETURN], 4, &numWritten, NULL);
}

void CConsole::Read(bool initial) {
	/*
	SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), ENABLE_PROCESSED_INPUT);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	DWORD numRead;
	CONSOLE_READCONSOLE_CONTROL control;

	ReadConsole(GetStdHandle(STD_INPUT_HANDLE), &buffer[bufferPos], 1, &numRead, &control);
	if(numRead > 0) {
		if(buffer[bufferPos] == '\n') {
			// check commands

			bufferPos = 0;
		}
		else
			bufferPos++;
	}
	*/

	//SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);

	/*
	if(initial) {
		//WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE), &writeChars[RETURN], 4, &numWritten, NULL);
	}
	*/
	GetNumberOfConsoleInputEvents(GetStdHandle(STD_INPUT_HANDLE), &numEvents);

	if(numEvents == 0)
		return;

	INPUT_RECORD *records = new INPUT_RECORD[numEvents];

	ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), records, numEvents, &numRead);
	for(DWORD i = 0; i < numRead; i++) {
		switch(records[i].EventType) {
			case KEY_EVENT: {
				if(records[i].Event.KeyEvent.bKeyDown) {
					switch(records[i].Event.KeyEvent.uChar.AsciiChar) {
						case '`':
							ClearBuffer();
							WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE), &writeChars[CARRIAGERETURN], 1, NULL, NULL);
							//CApp::App.Pause();
							ShowWindow(GetConsoleWindow(), SW_HIDE);
							break;
						case '\b':
							if(bufferPos > 0) {
								buffer[bufferPos-1] = '\0';
								bufferPos -= 1;
								WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE), &writeChars[BACKSPACE], 3, &numWritten, NULL);
							}

							break;
						case '\r':
							WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE), &writeChars[RETURN], 4, &numWritten, NULL);
							ProcessBuffer();
							ClearBuffer();
							break;

						default:
							if(records[i].Event.KeyEvent.uChar.AsciiChar >= 32 && records[i].Event.KeyEvent.uChar.AsciiChar <= 140 && bufferPos < BUFFERSIZE) {
								buffer[bufferPos] = records[i].Event.KeyEvent.uChar.AsciiChar;

								WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE), &buffer[bufferPos], 1, &numWritten, NULL);

								bufferPos++;
							}
							else if(bufferPos >= BUFFERSIZE)
								MessageBoxA(NULL, "Console Buffer is full!", "Error!", MB_OK | MB_ICONERROR | MB_TOPMOST);
					}
				}

				break;
			}
		}
	}

	delete records;
}

void CConsole::ProcessBuffer() {
	//if(!strcmp(buffer, "quit"))
		//CApp::App.Quit();
}

void CConsole::ClearBuffer() {
	for(unsigned i = 0; i < bufferPos; i++)
		buffer[i] = '\0';

	bufferPos = 0;
}
#endif