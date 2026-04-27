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
	//m_sceneBase->Test();

	//初期化
	m_sceneBase->Init();
	m_screen->Init();
}

void Scene::Release()
{
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
		m_sceneBase->Release();
		m_sceneBase = std::make_shared<TitleScene>();
		m_sceneBase->Init();
	}

	if (ImGui::Button("Game"))
	{
		m_sceneBase->Release();
		m_sceneBase = std::make_shared<GameScene>();
		m_sceneBase->Init();
	}

	if (ImGui::Button("Result"))
	{
		m_sceneBase->Release();
		m_sceneBase = std::make_shared<ResultScene>();
		m_sceneBase->Init();
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
