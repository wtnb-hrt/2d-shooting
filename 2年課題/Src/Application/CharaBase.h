#pragma once

class CharaBase
{
public:

	CharaBase() {}
	~CharaBase() {}

	void Init();
	void Draw();
	void Update();

protected:

	int				m_hp;
	float			m_ang;
	float			m_rot;
	Math::Vector2   m_pos;
	Math::Matrix	m_rotMat;

	KdTexture m_tex;
};
