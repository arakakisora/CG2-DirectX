#pragma once
#include <numbers>
#include <algorithm>
#include <fstream>
#include <sstream>

#include "Input.h"
#include "WinApp.h"
#include "DirectXCommon.h"
#include"D3DResourceLeakChecker.h"
#include "Logger.h"
#include "SpriteCommon.h"
#include"Sprite.h"

#include "Object3DCommon.h"
#include "Object3D.h"
#include "RenderingData.h"
#include "Model.h"
#include "ModelManager.h"
#include "TextureManager.h"
#include"ImGuiManager.h"
#include <imgui.h>
#include "Audio.h"
#include "SrvManager.h"
#include "Camera.h"	
class Framework
{
public:
	//ゲームの初期化
	virtual void Initialize();
	//終了
	virtual void Finalize();
	//更新
	virtual void Update();
	//描画
	virtual void Draw()=0;

	void Run();

	//ゲーム終了フラグの取得
	virtual bool IsEndRequest()const { return endRequst_; }

public:
	//ゲーム終了フラグ	
	bool endRequst_ = false;

	//WinAppのポインタ
	WinApp* winApp = nullptr;
	//DirectXCommonのポインタ
	DirectXCommon* dxCommon = nullptr;
	//SrvManagerのポインタ
	SrvManager* srvManager = nullptr;
	//ImGuiManagerのポインタ
	ImGuiManager* imGuiMnager = nullptr;
	//Audioのポインタ
	Audio* audio_ = nullptr;
	//カメラのポインタ
	Camera* camera = nullptr;
	//スプライト宣言
	SpriteCommon* spriteCommon = nullptr;
	//3Dオブジェクト共通部宣言
	Object3DCommon* object3DCommon = nullptr;

};

