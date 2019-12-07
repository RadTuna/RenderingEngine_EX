
#include "Precompiled.h"
#include "SoftRenderer.h"
#include "RSIDataTypes.h"

SoftRenderer::SoftRenderer()
{
	mRendererContext = std::make_unique<RenderContext>();
	mRendererFactory = std::make_unique<RenderFactory>();
}

void SoftRenderer::OnTick()
{
	// ������ Initialize�Լ�ȣ���� ���� �ʱ� ���� �Ʒ��� ������.
	if (!IsAllInitialized)
	{
		// Init Query Performance Timer
		if(PerformanceInitFunc && PerformanceMeasureFunc)
		{
			CyclesPerMilliSeconds = PerformanceInitFunc();
			IsPerformanceCheckInitialized = true;
		}
		else
		{
			return;
		}

		// Init RSI
		if (CurrentScreenSize.HasZero())
		{
			return;
		}
		if (mRendererContext->Initialize(CurrentScreenSize) == false)
		{
			return;
		}

		IsRendererInitialized = true;

		// Check Input Binding
		if (mInputManager.GetXAxis && mInputManager.GetYAxis && mInputManager.MoveForward && mInputManager.MoveRight && mInputManager.MoveUp)
		{
			IsInputInitialized = true;
		}
		else
		{
			return;
		}

		IsAllInitialized = IsRendererInitialized && IsPerformanceCheckInitialized && IsInputInitialized;
		Awake();
	}
	else
	{
		PreUpdate();
		Update();
		PostUpdate();
	}
}

void SoftRenderer::OnResize(const ScreenPoint& InNewScreenSize)
{
	CurrentScreenSize = InNewScreenSize;

	if (IsRendererInitialized)
	{
		mRendererContext->Initialize(InNewScreenSize);
	}
}

void SoftRenderer::Shutdown()
{
	mRendererContext->Shutdown();
}

