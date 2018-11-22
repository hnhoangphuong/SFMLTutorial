#pragma once

#include <map> 
#include "Object.h"

namespace res
{
	const char* BACKGROUND = "";
}

#define CacheImageName(imgN, w, h) ResourcesManager::getInstance()->cacheImage(imgN, w, h);

class ResourcesManager
{
public:
	ResourcesManager();
	~ResourcesManager();

	static ResourcesManager * getInstance();

	Texture *cacheImage(const char *imgName, int &w, int &h);
private:
	static ResourcesManager * s_Instance;

	std::map<const char *, Texture*> *m_textureCacher;
};