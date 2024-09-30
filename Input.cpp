#include "Input.h"
#include <cassert>




#pragma comment(lib,"dinput8.lib")
#pragma comment(lib,"dxguid.lib")

void Input::Initialize(HINSTANCE hInstance, HWND hwnd)
{
	HRESULT hr;
	//DirectInputのインスタンスを生成
	ComPtr<IDirectInput8>directInput = nullptr;
	hr = DirectInput8Create(hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&directInput, nullptr);
	assert(SUCCEEDED(hr));
	//キーボードデバイス生成
	
	hr = directInput->CreateDevice(GUID_SysKeyboard, &keyboard, NULL);
	assert(SUCCEEDED(hr));
	//入力データ形式のセット
	hr = keyboard->SetDataFormat(&c_dfDIKeyboard);
	assert(SUCCEEDED(hr));
	//排他制御レベルのセット
	hr = keyboard->SetCooperativeLevel(hwnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE | DISCL_NOWINKEY);
	assert(SUCCEEDED(hr));




}

void Input::Update()
{
	//前回のキー入力を保存
	memcpy(preKey, key, sizeof(key));
	//キーボード情報の取得
	keyboard->Acquire();
	//全キーボード入力情報を取得
	keyboard->GetDeviceState(sizeof(key), key);

}

bool Input::PushKey(BYTE keyNumber)
{
	if (key[keyNumber]) {

		return true;
	}
}

bool Input::TriggerKey(BYTE keyNumber)
{
	if (key[keyNumber] && !preKey[keyNumber]) {

		return true;
	}
}
