#include "Enemy.h"

Enemy::~Enemy()
{
}

void Enemy::Render(RenderWindow &window)
{
	window.draw(m_spriteEnemy);
}
