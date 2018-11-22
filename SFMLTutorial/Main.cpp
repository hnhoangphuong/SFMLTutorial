// SFMLTutorial.cpp : Defines the entry point for the console application.
//
///////////////////////////////////////////

#include <math.h>
#include <cstdlib>
#include <vector>
#include <ctime> 

#include "SceneMgr.h"
#include "Windows.h"

void main()
{
	srand((unsigned int)time(NULL));
	//RenderWindow window(VideoMode(WINDOWS_W, WINDOWS_H), "Spaceship Game!", Style::Default);
	Windows::GetInstance()->Init(WINDOWS_NAME);
	//window.setFramerateLimit(200);
	Windows::GetInstance()->SetLimitFPS(200);

	SceneMgr::GetInstance()->Init();

	Clock clock;
	Time elapsed;
	while (Windows::GetInstance()->IsDisplayed())
	{
		Event event;
		while (Windows::GetInstance()->EventListener(event));
		{
			if (event.type == Event::Closed)
				Windows::GetInstance()->Close();
		}

		elapsed = clock.getElapsedTime();

		//UPDATE =========================UPDATE========================================== 
		SceneMgr::GetInstance()->Update(elapsed.asSeconds());

		clock.restart();

		//Draw ============================DRAW=========================================== 
		Windows::GetInstance()->Clear();
		SceneMgr::GetInstance()->Render(Windows::GetInstance()->m_renderWindow);
		Windows::GetInstance()->Display();
	}
}