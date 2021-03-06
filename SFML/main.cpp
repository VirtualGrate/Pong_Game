#include "stdafx.h"
#include "Menu.h"
#include "game_state.h"
#include "Game.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <Windows.h>

game_state main_state;

int main()
{
	RenderWindow* window{ new RenderWindow{{ 1127,632 }, "Gra" } };
	main_state.SetWindow(window);
	main_state.SetState(new Menu());


	while (window->isOpen()) {
		Event* windowEvent = new Event;
		while (window->pollEvent(*windowEvent)) {
				if (windowEvent->type == Event::Closed)
					window->close();
		}
		window->clear(Color::Black);

		main_state.Update();
		main_state.Render();
		window->display();

	}
	Sleep(3);
}
	

