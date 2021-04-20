#include "HUD.h"

HUD::HUD()
{

}

void HUD::init(sf::Font& t_font)
{
	m_hiddenStatusText.setFont(t_font);
	m_hiddenStatusText.setString("Exposed");
	m_hiddenStatusText.setCharacterSize(30u);
	m_hiddenStatusText.setStyle(sf::Text::Italic);
	m_hiddenStatusText.setFillColor(sf::Color::Red);
	m_hiddenStatusText.setOrigin(m_hiddenStatusText.getGlobalBounds().width / 2, m_hiddenStatusText.getGlobalBounds().height / 2);
	m_hiddenStatusText.setPosition(ScreenSize::s_width - (ScreenSize::s_width / 10), ScreenSize::s_height - (ScreenSize::s_height / 10));
	m_hiddenStatusText.setOutlineThickness(2u);
	m_hiddenStatusText.setOutlineColor(sf::Color::White);

	m_ammoCounterText.setFont(t_font);
	m_ammoCounterText.setString("");
	m_ammoCounterText.setCharacterSize(30u);
	m_ammoCounterText.setStyle(sf::Text::Italic);
	m_ammoCounterText.setFillColor(sf::Color::Red);
	m_ammoCounterText.setOutlineThickness(2u);
	m_ammoCounterText.setOutlineColor(sf::Color::White);


	m_gunStatusText.setFont(t_font);
	m_gunStatusText.setString("Unarmed");
	m_gunStatusText.setCharacterSize(30u);
	m_gunStatusText.setStyle(sf::Text::Italic);
	m_gunStatusText.setFillColor(sf::Color::Red);
	m_gunStatusText.setOrigin(m_gunStatusText.getGlobalBounds().width / 2, m_gunStatusText.getGlobalBounds().height / 2);
	m_gunStatusText.setPosition(ScreenSize::s_width / 2, ScreenSize::s_height - (ScreenSize::s_height / 10));
	m_gunStatusText.setOutlineThickness(2u);
	m_gunStatusText.setOutlineColor(sf::Color::White);

}

void HUD::update(Player& t_player)
{
	if (t_player.isHidden())
	{
		m_hiddenStatusText.setString("Hidden");
	}
	else
	{
		m_hiddenStatusText.setString("Exposed");
	}

	if (t_player.doesHaveGun())
	{
		m_gunStatusText.setString("You Have The Gun!");
	}
	else
	{
		m_gunStatusText.setString("Unarmed");
	}

	m_gunStatusText.setOrigin(m_gunStatusText.getGlobalBounds().width / 2, m_gunStatusText.getGlobalBounds().height / 2);
	m_gunStatusText.setPosition(ScreenSize::s_width / 2, ScreenSize::s_height - (ScreenSize::s_height / 10));

	m_ammoCounterText.setString("Ammo: " + std::to_string(t_player.getAmmo()));
	m_ammoCounterText.setOrigin(m_ammoCounterText.getGlobalBounds().width / 2, m_ammoCounterText.getGlobalBounds().height / 2);
	m_ammoCounterText.setPosition((ScreenSize::s_width / 10), ScreenSize::s_height - (ScreenSize::s_height / 10));
}

void HUD::draw(sf::RenderWindow& window)
{
	window.draw(m_hiddenStatusText);
	window.draw(m_ammoCounterText);
	window.draw(m_gunStatusText);
}
