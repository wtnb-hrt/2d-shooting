#pragma once

static class TextureLoader
{
public:

	static KdTexture m_playerTex;
	static void LoadTex() { m_playerTex.Load("Textures/player.png"); }
	static void ReleaseTex() { m_playerTex.Release(); }

private:

};