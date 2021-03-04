#pragma once
#include "ovni.h"
using namespace sf;

class Explosion : public Ovni {

public : 
	Explosion();
	~Explosion();
	virtual void mettreAJour(float deltaT);
	void explosionSetPosition(Vector2f newP);
	void setTouche(bool state);

private:
	float cropFactor = 0;
	bool touche = false;
};