// SFMLTutorial.cpp : Defines the entry point for the console application.
//
///////////////////////////////////////////

#include <math.h>
#include <cstdlib>
#include <vector>
#include <ctime> 

#include "SceneMgr.h"

void main()
{
	srand((unsigned int)time(NULL));
	RenderWindow window(VideoMode(WINDOWS_W, WINDOWS_H), "Spaceship Game!", Style::Default);
	window.setFramerateLimit(200);

	SceneMgr::GetInstance()->Init();

	Clock clock;
	Time elapsed;
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		elapsed = clock.getElapsedTime();

		//UPDATE =========================UPDATE========================================== 
		SceneMgr::GetInstance()->Update(elapsed.asSeconds());

		clock.restart();

		//Draw ============================DRAW=========================================== 
		window.clear();
		SceneMgr::GetInstance()->Render( window);
		window.display();
	}
}