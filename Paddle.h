#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Paddle
{
private:
	RenderWindow *window;
	RectangleShape rectangle;
	Text scoreText;
	Font* scoreFont;
	
	int y;
	int x;
	
	int height;
	int width;

	int player;
	
	int score;

	float speed;
public:
	// Constructor
	// window - pointer to window, there we could draw paddle
	// player - number of player ->
	// [1 - player 1
	// 2 - player 2 ]
	// speed - speed of player on Y axis
	Paddle(RenderWindow *window, int height, int width, int player, float speed);

	// I don't think that this must be explained
	void draw();

	// Update state of paddle
	// Controls:
	// 1 player: W, A, S, D
	// 2 player: arrows (left, top, right, bottom)
	void update(float time);

	// Setters
	void setY(int y);

	int getX();
	int getY();

	// Increment score;
	void updateScore();

	void setScoreFont(Font* scoreFont);

	void setScorePosition(int x, int y);

	void drawScore();
};