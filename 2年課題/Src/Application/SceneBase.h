#pragma once

class SceneBase
{
public:
	SceneBase() {}
	~SceneBase() {}

	virtual void Init() {};
	virtual void Update() {};
	virtual void Draw() {};
};