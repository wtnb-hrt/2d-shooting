#include "Player.h"

//初期化
void Player::Init()
{
	m_hp		= 3;
	m_ang		= 90.0f;
	m_rot		= 0.0f;
	m_moveX		= 0.0f;
	m_moveY		= 0.0f;
	m_aliveFlg  = true;
	m_activeFlg = true;
	m_pos		= {0,0};
}

//更新
void Player::Update()
{
	//生存フラグ、アクティブフラグ確認
	if (!m_aliveFlg || !m_activeFlg)
	{
		return;
	}

	//回転量リセット
	m_rot = 0.0f;

	//加速、減速
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		m_speed += m_speedAdd;

		//スピード上限設定
		if (m_speed > m_maxSpeed)
		{
			m_speed = m_maxSpeed;
		}
	}
	else
	{
		if (m_speed > 0.0f)
		{
			m_speed -= m_speedSub;
		}
		if (m_speed < 0.0f)
		{
			m_speed = 0.0f;
		}
	}

	//回転
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		m_rot = rotSpeed;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		m_rot = -rotSpeed;
	}

	//ショット

	//座標、回転更新
	m_ang += m_rot;

	m_moveX = cos(ToRadians(m_ang)) * m_speed;
	m_moveY = sin(ToRadians(m_ang)) * m_speed;

	m_pos.x += m_moveX;
	m_pos.y += m_moveY;

	//角度調整
	if (m_ang < 0)
	{
		m_ang += 360.0f;
	}
	if (m_ang >= 360)
	{
		m_ang -= 360.0f;
	}

	//行列
	m_rotMat = Math::Matrix::CreateRotationZ(ToRadians(m_ang-90));	//元画像が270度方向が正面のため調整
	m_transMat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);
	m_mat = m_rotMat * m_transMat;

	//死亡処理
	if (m_hp <= 0)
	{
		m_aliveFlg = false;
	}
}

//描画
void Player::Draw()
{
	//生存確認
	if (!m_aliveFlg)
	{
		return;
	}

	//行列
	SHADER.m_spriteShader.SetMatrix(m_mat);
	SHADER.m_spriteShader.DrawTex(m_tex, { 0,0,64,64 }, 1.0f);
}
