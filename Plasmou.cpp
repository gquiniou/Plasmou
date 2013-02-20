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

#define MAP_SIZE 64
#define BLOC_SIZE 8

float distance(float x1, float y1, float x2, float y2) {
  return sqrt( pow(x2 - x1, 2) + pow(y2 - y1, 2));
}


void calculate(int (&map)[MAP_SIZE][MAP_SIZE], int t) {
  for (int x = 0; x < MAP_SIZE; x++) {
    for (int y = 0; y < MAP_SIZE; y++) {
      //map[x][y] = 127+ 128* sin( t * 3.14159 / 180);
      map[x][y] =  MAP_SIZE/2 + MAP_SIZE/2* sin(distance(x, y, 128+128*cos(t*3.14159/180),128));
      
      //	std::cout <<map[x][y] << std::endl;
    }
  }
}

/*
 * TODO
 * - screenshot
 * - chgt palette
 * - chgt algo
 *
 */

int main(void) {
  sf::RenderWindow App(sf::VideoMode(512, 512, 32), "Plasmou");
  App.setVerticalSyncEnabled(true);
  
  int  map[MAP_SIZE][MAP_SIZE];
  int time = 0;
  
  sf::Vector2f rect(BLOC_SIZE, BLOC_SIZE);
  
  sf::Color palette[256];
  int j, k, l;
  for (int i = 0; i < 256; i++) {
    j =  k = l =   sin(i * 180/255 * 3.14159265/180) *255;
    
    palette[i] = sf::Color(j, k, l,255);
    //std::cout << (int)palette[i].r << std::endl;
  }
  
  while (App.isOpen()) {
    
    sf::Event Event;
    while (App.pollEvent(Event)) {
      if ((Event.type == sf::Event::Closed) || ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Escape))) {
	App.close();
	break;
      }
    }
    App.clear();
    time++;
    calculate(map, time++);

    for (int x = 0; x < MAP_SIZE; x++) {
      for (int y = 0; y < MAP_SIZE; y++) {
	sf::RectangleShape r(rect);
	r.setFillColor(palette[map[x][y]]);
	r.setPosition(x * BLOC_SIZE, y * BLOC_SIZE);
	App.draw(r);
      }
    }
    
    App.display();
  }
}
