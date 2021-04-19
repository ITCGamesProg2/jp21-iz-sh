#include "Cutscene.h"

Cutscene::Cutscene()
{
	m_introText[0] = "According to all known laws of Astrobiology, there is no way \nany life form could exist within the same galaxy as the humans.\n";
	m_introText[1] = "Such vengeful creatures don't make the best neighbours and so \nall other lifeforms have abandoned the Milky Way in search \nof a better neighbourhood.";
	m_introText[2] = "All except one...\n\n\n			You.\n";
	m_introText[3] = "You apparently have missed the memo and as a result was captured\n by mad human scientists who really have no idea what they're doing.\n";
	m_introText[4] = "Such primitive technology. Breaking out wasn't hard.\n";
	m_introText[5] = "Now you're on the run from the androids the scientists have \nsent after you.\n";
	m_introText[6] = "In the distance you notice the house of Wares. That should provide\n you with some cover.\n";
	m_introText[7] = "Time to play hide n seek with these droids. \n			Perhaps you will find a weapon.\n\n			May the smartest lifeform win!";

}

void Cutscene::init(sf::Font& t_font)
{
	if (!m_bgTexture.loadFromFile("./resources/cutscene.png"))
	{
		std::cout << "Error with cutscene bg texture";
	}

	m_bgSprite.setTexture(m_bgTexture);
	m_bgSprite.setPosition(0, 0);

	if (!m_blackOutTexture.loadFromFile("./resources/blackout.png"))
	{
		std::cout << "Error with cutscene blackout texture";
	}

	m_blackOutSprite.setTexture(m_blackOutTexture);
	m_blackOutSprite.setPosition(0, 0);

	if (!m_robotTexture.loadFromFile("./resources/robot.png"))
	{
		std::cout << "Error with cutscene robot texture";
	}


	if (!m_playerTexture.loadFromFile("./resources/head.png"))
	{
		std::cout << "Error with cutscene bg texture";
	}

	m_playerSprite.setTexture(m_playerTexture);
	m_playerSprite.setScale(3, 3);
	m_playerSprite.setOrigin(m_playerSprite.getGlobalBounds().width / 2, m_playerSprite.getGlobalBounds().height / 2);
	m_playerSprite.setPosition(1300, 900);

	if (!m_torsoTexture.loadFromFile("./resources/torso.png"))
	{
		std::cout << "Error with cutscene bg texture";
	}

	m_torsoSprite.setTexture(m_torsoTexture);
	m_torsoSprite.setScale(0.25, 0.25);
	m_torsoSprite.setOrigin(m_torsoSprite.getGlobalBounds().width / 2, m_torsoSprite.getGlobalBounds().height / 2);
	m_torsoSprite.setPosition(820,600);

	m_robotSprite.setTexture(m_robotTexture);
	m_robotSprite.setScale(-2.7, 2.7);
	m_robotSprite.setOrigin(m_robotSprite.getGlobalBounds().width / 2, m_robotSprite.getGlobalBounds().height / 2);
	m_robotSprite.setPosition(m_robotSprite.getGlobalBounds().width / 2, m_robotSprite.getGlobalBounds().height * 3);

	for (int i = 0; i < MAX_INTRO; i++)
	{
		m_intro[i].setFont(t_font);
		m_intro[i].setCharacterSize(50u);
		m_intro[i].setString(m_introText[i]);
		m_intro[i].setOrigin(m_intro[i].getGlobalBounds().width / 2, m_intro[i].getGlobalBounds().height / 2);
		m_intro[i].setPosition(ScreenSize::s_width / 2,1000 + m_intro[0].getGlobalBounds().height  *  1.7 * i);
	}
}

void Cutscene::draw(sf::RenderWindow& t_window)
{
	t_window.draw(m_bgSprite);
	t_window.draw(m_robotSprite);
	t_window.draw(m_torsoSprite);
	t_window.draw(m_playerSprite);
	t_window.draw(m_blackOutSprite);
	for (int i = 0; i < MAX_INTRO; i++)
	{
		t_window.draw(m_intro[i]);
	}
}

/// <summary>
/// moves up the text and changes gamestate when all text is gone from screen
/// </summary>
/// <returns></returns>
bool Cutscene::update()
{
	for (int i = 0; i < MAX_INTRO; i++)
	{
		m_intro[i].move(0, -1);
	}
	if (m_intro[7].getPosition().y < -m_intro[7].getGlobalBounds().height)
	{
		return true;
	}
	else
	{
		return false;
	}
}
