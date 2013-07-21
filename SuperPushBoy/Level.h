/*
 *  Level.h
 *  sdlgame
 *
 *  Created by Alexis Urvoy on 26/12/12.
 *  Copyright 2012 Alexis URVOY All rights reserved.
 *
 */

#ifndef Level_h
#define Level_h

#include <iostream>
#include <fstream>
#include "SDL_image.h"
#include "Character.h"
#include "Box.h"

using namespace std;

class Level{

	public :
		Level(char*, SDL_Surface*);
		~Level();
		void loadLevel(char*);
		void drawLevel();
		void startLevel();
	
	private :
		SDL_Surface* screen;
		char levelArray[11][20];
		Character* charact;
		Box* box;
		int theEnd;
		int win;
};
#endif