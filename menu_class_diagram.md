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
}

note "All classes dependant on SFML " as N1
MainMenu -> Cutscene
MainMenu -> HelpScreen
Game -> GameOverScreen
Game -> MainMenu
Cutscene -> Game
@enduml

![menu_diagram](https://user-images.githubusercontent.com/58521962/115789702-71e65900-a3bd-11eb-8de5-6b1bcb36b5ae.png)
