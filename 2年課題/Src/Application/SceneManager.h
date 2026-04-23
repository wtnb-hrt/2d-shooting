#pragma once

class SceneManager
{
public:

	enum scene
	{
		Title,
		Game,
		Result
	};

	SceneManager() {}
	~SceneManager() {}

	void Init() {m_nowScene = Title ; }
	void SetScene(int val) { m_nowScene = val; }
	int  GetScene() { return m_nowScene; }

private:

	int m_nowScene;
};
