#pragma once
#include "SceneBase.h" 

class TitleScene :public SceneBase
{
public:
	TitleScene() {}
	~TitleScene() {}

	void Init()   override;
	void Update() override;
	void Draw()   override;
};