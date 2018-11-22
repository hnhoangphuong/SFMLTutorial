// SFMLTutorial.cpp : Defines the entry point for the console application.
//
///////////////////////////////////////////

#include <math.h>
#include <cstdlib>
#include <vector>
#include <ctime> 

#include "SceneMgr.h"
#include "GameWindow.h"
#include "GameEvent.h"
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
		GameEvent event;
		while (GameWindow::GetInstance()->EventListener(event.m_event));
		{
			if (event.GetTypes() == EventTypes::Closed)
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