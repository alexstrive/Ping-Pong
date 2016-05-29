#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Paddle.h"

using namespace std;
using namespace sf;

class Ball
{
private:
	CircleShape circle;
	RenderWindow* window;
	Paddle* playerLeft;
	Paddle* playerRight;
	int radius;
	int x;
	int y;
	float dx;
	float dy;
public:
	// window - pointer to renderwindow
	// x - start position X
	// y - start position Y
	// dx - start dx
	// dy - start dy
	// radius - radius of the ball
	Ball(RenderWindow* window, int x, int y, float dx, float dy, int radius, Paddle* playerLeft, Paddle* playerRight);
	
	// Draw ball to RenderWindow
	void draw();

	// Update ball logic
	void update(float time);

	void setX(int x);
	void setY(int y);
};