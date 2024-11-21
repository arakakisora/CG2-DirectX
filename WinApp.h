#pragma once
#include <Windows.h>
#include <cstdint>


class WinApp
{

public:

	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

public:

	//初期化
	void Initialize();
	//更新
	void Update();


};

