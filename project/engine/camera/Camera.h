#pragma once
#include "RenderingData.h"
#include <WinApp.h>

class Object3D;
class Camera
{
public:

/// <summary>
/// 更新
/// </summary>
	
	Camera();
	void Update();

	void SetFollowTarget(Object3D *obj, const Vector3& offset);
	void SetFollowMode(bool enable);

	void SetRotate(const Vector3& rotate) { this->transform.rotate = rotate; }
	void SetTranslate(const Vector3& translate) { this->transform.translate = translate; }
	void SetFovY(const float& fovy) { this->fovY = fovy; }
	void SetAspectRatio(const float& aspectRation) { this->aspectRatio = aspectRation; }
	void SetNearClip(const float& nearClip) { this->nearCilp = nearClip; }
	void SetFarClip(const float& farClip) { this->farClip = farClip; }

	const Matrix4x4& GetWorldMatrix()const { return worldMatrix; }
	const Matrix4x4& GetViewMatrix()const { return viewMatrix; }
	const Matrix4x4& GetProjextionMatrix()const { return projectionMatrix; }
	const Matrix4x4& GetViewprojectionMatrix()const { return viewProjectionMatrix; }
	const Transform& GetTransform()const { return transform; }

private:
	
	//カメラ用のTransformを作る
	Transform transform;
	Matrix4x4 worldMatrix;
	Matrix4x4 viewMatrix;
	Matrix4x4 projectionMatrix;
	Matrix4x4 viewProjectionMatrix;


	float fovY=0.45f;
	float aspectRatio= float(WinApp::kClientWindth) / float(WinApp::kClientHeight);
	float nearCilp=0.1f;
	float farClip=100.0f;

	Object3D* followTarget = nullptr;
	Vector3 followOffset = { 0.0f, 0.0f, -15.0f };
	bool followMode = false;
	static inline const float interpolationRate = 0.5f; // 補間率
};
