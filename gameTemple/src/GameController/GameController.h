﻿/**
 * @file GameController.hpp
 * @brief アプリケーションの処理を行います
 * @author tonarinohito
 * @date 2018/10/06
 * @par History
 - 2018/10/14 tonarinohito
 -# このクラスでシーンのスタックを監視するように変更 
 */
#pragma once
#include "../ECS/ECS.hpp"
#include "Scene/SceneManager.hpp"
#include "Scene/Parameter.hpp"
#include <stack>
#define ENTITY_GROUP (ECS::Group)GameController::GameGroup

class GameController final : public Scene::IOnSceneChangeCallback
{
private:
	ECS::EntityManager entityManager_;
	std::stack<std::unique_ptr<Scene::AbstractScene>> sceneStack_;	//シーンのスタック
	Parameter param_;
	void resourceLoad();
	//!シーンスタックのチェックを行います
	void isSceneEmpty();
public:

	/**
	*  @brief エンティティの属するグループです
	* - 描画レイヤー、処理順、エンティティの取得に使います
	* - OrderByDraw使用時、番号が大きいほど手前に描画されます
	*/
	enum class GameGroup : ECS::Group
	{
		LAYER1,			//テスト用
		MAX,			//最大数
	};
	GameController();
	~GameController();
	/*!
	* @brief シーン変更(各シーンからコールバックされる)
	* @param scene 変更するシーンのenum
	* @param parame 次のシーンに渡したい値。不要ならnullptrを指定します
	* @param stackClear 現在のシーンのスタックをクリアするか
	*/
	void onSceneChange(const Scene::SceneName& scene, const Parameter* parame, Scene::StackPopFlag stackClear) override;
	//!すべてのシーンスタックをクリアします
	void stackClear() override;
	//!Entityの更新処理を行います
	void update();
	//!Entityの描画を行います
	void draw();
};
