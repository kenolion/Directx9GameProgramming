#ifndef GAMESPRITE_H
#define GAMESPRITE_H
#include <d3dx9.h>
#include <string>

class GameSprite
{
private:
	//attributes
	LPDIRECT3DTEXTURE9 tex;

public:
	GameSprite();
	void initializeTex(LPDIRECT3DDEVICE9 device3d, std::string file, int width, int height, int row, int col);

	virtual void draw(D3DXVECTOR3 position, LPD3DXSPRITE sprite, RECT spriteRect, D3DCOLOR color);
	~GameSprite();
};


#endif // !GAMEPSRITE_H