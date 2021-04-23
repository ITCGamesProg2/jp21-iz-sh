@startuml  
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

class MainMenu  
{  
void initialise(sf::Font& t_font);  
void render(sf::RenderWindow& t_window);  
int processInput(sf::Window& t_window, Player& t_player, sf::Event t_event);  
void update(sf::Window& t_window);  
}
class GameOverScreen  
{
void initialise(sf::Font& t_font);  
void render(sf::RenderWindow& t_window);  
bool processInput(sf::Window& t_window, sf::Event t_event);  
void update(sf::Window& t_window, bool t_win);  
}

class HelpScreen  
{  

void initialise(sf::Font& t_font);  
void render(sf::RenderWindow& t_window);  
bool processInput(sf::Window& t_window, sf::Event t_event);  
void update(sf::Window& t_window);  
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

Game --|> SFML  
Game --|> WindowsOS  
Player <-- MainMenu : Setting Colour   
GameState --|> Game  
Game <|-- MainMenu  
Game <|-- GameOverScreen  
Game <|-- HelpScreen  
@enduml![class_diagram(MENUS_ONLY)] 
(https://user-images.githubusercontent.com/58521962/115897677-95101780-a454-11eb-9b55-b5467d1a0ead.png)
