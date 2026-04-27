#pragma once

class SceneBase
{
public:

	SceneBase() { m_playerTex.Load("Textures/player.png"); }
	~SceneBase() { m_playerTex.Release(); }

	virtual void Init() {};
	virtual void Update() {};
	virtual void Draw() {};
	virtual void Release() {};

protected:

	KdTexture m_playerTex;

};