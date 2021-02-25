#pragma once
#include "ovni.h"
#include "SFML/Graphics.hpp"

#define NOMBRE_MAX_ITEMS 2

class Menu {
public:
	Menu();
	void afficherMenu(RenderWindow & window);
	void mettreAJour(bool display);
	void monter();
	void descendre();
	int itemSelectione() { return itemIndex; };
	void afficherGameOver(RenderWindow & window);
	void afficherCopyright(RenderWindow & window);

private:
	int itemIndex = 1;
	Text menu[NOMBRE_MAX_ITEMS];
	Font font;
	Text text;
	Text gameOver;
	Font fontCopyright;
	Text copyright;
};