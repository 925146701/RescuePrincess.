#include "UIManager.h"

UIManager* UIManager::getInstance()
{
	static UIManager uiManager;
	return &uiManager;
}

void UIManager::load()
{
	//手动添加音乐名和音效
}

UIManager::UIManager(){}

UIManager::~UIManager()
{
	_gameMusic.clear();
	_gameEffects.clear();
}

void UIManager::replaceScene(string sceneName)
{
	auto iter = _scene.find(sceneName);
	if (iter == _scene.end())
	{
		return;
	}
	Director::getInstance()->replaceScene(iter->second);
}

Layer* UIManager::getLayerByName(string layerName)
{
	auto iter = _layer.find(layerName);
	return iter != _layer.end() ? iter->second : nullptr;
}

string UIManager::getMusicName(string music)
{
	auto iter = _gameMusic.find(music);
	return iter != _gameMusic.end() ? iter->second : "";
}
string UIManager::getEffectsName(string effects)
{
	auto iter = _gameEffects.find(effects);
	return iter != _gameEffects.end() ? iter->second : "";
}
