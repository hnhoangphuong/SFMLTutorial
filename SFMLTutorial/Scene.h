#pragma once
#include "Config.h"

using namespace std;


class Scene
{
public:
	
	char* backgroundPath;
	Texture m_textureBackground;
	Sprite m_spriteBackground;
	Vector2u m_vecTextureSize;
	Vector2u m_vecWindowSize;

	Scene();
	~Scene();

	virtual void Update(float deltime){};
	virtual void Render(RenderWindow &window){};
	virtual void Init(){};
};

