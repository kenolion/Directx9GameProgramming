#include "Windows.h"
#include <windows.h>
#include <d3d9.h>
#include "Constants.h"
#include "Graphics.h"
#include "GameSprite.h"
#include "Game.h"
#include "Level1.h"
#include "LevelMainMenu.h"
#include "LevelPlayerWins.h"
#include "FlappyBird.h"
#include "GameStateManager.h"

#include <iostream>
#include <conio.h>


//CONSTANTS
#define WIN32_LEAN_AND_MEAN
//Global Player Sprites
LRESULT WINAPI WinProc(HWND, UINT, WPARAM, LPARAM);
Game * game;
GameStateManager * gamestatemanager;


void RedirectIOToConsole() //THE FUNCTION TO CREATE A CONSOLE BEN IF U READ THIS CODE EVENTUALLY
{
	FILE *conin, *conout;
	AllocConsole();
	freopen_s(&conin, "conin$", "r", stdin);
	freopen_s(&conout, "conout$", "w", stdout);
}



int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)   //Main function
{
	HWND hwnd;
	WNDCLASSEX wcex;
	MSG msg;

	RECT rect;
	rect.bottom = GetSystemMetrics(SM_CYSCREEN) / 2 - GAME_HEIGHT / 2 + GAME_HEIGHT;
	rect.right = (GetSystemMetrics(SM_CXSCREEN) / 2 - GAME_WIDTH / 2) + GAME_WIDTH;
	rect.left = GetSystemMetrics(SM_CXSCREEN) / 2 - GAME_WIDTH / 2;
	rect.top = GetSystemMetrics(SM_CYSCREEN) / 2 - GAME_HEIGHT / 2+50;

	ShowCursor(false);
	RedirectIOToConsole();
	wcex.cbSize = sizeof(wcex);
	wcex.cbClsExtra = 0;                 // no extra class memory				
	wcex.cbWndExtra = 0;                 // no extra window memory 
	wcex.lpfnWndProc = WinProc;
	wcex.hInstance = hInstance;
	wcex.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wcex.hIcon = NULL;
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = CLASS_NAME;
	wcex.hIconSm = NULL;


	if (RegisterClassEx(&wcex) == 0)    // if error
		return false;

	hwnd = CreateWindow(CLASS_NAME,
		GAME_TITTLE,
		WS_OVERLAPPEDWINDOW | WS_MINIMIZEBOX | WS_SYSMENU,
		GetSystemMetrics(SM_CXSCREEN) / 2 - GAME_WIDTH / 2,          // default horizontal position of window
		GetSystemMetrics(SM_CYSCREEN) / 2 - GAME_HEIGHT / 2,
		GAME_WIDTH,             // width of window
		GAME_HEIGHT,            // height of the window
		(HWND)NULL,            // no parent window
		(HMENU)NULL,           // no menu
		hInstance,              // handle to application instance
		(LPVOID)NULL);         // no window parameters

	ShowWindow(hwnd, nCmdShow);

	ZeroMemory(&msg, sizeof(MSG));

	//========================================================================================================================================================================

	

				//GameStates gameState = GameStates::MENU; 
				///	gamestatemanager->run(hwnd, gamestatemanager->gameState::MAINMENU);

					game = new LevelMainMenu(); //<--- use this to change level 

					game->initializeGame(hwnd);
			
					if (game->initialize == true) {
						while (msg.message != WM_QUIT) {
							if (msg.message == WM_QUIT)
								break;
							while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
								TranslateMessage(&msg);
								DispatchMessage(&msg);
							}
						    	ClipCursor(&rect);
								game->run();
						}
					}
		game->deleteAll();

		dltPtr(game);
	
	//========================================================================================================================================================================
	UnregisterClass(wcex.lpszClassName, hInstance);
	return msg.wParam;
	system("pause");
	return 0;
}


LRESULT WINAPI WinProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {		//Windows procedure

	return game->messageHandler(hwnd, msg, wParam, lParam);
}



