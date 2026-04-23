#include "Screen.h"

//初期化
void Screen::Init()
{
	//画面位置初期化
	m_pos = {0,0};

	//画面振動初期化
	m_shakePow = 0.0f;
	m_shakeSub = 0.0f;
	m_offSet = { 0,0 };
}

//更新
void Screen::Update()
{
	//画面振動
	if (m_shakePow > 0)
	{
		m_offSet = { m_shakePow * (1 - (rand() % 2) * 2),m_shakePow * (1 - (rand() % 2) * 2) };
		m_shakePow -= m_shakeSub;
	}
	else
	{
		m_shakePow = 0.0f;
		m_shakeSub = 0.0f;
		m_offSet = { 0,0 };
	}

	//移動行列
	m_mat = Math::Matrix::CreateTranslation(m_pos.x + m_offSet.x, m_pos.y + m_offSet.y, 0);
}

//レンダーターゲット変更
void Screen::DynamicDraw()
{
	m_tex.ClearRenderTarget(Math::Color(0.0f, 0.0f, 0.0f, 0.0f));
	m_tex.SetRenderTarget();
}

//描画
void Screen::Draw()
{
	SHADER.m_spriteShader.SetMatrix(m_mat);
	SHADER.m_spriteShader.DrawTex(&m_tex, Math::Rectangle(0, 0, 1280, 720), 1.0f);
}

//画面振動
void Screen::Shake(float power, float subtract)
{
	m_shakePow = power;
	m_shakeSub = subtract;
}