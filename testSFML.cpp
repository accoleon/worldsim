#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
 
int main()
{
    // Create the main window
    sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Hello World - SFML");
 
    // Start the main loop
    while (App.isOpen())
    {
        // Process events
        sf::Event Event;
        while (App.pollEvent(Event))
        {
            // Close window : exit
            if (Event.type == sf::Event::Closed)
                App.close();
						std::vector<int> vec;
						vec.push_back(1);
						vec.push_back(2);
						for (auto num : vec) {
							std::cout << num << std::endl;
						}
        }
 
        // Clear screen, and fill it with blue
        App.clear(sf::Color(0x00, 0x00, 0xff));
 
        // Display the content of the window on screen
        App.display();
    }
 
    return 0;
}