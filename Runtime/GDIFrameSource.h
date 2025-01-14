#pragma once
#include "pch.h"
#include "FrameSourceBase.h"


class GDIFrameSource : public FrameSourceBase {
public:
	GDIFrameSource() {};
	virtual ~GDIFrameSource() {}

	bool Initialize() override;

	ComPtr<ID3D11Texture2D> GetOutput() override;

	bool Update() override;

	bool HasRoundCornerInWin11() override {
		return false;
	}

protected:
	ComPtr<ID3D11DeviceContext> _d3dDC;

	SIZE _frameSize{};
	ComPtr<IDXGISurface1> _dxgiSurface;
	ComPtr<ID3D11Texture2D> _output;
};
