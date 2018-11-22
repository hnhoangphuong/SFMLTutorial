#pragma once
#include "Config.h"

class Object
{
public:
	char* m_pObjectPath;

	Texture m_ObjTexture;
	Sprite m_Object;

	Object();
	~Object();

	virtual void Init(Texture *texture) = 0;
	virtual void Render(RenderWindow &window) =0;
	virtual void Update(float deltime) =0;
};

