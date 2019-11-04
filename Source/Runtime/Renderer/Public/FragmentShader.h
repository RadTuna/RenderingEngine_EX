#pragma once

class FragmentShader final
{
public:

	// Structure�� �̸��� ����.
	struct FragmentInput
	{
		Vector4 Position;
	};

public:

	FragmentShader() = default;
	~FragmentShader() = default;

	FORCEINLINE void ProcessFragmentShader(FragmentInput* InFragments, UINT FragmentSize); // WIP

private:

	FORCEINLINE const Vector4& FragmentMain(FragmentInput& InputData); // WIP

private:
};

