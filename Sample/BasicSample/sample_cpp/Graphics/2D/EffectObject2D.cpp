﻿
#include <ace.h>

// EffectObject2Dのサンプル。エフェクトを表示しています。
void EffectObject2D()
{
	// AC-Engineを初期化する。
	ace::Engine::Initialize(ace::ToAString("EffectObject2D").c_str(), 640, 480, ace::EngineOption());

	// シーンを生成する
	auto scene = std::make_shared<ace::Scene>();

	// レイヤーを生成する
	auto layer = std::make_shared<ace::Layer2D>();

	// シーンにレイヤーを追加する
	scene->AddLayer(layer);

	// シーンを切り替える
	ace::Engine::ChangeScene(scene);

	// エフェクトを読み込む
	auto effect = ace::Engine::GetGraphics()->CreateEffect(ace::ToAString("Data/Effect/magic.efk").c_str());

	// エフェクトオブジェクトを生成する
	auto effectObj = std::make_shared<ace::EffectObject2D>();

	// エフェクトをレイヤーに追加する
	layer->AddObject(effectObj);

	// エフェクトの位置、大きさを指定する
	effectObj->SetPosition(ace::Vector2DF(320, 240));
	effectObj->SetScale(ace::Vector2DF(50, 50));
	
	// エフェクトを設定する
	effectObj->SetEffect(effect);

	// エフェクトを再生する
	effectObj->Play();

	// AC-Engineのウインドウが閉じられていないか確認する。
	while (ace::Engine::DoEvents())
	{
		// AC-Engineを更新する。
		ace::Engine::Update();
	}

	// AC-Engineの終了処理をする。
	ace::Engine::Terminate();

	return;
}