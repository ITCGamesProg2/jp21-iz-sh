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

	m_ammoCounterText.setFont(t_font);
	m_ammoCounterText.setString("");
	m_ammoCounterText.setCharacterSize(30u);
	m_ammoCounterText.setStyle(sf::Text::Italic);
	m_ammoCounterText.setFillColor(sf::Color::Red);
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

	m_ammoCounterText.setString("Ammo: " + std::to_string(t_player.getAmmo()));
	m_ammoCounterText.setOrigin(m_ammoCounterText.getGlobalBounds().width / 2, m_ammoCounterText.getGlobalBounds().height / 2);
	m_ammoCounterText.setPosition((ScreenSize::s_width / 10), ScreenSize::s_height - (ScreenSize::s_height / 10));
}

void HUD::draw(sf::RenderWindow& window)
{
	window.draw(m_hiddenStatusText);
	window.draw(m_ammoCounterText);
}
