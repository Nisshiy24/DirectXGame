#include "Enemy.h"
#include "time.h"

//コンストラクタ
Enemy::Enemy() {}


//デストラクタ
Enemy::~Enemy() { 
	
	delete modelEnemy_;

}


// 初期化
void Enemy::Initialize(ViewProjection viewProjection) {

	viewProjection_ = viewProjection;

	textureHandleEnemy_ = TextureManager::Load("enemy.png");
	modelEnemy_ = Model::Create();
	worldTransformEnemy_.scale_ = {0.5f, 0.5f, 0.5f};
	worldTransformEnemy_.Initialize();


	srand((unsigned int)time(NULL));

}


//更新
void Enemy::Update() {

	//移動
	Move();

	//発生
	Born();


	worldTransformEnemy_.matWorld_ = MakeAffineMatrix(
	    worldTransformEnemy_.scale_, worldTransformEnemy_.rotation_,
	    worldTransformEnemy_.translation_);

	worldTransformEnemy_.TransferMatrix();

	



}


//３D描画
void Enemy::Draw3D() {

	

	if (aliveFlag_ == 1) {
		modelEnemy_->Draw(worldTransformEnemy_, viewProjection_, textureHandleEnemy_);
	}
}


//移動
void Enemy::Move() {

	worldTransformEnemy_.translation_.z -= 0.5;

	worldTransformEnemy_.rotation_.x -= 0.1f;

	//worldTransformEnemy_.translation_.x += enemySpeed_;

	if (worldTransformEnemy_.translation_.x > 4) {
		enemySpeed_ = -0.1f;
	}

}


//発生
void Enemy::Born() {


	if (rand() % 10 == 0) {

		if (aliveFlag_ == 0) {

			worldTransformEnemy_.translation_.x = 0.0f;
			worldTransformEnemy_.translation_.y = 0.0f;
			worldTransformEnemy_.translation_.z = 40.0f;

			aliveFlag_ = 1;

			// 乱数でX座標の指定
			int x = rand() % 80;

			// 80は4の10倍の2倍
			float x2 = (float)x / 10 - 4;


			// 10で割り、4を引く
			worldTransformEnemy_.translation_.x = x2;

			//// 敵のスピード
			//if (rand() % 2 == 0) {
			//	enemySpeed_ = 0.1f;
			//} else {
			//	enemySpeed_ = -0.1f;
			//}

		
		}
		if (worldTransformEnemy_.translation_.z < -10) {
			aliveFlag_ = 0;
		}
	}
}

