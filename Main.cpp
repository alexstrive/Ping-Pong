#include <iostream>
#include <string>
#include <cmath>
#include <ctime>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Paddle.h";
#include "Ball.h"
#include "Constants.h"

using namespace std;
using namespace sf;

int main()
{
	cout << "Ping Pong by allordiron. Version: " << GAME_VERSION << endl;
	cout << "Starting game ..." << endl;

	cout << "Video Mode:" << WINDOW_WIDTH << "x" << WINDOW_HEIGHT << endl;

	// Main time variable
	float time;

	// flags
	bool isRunning = true;
	bool isPlaying = true;
	bool isMouseVisible = false;
	bool isVSyncEnabled = true;

	// Clock for get time in game loop
	Clock clock;

	// Font
	Font PS2PR;
	PS2PR.loadFromFile("assets/fonts/PressStart2P-Regular.ttf");

	// Main and once window
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Ping Pong | Version: " + GAME_VERSION);

	// Init two players
	Paddle playerLeft(&window, 50, 10, 1, 0.5);
	Paddle playerRight(&window, 50, 10, 2, 0.5);

	playerLeft.setScoreFont(&PS2PR);
	playerLeft.setScorePosition(WINDOW_WIDTH / 4, 25);

	playerRight.setScoreFont(&PS2PR);
	playerRight.setScorePosition(3 * WINDOW_WIDTH / 4, 25);

	// Init ball
	Ball ball(&window, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, -0.25, 0.25, 5, &playerLeft, &playerRight);

	// Enable vertical synchronization
	window.setVerticalSyncEnabled(isVSyncEnabled);
	window.setMouseCursorVisible(isMouseVisible);

	// Game loop
	while (isRunning)
	{
		// Handle events
		// Code is wierd, but i don't know how to do it more pretty
		// Hey, i'm a 16 year student :)
		Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
				isRunning = false;
				cout << "Closed event is activated. Exit from game ..." << endl;
				break;
			case Event::KeyPressed:
				switch (event.key.code)
				{
				case Keyboard::Escape:
					isRunning = false;
					cout << "Escape is pressed. Exit from game ..." << endl;
					break;
				case Keyboard::P:
					isPlaying = !isPlaying;
					break;
				default:
					break;
				}
			default:
				break;
			}
		}

		// Render here
		window.clear();

		playerLeft.drawScore();
		playerRight.drawScore();

		if (isPlaying)
		{
			time = clock.restart().asMilliseconds();

			ball.update(time);

			playerRight.update(time);
			playerLeft.update(time);
			

			ball.draw();

			playerLeft.draw();
			playerRight.draw();

		}

		window.display();
	}

	window.close();

	return EXIT_SUCCESS;
}