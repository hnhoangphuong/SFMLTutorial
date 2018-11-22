#include "ResourcesManager.h"

ResourcesManager::~ResourcesManager() {
	for (auto pair : *m_textureCacher) {
		// pair.second->Destroy();
	}
	delete m_textureCacher;
}

ResourcesManager::ResourcesManager() {
	m_textureCacher = new std::map<const char *, Texture*>;
}

ResourcesManager * ResourcesManager::s_Instance = 0;
ResourcesManager *ResourcesManager::getInstance() {
	if (!s_Instance) {
		s_Instance = new ResourcesManager();
	}
	return s_Instance;
}

Texture* ResourcesManager::cacheImage(const char *imgName)
{
	Texture *texture = nullptr;

	// LOAD CACHE
	if (m_textureCacher->size()) {
		for (auto pair : *m_textureCacher) {
			if (strcmp(pair.first, imgName) == 0) {
				texture = m_textureCacher->at(imgName);
				// SDL_QueryTexture(texture, NULL, NULL, &w, &h);
				break;
			}
		}
	}

	// ADD OBJECT TO POOL
	if (!texture) {
		// A.Phuong TODO CHECK
		texture = new Texture();
		texture->loadFromFile(imgName);
		if (texture) {
			std::pair<const char *, Texture*> pair(imgName, texture);
			m_textureCacher->insert(pair);
		}
	}
	return texture;
}
