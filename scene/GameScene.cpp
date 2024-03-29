#include "GameScene.h"
#include "TextureManager.h"
#include <cassert>
#include "Stage.h"
#include "Enemy.h"

GameScene::GameScene() { }



GameScene::~GameScene() {

	//各クラスの削除
	//ステージ
	delete stage_;

	//プレイヤー
	delete player_;

	//ビーム
	delete beam_;

	//敵
	delete enemy_;
	
}

void GameScene::Initialize() {

	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();


	viewProjection_.translation_.y = 1;
	viewProjection_.translation_.z = -6;
	viewProjection_.Initialize();


	//各クラスの生成
	//ステージ
	stage_ = new Stage();

	//各クラスの初期化
	//ステージ
	stage_->Initialize(viewProjection_);


	//プレイヤー
	player_ = new Player();

	player_->Initialize(viewProjection_);



	//ビーム
	beam_ = new Beam();
	beam_->Initialize(viewProjection_, player_);

	//敵
	enemy_ = new Enemy();
	enemy_->Initialize(viewProjection_);
	

}

void GameScene::Update() {

	//各クラスの更新
	//ステージ
	stage_->Update();


	player_->Update();

	beam_->Update();

	enemy_->Update();

}

void GameScene::Draw() {

	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

#pragma region 背景スプライト描画
	// 背景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに背景スプライトの描画処理を追加できる
	/// </summary>

	//背景の描画
	stage_->Draw2DFar();

	

	// スプライト描画後処理
	Sprite::PostDraw();
	// 深度バッファクリア
	dxCommon_->ClearDepthBuffer();
#pragma endregion

#pragma region 3Dオブジェクト描画
	// 3Dオブジェクト描画前処理
	Model::PreDraw(commandList);

	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	/// </summary>



	stage_->Draw3D();

	//プレイヤー
	player_->Draw3D();

	//ビーム
	beam_->Draw3D();

	//敵
	enemy_->Draw3D();
	





	// 3Dオブジェクト描画後処理
	Model::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion
}
