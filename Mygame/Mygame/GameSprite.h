#ifndef GAMESPRITE_H
#define GAMESPRITE_H
#include <d3dx9.h>
#include <string>

class GameSprite
{
private:
	//attributes
	LPDIRECT3DTEXTURE9 tex;
	LPD3DXSPRITE sprite;
	D3DCOLOR color;
	bool initialized;
	
public:
	GameSprite();
	bool initialize(LPDIRECT3DDEVICE9 device3d, std::string file, int width, int height);
	bool isInitialize();
	virtual void draw(float gameTime,D3DXVECTOR3 position);
	~GameSprite();
};


#endif // !GAMEPSRITE_H