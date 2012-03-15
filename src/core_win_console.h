/*
==================================================================

						Core Debug Console Header

==================================================================
*/

// -- NOTE --
// This debug code taken from BlackFyre game engine.
// Adapted into the Perdix engine.
// http://core1.saintjoe.edu/wiki/Blackfyre

#ifdef _DEBUG
#ifdef WIN32

#ifndef CCONSOLE_H
#define CCONSOLE_H

#include <sstream>
#include <windows.h>

#define BUFFERSIZE 256

enum MessageTypes	{MSG_NORMAL, MSG_DIAG, MSG_ALERT, MSG_ERROR};
enum ConsoleColors	{BLACK, DARKBLUE, DARKGREEN, DARKCYAN, DARKRED, DARKMAGENTA, DARKYELLOW, DEFAULT, GREY, BLUE, GREEN, CYAN, RED, MAGENTA, YELLOW, WHITE};
enum SpecialChars {BACKSPACE = 0, RETURN = 3, CARRIAGERETURN = 7};

class CConsole {
public:
	static CConsole Console;

	CConsole();

	void init();
	void cleanUp();

	void Print(std::string message, unsigned messageType);
	void Read(bool initial = false);

	HANDLE in;
	HANDLE out;

private:
	void ProcessBuffer();
	void ClearBuffer();

	char buffer[BUFFERSIZE];
	unsigned bufferPos;
	char *writeChars;

	DWORD numEvents;
	DWORD numRead;
	DWORD numWritten;
};

#endif

#endif
#endif