#include "Help.h"

void HelpScreen::initialise(sf::Font& t_font)
{
	m_font = t_font;

	if (!m_controlsTexture.loadFromFile("./resources/keyboard.png"))
	{
		std::cout << "Error with keyboard texture";
	}
	
	m_controlsSprite.setTexture(m_controlsTexture);
	m_controlsSprite.setScale(2, 2);
	m_controlsSprite.setOrigin(m_controlsSprite.getGlobalBounds().width / 2, m_controlsSprite.getGlobalBounds().height / 2);
	m_controlsSprite.setPosition(ScreenSize::s_width / 2, ScreenSize::s_height / 4);

	if (!m_buttonTexture.loadFromFile("./resources/button.png"))
	{
		std::cout << "Error with button texture";
	}

	m_buttonSprite.setTexture(m_buttonTexture);
	m_originalPos.x = (m_buttonSprite.getGlobalBounds().width / 2 + m_buttonSprite.getGlobalBounds().height) * 1.75;
	m_originalPos.y = m_originalPos.x;
	m_buttonSprite.setPosition(m_originalPos);

	m_pushedDownPos = { m_buttonSprite.getPosition().x, m_buttonSprite.getPosition().y + 10 };

	m_buttonSprite.setOrigin(m_buttonSprite.getGlobalBounds().width / 2, m_buttonSprite.getGlobalBounds().height / 2);

	m_exitText.setFont(m_font);
	m_exitText.setString("Click here to return to main menu");
	m_exitText.setFillColor(sf::Color::White);
	m_exitText.setCharacterSize(30u);

	m_exitText.setOrigin(m_exitText.getGlobalBounds().width / 2, m_exitText.getGlobalBounds().height / 2);

	m_helpTextString = "Use WASD To Move. Press E near a box to hide in it and look for a weapon and ammo pickups. \n Once you found the gun, you can shoot in any direction by clicking on the screen. \n ";
	m_helpText.setString(m_helpTextString);
	m_helpText.setCharacterSize(30u);
	m_helpText.setOutlineThickness(2u);
	m_helpText.setOutlineColor(sf::Color::White);
	m_helpText.setFont(m_font);
	m_helpText.setFillColor(sf::Color::Red);
	m_helpText.setOrigin(m_helpText.getGlobalBounds().width / 2, m_helpText.getGlobalBounds().height / 2);
	m_helpText.setPosition(ScreenSize::s_width / 2, ScreenSize::s_height / 2);
}

void HelpScreen::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_controlsSprite);
	t_window.draw(m_buttonSprite);
	t_window.draw(m_helpText);
	t_window.draw(m_exitText);

}

bool HelpScreen::processInput(sf::Window& t_window,sf::Event t_event)
{
	sf::Vector2i mousePos;
	mousePos = sf::Mouse::getPosition(t_window);

	bool changeState = false;
	
	if (mousePos.x > m_buttonSprite.getGlobalBounds().left && mousePos.x < m_buttonSprite.getGlobalBounds().left + m_buttonSprite.getGlobalBounds().width &&
		mousePos.y > m_buttonSprite.getGlobalBounds().top && mousePos.y < m_buttonSprite.getGlobalBounds().top + m_buttonSprite.getGlobalBounds().height)
	{
		if (t_event.type == sf::Event::MouseButtonReleased)
		{
			changeState = true;
		}
	}
	return changeState;
}

void HelpScreen::update(sf::Window& t_window)
{
	sf::Vector2i mousePos;
	mousePos = sf::Mouse::getPosition(t_window);

	/// <summary>
	/// changes position and colour slightly to show which button is being pressed
	/// </summary>
	/// <param name="t_window"></param>
	/// <returns></returns>
	if (mousePos.x > m_buttonSprite.getGlobalBounds().left && mousePos.x < m_buttonSprite.getGlobalBounds().left + m_buttonSprite.getGlobalBounds().width &&
		mousePos.y > m_buttonSprite.getGlobalBounds().top && mousePos.y < m_buttonSprite.getGlobalBounds().top + m_buttonSprite.getGlobalBounds().height)
	{
		m_buttonSprite.setPosition(m_pushedDownPos);
		m_buttonSprite.setColor(sf::Color(135, 130, 189));

	}
	else
	{
		m_buttonSprite.setPosition(m_originalPos);
		m_buttonSprite.setColor(sf::Color::White);
	}
	m_exitText.setPosition(m_buttonSprite.getPosition().x, m_buttonSprite.getPosition().y - 10);
}
