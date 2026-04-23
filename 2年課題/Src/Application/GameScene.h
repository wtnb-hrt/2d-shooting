#pragma once
#include "BaseScene.h" 

class GameScene :public BaseScene
{
public:
	GameScene() {}
	~GameScene() {}

	void Init()   override;
	void Update() override;
	void Draw()   override;
};