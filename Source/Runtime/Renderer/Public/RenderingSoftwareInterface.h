
#pragma once

#include "ScreenPoint.h"
#include "LinearColor.h"
#include "RSIDataTypes.h"

class RenderingSoftwareInterface
{
public:

	virtual bool Init(const ScreenPoint& InSize) = 0;
	virtual void Shutdown() = 0;
	virtual bool IsInitialized() const = 0;
	virtual void SetBlendingMode(BlendingModes InNewBlendingMode) = 0;

	virtual void Clear(const LinearColor& InClearColor) = 0;
	virtual void BeginFrame() = 0;
	virtual void BufferSwap() = 0;

	virtual void DrawPoint(const Vector2& InVectorPos, const LinearColor& InColor) = 0;
	virtual void DrawPoint(const ScreenPoint& InScreenPos, const LinearColor& InColor) = 0;

	virtual bool SetDepthPoint(const Vector2& InVectorPos, float InDepth) = 0;
	virtual bool SetDepthPoint(const ScreenPoint& InScreenPos, float InDepth) = 0;

	virtual void DrawFullVerticalLine(int InX, const LinearColor& InColor) = 0;
	virtual void DrawFullHorizontalLine(int InY, const LinearColor& InColor) = 0;
};
