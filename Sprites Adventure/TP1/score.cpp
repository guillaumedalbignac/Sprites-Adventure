#include <iostream>
#include "ovni.h"
#include "score.h"

Score::Score()
{
	if (!font.loadFromFile("../lunchds.ttf")) {
		cout << "Erreur font score display !..." << endl;
	}
}

void Score::afficherScore(RenderWindow & window)
{
	window.draw(text);
}

void Score::mettreAJour(long int scoreJoueur)
{		
	text.setFont(font);
	text.setString("Score : " + to_string(scoreJoueur) + " points");
	text.setFillColor(Color::White);
	text.setPosition(425, 2);
	text.setStyle(Text::Regular);
	text.setCharacterSize(43);
}
