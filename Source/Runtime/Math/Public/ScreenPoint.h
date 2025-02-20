#pragma once

#include "CoreDefinition.h"
#include "Vector2.h"

struct ScreenPoint
{
public:
	ScreenPoint() : X(0), Y(0) { }
	explicit ScreenPoint(int InX, int InY) : X(InX), Y(InY) { }
	explicit ScreenPoint(float InX, float InY) : X(Math::RoundToInt(InX)), Y(Math::RoundToInt(InY)) { }
	explicit ScreenPoint(const Vector2& InPos) : ScreenPoint(InPos.X, InPos.Y) {}
	explicit ScreenPoint(const Vector3& InPos) : ScreenPoint(InPos.X, InPos.Y) {}

	ScreenPoint GetHalf() { return ScreenPoint(Math::RoundToInt(0.5f * X), Math::RoundToInt(0.5f * Y)); }
	FORCEINLINE bool HasZero() const { return ( X == 0 || Y == 0 ); }

	FORCEINLINE static ScreenPoint ToScreenCoordinate(const ScreenPoint& InScreenSize, const Vector2& InPos)
	{
		return ScreenPoint(InPos.X + InScreenSize.X * 0.5f, -InPos.Y + InScreenSize.Y * 0.5f);
	}

	FORCEINLINE Vector2 ToVectorCoordinate(const ScreenPoint& InScreenSize)
	{
		return Vector2(X - InScreenSize.X * 0.5f + 0.5f, -Y + InScreenSize.Y * 0.5f + 0.5f);
	}

	FORCEINLINE ScreenPoint operator-(const ScreenPoint& InPoint) const;
	FORCEINLINE ScreenPoint operator+(const ScreenPoint& InPoint) const;

	int X;
	int Y;
};

FORCEINLINE ScreenPoint ScreenPoint::operator-(const ScreenPoint& InPoint) const
{
	return ScreenPoint(X - InPoint.X, Y - InPoint.Y);
}

FORCEINLINE ScreenPoint ScreenPoint::operator+(const ScreenPoint& InPoint) const
{
	return ScreenPoint(X + InPoint.X, Y + InPoint.Y);
}