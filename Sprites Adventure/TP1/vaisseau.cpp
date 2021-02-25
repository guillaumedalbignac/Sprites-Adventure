#include <iostream>
#include "vaisseau.h"
using namespace std;
using namespace sf;

//Appel du constructeur de la classe mère Ovni par liste d'initialisation
Vaisseau::Vaisseau() : Ovni("../sprite.png")	
{		
	
}

void Vaisseau::actualiserEtat(Event const &event)
{
	//Gestion au JOYSTICK

	//if (!Joystick::isConnected(0)) {
	//	/*cout << "Joystick non connecte ! " << endl;*/
	//   }

	//if (Joystick::getAxisPosition(0, Joystick::Y) < -30) {
	//	accelerationEnCours = true;
	//}
	//else {
	//	accelerationEnCours = false;
	//}

	//if (Joystick::getAxisPosition(0, Joystick::R) > 80 ) {
	//	tournerDroite = true;		
	//}
	//else {
	//	tournerDroite = false;
	//}

	//if (Joystick::getAxisPosition(0, Joystick::R) < -80) {
	//	tournerGauche = true;		
	//}
	//else {
	//	tournerGauche = false;
	//}
	
	//Gestion au CLAVIER

	if (event.type == Event::KeyPressed && event.key.code == Keyboard::Up) {
		accelerationEnCours = true;
	}
	else if (event.type == Event::KeyReleased && event.key.code == Keyboard::Up) {
		accelerationEnCours = false;	
	}

	if (event.type == Event::KeyPressed && event.key.code == Keyboard::Left) {
		tournerGauche = true;
	}
	else if (event.type == Event::KeyReleased && event.key.code == Keyboard::Left) {
		tournerGauche = false;
	}

	if (event.type == Event::KeyPressed && event.key.code == Keyboard::Right) {
		tournerDroite = true;
	}
	else if (event.type == Event::KeyReleased && event.key.code == Keyboard::Right) {
		tournerDroite = false;
	}
}

void Vaisseau::mettreAJour(float deltaT) 
{	
	//Gestion acceleration et frottements
	if (accelerationEnCours) {
		vitesse = vitesse + vecteurVitesse(ACCELERATION * deltaT, sprite.getRotation() - 90);
	}
	else {
		vitesse = vitesse - (vitesse * FROTTEMENT * deltaT); 
	}
	sprite.move(vitesse);

	//Gestion de la rotation du vaisseau
	if (tournerGauche) {
		sprite.rotate(-VITESSE_ANGULAIRE * deltaT);
	}

	if (tournerDroite) {
		sprite.rotate(VITESSE_ANGULAIRE * deltaT);
	}
	
	//Gestion du maintien du vaisseau dans la fenêtre
	if (sprite.getPosition().x > 1280) {
		sprite.setPosition(0, sprite.getPosition().y);
	}
	if (sprite.getPosition().x < 0) {
		sprite.setPosition(1280, sprite.getPosition().y);
	}
	if (sprite.getPosition().y > 720) {
		sprite.setPosition(sprite.getPosition().x, 0);
	}
	if (sprite.getPosition().y < 0) {
		sprite.setPosition(sprite.getPosition().x, 720);
	}
}

Vector2f Vaisseau::vecteurVitesse(float module, float argument)
{
	return Vector2f(module * cos(argument / 180.f * 3.1416), module * sin(argument / 180.f * 3.1416));	//Vecteur directionnel du vaisseau
}

Vector2f Vaisseau::getVaisseauPosition()
{
	return Vector2f(sprite.getPosition());	//Méthode pour correctement positionner l'explosion du vaisseau
}

