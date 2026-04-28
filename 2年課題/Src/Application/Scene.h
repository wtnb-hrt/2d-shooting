#pragma once

//前方宣言
class SceneBase;
class Screen;

class Scene
{
private:

	//インスタンス
	std::shared_ptr<SceneBase>m_sceneBase;
	std::shared_ptr<Screen>m_screen;

public:

	// 初期設定
	void Init();

	// 解放
	void Release();

	// 更新処理
	void Update();

	//テクスチャへ描画
	void DynamicDraw2D();

	// 描画処理
	void Draw2D();

	// GUI処理
	void ImGuiUpdate();

	//シーン遷移
	void SetScene(int scene);

	//テクスチャ
	KdTexture m_playerTex;

private:

	Scene() {}

public:
	static Scene& GetInstance()
	{
		static Scene instance;
		return instance;
	}
};

#define SCENE Scene::GetInstance()
