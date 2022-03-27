#pragma once

#include "Graphics.h"

class Box
{
private:
	int x;
	int y;
	int width;
	int height;
	int speedX = 0;
	int speedY = 0;

	void ClampPositionToScreen();
public:
	Box(int x, int y, int boxWidth, int boxHeight);
	Box(int x, int y,int vX, int vY, int boxWidth, int boxHeight);

	bool isIntersecting(const Box& box) const;
	void draw(Graphics& gfx, int r, int g, int b) const;

	void update();
	void translate(int dx, int dy);
	void setPosition(int xpos, int ypos);
	void setVelocity(int xvel, int yvel);

	int getX() const { return x; }
	int getY() const { return y; }

	int getWidth() const { return width; }
	int getHeigth() const { return height; }

	int getVelocityX() const { return speedX; }
	int getVelocityY() const { return speedY; }
	

};

