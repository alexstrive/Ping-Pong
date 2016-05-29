#include "Ball.h"
#include "Constants.h"

Ball::Ball(RenderWindow * window, int x, int y, float dx, float dy, int radius, Paddle* playerLeft, Paddle* playerRight)
{
	this->window = window;
	this->x = x;
	this->y = y;
	this->dx = dx;
	this->dy = dy;
	this->radius = radius;
	this->playerLeft = playerLeft;
	this->playerRight = playerRight;

	this->circle.setOrigin(radius / 2, radius / 2);
	this->circle.setRadius(this->radius);
	this->circle.setPosition(this->x, this->y);
	this->circle.setPointCount(50);
}

void Ball::draw()
{
	this->window->draw(this->circle);
}

void Ball::update(float time)
{

	setX(this->x + time * this->dx);
	setY(this->y + time * this->dy);

	if (
		((this->x >= this->playerLeft->getX() - 10 / 2) && (this->x <= this->playerLeft->getX() + 10 / 2))
		&&
		((this->y >= this->playerLeft->getY() - 50 / 2) && (this->y <= this->playerLeft->getY() + 50 / 2))
		||
		((this->x >= this->playerRight->getX() - 10 / 2) && (this->x <= this->playerRight->getX() + 10 / 2))
		&&
		((this->y >= this->playerRight->getY() - 50 / 2) && (this->y <= this->playerRight->getY() + 50 / 2))
		)
	{
		cout << "Ball was reflected" << endl;
		this->dx *= -1;
		this->dy *= -1;
	}

	if (this->x > WINDOW_WIDTH)
	{
		this->playerLeft->updateScore();
		setX(WINDOW_WIDTH / 2);
	}
	else if (this->x < 0)
	{
		this->playerRight->updateScore();
		setX(WINDOW_WIDTH / 2);
	}

	if (this->y >= WINDOW_HEIGHT || this->y < 0)
	{
		this->dy *= -1;
	}
}

void Ball::setX(int x)
{
	this->x = x;
	this->circle.setPosition(this->x, this->y);
}

void Ball::setY(int y)
{
	this->y = y;
	this->circle.setPosition(this->x, this->y);
}