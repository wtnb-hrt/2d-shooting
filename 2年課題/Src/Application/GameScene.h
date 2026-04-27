#pragma once
#include "SceneBase.h" 

//前方宣言
class Player;

class GameScene :public SceneBase
{
public:

	GameScene() {};
	~GameScene() {};

	void Init()    override;
	void Update()  override;
	void Draw()    override;
	void Release() override;

private:

	//インスタンス 
	Player* m_player;
	//std::vector<Enemy*>m_enemy;

};