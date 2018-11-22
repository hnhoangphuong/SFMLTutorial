#include "Player.h"


Player::Player()
{
}


Player::~Player()
{
}
Player::Player(Texture *texture, Vector2f pos)
{
	m_iHPMax = 10;
	m_iHP = m_iHPMax;

	m_spritePlayer.setTexture(*texture);
	m_spritePlayer.setScale(0.25f, 0.25f);
	m_spritePlayer.setRotation(90);
	m_spritePlayer.setPosition(pos);

	if(!m_textureBullet.loadFromFile("../Resources/Assets/Bullets/goldBulletDown.png"))
		cout << "Error : Failed to load Bullet" << endl;
}

void Player::Init(Texture *window)
{}

void Player::Render(RenderWindow &window)
{
	//player
	window.draw(m_spritePlayer);

	//bullets
	for (size_t i = 0; i < bullets.size(); i++)
	{
		window.draw(bullets[i].m_spriteBullet);
	}

}
void Player::CheckCollisionPlayerWindow()
{
	if (m_spritePlayer.getPosition().x - m_spritePlayer.getGlobalBounds().height <= 0) //Left
		m_spritePlayer.setPosition(m_spritePlayer.getGlobalBounds().height, m_spritePlayer.getPosition().y);

	if (m_spritePlayer.getPosition().x >= WINDOWS_W - m_spritePlayer.getGlobalBounds().width) //Right
		m_spritePlayer.setPosition(WINDOWS_W - m_spritePlayer.getGlobalBounds().width, m_spritePlayer.getPosition().y);

	if (m_spritePlayer.getPosition().y <= 0) //Top
		m_spritePlayer.setPosition(m_spritePlayer.getPosition().x, 0.f);

	if (m_spritePlayer.getPosition().y >= WINDOWS_H - m_spritePlayer.getGlobalBounds().height) //Bottom
		m_spritePlayer.setPosition(m_spritePlayer.getPosition().x, WINDOWS_H - m_spritePlayer.getGlobalBounds().height);
}
void Player::Shooting(float deltime)
{
	if (m_fShootTimer < 15)
	{
		m_fShootTimer += deltime*62.0f;
	}

	//if (Mouse::isButtonPressed(Mouse::Left) && m_fShootTimer >= 15) //Click to Shooting
	if (m_fShootTimer >= 15) // Auto Shooting
	{
		bullets.push_back(Bullet(&m_textureBullet,
			Vector2f(m_spritePlayer.getPosition().x,
			m_spritePlayer.getPosition().y + m_spritePlayer.getGlobalBounds().width / 2 + 10.0f)));
		m_fShootTimer = 0; //reset timer
	}
}

void Player::Update(float deltime)
{
	//control Player
	if (Keyboard::isKeyPressed(Keyboard::W))
		m_spritePlayer.move(0.f, -600.f * deltime);
	if (Keyboard::isKeyPressed(Keyboard::A))
		m_spritePlayer.move(-600.f * deltime, 0.f);
	if (Keyboard::isKeyPressed(Keyboard::S))
		m_spritePlayer.move(0.f, 600.f * deltime);
	if (Keyboard::isKeyPressed(Keyboard::D))
		m_spritePlayer.move(600.f * deltime, 0.f);

	////Collision with window 
	CheckCollisionPlayerWindow();

	////shooting
	Shooting(deltime);
}
