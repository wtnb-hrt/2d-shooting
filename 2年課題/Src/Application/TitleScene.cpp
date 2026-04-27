#include "TitleScene.h"

//‰Šú‰»
void TitleScene::Init()
{

}

//XV
void TitleScene::Update()
{
	Test();
}

//•`‰æ
void TitleScene::Draw()
{
	Math::Color color;
	color = { 0,0,0,1.0f };
	SHADER.m_spriteShader.DrawBox(0, 0, 320, 180, &color, true);
}
