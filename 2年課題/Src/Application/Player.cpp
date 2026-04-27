#include "Player.h"

//‰Šú‰»
void Player::Init()
{

}

//XV
void Player::Update()
{

}

//•`‰æ
void Player::Draw()
{
	SHADER.m_spriteShader.DrawTex(m_tex, { 0,0,64,64 }, 1.0f);
}
