#include "ParticalEffects.h"

void Particle::draw(sf::RenderWindow& win)
{
	if (timetoLive > 0)
	{
		win.draw(particleShape);
	}
}

void Particle::update()
{
	if (timetoLive > 0)
	{
		particleShape.move(velocity);

		timetoLive--;
	}
}

Particle::Particle(sf::Vector2f pos, sf::Vector2f vel, sf::Color color)
{
	particleShape.setSize(sf::Vector2f(3, 3));
	particleShape.setPosition(pos);
	particleShape.setFillColor(color);

	velocity = vel;
	timetoLive = rand() % 50;
}

void ParticleSystem::spawnExplosion(sf::Vector2f pos, sf::Color color)
{
	position = pos;
	for (int i = 0; i < M_MAX_PARTICLES; i++)
	{
		m_explosionParticles[i] = Particle(position, sf::Vector2f(rand() / double(RAND_MAX) * 4 - 2, rand() / double(RAND_MAX) * 4 - 2), color);
	}
}

void ParticleSystem::update()
{
	for (int i = 0; i < M_MAX_PARTICLES; i++)
	{
		m_explosionParticles[i].update();
	}
}

void ParticleSystem::draw(sf::RenderWindow& win)
{
	for (int i = 0; i < M_MAX_PARTICLES; i++)
	{
		m_explosionParticles[i].draw(win);
	}
}
