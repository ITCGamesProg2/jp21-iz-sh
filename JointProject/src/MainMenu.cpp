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
	m_menuScreen.setSize(sf::Vector2f(ScreenSize::s_width, ScreenSize::s_height));
	m_menuScreen.setPosition(0, 0);
	m_menuScreen.setFillColor(sf::Color::Black);

	m_font = t_font;

	if (!m_buttonTexture.loadFromFile("./resources/button.png"))
	{
		std::cout << "Error with button texture";
	}

	/*if (!m_pyreTexture.loadFromFile("ASSETS/IMAGES/pyre.png"))
	{
		std::cout << "Error with pyre texture";
	}*/

	//m_pyreSprite.setTexture(m_pyreTexture);
	//m_pyreSprite.setPosition(80, 100);
	//m_pyreSprite.setScale(7, 8);

	m_buttonWidth = 600.0f;
	m_buttonSpacing = 250.0f;
	m_Offset = (ScreenSize::s_width - m_buttonWidth + 200) / 2;
	m_buttonHeight = 100;
	m_OffsetOfTop = (ScreenSize::s_height - m_buttonHeight) / 7;
	sf::String m_menuTexts[m_buttonCount] = { "Play","Help","Exit" };
	int textDropOff = 15;

	for (int index = 0; index < m_buttonCount; index++)
	{
		m_buttonPic[index].setTexture(m_buttonTexture);
		m_buttonPic[index].setPosition(m_Offset, m_buttonSpacing * index + m_OffsetOfTop);

		sf::Vector2u sizeOfTexture = m_buttonTexture.getSize();
		m_buttonPic[index].setScale((m_buttonWidth / sizeOfTexture.x), (m_buttonHeight / sizeOfTexture.y));

		m_TextOnButton[index].setFont(m_font);
		m_TextOnButton[index].setString(m_menuTexts[index]);
		m_TextOnButton[index].setFillColor(sf::Color::White);
		m_TextOnButton[index].setCharacterSize(50u);

		sf::FloatRect textSize = m_TextOnButton[index].getGlobalBounds();
		float offSetText = (m_buttonWidth - textSize.width) / 2;
		m_TextOnButton[index].setPosition(m_Offset + offSetText, m_buttonSpacing * index + m_OffsetOfTop + textDropOff);
	}
}
//draws the button sprites and text
void MainMenu::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_menuScreen);
	//t_window.draw(m_pyreSprite);
	for (int index = 0; index < m_buttonCount; index++)
	{
		t_window.draw(m_buttonPic[index]);
		t_window.draw(m_TextOnButton[index]);
	}
}
//checks if mouseclick is within button boundary, changes gamestate if true
int MainMenu::update(sf::Window& t_window)
{
	int changeState = 0;

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::Vector2i MouseClick;
		MouseClick = sf::Mouse::getPosition(t_window);
		if (MouseClick.x > m_Offset && MouseClick.x < m_Offset + m_buttonWidth)
		{
			if (MouseClick.y > m_OffsetOfTop && MouseClick.y < m_OffsetOfTop + m_buttonHeight)
			{
				changeState = 1;
			}
			if (MouseClick.y > m_OffsetOfTop + m_buttonSpacing && MouseClick.y < m_OffsetOfTop + m_buttonSpacing + m_buttonHeight)
			{
				changeState = 2;
			}
			if (MouseClick.y > m_OffsetOfTop + m_buttonSpacing * 2 && MouseClick.y < m_OffsetOfTop + m_buttonHeight + m_buttonSpacing * 2)
			{
				t_window.close();
			}
		}

	}
	return changeState;
}