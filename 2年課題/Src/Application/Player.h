#pragma once
#include "CharaBase.h"

class Player :public CharaBase
{
public:

	Player() {}
	~Player() {}

	void Init() override;
	void Update() override;
	void Draw() override;
	
private:

	
};