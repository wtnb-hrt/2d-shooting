#pragma once

//前方宣言
class SceneBase;
class Screen;
class Player;

class Scene
{
private:

	// テクスチャ ・・・ 画像データ
	KdTexture charaTex;

	// 行列 ・・・ 座標などの情報
	Math::Matrix matrix;

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

	//インスタンス
	std::shared_ptr<SceneBase>m_sceneBase;
	std::shared_ptr<Screen>m_screen;

	//std::vector<Player*>m_player;

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
