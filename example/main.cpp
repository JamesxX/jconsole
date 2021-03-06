#include "public/console.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

int main() {

	sf::RenderWindow window(sf::VideoMode(800, 600), "JConsole");

	JCON_NAMESPACE::console* MyConsole = JCON_NAMESPACE::consoleFactory();
	MyConsole->setWindow(&window);

	MyConsole->AppendLine({ "Welcome to the console!" });

	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();

			else if (event.type == sf::Event::Resized)
				MyConsole->HandleWindowOnResize(&event);

		}

		window.clear();
		MyConsole->Paint();
		window.display();
	}

	delete MyConsole;
}
