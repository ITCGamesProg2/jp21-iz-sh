#include <iostream> 
#include "MainMenu.h"
#include "Game.h"

MainMenu::MainMenu()
{
}


MainMenu::~MainMenu()
{
}

//gets reference for the texture and sets properties for the buttons
void MainMenu::initialise(sf::Font& t_font)
{
	m_font = t_font;

	if (!m_buttonTexture.loadFromFile("./resources/button.png"))
	{
		std::cout << "Error with button texture";
	}

	if (!m_menuTexture.loadFromFile("./resources/menubg.jpg"))
	{
		std::cout << "Error with menu background";
	}

	m_menuScreen.setTexture(m_menuTexture);
	m_menuScreen.setScale(1.2, 1.3);
	m_menuScreen.setPosition(0, 0);

	if (!m_playerTexture.loadFromFile("./resources/standstill.png"))
	{
		std::cout << "Error with robot stand still texture";
	}

	m_playerSprite.setTexture(m_playerTexture);
	m_playerSprite.setPosition(ScreenSize::s_width - m_playerSprite.getGlobalBounds().width * 1.63, ScreenSize::s_height - m_playerSprite.getGlobalBounds().height * 1.1);
	m_playerSprite.setColor(m_robotColour[7]);

	for (int index = 0; index < MAX_BUTTON; index++)
	{
		m_buttonSprite[index].setTexture(m_buttonTexture);
		m_originalPos[index].x = m_buttonSprite[index].getGlobalBounds().width / 2 + m_buttonSprite[index].getGlobalBounds().height;
		m_originalPos[index].y = m_originalPos[index].x  / 2.5 + (m_buttonSpacing * index);

		m_buttonSprite[index].setPosition(m_originalPos[index]);
		m_pushedDownPos[index] = { m_buttonSprite[index].getPosition().x, m_buttonSprite[index].getPosition().y + 10 };

		m_buttonSprite[index].setOrigin(m_buttonSprite[index].getGlobalBounds().width / 2, m_buttonSprite[index].getGlobalBounds().height / 2);

		m_TextOnButton[index].setFont(m_font);
		m_TextOnButton[index].setString(m_menuTexts[index]);
		m_TextOnButton[index].setFillColor(sf::Color::White);
		m_TextOnButton[index].setCharacterSize(50u);

		m_TextOnButton[index].setOrigin(m_TextOnButton[index].getGlobalBounds().width / 2, m_TextOnButton[index].getGlobalBounds().height / 2);
	}
	for (int i = 0; i < MAX_COLOUR; i++)
	{
		m_colourSwatch[i].setFillColor(m_robotColour[i]);
		m_colourSwatch[i].setSize({50, 50 });
		m_colourSwatch[i].setPosition(ScreenSize::s_width - m_colourSwatch[i].getGlobalBounds().width * (MAX_COLOUR + 3) + (m_colourSwatch[i].getGlobalBounds().width * i), ScreenSize::s_height - m_colourSwatch[i].getGlobalBounds().height * MAX_COLOUR / 2.5);
		m_colourSwatch[i].setOutlineThickness(1);
		m_colourSwatch[i].setOutlineColor(sf::Color::Black);
	}

	float xCord = m_colourSwatch[0].getGlobalBounds().width * (MAX_COLOUR + 0.75);
	float yCord = m_colourSwatch[0].getGlobalBounds().height * 1.65;
	m_colourBg.setFillColor(sf::Color(33, 60, 83));
	m_colourBg.setSize({ xCord,yCord });
	m_colourBg.setPosition(m_colourSwatch[0].getPosition().x - m_colourSwatch[0].getGlobalBounds().width / 2, m_colourSwatch[0].getPosition().y - m_colourSwatch[0].getGlobalBounds().height / 3);


}
//draws the button sprites and text
void MainMenu::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_menuScreen);
	t_window.draw(m_playerSprite);
	t_window.draw(m_colourBg);
	for (int index = 0; index < MAX_BUTTON; index++)
	{
		t_window.draw(m_buttonSprite[index]);
		t_window.draw(m_TextOnButton[index]);
	}
	for (int i = 0; i < MAX_COLOUR; i++)
	{
		t_window.draw(m_colourSwatch[i]);
	}

}
//checks if mouseclick is within button boundary, changes gamestate if true
int MainMenu::processInput(sf::Window& t_window,Player & t_player, sf::Event t_event)
{
	int changeState = 0;
	sf::Vector2i mousePos;
	mousePos = sf::Mouse::getPosition(t_window);
	for (int i = 0; i < MAX_BUTTON; i++)
	{
		if (mousePos.x > m_buttonSprite[i].getGlobalBounds().left && mousePos.x < m_buttonSprite[i].getGlobalBounds().left + m_buttonSprite[i].getGlobalBounds().width &&
			mousePos.y > m_buttonSprite[i].getGlobalBounds().top && mousePos.y < m_buttonSprite[i].getGlobalBounds().top + m_buttonSprite[i].getGlobalBounds().height)
		{
			if (t_event.type == sf::Event::MouseButtonReleased)
			{
				changeState = i + 1;
			}
		}
	}
	
	/// <summary>
	/// lets player choose color of character by clicking on colour swatches
	/// </summary>
	/// <param name="t_window"></param>
	/// <param name="t_player"></param>
	/// <returns></returns>

	for (int i = 0; i < MAX_COLOUR; i++)
	{
		if (t_event.type == sf::Event::MouseButtonReleased)
		{
			if (m_colourSwatch[i].getGlobalBounds().contains((sf::Vector2f)mousePos))
			{
				m_playerSprite.setColor(m_robotColour[i]);
				m_colourSwatch[i].setOutlineColor(sf::Color::White);
				t_player.setColour(m_robotColour[i]);
			}
			else
			{
				m_colourSwatch[i].setOutlineColor(sf::Color::Black);
			}
		}
	}
	return changeState;
}

void MainMenu::update(sf::Window& t_window)
{
	sf::Vector2i mousePos;
	mousePos = sf::Mouse::getPosition(t_window);
	/// <summary>
	/// changes position and colour slightly to show which button is being pressed
	/// </summary>
	/// <param name="t_window"></param>
	/// <param name="t_player"></param>
	/// <returns></returns>
	for (int i = 0; i < MAX_BUTTON; i++)
	{
		if (mousePos.x > m_buttonSprite[i].getGlobalBounds().left && mousePos.x < m_buttonSprite[i].getGlobalBounds().left + m_buttonSprite[i].getGlobalBounds().width &&
			mousePos.y > m_buttonSprite[i].getGlobalBounds().top && mousePos.y < m_buttonSprite[i].getGlobalBounds().top + m_buttonSprite[i].getGlobalBounds().height)
		{
			m_buttonSprite[i].setPosition(m_pushedDownPos[i]);
			m_buttonSprite[i].setColor(sf::Color(135, 130, 189));

		}

		else
		{
			m_buttonSprite[i].setPosition(m_originalPos[i]);
			m_buttonSprite[i].setColor(sf::Color::White);
		}
		m_TextOnButton[i].setPosition(m_buttonSprite[i].getPosition().x, m_buttonSprite[i].getPosition().y - 10);
	}
}
