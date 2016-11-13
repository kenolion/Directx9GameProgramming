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
	RECT spriteRect;
	int height;
	int width;
	int spriteRow;				// this int changes according to its sprite sheet
	int spriteCol;				//this int changes according to its sprite sheet
	int row;					// this variable changes according to the game loop
	int col;					// this variable changes according to the game loop
	int spriteHeight;
	int spriteWidth;
public:
	GameSprite();
	bool initialize(LPDIRECT3DDEVICE9 device3d, std::string file, int width, int height, int row, int col);
	bool isInitialize();


	//getter and setter
	int getRow();		// returns current row
	int getCol();		// returns current col
	int getSpriteRow();		// returns current row
	int getSpriteCol();		// returns current col


	void setRow(int row);		//sets current row
	void setCol(int col);		//sets current col
	void updateFrame();

	virtual void draw(float gameTime,D3DXVECTOR3 position);
	~GameSprite();
};


#endif // !GAMEPSRITE_H