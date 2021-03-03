#include <iostream>
#include "menu.h"

Menu::Menu()
{
	if (!font.loadFromFile("../lunchds.ttf")) {
		cout << "Erreur font menu display !..." << endl;
	}

	if (!fontCopyright.loadFromFile("../arial.ttf")) {
		cout << "Erreur font copyright display !..." << endl;
	}

	menu[0].setFillColor(Color::Yellow);
	menu[1].setFillColor(Color::Black);
}

void Menu::afficherMenu(RenderWindow & window)
{			
	window.draw(text);	//Affichage du nom du jeu

	for (int i = 0; i < NOMBRE_MAX_ITEMS; i++) {		//Affichage des choix du menu 
		window.draw(menu[i]);
	}
}

void Menu::mettreAJour(bool display)
{
	if (display == true) {
		text.setFont(font);
		text.setString("Sprites Adventures");
		text.setFillColor(Color::Black);
		text.setPosition(90, 180);
		text.setStyle(Text::Italic && Text::Bold);
		text.setCharacterSize(105);

		menu[0].setString("Play");
		menu[0].setFont(font);
		menu[0].setCharacterSize(50);
		menu[0].setPosition(550, 400);

		menu[1].setString("Exit");
		menu[1].setFont(font);
		menu[1].setCharacterSize(50);
		menu[1].setPosition(550, 500);
	}
	else if(display == false){
		text.setString("");

		menu[0].setString("");
		
		menu[1].setString("");
	}
}

void Menu::monter()
{
	menu[0].setFillColor(Color::Yellow);
	menu[1].setFillColor(Color::Black);
	
	itemIndex = 1;
}

void Menu::descendre()
{
	menu[0].setFillColor(Color::Black);
	menu[1].setFillColor(Color::Yellow); 

	itemIndex = 2;
}

void Menu::afficherGameOver(RenderWindow & window)
{
	text.setFont(font);
	text.setString("Game Over ! Press Y to restart");
	text.setFillColor(Color::Black);
	text.setPosition(50, 350);
	text.setStyle(Text::Italic && Text::Bold);
	text.setCharacterSize(70);
	window.draw(text);
}

void Menu::afficherCopyright(RenderWindow & window)
{
	copyright.setFont(fontCopyright);
	copyright.setString("Lycée Jules Verne  © Guillaume d'Albignac 2019");
	copyright.setFillColor(Color::Black);
	copyright.setPosition(895, 690);
	copyright.setCharacterSize(20);
	window.draw(copyright);
}
