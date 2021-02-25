#include "explosion.h"
#include <iostream>
using namespace std;
using namespace sf;

Explosion::Explosion() : Ovni("../explosion.png")
{
	Vector2f vitesse = { 0.f, 0.f };		
}

Explosion::~Explosion()
{

}

void Explosion::mettreAJour(float deltaT)
{
	if (cropFactor >= 0 && touche == true) {		//cropFactor < 0.75 && touche == true
		cropFactor = cropFactor + deltaT * 1;
		/*cout << cropFactor << endl;*/
		sprite.setScale(cropFactor, cropFactor);
	}
	else {
		sprite.setScale(0, 0);
		touche = false;
		cropFactor = 0;
	}
}

void Explosion::explosionSetPosition(Vector2f newP)
{
	sprite.setPosition(newP);
}

void Explosion::setTouche(bool state)
{
	touche = state;
}

