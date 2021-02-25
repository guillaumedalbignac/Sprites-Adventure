#pragma once

class Score {
public:
	Score();
	void afficherScore(RenderWindow & window);
	void mettreAJour(long int scoreJoueur);

private:
	Font font;
	Text text;
};