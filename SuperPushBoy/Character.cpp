/*
 *  Character.cpp
 *  sdlgame
 *
 *  Created by Alexis Urvoy on 28/12/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "Character.h"

Character::Character(SDL_Surface* _screen, SDL_Rect _position):screen(_screen),position(_position){
	/* constants initialization*/
	CHAR_DOWN = "/Users/alex/Documents/sdlgame/images/character_face.png";
	CHAR_UP = "/Users/alex/Documents/sdlgame/images/character_top.png";
	CHAR_LEFT = "/Users/alex/Documents/sdlgame/images/character_left.png";
	CHAR_RIGHT = "/Users/alex/Documents/sdlgame/images/character_right.png";
	/***************************/
	
	orientation = Character::DOWN;
	charIm = IMG_Load(CHAR_DOWN.c_str());
	floorIm = IMG_Load("/Users/alex/Documents/sdlgame/images/floor.png");
	SDL_BlitSurface(charIm, NULL, screen, &position);
}

Character::~Character(){}

Character::Character(SDL_Surface* _screen):screen(_screen){
	/* constants initialization*/
	CHAR_DOWN = "/Users/alex/Documents/sdlgame/images/character_face.png";
	CHAR_UP = "/Users/alex/Documents/sdlgame/images/character_top.png";
	CHAR_LEFT = "/Users/alex/Documents/sdlgame/images/character_left.png";
	CHAR_RIGHT = "/Users/alex/Documents/sdlgame/images/character_right.png";
	/***************************/
	
	orientation = Character::DOWN;
	floorIm = IMG_Load("/Users/alex/Documents/sdlgame/images/floor.png");
}

Character& Character::operator=(const Character& ch){
	screen = ch.screen;
	position = ch.position;
	return *this;
}

void Character::setPosition(SDL_Rect newPos){
	position = newPos;
}


int Character::canMove(char level[11][20], int direction){
	int possible = 0;
	char c;
	
	switch(direction){
		case Character::UP: 
			c = level[position.y/62-1][position.x/62];
			if(c=='0' || c=='3') possible=1;
			else if (c=='2')	 possible=2;
			break;
		case Character::DOWN:
			c = level[position.y/62+1][position.x/62];
			if(c=='0' || c=='3')	possible=1;
			else if (c=='2')		possible=2;
			break;
		case Character::LEFT: 
			c = level[position.y/62][position.x/62-1];
			if(c=='0' || c=='3')	possible=1;
			else if (c=='2')		possible=2;
			break;
		case Character::RIGHT: 
			c = level[position.y/62][position.x/62+1];
			if(c=='0' || c=='3')	possible=1;
			else if (c=='2')		possible=2;
			break;
		default: break;
	}
	
	return possible;
}

void Character::redraw(){
	switch(orientation){
		case Character::UP: charIm = IMG_Load(CHAR_UP.c_str()); break;
		case Character::DOWN: charIm = IMG_Load(CHAR_DOWN.c_str()); break;
		case Character::LEFT: charIm = IMG_Load(CHAR_LEFT.c_str()); break;
		case Character::RIGHT: charIm = IMG_Load(CHAR_RIGHT.c_str()); break;
		default: break;
	}
	
	SDL_BlitSurface(charIm, NULL, screen, &position);
	SDL_Flip(screen);
}

void Character::move(int direction){
	SDL_Rect previousPos = position;
	SDL_Surface* floorIm = IMG_Load("/Users/alex/Documents/sdlgame/images/floor.png");
	
	switch(direction){
		case Character::UP: 
			position.y -= 62;
			if(orientation!=Character::UP){
				charIm = IMG_Load(CHAR_UP.c_str());
				orientation = Character::UP;
			}
			break;
		case Character::DOWN: 
			position.y += 62;
			if(orientation!=Character::DOWN){
				charIm = IMG_Load(CHAR_DOWN.c_str());
				orientation = Character::DOWN;
			}
			break;
		case Character::LEFT: 
			position.x -= 62;
			if(orientation!=Character::LEFT){
				charIm = IMG_Load(CHAR_LEFT.c_str());
				orientation = Character::LEFT;
			}
			break;
		case Character::RIGHT: 
			position.x += 62;
			if(orientation!=Character::RIGHT){
				charIm = IMG_Load(CHAR_RIGHT.c_str());
				orientation = Character::RIGHT;
			}
			break;
		default: break;
	}
	
	SDL_BlitSurface(floorIm, NULL, screen, &previousPos);
	SDL_BlitSurface(floorIm, NULL, screen, &position);
	SDL_BlitSurface(charIm, NULL, screen, &position);
	SDL_Flip(screen);
}