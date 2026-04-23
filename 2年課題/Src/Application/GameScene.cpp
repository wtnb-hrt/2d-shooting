#include "GameScene.h"

//‰Šú‰»
void GameScene::Init()
{

}

//XV
void GameScene::Update()
{

}

//•`‰æ
void GameScene::Draw()
{
	Math::Color color;
	color = { 0,0,1.0f,1.0f };
	SHADER.m_spriteShader.DrawBox(0, 0, 320, 180, &color, true);
}
