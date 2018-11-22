#pragma once
#include "Scene.h"
#include "Player.h"
#include "Enemy.h"
#include"SFML\Window.hpp"
#include"SFML\System.hpp"

class GameScene :
	public Scene
{
public:
	GameScene();
	~GameScene();

	void Render(RenderWindow &window);
	void Update(float deltime);
	void Init();


private:
	Player* m_pPlayer;
	Texture m_texturePlayer;

	std::vector<Enemy> m_vEnemyList;
	Texture m_textureEnemy;
	float m_fEnemySpawnTimer = 0.f;

	int m_iScore;


	//UI init
	//Text scoreText;
	//Text eHpText;
	//Text gameOverText;
	//Text hpText;
	
};

