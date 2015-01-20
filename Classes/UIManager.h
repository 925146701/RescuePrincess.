#pragma once


#include <map>
#include <string>
#include "cocos2d.h"

using namespace std;
USING_NS_CC;



class UIManager :public Ref
{
public:
	static UIManager* getInstance();

	
	void replaceScene(string sceneName);
	Layer *getLayerByName(string layerName);
	string getMusicName(string music);
	string getEffectsName(string effects);


	~UIManager();

private:
	UIManager();
	void load();
private:
	map<string, string> _gameMusic;
	map<string, string> _gameEffects;

	map<string, Scene*> _scene;
	map<string, Layer*> _layer;
};