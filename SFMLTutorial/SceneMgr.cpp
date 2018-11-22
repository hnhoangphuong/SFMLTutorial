#include "SceneMgr.h"

SceneMgr* SceneMgr::m_pInstance = NULL;//nullptr
SceneMgr* SceneMgr::GetInstance()
{
	if (m_pInstance == NULL)
	{
		m_pInstance = new SceneMgr();
	}
	return m_pInstance;
}

SceneMgr::SceneMgr()
{
}

SceneMgr::~SceneMgr()
{
	if (m_pInstance != NULL)
	{
		delete SceneMgr::GetInstance()->m_pInstance;
		SceneMgr::GetInstance()->m_pInstance = 0;
	}

	if (m_sCurrentScene != NULL)
	{
		delete m_sCurrentScene;
		m_sCurrentScene = 0;
	}
}
void SceneMgr::Init()
{
	m_sCurrentScene = new GameScene();
	m_sCurrentScene->Init();

}
void SceneMgr::Update(float deltime)
{
	m_sCurrentScene->Update(deltime);
}

void SceneMgr::Render(RenderWindow &window)
{
	m_sCurrentScene->Render(window);
}

Scene* SceneMgr::GetCurrentScene()
{
	return m_sCurrentScene;
}