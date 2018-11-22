#pragma once

#include "Scene.h"
#include "GameScene.h"

class SceneMgr
{
public:
	static SceneMgr* GetInstance();
	void Update(float deltime);
	void Render(RenderWindow &window);
	void Init();
	Scene* GetCurrentScene();
	~SceneMgr();

private:
	SceneMgr();

	static SceneMgr* m_pInstance;
	Scene *m_sCurrentScene;
	Scene * m_sNewScene;

	
};

