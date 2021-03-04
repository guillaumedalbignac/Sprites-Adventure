#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Ovni {	//Classe mère du programme

public:
	Ovni(string path);
	~Ovni();
	void afficher(RenderWindow &window) const;
	virtual void mettreAJour(float deltaT);
	float calculerDistance(Ovni const &autreOvni) const;
	void changerCouleur(Color c);
	void changerPosition(float x, float y);

private:
		

protected:
	Vector2f vitesse;
	Sprite sprite;
	Texture texture;
};

