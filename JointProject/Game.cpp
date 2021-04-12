#include "Game.h"

Game::Game() : player(playerSpriteSheet)
{
	window.create(sf::VideoMode(800, 600), "Endless Runner Game");
}

void Game::init()
{
	view = window.getDefaultView();


	if (!playerTextureSheet.loadFromFile("character_robot_sheet.png"))
	{
		// error...
	}


	playerSpriteSheet.setTexture(playerTextureSheet);
	player.InitAnimationData();



	player.startAnimaton(Player::PlayerAnimationState::walk);

}

void Game::run()
{
		sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);

		sf::Time timeSinceLastUpdate = sf::Time::Zero;

		sf::Clock clock;


		clock.restart();

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			timeSinceLastUpdate += clock.restart();

			if (timeSinceLastUpdate > timePerFrame)
			{
				player.Update();


				window.clear();
				player.Draw(window);
				window.display();

				timeSinceLastUpdate = sf::Time::Zero;
			}
		}
}
