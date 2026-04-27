#pragma once

//‘O•ûéŒ¾
class Scene;

class SceneBase
{
public:

	SceneBase():m_owner(nullptr) { m_playerTex.Load("Textures/player.png"); }
	~SceneBase() { m_playerTex.Release(); }

	virtual void Init() {};
	virtual void Update() {};
	virtual void Draw() {};
	virtual void Release() {};
	void SetOwner(Scene* owner) {m_owner = owner ; }

	void Test();

protected:

	Scene *m_owner;

	KdTexture m_playerTex;

};