@startuml
scale 1800*800

package "Player Interaction with game"{

class Game 
{
    init()
    processMouseInput(sf::Event t_event)
    run()
    draw()
    update()
    restart()
    initSound()
}

class Animation {

	int numframes;
	int startOffset;
	int speed;
	bool loop;

}
class AnimationSheet
{

	int frameCounter;
	sf::Vector2i frameSize{  };
	int numRows = 0;
	int numCols = 0;
	Animation curAnimation;
	int curFrameOffset = 0;

	void init(int _pixelWidth, int _pixelHeight, int _numRows, int _numCols)
	
	sf::IntRect getFrame()
	
	void startAnimation(Animation curAnimation)
	
	void nextFrame()
}

class Box
{
    Box() 
	
    void draw(sf::RenderWindow& t_win);

	
    void update(Player &t_player, sf::Sound& t_boxOpen);

	
    void init(sf::Font& t_font);

    float distanceBetween(sf::Vector2f t_entity, sf::Vector2f t_secondEntity);

    void collisionBetweenPlayerAndBox(Player& t_playerSprite);

    sf::Sprite getSprite(int t_arrayCell)
	
    int getMaxBox()
	

    int getActiveBox()
	

    void setAlive(int t_arrayCell)
	

    bool getAlive(int t_arrayCell)
	

    int getNumberOfBoxesInGame()
	

    void reduceNumOfBoxes()
	

    void restart();
}

class Bullet
{

   Bullet()

   void init()

   void draw(sf::RenderWindow& t_window);
	
	void input(sf::Vector2f t_shooterPos, sf::RenderWindow& t_window);
	
	void update(Box& t_box, AI& t_enemy, sf::Sound& t_boxShoot, sf::Sound& t_enemyShot);
	
	void boundaryCheck();
	
	void checkBoxIntersect(sf::Sprite t_box, bool m_isAlive, sf::Sound& t_boxShoot);

	void checkIntersect(AI& t_enemy, sf::Sound& t_enemyShot);

	sf::Vector2f getMousePos()
	
	void restart();
}

class HUD
{

	HUD();

	void init(sf::Font& t_font);

	void update(Player &t_player);

	void draw(sf::RenderWindow & window);
}

class Particle
{
	int timetoLive = 0;
	sf::Vector2f velocity;
	sf::RectangleShape particleShape;

	void draw(sf::RenderWindow& win);
	
	void update();

	Particle() {}

	Particle(sf::Vector2f pos, sf::Vector2f vel, sf::Color color);
}


class ParticleSystem
{

	static const int M_MAX_PARTICLES = 50;

	Particle m_explosionParticles[M_MAX_PARTICLES];

	sf::Vector2f position;

	void spawnExplosion(sf::Vector2f pos, sf::Color color);

	void update();
	
	void draw(sf::RenderWindow& win);

	ParticleSystem() {}
}

class Pickups
{

	Pickups()

	void draw(sf::RenderWindow& t_win);

	void update(Player& t_player, int t_activeBox,sf::Sound& t_itemGet);

	void initPickups(Box& t_box);

	void restart();
}

class Player
{

        enum  class PlayerAnimationState { walk, idle };
	
	Player(sf::Sprite& t_spheet);

	void initAnimationData();
	
	void startAnimaton(PlayerAnimationState t_animationState);

	void draw(sf::RenderWindow& t_win);

	bool update(sf::Vector2f t_mousePos, bool& t_clickedMouse);


	void interactWithBox(sf::Sound& t_boxOpen);

	void boundaryCheck();


	void setPos(sf::Vector2f t_previous)

	sf::Sprite getSprite()
	

	bool isHidden()
	

	void setHiddenStatus(bool t_hiddenStatus)
	

	bool canE()
	

	void giveAmmo(int t_value)
	

	void giveGun()
	

	int getAmmo()
	

	bool doesHaveGun()
	

	void takeDamage(int damage)
	

	bool isAlive()
	
	void setColour(sf::Color& t_color)

	void restart();

}
}

ParticleSystem *-- "many" Particle : Contains
AnimationSheet *-- "many" Animation : Contains

SFML <.. Game
WindowsOS <.. Game

AnimationSheet -> Player
Player -> HUD
Player -> Pickups
ParticleSystem -> Player
ParticleSystem -> Bullet
Game -> Player
Player -> Bullet
Bullet -> Box
Player -> Box
@enduml!

[player_interaction_class_diagram](https://user-images.githubusercontent.com/58521962/115866630-d93df080-a431-11eb-81a4-fbee7e139c87.png)
