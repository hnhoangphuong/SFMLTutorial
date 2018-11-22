#pragma once

#include "Bullet.h"
#include "Object.h"
class Player : public Object
{
public:
	Player();
	~Player();

	char* m_pObjectPath;

	int m_iHP;
	int m_iHPMax;
	float m_fShootTimer = 20.0f;

	Sprite m_spritePlayer;

	Texture m_textureBullet;

	vector<Bullet> bullets;
	
	Player(Texture *texture, Vector2f pos);
	void Init(Texture *texture);
	void Update(float deltime);
	void Render(RenderWindow &window);
	void CheckCollisionPlayerWindow();
	void Shooting(float deltime);
};

