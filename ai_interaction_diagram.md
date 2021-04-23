@startuml
scale 1800*800
package "AI Interaction with game"{

class AI
{
 AI();
 void init(Grid &t_grid)
 void draw(sf::RenderWindow& t_window)
 bool update(Grid& m_grid)

 sf::Sprite getSprite()
	
 void dealDamage()

 bool isAlive()

 bool getShootingAtPlayer()

 void setShootingAtPlayer(bool shootingAtPlayerStatus)

 void setOutlineColor(sf::Color color)

 void setScaleSprite(int scale)

 float m_spotPlayerRange = 200

 void restart(Grid& t_grid)

}

class AIBullet {

        AIBullet()

	void init()

	void draw(sf::RenderWindow& t_window);

	void shootAtBox(sf::Vector2f t_boxPos, sf::Vector2f t_aiPos);

	void shootAtPlayer(sf::Vector2f t_playerPos, sf::Vector2f t_aiPos);

	void update(Box& t_box, AI& t_ai, Player& t_player, sf::Sound& t_boxShoot, sf::Sound& t_playerShot, sf::Sound& 
        t_enemyAttack);
	
	void checkBoxIntersect(Box& t_box, int t_arrayCell, sf::Sound& t_boxShoot);

	void checkPlayerIntersect(Player& t_player, sf::Sound& t_playerShot);

	void boundaryCheck();

	float distanceBetween(sf::Vector2f t_entity, sf::Vector2f t_secondEntity);

	void restart();
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

class Cell
{
	Cell(int t_cellWidth, int t_cellHeight, int t_cellId = -1) : m_id(t_cellId)
	
	void findCentreXandCentreY(int t_cellWidth, int t_cellHeight);
	void draw(sf::RenderWindow& t_window);
	void update();
	static void neighbours(std::vector<Cell>& t_grid);

	void addNeighbour(int t_cellId)
	
	void setPassable(bool t_imPass)
	
	bool isPassable()
	
	std::vector<int>& neighbours()
	
	void setMarked(bool t_marked)
	
	bool isMarked() const
	
	int id() const
	
	void setParentCellId(int t_cellId)
	
	int getParentCellId()
	
	int getCentreX()
	
	int getCentreY()
	
	void colourPath(bool t_onpath)
}

class Grid
{
	Grid();
	
	void makeGrid();

	void draw(sf::RenderWindow& t_window);

	void markImpassableCells(Box& t_box);

	std::vector<int> breadthFirst(int t_startCellId, int t_destCellId);

	void update();

	std::vector<Cell> getCells()
	
	void restart();
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

Grid *-- "many" Cell : Contains
ParticleSystem *-- "many" Particle : Contains
AI -> AIBullet
AIBullet -> Box
AIBullet -> Player
Grid -> AI
@enduml

![ai_interaction_diagram](https://user-images.githubusercontent.com/58521962/115808594-a587aa00-a3e2-11eb-85b4-56330be0a7f3.png)


