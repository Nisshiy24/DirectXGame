#include "Player.h"


//コンストラクタ
Player::Player() {}

//デストラクタ
Player::~Player() {

	//プレイヤー
	delete modelPlayer_;

}

//初期化
void Player::Initialize(ViewProjection viewProjection) {
	//メンバー変数に代入
	viewProjection_ = viewProjection;

	//プレイヤー
	textureHandlePlayer_ = TextureManager::Load("player.png");
	modelPlayer_ = Model::Create();
	worldTransformPlayer_.scale_ = {0.5f, 0.5f, 0.5f};
	worldTransformPlayer_.Initialize();



	//インプットクラス
	input_ = Input::GetInstance();


}

//更新
void Player::Update() {

	//変換行列を更新
	worldTransformPlayer_.matWorld_ = MakeAffineMatrix(
	    worldTransformPlayer_.scale_, worldTransformPlayer_.rotation_,
	    worldTransformPlayer_.translation_);
	//変換行列を定数バッファに転送
	worldTransformPlayer_.TransferMatrix();


	// 右移動
	if (input_->PushKey(DIK_RIGHT)) {
		worldTransformPlayer_.translation_.x += 0.1f;
	}

	// 左へ移動
	if (input_->PushKey(DIK_LEFT)) {
		worldTransformPlayer_.translation_.x -= 0.1f;
	}

	if (worldTransformPlayer_.translation_.x > 4) {
		worldTransformPlayer_.translation_.x = 4;
	}

	if (worldTransformPlayer_.translation_.x < -4) {
		worldTransformPlayer_.translation_.x = -4;
	}

}

//３D描画
void Player::Draw3D() {

	//プレイヤー
	modelPlayer_->Draw(worldTransformPlayer_, viewProjection_, textureHandlePlayer_);

}
