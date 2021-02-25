#include "son.h"
using namespace std;
using namespace sf;

Son::Son()
{
	//D�tection d'erreur de chargement de la music
	if (!music.openFromFile("../Blazer_Rail.wav")) {
		cout << "Music Loading Error ...!" << endl;
	}

	//D�tection d'erreur de chargement des sons
	if (!buffer.loadFromFile("../laser.wav")) {
		cout << "Laser Sound Loading Error ...!" << endl;
	}

	//D�tection d'erreur de chargement des sons
	if (!buffer.loadFromFile("../cloche.wav")) {
		cout << "Bell Sound Loading Error ...!" << endl;
	}
}

Son::~Son()
{

}

void Son::diffuserMusic()
{
	music.setVolume(25);
	music.play();
}

void Son::diffuserCloche()
{
	soundCloche.setBuffer(buffer);	//Cr�ation du buffer
	soundCloche.setVolume(28);	//Ajustement du volume
	soundCloche.play();
}
