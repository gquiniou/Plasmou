//============================================================================
// Name        : Plasmou.cpp
// Author      : greg
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================


#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>
#include <cmath>

#define MAP_SIZE 256
#define BLOC_SIZE 4

float distance(float x1, float y1, float x2, float y2) {
	return sqrt( pow(x2 - x1, 2) + pow(y2 - y1, 2));
}


void calculate(int (&map)[MAP_SIZE][MAP_SIZE], int t) {
	for (int x = 0; x < MAP_SIZE; x++) {
		for (int y = 0; y < MAP_SIZE; y++) {
			map[x][y] = 127+ 128* sin(  (cos(x*50) +t - cos(y*25) + distance(x,y, 35,120))/ 1.01255);
		//	std::cout <<map[x][y] << std::endl;
		}
	}
}

int main(void) {
	sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Plasmou");
	App.EnableVerticalSync(true);

	int  map[MAP_SIZE][MAP_SIZE];
	int time = 0;

	sf::Vector2f rect(BLOC_SIZE, BLOC_SIZE);

	sf::Color palette[256];
	for (int i = 0; i < 256; i++) {
		palette[i] = sf::Color(i, i, i,255);
		//std::cout << (int)palette[i].r << std::endl;
	}

	while (App.IsOpened()) {

		sf::Event Event;
		while (App.PollEvent(Event)) {
			if ((Event.Type == sf::Event::Closed) ||
					((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Keyboard::Escape))) {
				App.Close();
				break;
			}

		}
		App.Clear();

		calculate(map, time++);

		for (int x = 0; x < MAP_SIZE; x++) {
			for (int y = 0; y < MAP_SIZE; y++) {
				sf::RectangleShape r(rect);
				r.SetFillColor(palette[map[x][y]]);
				r.SetPosition(x * BLOC_SIZE, y * BLOC_SIZE);
				App.Draw(r);
			}
		}


		App.Display();
	}
}
