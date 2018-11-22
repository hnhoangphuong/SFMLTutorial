#pragma once

#include <map> 
#include "Object.h"

#if _DEBUG
#define ROOT "../Resources"
#else
#define ROOT "Resources"
#endif // DEBUG

#define PATH_TEXTURE_BACKGROUND ""

#define PATH_TEXTURE_PLAYER std::string(std::string(ROOT) + std::string("/Assets/mc.png")).c_str()

#define CacheImageName(imgN) ResourcesManager::getInstance()->cacheImage(imgN)
// #define CacheImageName(imgN, w, h) ResourcesManager::getInstance()->cacheImage(imgN, w, h);

class ResourcesManager
{
public:
	ResourcesManager();
	~ResourcesManager();

	static ResourcesManager * getInstance();

	Texture *cacheImage(const char *imgName);
private:
	static ResourcesManager * s_Instance;

	std::map<const char *, Texture*> *m_textureCacher;
};