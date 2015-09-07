//////////////////////////////////////////////////////////// 
// Headers 
//////////////////////////////////////////////////////////// 
#include "stdafx.h" 
#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib") 

////////////////////////////////////////////////////////////
/// Entrypoint of application 
//////////////////////////////////////////////////////////// 


int main(int argc, char** argv)
{	
	
	// Window creation
	sf::RenderWindow app(sf::VideoMode(1440, 900, 32), "SFML Playground");	
	sf::Event event;
	bool running = true;
	// Loop forever
	while (running)
	{
		// While there are pending events.
		while (app.pollEvent(event))
		{
			// Window closed
			if (event.type == sf::Event::Closed)
			{
				return EXIT_SUCCESS;
			}
			// Key pressed
			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
				case sf::Keyboard::Escape:
					return EXIT_SUCCESS;
					break;
				case sf::Keyboard::Up:
					// Up key was pressed...
					break;
				default:
					break;
				}
			}

		}

		// Clearing screen
		app.clear(sf::Color(0, 0, 0, 0));
		// TODO: Draw sprites etc. here using app.draw()...	

		// Now display on-screen everthing that has been rendered to the SFML window.
		app.display();

	} // end loop forever
	
	
	return EXIT_SUCCESS;
}