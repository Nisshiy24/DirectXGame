#pragma once

#include "DirectXCommon.h"
#include "MathUtilityForText.h"
#include "Model.h"
#include "SafeDelete.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"

class Enemy {

	public:
		//コンストラクタ
	    Enemy();

		//デストラクタ
	    ~Enemy();

		//初期化
	    void Initialize(ViewProjection viewProjection);

		//更新
	    void Update();

		//3D描画
	    void Draw3D();

		//移動
	    void Move();

		//発生
	    void Born();



	private:
	    // ビュープロダクション（共通）
	    ViewProjection viewProjection_;

		//敵
	    uint32_t textureHandleEnemy_ = 0;
	    Model* modelEnemy_ = nullptr;
	    WorldTransform worldTransformEnemy_;


		//存在フラグ
	    int aliveFlag_ = 0;

		float enemySpeed_ = 5.0f;
};
