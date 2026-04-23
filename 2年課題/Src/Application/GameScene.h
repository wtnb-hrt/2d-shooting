#pragma once
#include "SceneBase.h" 

class GameScene :public SceneBase
{
public:
	GameScene() {}
	~GameScene() {}

	void Init()   override;
	void Update() override;
	void Draw()   override;
};