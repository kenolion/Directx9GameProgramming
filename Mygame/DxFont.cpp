#include "DxFont.h"



void DxFont::initialize(LPDIRECT3DDEVICE9 d3dDevice,)
{
	HRESULT hr = D3DXCreateFont(d3dDevice,10,0,FW_NORMAL,1,false,DEFAULT_CHARSET,)

}

DxFont::DxFont()
{
}


DxFont::~DxFont()
{
}
