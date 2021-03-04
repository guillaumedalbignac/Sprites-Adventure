#include "asteroide.h"
#include <iostream>
#include <random>
using namespace std;
using namespace sf;

Asteroide::Asteroide() : Ovni("../asteroides.png"){
	//G�n�rateur de nombres al�atoires
	random_device rd;
	mt19937 rng(rd());
	uniform_int_distribution<int> uni(-5, 5);
	const string digits("0123456789");

	//G�n�ration d'un nombre al�atoire d'un nombre de chiffres choisie		
	int random_integer = uni(rng);
	float vitesseAsteroides = random_integer;
	cout << "Random Speeds : " << vitesseAsteroides << endl;
	
	vitesse = { vitesseAsteroides, vitesseAsteroides };	//Vecteur de gestion des d�pla�ements des ast�ro�des ( x , y )

	vitesseAsteroides = 0;
}
