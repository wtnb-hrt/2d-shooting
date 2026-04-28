#pragma once

class ObjectBase
{
public:

	ObjectBase() {}
	~ObjectBase() {}

	virtual void Init();
	virtual void Update();
	virtual void Draw();
	void SetTex(KdTexture *tex) { m_tex = tex; }
	void SetActive(bool active) { m_activeFlg = active; }	//キャラクターの静止状態を管理する
	int GetHp() { return m_hp; }

protected:

	int				m_hp;
	float			m_ang;
	float			m_rot;
	float			m_moveX;
	float			m_moveY;
	bool			m_aliveFlg;
	bool			m_activeFlg;
	Math::Vector2   m_pos;
	Math::Matrix	m_rotMat;
	Math::Matrix    m_transMat;
	Math::Matrix    m_mat;

	KdTexture       *m_tex;
};
