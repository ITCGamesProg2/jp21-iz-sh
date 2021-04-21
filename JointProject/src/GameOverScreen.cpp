#include "GameOverScreen.h"

void GameOverScreen::initialise(sf::Font& t_font)
{
	m_font = t_font;


	if (!m_buttonTexture.loadFromFile("./resources/button.png"))
	{
		//std::cout << "Error with button texture";
	}

	m_buttonSprite.setTexture(m_buttonTexture);
	m_originalPos.x = (m_buttonSprite.getGlobalBounds().width / 2 + m_buttonSprite.getGlobalBounds().height) * 1.75;
	m_originalPos.y = m_originalPos.x;
	m_buttonSprite.setPosition(m_originalPos);

	m_pushedDownPos = { m_buttonSprite.getPosition().x, m_buttonSprite.getPosition().y + 10 };

	m_buttonSprite.setOrigin(m_buttonSprite.getGlobalBounds().width / 2, m_buttonSprite.getGlobalBounds().height / 2);

	m_exitText.setFont(m_font);
	m_exitText.setString("Click here to restart");
	m_exitText.setFillColor(sf::Color::White);
	m_exitText.setCharacterSize(30u);

	m_exitText.setOrigin(m_exitText.getGlobalBounds().width / 2, m_exitText.getGlobalBounds().height / 2);

	m_gameOverString = "GAME OVER. YOU COULD NOT DEFEND YOURSELF AGAINST THE ROBOTS. ";
	m_gameOverText.setString(m_gameOverString);
	m_gameOverText.setCharacterSize(30u);
	m_gameOverText.setOutlineThickness(2u);
	m_gameOverText.setOutlineColor(sf::Color::White);
	m_gameOverText.setFont(m_font);
	m_gameOverText.setFillColor(sf::Color::Black);
	m_gameOverText.setOrigin(m_gameOverText.getGlobalBounds().width / 2, m_gameOverText.getGlobalBounds().height / 2);
	m_gameOverText.setPosition(ScreenSize::s_width / 2, ScreenSize::s_height / 2);
}

void GameOverScreen::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_gameOverText);
	t_window.draw(m_buttonSprite);
	t_window.draw(m_exitText);
}

bool GameOverScreen::processInput(sf::Window& t_window, sf::Event t_event)
{
	sf::Vector2i mousePos;
	mousePos = sf::Mouse::getPosition(t_window);

	bool changeState = false;

	if (mousePos.x > m_buttonSprite.getGlobalBounds().left&& mousePos.x < m_buttonSprite.getGlobalBounds().left + m_buttonSprite.getGlobalBounds().width &&
		mousePos.y > m_buttonSprite.getGlobalBounds().top&& mousePos.y < m_buttonSprite.getGlobalBounds().top + m_buttonSprite.getGlobalBounds().height)
	{
		if (t_event.type == sf::Event::MouseButtonReleased)
		{
			changeState = true;
		}
	}
	return changeState;
}

void GameOverScreen::update(sf::Window& t_window, bool t_win)
{
	sf::Vector2i mousePos;
	mousePos = sf::Mouse::getPosition(t_window);

	/// <summary>
	/// changes position and colour slightly to show which button is being pressed
	/// </summary>
	/// <param name="t_window"></param>
	/// <returns></returns>
	if (mousePos.x > m_buttonSprite.getGlobalBounds().left&& mousePos.x < m_buttonSprite.getGlobalBounds().left + m_buttonSprite.getGlobalBounds().width &&
		mousePos.y > m_buttonSprite.getGlobalBounds().top&& mousePos.y < m_buttonSprite.getGlobalBounds().top + m_buttonSprite.getGlobalBounds().height)
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

	if (t_win)
	{
		m_gameOverString = "YOU SURVIVED!";
		m_gameOverText.setString(m_gameOverString);

	}
	else
	{
		m_gameOverString = "GAME OVER. YOU COULD NOT DEFEND YOURSELF AGAINST THE ROBOTS. ";
		m_gameOverText.setString(m_gameOverString);
	}
	m_gameOverText.setOrigin(m_gameOverText.getGlobalBounds().width / 2, m_gameOverText.getGlobalBounds().height / 2);
	m_gameOverText.setPosition(ScreenSize::s_width / 2, ScreenSize::s_height / 2);
}
