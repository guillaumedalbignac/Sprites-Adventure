#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <array>
#include "vaisseau.h"
#include "asteroide.h"
#include "explosion.h"
#include "ovni.h"
#include "son.h"
#include "score.h"
#include "menu.h"
#include "projectile.h"
using namespace std;
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(1280, 720), "Sprites Adventure");		//Création de la fenêtre
	window.setFramerateLimit(60);		//Vérouillage des images par seconds

	Image icon;
	icon.loadFromFile("../vaisseau.bmp");
	window.setIcon(225, 225, icon.getPixelsPtr());

	//Déclaration des objets et variables
	Clock clock;
	Vaisseau v1;	
	Asteroide a1, a2, a3;
	Explosion e1;
	Son s1;
	Score score;
	Menu menu;
	Projectile p1;	
	long int scoreFinal = 0;
	bool gameOver = false;
	bool partieDemarree = false;
	bool menuDisplay = true;
		   	 
	auto jeu = vector<Ovni *>{};	// jeu vide Allocation dynamique de mémoire avec un tableau de type vecteur
	s1.diffuserMusic();		//On joue la musique dès l'apparition de la fenetre
	
	//Boucle principale
	while (window.isOpen())		
	{		
		Event event;		
		
			while (window.pollEvent(event)) {
				if (event.type == Event::Closed) {	//Si l'utilisateur souhaite quitter
					window.close();
				}
				v1.actualiserEtat(event);
				p1.actualiserEtat(event);

				if (partieDemarree) {	// Attente qu'un choix fait pour lancer le jeu
					jeu.push_back(&v1);		// ajout des éléments dans le tableau dynamique de typoe vecteur
					jeu.push_back(&a1);					
					jeu.push_back(&a2);				
					jeu.push_back(&a3);				
					jeu.push_back(&e1);
					score.mettreAJour(0);
					v1.changerPosition(640, 400);
					e1.setTouche(false);
					a1.changerPosition(555, 100);		//Positionnement des différents astéroïdes
					a2.changerPosition(50, 600);
					a3.changerPosition(250, 150);
					gameOver = false;
					partieDemarree = false;					
				}

				//Déplacement dans le menu clavier
				/*if (event.type == Event::KeyPressed && event.key.code == Keyboard::Up) {
					menu.monter();
				}
				if (event.type == Event::KeyPressed && event.key.code == Keyboard::Down) {
					menu.descendre();
				}

				//Action des choix du menu clavier
				if (menu.itemSelectione() == 1 && event.type == Event::KeyPressed && event.key.code == Keyboard::Enter) {	//
					partieDemarree = true;	//Si "Play" est selectionné on lance le jeu
					menuDisplay = false;
				}
				if (menu.itemSelectione() == 2 && event.type == Event::KeyPressed && event.key.code == Keyboard::Enter) {	
					event.type = Event::Closed;	//Si "Exit" est selectionné on ferme le jeu
					window.close();
				}	*/			

				//Retour menu clavier
				/*if (event.type == Event::KeyPressed && event.key.code == Keyboard::M) {	 //Si "M" est appuyé on arrive au menu
					jeu.clear();
					scoreFinal = 0;
					score.mettreAJour(0);
					menuDisplay = true;
					partieDemarree = false;
				}*/	

				//Redemarrage de la partie au clavier
				/*if (event.type == Event::KeyPressed && event.key.code == Keyboard::R) {
					cout << "Redemarrage du jeu" << endl;
					jeu.clear();
					scoreFinal = 0;
					score.mettreAJour(0);
					menuDisplay = true;
					partieDemarree = false;
				}*/
			} 

			//Restart de la partie joystick
			if (Joystick::isButtonPressed(0, 2)) {
				jeu.clear();
				scoreFinal = 0;
				score.mettreAJour(0);
				menuDisplay = true;
				partieDemarree = false;
			}

			//Action des choix du menu joystick
			if (menu.itemSelectione() == 1 && Joystick::isButtonPressed(0, 0)) {
				jeu.clear();
				partieDemarree = true;
				menuDisplay = false;
			}
			if (menu.itemSelectione() == 2 && Joystick::isButtonPressed(0, 0)) {
				event.type = Event::Closed;	
				window.close();
			}

			//Action des choix du menu clavier
			/*if (menu.itemSelectione() == 1 && event.type == Event::KeyPressed && event.key.code == Keyboard::Enter) {
				jeu.clear();
				partieDemarree = true;
				menuDisplay = false;
			}
			if (menu.itemSelectione() == 2 && event.type == Event::KeyPressed && event.key.code == Keyboard::Enter) {
				event.type = Event::Closed;
				window.close();
			}*/

			//Déplacement dans le menu joystick
			if (Joystick::getAxisPosition(0, Joystick::Y) < -30) {
				menu.monter();
			}
			if (Joystick::getAxisPosition(0, Joystick::Y) > 30) {
				menu.descendre();
			}

			//Déplacement dans le menu clavier
			/*if (event.type == Event::KeyPressed && event.key.code == Keyboard::Up){
				menu.monter();
			}
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Down) {
				menu.descendre();
			}*/

		window.clear(Color(204, 204, 204));	//Ici on peut régler la couleur d'arrière plan de la fenêtre		

		if (menuDisplay) {
			menu.mettreAJour(true);
		}
		if (!menuDisplay) {
			menu.mettreAJour(false);
		}
		menu.afficherMenu(window);
		
		float tempsBoucle = clock.restart().asSeconds();	//variable de temps (utilisation de la clock)		

		//Boucle permettant l'affichage et la mise à jour des éléments du jeu (main game loop)
		for (auto *element : jeu) {
			element->mettreAJour(tempsBoucle);
			p1.mettreAJour(v1.getVaisseauPosition().x, v1.getVaisseauPosition().y, tempsBoucle);
			score.mettreAJour(scoreFinal);
		
			//Détection de colision (vaisseau / astéroïdes)
			if (element != &v1 && element->calculerDistance(v1) <= 75) {			
				e1.setTouche(true);
				e1.explosionSetPosition(v1.getVaisseauPosition());
				gameOver = true;				
			}	

			//Détection des chocs aveec les projectiles
			if (p1.calculerDistance(a1) <= 50) {
				scoreFinal  = scoreFinal + 5; // +15 points par astéroides touchés
				cout << " +15 " << endl;				
				s1.diffuserCloche();							
			}
			if (p1.calculerDistance(a2) <= 50) {
				scoreFinal = scoreFinal + 5;
				cout << " +15 " << endl;
				s1.diffuserCloche();
			}
			if (p1.calculerDistance(a3) <= 50) {
				scoreFinal = scoreFinal + 5;
				cout << " +15 " << endl;
				s1.diffuserCloche();
			}

			//Affichage du message de Game Over			
			p1.afficher(window);
			element->afficher(window);	
			score.afficherScore(window);
			if (gameOver == true) {
				menu.afficherGameOver(window);
			}
		}		
		menu.afficherCopyright(window);
		window.display();		
	}
	return 0;
 }