﻿#include "Title.h"
#include "../../Input/Input.hpp"
#include "SceneManager.hpp"
#include "../GameController.h"
#include "../../System/System.hpp"


namespace Scene
{
	Title::Title(IOnSceneChangeCallback* sceneTitleChange, [[maybe_unused]] const Parameter& parame, ECS::EntityManager* entityManager)
		: AbstractScene(sceneTitleChange)
		, entitytManager_(entityManager)
	{
		
	}
	void Title::update()
	{
		if (Input::Get().getKeyFrame(KEY_INPUT_X) == 1)
		{
			getCallBack().onSceneChange(SceneName::GAME, nullptr, StackPopFlag::POP);
			return;
		}
		
	}
	void Title::draw()
	{
		DrawFormatString(0, 0, 0xffffffff, "タイトル画面");
	}

}