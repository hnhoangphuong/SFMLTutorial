#include "GameScene.h"
#include "ResourcesManager.h"

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
	if (m_pPlayer != NULL)
	{
		delete m_pPlayer;
		m_pPlayer = 0;
	}
}

void GameScene::Init()
{
	//Font font;
	//font.loadFromFile("../Resources/Fonts/Dosis-Light.ttf");
		
	//scoreText.setFont(font);
	//scoreText.setCharacterSize(20);
	//scoreText.setFillColor(Color::White);
	//scoreText.setPosition(10.f, 10.f);

	////player HP
	//hpText.setFont(font);
	//hpText.setCharacterSize(12);
	//hpText.setFillColor(Color::White);

	////enemy HP
	//eHpText.setFont(font);
	//eHpText.setCharacterSize(12);
	//eHpText.setFillColor(Color::White);

	////gameover
	//gameOverText.setFont(font);
	//gameOverText.setCharacterSize(30);
	//gameOverText.setFillColor(Color::Red);
	//gameOverText.setPosition(100.f, WINDOWS_H / 2);
	//gameOverText.setString("GAME OVER!");
	
	// ALL PATH LINK SHOULD BE LOAD FROM TXT BY RESOUCEMANGER
	//background
	if (!m_textureBackground.loadFromFile("../Resources/Assets/Background/SpaceBackground-70.jpg"))
		cout << "Error : Failed to load backgroud" << endl;
	else
	{
		m_vecTextureSize = m_textureBackground.getSize();
		m_vecWindowSize = Vector2u(WINDOWS_W, WINDOWS_H);
		float ScaleX = (float)m_vecWindowSize.x / m_vecTextureSize.x;
		float ScaleY = (float)m_vecWindowSize.y / m_vecTextureSize.y;

		m_spriteBackground.setTexture(m_textureBackground);
		m_spriteBackground.setScale(ScaleX, ScaleY);
	}
	
	//Player
	m_pPlayer = new Player(CacheImageName(PATH_TEXTURE_PLAYER),
		Vector2f(0.f, WINDOWS_H/2));

	//Enemy texture
	if(!m_textureEnemy.loadFromFile("../Resources/Assets/SpaceShips/F2.png"))
		cout << "Error : Failed to load Enemy" << endl;

}
void GameScene::Render(RenderWindow &window)
{
		//background
		window.draw(m_spriteBackground);

		//Player
		m_pPlayer->Render(window);

		//enemies
		for (size_t i = 0; i < m_vEnemyList.size(); i++)
		{
			m_vEnemyList[i].Render(window);
		}
		//window.draw(scoreText);
		//window.draw(hpText);
}
	

void GameScene::Update(float deltime)
{
	if (m_pPlayer->m_iHP > 0)
	{
		
		//hpText.setPosition(m_pPlayer->m_spritePlayer.getPosition().x, m_pPlayer->m_spritePlayer.getPosition().y - hpText.getGlobalBounds().height);
		//hpText.setString(std::to_string(m_pPlayer->m_iHP) + "/" + std::to_string(m_pPlayer->m_iHPMax));

		////Update shooting
		m_pPlayer->Update(deltime);

		////Bullets
		for (size_t i = 0; i < m_pPlayer->bullets.size(); i++)
		{
			//Move
			m_pPlayer->bullets[i].m_spriteBullet.move(1000.f * deltime, 0.f);

			//Out of window bounds
			if (m_pPlayer->bullets[i].m_spriteBullet.getPosition().x > WINDOWS_W)
			{
				m_pPlayer->bullets.erase(m_pPlayer->bullets.begin() + i);
				break;
			}

			//Enemy collision
			for (size_t k = 0; k < m_vEnemyList.size(); k++)
			{
				if (m_pPlayer->bullets[i].m_spriteBullet.getGlobalBounds().intersects(m_vEnemyList[k].m_spriteEnemy.getGlobalBounds()))
				{
					if (m_vEnemyList[k].m_iHP <= 1)
					{
						m_iScore += m_vEnemyList[k].m_iHPMax;
						m_vEnemyList.erase(m_vEnemyList.begin() + k);
					}
					else
						m_vEnemyList[k].m_iHP--; //ENEMY TAKE DAMAGE

					m_pPlayer->bullets.erase(m_pPlayer->bullets.begin() + i);
					break;
				}
			}
		}

		//Enemy
		if (m_fEnemySpawnTimer < 25)
			m_fEnemySpawnTimer += 62.f * deltime;

		//enemy spawn
		if (m_fEnemySpawnTimer >= 25)
		{
			m_vEnemyList.push_back(Enemy(&m_textureEnemy, Vector2f(WINDOWS_W + 100.0f, rand() % (int)WINDOWS_H - 70.f)));
			m_fEnemySpawnTimer = 0; //reset timer
		}

		for (size_t i = 0; i < m_vEnemyList.size(); i++)
		{
			m_vEnemyList[i].m_spriteEnemy.move(-360.f * deltime, 0.f);

			if (m_vEnemyList[i].m_spriteEnemy.getPosition().x <= 0 - m_vEnemyList[i].m_spriteEnemy.getGlobalBounds().width)
			{
				m_vEnemyList.erase(m_vEnemyList.begin() + i);
				break;
			}

			if (m_vEnemyList[i].m_spriteEnemy.getGlobalBounds().intersects(m_pPlayer->m_spritePlayer.getGlobalBounds()))
			{
				m_vEnemyList.erase(m_vEnemyList.begin() + i);

				m_pPlayer->m_iHP--; // PLAYER TAKE DAMAGE
				break;
			}
		}

		//UI Update
		//scoreText.setString("Score: " + std::to_string(score));
	}

	//if (m_pPlayer->m_iHP <= 0)
		//window.draw(gameOverText);
}
