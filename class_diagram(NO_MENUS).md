@startuml  
left to right direction   

scale 4/5  

class Game  
{  
Game();  
void init();  
void processMouseInput(sf::Event t_event);  
void run();  
void draw();  
void update();  
void restart();  
void initSound();  
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
}

class GameState  
{  
None,  
MainMenu,  
Help,  
Cutscene,  
Game,   
Win,  
Lose,  
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
Bullet() { ; }  
void init();  
void draw(sf::RenderWindow& t_window);  
void input(sf::Vector2f t_shooterPos, sf::RenderWindow& t_window);  
void update(Box& t_box, AI& t_enemy, sf::Sound& t_boxShoot, sf::Sound& t_enemyShot);  
void boundaryCheck();  
void checkBoxIntersect(sf::Sprite t_box, bool m_isAlive, sf::Sound& t_boxShoot);  
void checkIntersect(AI& t_enemy, sf::Sound& t_enemyShot);  
sf::Vector2f getMousePos()   
void restart();  
}

class Player  
{  
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

class AI  
{  
AI()  
void init(Grid &t_grid);  
void draw(sf::RenderWindow& t_window);  
bool update(Grid& m_grid);  
sf::Sprite getSprite()   
void dealDamage()  
bool isAlive()  
bool getShootingAtPlayer()  
void setShootingAtPlayer(bool shootingAtPlayerStatus)  
void setOutlineColor(sf::Color color)  
void setScaleSprite(int scale)  
float m_spotPlayerRange = 200;  
void restart(Grid& t_grid);  
}

class AIBullet  
{  
AIBullet() { ; }  
void init();  
void draw(sf::RenderWindow& t_window);	  
void shootAtBox(sf::Vector2f t_boxPos, sf::Vector2f t_aiPos);  
void shootAtPlayer(sf::Vector2f t_playerPos, sf::Vector2f t_aiPos);	  
void update(Box& t_box, AI& t_ai, Player& t_player, sf::Sound& t_boxShoot, sf::Sound& t_playerShot, sf::Sound& t_enemyAttack);	  
void checkBoxIntersect(Box& t_box, int t_arrayCell, sf::Sound& t_boxShoot);	  
void checkPlayerIntersect(Player& t_player, sf::Sound& t_playerShot);	  
void boundaryCheck();  
float distanceBetween(sf::Vector2f t_entity, sf::Vector2f t_secondEntity);  
void restart();  
}

class Pickups
{
Pickups()  
void draw(sf::RenderWindow& t_win);  
void update(Player& t_player, int t_activeBox,sf::Sound& t_itemGet);  
void initPickups(Box& t_box);  
void restart();  
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

Game --|> SFML  
Game --|> WindowsOS  
GameState --|> Game  
Player --|> Game  
Bullet --|> Game  
AIBullet --|> Game  
Box --|> Game  
Pickups --|> Game  
AI --|> Game  

Grid *-- "many" Cell  
Grid --> AI  
ParticleSystem *-- "many" Particle  
ParticleSystem --|> Bullet  
ParticleSystem --|> AIBullet  
Animation *-- "many" Player  
AnimationSheet --|> Player  
@enduml!  
[class_diagram(NO_MENUS)] (https://user-images.githubusercontent.com/58521962/115897416-4d898b80-a454-11eb-98db-83494a27bf5e.png)
