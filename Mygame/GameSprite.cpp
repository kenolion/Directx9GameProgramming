#include "GameSprite.h"


GameSprite::GameSprite()
{
	// When color is set to white, what you see is exactly what the image looks like
	
}

void GameSprite::initializeTex(LPDIRECT3DDEVICE9 device3d,std::string file, int width, int height, int row, int col)
{
	
	if (!SUCCEEDED(D3DXCreateTextureFromFileEx(device3d,
		file.c_str(),
		width,
		height,
		D3DX_DEFAULT,
		0,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		0,
		NULL,
		NULL,
		&tex)))
	{
		std::string s = "There was an issue creating the Texture.  Make sure the requested image is available.  Requested image: " + file;
		MessageBox(NULL, s.c_str(), NULL, NULL);

	}
	
	

}



void GameSprite::draw(D3DXVECTOR3 position, LPD3DXSPRITE sprite, RECT spriteRect,D3DCOLOR color)
{


	//MATRIX TRANSFORMATION
	if (tex == NULL) {
		MessageBox(NULL, "tex is empty", "", MB_OK);

	}


	if (sprite && tex) {
		sprite->Begin(D3DXSPRITE_ALPHABLEND);
		sprite->Draw(tex, &spriteRect, NULL, &position, color);
		sprite->End();
		
	}
}


GameSprite::~GameSprite()
{
	if (tex) {
		tex->Release();
		tex = 0;
	}
	
}

