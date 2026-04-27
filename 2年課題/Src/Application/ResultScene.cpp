#include "ResultScene.h"

//‰Šú‰»
void ResultScene::Init()
{

}

//XV
void ResultScene::Update()
{
	Test();
}

//•`‰æ
void ResultScene::Draw()
{
	Math::Color color;
	color = { 1.0f,0,0,1.0f };
	SHADER.m_spriteShader.DrawBox(0, 0, 320, 180, &color, true);
}