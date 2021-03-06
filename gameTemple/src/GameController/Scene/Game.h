﻿/**
* @file Game.hpp
* @brief ゲームシーンでの動作を記述します
* @author 
* @date 
*/
#pragma once
#include "../../ECS/ECS.hpp"
#include "Parameter.hpp"
#include "../Scene/SceneManager.hpp"

namespace Scene
{
	class Game : public AbstractScene
	{
	private:
		Parameter playerDetail_;
		ECS::EntityManager* entityManager_;
		ECS::Entity* me;
		ECS::Entity* you;
	public:
		Game(IOnSceneChangeCallback* sceneTitleChange, const Parameter& parame, ECS::EntityManager* entityManager);
		~Game();
		virtual void update() override;
		virtual void draw() override;
	
	};
}