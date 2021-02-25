#pragma once
#include <iostream>
#include <SFML/Audio.hpp>
using namespace std;
using namespace sf;

class Son {
public:
	Son();
	~Son();
	void diffuserMusic();
	void diffuserCloche();

private:
	SoundBuffer buffer;
	Sound sound, soundLaser, soundCloche;
	Music music;
};
