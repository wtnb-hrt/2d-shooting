#pragma once
#include "ObjectBase.h"

class Player :public ObjectBase
{
public:

	Player() {}
	~Player() {}

	void Init() override;
	void Update() override;
	void Draw() override;
	
private:

	float m_speed;
	
	//’è”
	const float rotSpeed	= 3.5f;
	const float m_speedAdd	= 0.15f;
	const float m_speedSub	= 0.08f;
	const float m_maxSpeed  = 8.0f;
};