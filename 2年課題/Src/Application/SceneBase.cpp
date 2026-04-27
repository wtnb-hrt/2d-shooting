#include "Scene.h"
#include "SceneBase.h"

void SceneBase::Test()
{
	if (GetAsyncKeyState('0') & 0x8000)
	{
		m_owner->SetScene(0);
	}
	else if (GetAsyncKeyState('1') & 0x8000)
	{
		m_owner->SetScene(1);
	}
}
