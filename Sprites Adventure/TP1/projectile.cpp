#include "projectile.h"
#include <iostream>
using namespace std;
using namespace sf;

Projectile::Projectile() : Ovni("../projectile.png")
{
	vitesse = { 0.f, 0.f };
}

void Projectile::actualiserEtat(Event const & event)
{
	//Gestion au Clavier
	/*
	if (event.type == Event::KeyPressed && event.key.code == Keyboard::Space) {
		lancerProjectile = true;
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
	}*/

	//Gestion au Joystick

	if (Joystick::isButtonPressed(0, 5)) {
		lancerProjectile = true;
	}
	if (Joystick::getAxisPosition(0, Joystick::X) > 80) {
		tournerDroite = true;
	}
	else {
		tournerDroite = false;
	}

	if (Joystick::getAxisPosition(0, Joystick::X) < -80) {
		tournerGauche = true;
	}
	else {
		tournerGauche = false;
	}
}

void Projectile::mettreAJour(float vaisseauPositionX, float vaisseauPositionY, float deltaT)
{
	sprite.setPosition(vaisseauPositionX, vaisseauPositionY);
	sprite.setScale(0, 0);

	//Gestion de la rotation du projectile
	if (tournerGauche) {
		sprite.rotate(-VITESSE_ANGULAIRE * deltaT);
	}
	if (tournerDroite) {
		sprite.rotate(VITESSE_ANGULAIRE * deltaT);
	}

	//Détection lancement projectile
	if (lancerProjectile) {	
		sprite.setScale(0.2f, 0.2f);
		vitesse = vitesse + vecteurProjectile(ACCELERATION, sprite.getRotation() - 90);
		sprite.move(vitesse);			
	}
	else {
		vitesse = vitesse - (vitesse * FROTTEMENT * deltaT);	
	}	

	//Gestion du maintien du projectile dans la fenêtre
	if (sprite.getPosition().x > 1280) {
		sprite.setPosition(vaisseauPositionX, vaisseauPositionY);
		vitesse = { 0.f, 0.f };
		lancerProjectile = false;
	}
	if (sprite.getPosition().x < 0) {
		sprite.setPosition(vaisseauPositionX, vaisseauPositionY);
		vitesse = { 0.f, 0.f };
		lancerProjectile = false;
	}
	if (sprite.getPosition().y > 720) {
		sprite.setPosition(vaisseauPositionX, vaisseauPositionY);
		vitesse = { 0.f, 0.f };
		lancerProjectile = false;
	}
	if (sprite.getPosition().y < 0) {
		sprite.setPosition(vaisseauPositionX, vaisseauPositionY);
		vitesse = { 0.f, 0.f };
		lancerProjectile = false;
	}
}

Vector2f Projectile::vecteurProjectile(float module, float argument)
{
	return Vector2f(module * cos(argument / 180.f * 3.1416), module * sin(argument / 180.f * 3.1416));	//Vecteur directionnel du projectile
}
