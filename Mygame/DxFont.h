#ifndef DXFONT_H
#define DXFONT_H

#include "Constants.h"
#include <d3dx9.h>

class DxFont
{
private:
	LPD3DXFONT font;
public:
	void initialize(LPDIRECT3D9 d3dDevice);
	DxFont();
	~DxFont();
};
#endif // !DXFONT_H
