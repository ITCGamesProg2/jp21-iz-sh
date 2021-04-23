@startuml
@startuml
package "Menu System"{

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

class Cutscene
{
	Cutscene();
	void init(sf::Font& t_font);
	void draw(sf::RenderWindow& t_window);
	bool update();
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

class MainMenu {

	void initialise(sf::Font& t_font);
	void render(sf::RenderWindow& t_window); 
	int processInput(sf::Window& t_window, Player& t_player, sf::Event t_event); 
	void update(sf::Window& t_window);

}

SFML <.. Game
WindowsOS <.. Game
Game <- GameOverScreen
Game <- MainMenu
Game <- HelpScreen
Game <- Cutscene
@enduml

![menu_diagram](https://user-images.githubusercontent.com/58521962/115807610-debf1a80-a3e0-11eb-8ad0-edd710a2deea.png)
