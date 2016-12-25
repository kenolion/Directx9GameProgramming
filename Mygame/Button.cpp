#include "Button.h"



Button::Button(float x, float y, D3DXVECTOR2 scaling, int animSpeed) : GameObject(x, y, scaling , animSpeed)
{
}

Button::~Button()
{
	font->Release();
	font = NULL;
}


bool Button::initialize(LPDIRECT3DDEVICE9 device3d, std::string file, int width, int height, int row, int col, bool frameHorizontal, D3DXCOLOR color)
{
	GameObject::initialize(device3d, file, width, height, row, col, frameHorizontal, color);

	hr = D3DXCreateFont(device3d,			    //(1st Parameter) [LPDIRECT3DDEVICE9] Pointer to an IDirect3DDevice9 interface, the device to be associated with the font object.
		25,										//(2nd Parameter) [INT] The height of the characters in logical units.
		0,										//(3rd Parameter) [UINT] The width of the characters in logical units. 
		0,										//(4th Parameter) [UINT] Typeface weight. One example is bold.
		1,										//(5th Parameter) [UINT] The number of mipmap levels.
		false,									//(6th Parameter) [BOOL] True for italic font, false otherwise.
		DEFAULT_CHARSET, 						//(7th Parameter) [DWORD] The character set of the font.
		OUT_TT_ONLY_PRECIS,						//(8th Parameter) [DWORD] Specifies how Windows should attempt to match the desired font sizes and characteristics with actual fonts. Use OUT_TT_ONLY_PRECIS for instance, to ensure that you always get a TrueType font.
		DEFAULT_QUALITY,						//(9th Parameter) [DWORD] Specifies how Windows should match the desired font with a real font. It applies to raster fonts only and should not affect TrueType fonts
		DEFAULT_PITCH | FF_DONTCARE,			//(10th Parameter) [DWORD]Pitch and family index
		"Arial",								//(11th Parameter) [LPCSTR] String containing the typeface name. If the compiler settings require Unicode, the data type LPCTSTR resolves to LPCWSTR. Otherwise, the string data type resolves to LPCSTR. See Remarks. 
		&font);									//(12th Parameter) [LPD3DXFONT]Returns a pointer to an ID3DXFont interface, representing the created font object.

	if (FAILED(hr))
	{
		MessageBox(NULL, "ERROR", "Could not initialize Font", MB_ICONERROR);
		return false;
	}

	return true;
}

bool Button::onHover(int mouseX, int mouseY)
{
	if (mouseX >= position.x && mouseX <= position.x + spriteRect.right)
	{
		if (mouseY >= position.y&& mouseY <= position.y + spriteRect.bottom)
		{
			
			return true;
		}
	}

	return false;
}


void Button::draw() {

	GameObject::draw();
	buttonRect.top = spriteHeight / 2 - 10;
	buttonRect.bottom = spriteRect.top + 200;
	buttonRect.left = spriteWidth / 2 - 60;
	buttonRect.right = spriteRect.left + 200;

	font->DrawText(sprite,														//(1st Parameter) [LPD3DX10SPRITE] Pointer to an ID3DX10Sprite object that contains the string you wish to draw. Can be NULL, in which case Direct3D will render the string with its own sprite object. To improve efficiency, a sprite object should be specified if ID3DX10Font::DrawText is to be called more than once in a row.
		"burdenben",															//(2nd Parameter) [LPCTSTR] Pointer to a string to draw. If UNICODE is defined, this parameter type resolves to an LPCWSTR, otherwise, the type resolves to an LPCSTR. If the Count parameter is -1, the string must be NULL terminated.	
		15, 																	//(3rd Parameter) [INT] The number of characters in the string. If Count is -1, then the pString parameter is assumed to be a pointer to a sprite containing a NULL-terminated string and ID3DX10Font::DrawText computes the character count automatically.	
		&buttonRect,														    //(4th Parameter) [LPRECT] Pointer to a RECT structure that contains the rectangle, in logical coordinates, in which the text is to be formatted. As with any RECT object, the coordinate value of the rectangle's right side must be greater than that of its left side. Likewise, the coordinate value of the bottom must be greater than that of the top.	
		0, 																		//(5th Parameter) [UINT] Specify the method of formatting the text.It can be any combination of the following values : REFER FontFormats.txt													
		D3DCOLOR_XRGB(255, 255, 255)); //MOUSE X COORDINATE DRAWING POSITION    //(6th Parameter) [D3DXCOLOR] Colour of the text	
}
void Button::update(int &gameTime)
{

	for(int i = 0 ; i < gameTime;i++){
	if (animTimer >= 60) {
		animTimer = 0;
		frame++;
		if (frame > maxFrame) {
			frame = maxFrame;
		}
	}
	animTimer += animSpeed;
	}
}


