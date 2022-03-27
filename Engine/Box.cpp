#include "Box.h"
#include "Graphics.h"


Box::Box(int xPos, int yPos, int boxWidth, int boxHeight)
{
	x = xPos;
	y = yPos;
	width = boxWidth;
	height = boxHeight;
}

Box::Box(int x, int y, int vX, int vY, int boxWidth, int boxHeight)
{
	Box(x, y, boxWidth, boxHeight);
	speedX = vX;
	speedY = vY;
}

bool Box::isIntersecting(const Box& box) const
{
	return x + width  >= box.x - box.width &&
		   x - width  <= box.x + box.width &&
		   y - height <= box.y + box.height &&
		   y + height >= box.y - box.height;

}

void Box::update()
{
	x += speedX; y += speedY;

	// right wall
	if (x + width >= Graphics::ScreenWidth / 2) {
		speedX = -speedX;
	}
	// left wall
	if (x - width <= -Graphics::ScreenWidth / 2) {
		speedX = -speedX;
	}
	// top wall
	if (y + height >= Graphics::ScreenHeight / 2) {
		speedY = -speedY;
	}
	if (y - height <= -Graphics::ScreenHeight / 2) {
		speedY = -speedY;
	}

	ClampPositionToScreen();
}

void Box::translate(int dx, int dy)
{
	x += dx; y += dy;

	ClampPositionToScreen();
}

void Box::ClampPositionToScreen()
{
	if (x + width >= Graphics::ScreenWidth / 2) { x = (Graphics::ScreenWidth / 2) - (width + 1); }
	if (x - width <= -Graphics::ScreenWidth / 2) { x = (-Graphics::ScreenWidth / 2) + (width + 1); }
	if (y + height >= Graphics::ScreenHeight / 2) { y = (Graphics::ScreenHeight / 2) - (height + 1); }
	if (y - height <= -Graphics::ScreenHeight / 2) { y = (-Graphics::ScreenHeight / 2) + (height + 1); }
}

void Box::setPosition(int xpos, int ypos)
{
	x = xpos; y = ypos;
	ClampPositionToScreen();
}

void Box::setVelocity(int xvel, int yvel)
{
	speedX = xvel; speedY = yvel;
}


void Box::draw(Graphics& gfx, int r, int g, int b) const
{
	int posX = x + (gfx.ScreenWidth / 2);
	int posY = -y + (gfx.ScreenHeight / 2);

	for (int i = posX - width; i <= posX + width; i++) {
		for (int j = posY - height; j <= posY + height; j++) {
			gfx.PutPixel(i, j, r, g, b);
			gfx.PutPixel(i, j, r, g, b);
		}
	}

}
