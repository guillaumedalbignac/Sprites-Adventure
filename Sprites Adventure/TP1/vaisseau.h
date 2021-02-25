#pragma once
#include <SFML/Graphics.hpp>
#include "ovni.h"
using namespace std;
using namespace sf;

class Vaisseau : public Ovni {	

public:
	Vaisseau();
	void actualiserEtat(Event const &event);
	void mettreAJour(float deltaT);
	static Vector2f vecteurVitesse(float module, float argument);	
	Vector2f getVaisseauPosition();

private:
	//Variables booléen de gestion des déplaçements
	bool accelerationEnCours = false;
	bool tournerDroite = false;
	bool tournerGauche = false;

	//Coefficients physiques des déplaçements du vaisseau
	static constexpr float ACCELERATION = 6.25f;
	static constexpr float FROTTEMENT = 2.0f;
	static constexpr float VITESSE_ANGULAIRE = 90.0f;
};

