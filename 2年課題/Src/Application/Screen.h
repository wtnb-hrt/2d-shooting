#pragma once

class Screen
{
public:
	Screen() { m_tex.CreateRenderTarget(1280, 720); }
	~Screen() {}

	void Init();
	void Update();
	void DynamicDraw();
	void Draw();

	//‰æ–ÊU“®
	//‘æˆêˆø”FU“®‚Ì‹­‚³
	//‘æ“ñˆø”F‹­‚³‚ÌŒ¸­—¦
	void Shake(float power, float subtract);

private:
	Math::Vector2 m_pos;
	Math::Vector2 m_offSet;
	Math::Matrix  m_mat;
	KdTexture	  m_tex;
	float		  m_shakePow;
	float		  m_shakeSub;
};