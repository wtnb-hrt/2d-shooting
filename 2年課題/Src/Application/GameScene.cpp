#include "GameScene.h"
#include "Player.h"
#include "Scene.h"

//初期化
void GameScene::Init()
{
	//プレイヤー
	m_player = new Player;
	m_player->Init();
	m_player->SetTex(&m_owner->m_playerTex);
}

//更新
void GameScene::Update()
{
	m_player->Update();

	Test();
}

//描画
void GameScene::Draw()
{
	m_player->Draw();
}

//解放処理
void GameScene::Release()
{
	if (m_player)
	{
		delete m_player;
		m_player = nullptr;
	}
}
