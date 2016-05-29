#include "Paddle.h"
#include "Constants.h"
#include <iostream>
#include <sstream>

using namespace std;

Paddle::Paddle(RenderWindow * window, int height, int width, int player, float speed)
{
	this->score = 0;
	
	this->y = 300;

	this->width = width;
	this->height = height;
	
	this->player = player;

	this->speed = speed;

	this->window = window;

	this->rectangle.setSize(Vector2f(this->width, this->height));

	this->rectangle.setOrigin(this->width / 2, this->height / 2);

	if (this->player == 1)
	{
		this->x = 25;
		this->rectangle.setPosition(this->x, this->y);
	}
	else
	{
		this->x = 775;
		this->rectangle.setPosition(this->x, this->y);
	}
}


void Paddle::draw()
{
	this->window->draw(this->rectangle);
}

void Paddle::update(float time)
{
	if (this->player == 1)
	{


		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			cout << "Left player go top" << endl;
			this->setY(this->y - time * this->speed);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			cout << "Right player go bottom" << endl;
			this->setY(this->y + time * this->speed);
		}
	}
	else
	{

		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			cout << "Right player go top" << endl;
			cout << this->y - time * this->speed << endl;
			this->setY(this->y - time * this->speed);
		}
		else if (Keyboard::isKeyPressed(Keyboard::S))
		{
			cout << "Right player go bottom" << endl;
			this->setY(this->y + time * this->speed);
		}
	}
}

void Paddle::setY(int y)
{
	if ((y >= 0 + this->height / 2) && (y <= WINDOW_HEIGHT - this->height / 2))
	{
		this->y = y;
		cout << "Y value of player " << this->player << " was changed to " << this->y << endl;
		this->rectangle.setPosition(rectangle.getPosition().x, this->y);
	}
	
}

void Paddle::updateScore()
{
	stringstream ss;
	this->score += 1;
	cout << "Score of player " << this->player << " was changed to " << this->score << endl;
	ss << this->score;
	this->scoreText.setString(ss.str());
}

void Paddle::setScoreFont(Font* scoreFont)
{
	this->scoreFont = scoreFont;
	this->scoreText.setFont(*this->scoreFont);
	this->scoreText.setString("0");
}

void Paddle::setScorePosition(int x, int y)
{
	this->scoreText.setPosition(x, y);
	this->scoreText.setOrigin(this->scoreText.getScale().x / 2, this->scoreText.getScale().y / 2);
}

void Paddle::drawScore()
{
	this->window->draw(this->scoreText);
}

int Paddle::getX()
{
	return this->x;
}

int Paddle::getY()
{
	return this->y;
}