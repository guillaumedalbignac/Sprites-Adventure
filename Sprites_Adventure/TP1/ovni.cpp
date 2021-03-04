#include <iostream>
#include "ovni.h"
using namespace std;
using namespace sf;

Ovni::Ovni(string path) {
	//Détection d'erreur de chargement d'image
	if (!texture.loadFromFile(path)) {
		cout << "Image loading error !... " + path + "!" << endl;
	}

	//Mise en place du sprite (texture) du vaisseau
	if (path == "../vaisseau.png") {
		sprite.setTexture(texture);
		sprite.scale(0.10f, 0.10f);
		sprite.setPosition(640, 675);
		sprite.setOrigin((sprite.getLocalBounds().width / 2), (sprite.getLocalBounds().height / 2));
	}

	//Mise en place du sprite (texture) des astéroïdes
	if (path == "../asteroides.png") {
		sprite.setTexture(texture);
		sprite.scale(0.20f, 0.20f);
		sprite.setPosition(100, 600);
		sprite.setOrigin((sprite.getLocalBounds().width / 2), (sprite.getLocalBounds().height / 2));
	}

	//Mise en place du sprite (texture) de l'explosion
	if (path == "../explosion.png") {
		sprite.setTexture(texture);
		sprite.scale(0, 0);	// Mise à l'échelle éventuelle
		sprite.setPosition(200, 300);
		sprite.setOrigin((sprite.getLocalBounds().width / 2), (sprite.getLocalBounds().height / 2));
	}
	
	//Mise en place du sprite (texture) des projectiles
	if (path == "../projectile.png") {
		sprite.setTexture(texture);
		sprite.scale(0.20f, 0.20f);	
		sprite.setOrigin((sprite.getLocalBounds().width / 2), (sprite.getLocalBounds().height / 2));
	}
}
	
Ovni::~Ovni()
{

}

void Ovni::afficher(RenderWindow & window) const
{
	window.draw(sprite);	//Méthode d'affichage pour les sprites
}

void Ovni::mettreAJour(float deltaT)
{
	sprite.move(vitesse);	//Déplacements des astéroïdes

	//Gestion du maintien des astéroïdes dans la fenêtre
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

float Ovni::calculerDistance(Ovni const &autreOvni) const	//Méthode de calcul de distance entre objets (détection de colision)
{
	float resultat;
	resultat = sqrt(pow(sprite.getPosition().x - autreOvni.sprite.getPosition().x, 2) + pow(sprite.getPosition().y - autreOvni.sprite.getPosition().y, 2));
	return resultat;
}

void Ovni::changerCouleur(Color c)		//Méthode pour changer la couleur d'un sprite (colision)
{
	sprite.setColor(c);
}

void Ovni::changerPosition(float x, float y)		//Méthode pour changer le positionnement d'un objet ( x , y )
{
	sprite.setPosition(x, y);
}


