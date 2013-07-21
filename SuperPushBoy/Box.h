/*
 *  Box.h
 *  sdlgame
 *
 *  Created by Alexis Urvoy on 29/12/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef Box_h
#define Box_h

#include <iostream>
#include <fstream>
#include <string>
#include "SDL_image.h"
#include "Character.h"

using namespace std;

class Box{
	public :
		Box(SDL_Surface*);
		~Box();
		void move(int);
		void setPosition(SDL_Rect);
		void redraw();
		int canMove(int);
		void setLevelArray(char*);
	
	private :
		SDL_Rect position;
		SDL_Surface* screen;
		SDL_Surface *boxIm;
		char* levelArray;
};
#endif