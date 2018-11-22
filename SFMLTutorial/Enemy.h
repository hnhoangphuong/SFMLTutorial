#pragma once

#include "Config.h"

class Enemy
{
public:
	Sprite m_spriteEnemy;

	int m_iHP;
	int m_iHPMax;
	
	Enemy(Texture *texture, Vector2f pos)
	{
		m_iHPMax = rand() % 3 + 1;
		m_iHP = m_iHPMax;

		m_spriteEnemy.setTexture(*texture);
		m_spriteEnemy.setRotation(90);
		m_spriteEnemy.setPosition(pos);
	}
	~Enemy();
	void Render(RenderWindow &window);
};

