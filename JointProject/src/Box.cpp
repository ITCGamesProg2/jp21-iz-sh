#include "Box.h"

void Box::draw(sf::RenderWindow& t_win)
{
	for (int i = 0; i < M_MAX_BOX; i++)
	{
		if (m_boxAlive[i])
		{
			t_win.draw(m_boxSprite[i]);
		}
		
	}
	// draw E button prompt on the active box when player is close to it
	if (m_drawInteractPrompt)
	{
		t_win.draw(m_interactPromptText);
	}
}

void Box::update(Player& t_player, sf::Sound& t_boxOpen)
{
	for (int i = 0; i < M_MAX_BOX; i++)
	{
		collisionBetweenPlayerAndBox(t_player);

		// check if box player was hiding in was destroyed
		if (t_player.isHidden() && m_boxAlive[m_activeBox] == false)
		{
			t_player.setHiddenStatus(false);
		}

		if (distanceBetween(t_player.getSprite().getPosition(), m_boxSprite[i].getPosition()) <= 130) // close enough to current box
		{
			if (m_boxAlive[i])
			{
				// store this close box as the active box
				m_activeBox = i;

				// enable drawing of E button interact prompt when it is possible to press E
				if (t_player.canE())
				{
					m_drawInteractPrompt = true;
				}
				else
				{
					m_drawInteractPrompt = false;
				}

				// set the position of the E button prompt on the active Box
				m_interactPromptText.setPosition(m_boxSprite[m_activeBox].getPosition().x - m_interactPromptText.getGlobalBounds().width,
					m_boxSprite[m_activeBox].getPosition().y - m_interactPromptText.getGlobalBounds().height);

				// check if player interacts with the box
				t_player.interactWithBox(t_boxOpen);

				break;
			}
			
		}
		else // not close enough to any box
		{
			m_drawInteractPrompt = false;
		}
	}
}

void Box::init(sf::Font& t_font)
{
	if (!m_boxTexture.loadFromFile("./resources/closedBox.png"))
	{
		std::string s("Error loading spritesheet");
		throw std::exception(s.c_str());
	}
	for (int i = 0; i < M_MAX_BOX; i++)
	{
		m_boxSprite[i].setTexture(m_boxTexture);
		m_boxSprite[i].setOrigin(m_boxSprite[i].getGlobalBounds().width / 2, m_boxSprite[i].getGlobalBounds().height / 2);
	}


	// set temp positions of the boxes
	m_boxSprite[0].setPosition(200, 200);
	m_boxSprite[1].setPosition(1200, 600);
	m_boxSprite[2].setPosition(400, 600);
	m_boxSprite[3].setPosition(750, 500);
	m_boxSprite[4].setPosition(1000, 800);
	m_boxSprite[5].setPosition(1200, 100);
	m_boxSprite[6].setPosition(m_boxSprite[0].getPosition().x + m_boxSprite[0].getGlobalBounds().width / 4, m_boxSprite[0].getPosition().y + m_boxSprite[0].getGlobalBounds().height /1.2);
	m_boxSprite[7].setPosition(m_boxSprite[6].getPosition().x - m_boxSprite[6].getGlobalBounds().width * 1.05, m_boxSprite[6].getPosition().y - m_boxSprite[6].getGlobalBounds().height / 4);
	m_boxSprite[8].setPosition(m_boxSprite[1].getPosition().x + m_boxSprite[1].getGlobalBounds().width * 1.05, m_boxSprite[1].getPosition().y + m_boxSprite[1].getGlobalBounds().height / 4);
	m_boxSprite[9].setPosition(m_boxSprite[1].getPosition().x + m_boxSprite[1].getGlobalBounds().width /1.1 , m_boxSprite[1].getPosition().y - m_boxSprite[1].getGlobalBounds().height / 1.2);
	m_boxSprite[10].setPosition(m_boxSprite[2].getPosition().x + m_boxSprite[2].getGlobalBounds().width / 1.1, m_boxSprite[2].getPosition().y - m_boxSprite[2].getGlobalBounds().height / 1.2);
	m_boxSprite[11].setPosition(m_boxSprite[2].getPosition().x + m_boxSprite[2].getGlobalBounds().width, m_boxSprite[2].getPosition().y + m_boxSprite[2].getGlobalBounds().height / 3);
	m_boxSprite[12].setPosition(m_boxSprite[2].getPosition().x - m_boxSprite[2].getGlobalBounds().width / 6, m_boxSprite[2].getPosition().y + m_boxSprite[2].getGlobalBounds().height / 1.2);
	m_boxSprite[13].setPosition(m_boxSprite[5].getPosition().x + m_boxSprite[5].getGlobalBounds().width , m_boxSprite[5].getPosition().y + m_boxSprite[5].getGlobalBounds().height / 4);
	m_boxSprite[14].setPosition(m_boxSprite[5].getPosition().x + m_boxSprite[5].getGlobalBounds().width / 6, m_boxSprite[5].getPosition().y + m_boxSprite[5].getGlobalBounds().height /1.1);
	m_boxSprite[15].setPosition(m_boxSprite[3].getPosition().x, m_boxSprite[3].getPosition().y - m_boxSprite[3].getGlobalBounds().height * 3.5);
	m_boxSprite[16].setPosition(m_boxSprite[15].getPosition().x - m_boxSprite[15].getGlobalBounds().width, m_boxSprite[15].getPosition().y + m_boxSprite[15].getGlobalBounds().height / 2);
	m_boxSprite[17].setPosition(m_boxSprite[4].getPosition().x + m_boxSprite[4].getGlobalBounds().width, m_boxSprite[4].getPosition().y + m_boxSprite[4].getGlobalBounds().height / 2);


	m_interactPromptText.setFont(t_font);
	m_interactPromptText.setString(m_interactPrompt);
	m_interactPromptText.setCharacterSize(30u);
	m_interactPromptText.setStyle(sf::Text::Bold | sf::Text::Underlined);
	m_interactPromptText.setFillColor(sf::Color::Red);

}


float Box::distanceBetween(sf::Vector2f t_entity, sf::Vector2f t_secondEntity)
{
	float distanceBetween = ((t_secondEntity.x - t_entity.x) * (t_secondEntity.x - t_entity.x)) + ((t_secondEntity.y - t_entity.y) * (t_secondEntity.y - t_entity.y));
	distanceBetween = std::sqrt(distanceBetween);
	return distanceBetween;
}


void Box::collisionBetweenPlayerAndBox(Player& t_player)
{
	int numIntersect = 0;
	for (int i = 0; i < M_MAX_BOX; i++)
	{
		if (m_boxAlive[i])
		{
			if (m_boxSprite[i].getGlobalBounds().intersects(t_player.getSprite().getGlobalBounds()))
			{
				numIntersect++;
			}
		}
	}
	if (numIntersect == 0)
	{
		m_previousPosition = t_player.getSprite().getPosition();
	}
	else
	{
		t_player.setPos(m_previousPosition);
	}
}

void Box::restart()
{
	for (int i = 0; i < M_MAX_BOX; i++)
	{
		m_boxAlive[i] = true;
	}
}
