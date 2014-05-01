// worldsim.cpp
// worldsim main simulation file - loads world and objects
// Samuel Cagle
// Juston Li
// Xu Junjie, Kevin
// University of Oregon
// 2014-04-16

#include <iostream>
using std::cout;
using std::endl;
#include <string>
#include <SFML/Graphics.hpp>

#include "Entity.h"
#include "EntityManager.h"
#include "units.h"
#include "World.h"
using namespace gws;

units world;

void setupGraphics() {
	// Setup Window
	sf::RenderWindow window(sf::VideoMode(0, 0), "Testing", sf::Style::Fullscreen);
  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Green);

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        window.close();
    }

    window.clear();
    window.draw(shape);
    window.display();
  }
}
void teardownGraphics() {

}

void createUnits(World& world) {
	cout << "Creating units...\n";
	// Create a basic plant;
	// Entities should be added to the world here
}

void runWorld() {
	cout << "Running world...\n";
	// Simulation loop should be here
	
	// Run Systems
}

void teardown()
{
	cout << "Tearing down...\n";
}

int main (int, char**)
{
	setupGraphics();
	EntityManager man;
	Entity ents;
	// create world
	World world;
	// create units
	createUnits(world);
	// run world
	runWorld();
	// teardown
	teardown();
	teardownGraphics();
	return 0;
}