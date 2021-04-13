#include "Game.h"

Game::Game() : player(playerSpriteSheet)
{
	window.create(sf::VideoMode(800, 600), "Joint Project");
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

	for (int i = 0; i < NUM_BOXES; i++)
	{
		boxes[i].initSprite();
	}

	// set temp positions of the boxes
	boxes[0].setPosition({ 100, 200 });
	boxes[1].setPosition({ 250, 300 });
	boxes[2].setPosition({ 400, 400 });
	boxes[3].setPosition({ 550, 300 });
	boxes[4].setPosition({ 650, 200 });

	initText();

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

			update();
			draw();

			timeSinceLastUpdate = sf::Time::Zero;
		}
	}
}

void Game::draw()
{
	window.clear();

	// draw boxes
	for (int i = 0; i < NUM_BOXES; i++)
	{
		boxes[i].draw(window);
	}

	// draw player if they are not hiding in a box
	if (player.m_hidden == false)
	{
		player.Draw(window);
	}

	// draw E button prompt on the active box when player is close to it
	if (m_drawInteractPrompt)
	{
		window.draw(m_interactPromptText);
	}

	window.display();
}

void Game::update()
{
	// update player movement
	player.Update();

	// store player pos
	sf::Vector2f playerPos = player.spriteSheet.getPosition();
	
	for (int i = 0; i < NUM_BOXES; i++)
	{
		// store box pos currently being checked
		sf::Vector2f boxPos = boxes[i].getPosition();

		if (distanceBetween(playerPos, boxPos) <= 100) // close enough to current box
		{
			// store this close box as the active box
			m_activeBox = i;

			sf::Sprite temp = boxes[m_activeBox].getSprite();

			player.collisionBetweenPlayerAndBox(temp);

			// enable drawing of E button interact prompt when it is possible to press E
			// note: this is messy and is only working because of the m_canPressE bool in player class is public.
			// when members of player are made private, adjustments to this functionality will have to be made.
			if (player.m_canPressE)
			{
				m_drawInteractPrompt = true;
			}
			else
			{
				m_drawInteractPrompt = false;
			}
			
			// set the position of the E button prompt on the active Box
			m_interactPromptText.setPosition(boxes[m_activeBox].getPosition().x - m_interactPromptText.getGlobalBounds().width ,
				boxes[m_activeBox].getPosition().y - m_interactPromptText.getGlobalBounds().height);

			// check if player interacts with the box
			player.interactWithBox();

			break;
		}
		else // not close enough to any box
		{
			m_drawInteractPrompt = false;
		}
	}
}

void Game::initText()
{
	if (!m_font.loadFromFile("arial.ttf"))
	{
		std::string s("Error loading font");
		throw std::exception(s.c_str());
	}

	m_interactPromptText.setFont(m_font);
	m_interactPromptText.setString(m_interactPrompt);
	m_interactPromptText.setCharacterSize(30u);
	m_interactPromptText.setStyle(sf::Text::Bold | sf::Text::Underlined);
	m_interactPromptText.setFillColor(sf::Color::Red);
}


float Game::distanceBetween(sf::Vector2f entity, sf::Vector2f secondEntity)
{
	float distanceBetween = ((secondEntity.x - entity.x ) * (secondEntity.x - entity.x )) + ((secondEntity.y - entity.y ) * (secondEntity.y - entity.y ));
	distanceBetween = std::sqrt(distanceBetween);
	return distanceBetween;
}
