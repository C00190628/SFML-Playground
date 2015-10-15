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
#include <vector>
#include "stdafx.h"

////////////////////////////////////////////////////////////
/// Entrypoint of application 
//////////////////////////////////////////////////////////// 


int main(int argc, char** argv)
{
	
	
	// Window creation
	sf::RenderWindow app(sf::VideoMode(1440, 900, 32), "SFML Playground");	
	sf::Sprite mySprite [3];

	sf::Texture myTexture;
	
	//std::vector<int> myVector;
	//std::vector<int> myVector;	
	//3, sf::Sprite(myTexture)
	std::vector<sf::Sprite> myVector[3];
	//int size = myVector.size();
	int index = 0;
	int size;

	sf::Event event;
	bool running = true;

	for (int i = 0; i < 3; i++)
	{
		mySprite[i].setPosition(300 + i * 100, 300 +i * 100);
		myVector[i].push_back(mySprite[i]);
		myVector[i].push_back(sf::Sprite(mySprite[i]));
		myVector[i].at(index).setPosition(100 + i * 100, 100 + i * 100);
	}



	if (!myTexture.loadFromFile("Tower.png"))
	{
		std::string s("Error loading texture");
		throw std::exception(s.c_str());
	}
	// Leave the declaration of variable mySprite at the start of main.
	

	
	// Loop forever
	while (running)
	{
		// While there are pending events.
		while (app.pollEvent(event))
		{
			for (int i = 0; i < 3; i++)
			{

				mySprite[i].setTexture(myTexture);
				sf::Sprite spriter = myVector[i].at(index);

			}

			
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
		
			//app.draw(mySprite);
			//mySprite.setRotation(1);
			mySprite[0].setOrigin(sf::Vector2f(31, 40));
			mySprite[0].setPosition(0, 0);
			mySprite[0].rotate(1);
			for (int i = 0; i < 3; i++)
			{

				app.draw(mySprite[i]);

			}


		app.setFramerateLimit(60);
		//app.draw(myVector);
		// Now display on-screen everthing that has been rendered to the SFML window.
		app.display();

	} // end loop forever
	
	
	return EXIT_SUCCESS;
}