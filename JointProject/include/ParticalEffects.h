#pragma once
#include <SFML/Graphics.hpp>

class Particle
{
public:
	int timetoLive = 0;
	sf::Vector2f velocity;
	sf::RectangleShape particleShape;

	void draw(sf::RenderWindow& win);
	
	void update();

	Particle() {}

	Particle(sf::Vector2f pos, sf::Vector2f vel, sf::Color color);
};


class ParticleSystem
{
public:

	static const int M_MAX_PARTICLES = 50;

	Particle m_explosionParticles[M_MAX_PARTICLES];

	sf::Vector2f position;

	void spawnExplosion(sf::Vector2f pos, sf::Color color);

	void update();
	
	void draw(sf::RenderWindow& win);

	ParticleSystem() {}
};