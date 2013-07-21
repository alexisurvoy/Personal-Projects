/*
 *  Character.h
 *  sdlgame
 *
 *  Created by Alexis Urvoy on 28/12/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef Character_h
#define Character_h

#include <iostream>
#include <fstream>
#include <string>
#include "SDL_image.h";

using namespace std;

class Character{
	public:
		Character(SDL_Surface*, SDL_Rect);
		Character(SDL_Surface*);
		~Character();
		void move(int);
		Character& operator=(const Character&);
		void setPosition(SDL_Rect);
		void redraw();
		int canMove(char[11][20], int);
	
		/*Static variables for orientation*/
		static const int LEFT = 0;
		static const int DOWN = 1;
		static const int RIGHT = 2;
		static const int UP = 3;
		/**********************************/
	
	private:
		SDL_Surface* screen;
		SDL_Rect position;
		SDL_Surface *charIm;
		SDL_Surface *floorIm;
		int orientation;
		
		/*String constants for images*/
		string CHAR_DOWN;
		string CHAR_UP;
		string CHAR_LEFT;
		string CHAR_RIGHT;
		/*****************************/
};
#endif