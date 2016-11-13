#include "GameSprite.h"


GameSprite::GameSprite()
{
	// When color is set to white, what you see is exactly what the image looks like
	color = D3DCOLOR_ARGB(255, 255, 255, 255);
	initialized = false;
	row = 1;			//Start it at frame 1
	col = 1;
}

bool GameSprite::initialize(LPDIRECT3DDEVICE9 device3d, std::string file, int width, int height, int row, int col)
{
	this->width = width;
	this->height = height;
	this->spriteRow = row;
	this->spriteCol = col;
	spriteHeight = height / spriteRow;
	spriteWidth = width / spriteCol;

	//Same function as D3DXCReateTextureFromFile except width and height are manually entered
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
		return false;
	}




	//Attemp to create the sprite
	if (!SUCCEEDED(D3DXCreateSprite(device3d, &sprite))) {
		MessageBox(NULL, "There was an issue creating the sprite.", NULL, NULL);
		return false;
	}
	initialized = true;
	return true;
}

bool GameSprite::isInitialize()
{

	return initialized;
}

int GameSprite::getRow()
{
	return row;
}

int GameSprite::getCol()
{
	return col;
}

int GameSprite::getSpriteRow()
{
	return spriteRow;
}

int GameSprite::getSpriteCol()
{
	return spriteCol;
}

void GameSprite::setRow(int row)
{
	this->row = row;
}

void GameSprite::setCol(int col)
{
	this->col = col;
}

void GameSprite::updateFrame()
{
	if (spriteCol > 1) {			//check to see if sprite has more than 1 collumn
		col++;						//increment collumn by 1
		if (col > spriteCol) {
			if (spriteRow > 1) {	//checks to see if theres more than 1 row
				row++;
				if (row > spriteRow) {
					row = 1;		//resets row if current row exceeds sprite row
				}
			}
			col = 1;				//resets collumn if current collumn exceeds sprite column
		}
	}

}


void GameSprite::draw(float gameTime, D3DXVECTOR3 position)
{


	spriteRect.top = (row - 1)*spriteHeight;
	spriteRect.bottom = row*spriteHeight;
	spriteRect.left = (col - 1)*spriteWidth;
	spriteRect.right = col *spriteHeight;



	if (sprite && tex) {
		sprite->Begin(D3DXSPRITE_ALPHABLEND);
		sprite->Draw(tex, &spriteRect, NULL, &position, color);
		sprite->End();
	}
}


GameSprite::~GameSprite()
{
	if (sprite) {
		sprite->Release();
		sprite = 0;
	}
	if (tex) {
		tex->Release();
		tex = 0;
	}
}

