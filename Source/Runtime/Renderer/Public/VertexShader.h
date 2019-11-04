#pragma once

#include "Vector4.h"
#include "RSIDataTypes.h"


class VertexShader final
{
public:

	// Structure�� �̸��� ����.
	struct VertexInput
	{
		Vector4 Position;
	};

	// Structure�� �̸��� ����.
	struct VertexOutput
	{
		Vector4 Position;
	};

public:

	VertexShader() = default;
	~VertexShader() = default;

	FORCEINLINE void ProcessVertexShader(VertexBuffer* InVertexBuffer, IndexBuffer* InIndexBuffer, UINT IndexOffset, VertexOutput* OutputData);

private:

	FORCEINLINE VertexOutput VertexMain(VertexInput InputData);

private:
};

