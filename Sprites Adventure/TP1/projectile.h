#pragma once
#include "ovni.h"

class Projectile : public Ovni {

public:

	Projectile();
	void actualiserEtat(Event const &event);
	void mettreAJour(float vaisseauPositionX, float vaisseauPositionY, float deltaT);
	static Vector2f vecteurProjectile(float module, float argument);

private:
	bool lancerProjectile = false;
	bool tournerDroite = false;
	bool tournerGauche = false;

	static constexpr float VITESSE_ANGULAIRE = 18.f;
	static constexpr float ACCELERATION = 2.85f;
	static constexpr float FROTTEMENT = 0.25f;
};
