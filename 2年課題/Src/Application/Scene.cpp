#include "main.h"
#include "Scene.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "ResultScene.h"
#include "Screen.h"

void Scene::DynamicDraw2D()
{
	//レンダーターゲット変更
	m_screen->DynamicDraw();

	//描画
	m_sceneBase->Draw();
}

void Scene::Draw2D()
{
	//バックバッファへ描画
	D3D.SetBackBuffer();

	//画面の描画
	m_screen->Draw();
}

void Scene::Update()
{
	m_sceneBase->Update();
	m_screen->Update();

}

void Scene::Init()
{
	//乱数シャッフル
	srand(timeGetTime());

	//インスタンス生成
	m_sceneBase = std::make_shared<GameScene>();
	m_screen    = std::make_shared<Screen>();

	//テクスチャ読み込み
	m_playerTex.Load("Textures/player.png");

	//仮
	m_sceneBase->SetOwner(this);

	//初期化
	m_sceneBase->Init();
	m_screen->Init();
}

void Scene::Release()
{
	m_playerTex.Release();

	//シーン開放
	m_sceneBase->Release();
}

void Scene::ImGuiUpdate()
{
	//return;

	ImGui::SetNextWindowPos(ImVec2(20, 20), ImGuiSetCond_Once);
	ImGui::SetNextWindowSize(ImVec2(200, 100), ImGuiSetCond_Once);

	//シーン管理
	if (ImGui::Button("Title"))
	{
		SetScene(0);
	}

	if (ImGui::Button("Game"))
	{
		SetScene(1);
	}

	if (ImGui::Button("Result"))
	{
		SetScene(2);
	}

	//画面振動
	if (ImGui::Button("Shake"))
	{
		m_screen->Shake(5,0.2f);
	}

	// デバッグウィンドウ
	if (ImGui::Begin("Debug Window"))
	{
		ImGui::Text("FPS : %d", APP.m_fps);
	}
	ImGui::End();
}

void Scene::SetScene(int scene)
{
	m_sceneBase->Release();

	switch (scene)
	{
	case 0:

		m_sceneBase = std::make_shared<TitleScene>();

		break;
	case 1:

		m_sceneBase = std::make_shared<GameScene>();

		break;
	case 2:

		m_sceneBase = std::make_shared<ResultScene>();

		break;
	}

	m_sceneBase->SetOwner(this);
	m_sceneBase->Init();
}
