#pragma once

class CharaBase
{
public:

	CharaBase() {}
	~CharaBase() {}

	virtual void Init();
	virtual void Update();
	virtual void Draw();
	void SetTex(KdTexture *tex) { m_tex = tex; }
	void SetActive(bool active) { m_activeFlg = active; }	//キャラクターの静止状態を管理する

protected:

	int				m_hp;
	float			m_ang;
	float			m_rot;
	bool			m_aliveFlg;
	bool			m_activeFlg;
	Math::Vector2   m_pos;
	Math::Matrix	m_rotMat;

	KdTexture       *m_tex;
};
