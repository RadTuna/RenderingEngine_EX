#pragma once

#include "BaseComponent.h"

class MovementComponent : public BaseComponent
{
public:

	MovementComponent() = default;
	virtual ~MovementComponent() = default;

	void Awake(class Entity* InParent) override;
	void Update(float DeltaTime) override;
	void Render() override;
	void End() override;

	void SetMovementParameter(float InMove, float InRot);

private:

	float mMoveSensivity = 100.0f;
	float mRotateSensivity = 50.0f;

};