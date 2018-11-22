#pragma once
#include "Config.h"

class Bullet
{
public:
	Sprite m_spriteBullet;

	Bullet(Texture *texture, Vector2f pos)
	{
		m_spriteBullet.setTexture(*texture);
		m_spriteBullet.setScale(0.5f, 0.5f);
		m_spriteBullet.setPosition(pos);
		m_spriteBullet.setRotation(-90);
	}
	Bullet(){};
	~Bullet();
};

