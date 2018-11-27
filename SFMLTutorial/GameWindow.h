#pragma once
#include "Config.h"

class GameWindow
{
public:
	static GameWindow* GetInstance();

	RenderWindow m_renderWindow;
	void Init(char* windowName);
	void SetLimitFPS(unsigned int limitFPS);
	void Display();
	bool IsDisplayed();
	bool EventListener(Event &event);
	void Close();
	void Clear();


	~GameWindow();

private:
	GameWindow();

	static GameWindow* m_pInstance;

};