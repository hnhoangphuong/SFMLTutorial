#include "GameWindow.h"
GameWindow * GameWindow::m_pInstance = nullptr;

GameWindow * GameWindow::GetInstance()
{
	if (m_pInstance == nullptr)
	{
		m_pInstance = new GameWindow();
	}
	return m_pInstance;
}


void GameWindow::Init(char* windowName)
{
	m_renderWindow.create(VideoMode(WINDOWS_W, WINDOWS_H), windowName, Style::Default);
}

void GameWindow::SetLimitFPS(unsigned int limitFPS)
{
	m_renderWindow.setFramerateLimit(limitFPS);
}

void GameWindow::Display()
{
	m_renderWindow.display();
}

bool GameWindow::IsDisplayed()
{
	return m_renderWindow.isOpen();
}

bool GameWindow::EventListener(Event &event)
{
	return m_renderWindow.pollEvent(event);
}

void GameWindow::Close()
{
	m_renderWindow.close();
}

void GameWindow::Clear()
{
	m_renderWindow.clear();
}

GameWindow::~GameWindow()
{
}

GameWindow::GameWindow()
{
}
