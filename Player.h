﻿#pragma once

#include "DirectXCommon.h"
#include "MathUtilityForText.h"
#include "Model.h"
#include "SafeDelete.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include "Input.h"



class Player {

	public:
		//コンストラクタ
	    Player();

		//デストラクタ
	    ~Player();

		//初期化
	    void Initialize(ViewProjection viewProjection);

		//更新
	    void Update();

		//2D背景描画
	    void Draw3D();

			// X座標の獲得
	    float GetX() { return worldTransformPlayer_.translation_.x; }

	private:
		//ビュープロダクション（共通）
	    ViewProjection viewProjection_;


		//プレイヤー
	    uint32_t textureHandlePlayer_ = 0;
	    Model* modelPlayer_ = nullptr;
	    WorldTransform worldTransformPlayer_;


		//インプットクラス
	    Input* input_ = nullptr;


	

};
