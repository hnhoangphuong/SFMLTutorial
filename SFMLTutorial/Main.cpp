// SFMLTutorial.cpp : Defines the entry point for the console application.
//
///////////////////////////////////////////

#include <math.h>
#include <cstdlib>
#include <vector>
#include <ctime> 

#include "SceneMgr.h"
#include "GameWindow.h"
#include <Windows.h>


void main()
{
	srand((unsigned int)time(NULL));

	GameWindow::GetInstance()->Init(WINDOWS_NAME);
	GameWindow::GetInstance()->SetLimitFPS(200);

	SceneMgr::GetInstance()->Init();

	DWORD start, end;
	DWORD deltaTime;
	start = GetTickCount();

	while (GameWindow::GetInstance()->IsDisplayed())
	{
		Event event;
		while (GameWindow::GetInstance()->EventListener(event));
		{
			if (event.type == Event::Closed)
				GameWindow::GetInstance()->Close();
		}

		end = GetTickCount();
		deltaTime = end - start;

		//UPDATE =========================UPDATE========================================== 
		SceneMgr::GetInstance()->Update((float)deltaTime / 1000.0f);

		//Draw ============================DRAW=========================================== 
		GameWindow::GetInstance()->Clear();
		SceneMgr::GetInstance()->Render(GameWindow::GetInstance()->m_renderWindow);
		GameWindow::GetInstance()->Display();
		start = end;

	}
}