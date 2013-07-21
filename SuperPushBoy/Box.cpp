/*
 *  Box.cpp
 *  sdlgame
 *
 *  Created by Alexis Urvoy on 29/12/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "Box.h"

Box::Box(SDL_Surface* _screen): screen(_screen){
	boxIm = IMG_Load("/Users/alex/Documents/sdlgame/images/box.png");
}

Box::~Box(){}

void Box::move(int direction){
	switch(direction){
		case Character::UP: 
			position.y -= 62;
			break;
		case Character::DOWN: 
			position.y += 62;
			break;
		case Character::LEFT: 
			position.x -= 62;
			break;
		case Character::RIGHT: 
			position.x += 62;
			break;
		default: break;
	}
	redraw();
}

void Box::setPosition(SDL_Rect newPos){
	position = newPos;
}

void Box::setLevelArray(char* _levelArray){
	levelArray = _levelArray;
}

void Box::redraw(){
	SDL_BlitSurface(boxIm, NULL, screen, &position);
	SDL_Flip(screen);
}

int Box::canMove(int direction){
	int possible = 0;
	char c;
	
	switch(direction){
		case Character::UP:
			c = levelArray[(position.y/62-1)*20+position.x/62];
			if(c!='1'){ 
				if(c=='4')possible = 2;
				else possible = 1;
				levelArray[(position.y/62-1)*20+position.x/62]='2';
				levelArray[(position.y/62)*20+position.x/62]='0';
				position.y -= 62;
				redraw();
			}
			break;
		case Character::DOWN:
			c = levelArray[(position.y/62+1)*20+position.x/62];
			if(c!='1'){
				possible = 1;
				levelArray[(position.y/62+1)*20+position.x/62]='2';
				levelArray[(position.y/62)*20+position.x/62]='0';
				position.y += 62;
				redraw();
			}
			break;
		case Character::LEFT:
			c = levelArray[(position.y/62)*20+position.x/62-1];
			if(c!='1'){
				possible = 1;
				levelArray[(position.y/62)*20+position.x/62-1]='2';
				levelArray[(position.y/62)*20+position.x/62]='0';
				position.x -= 62;
				redraw();
			}
			break;
		case Character::RIGHT:
			c = levelArray[(position.y/62)*20+position.x/62+1];
			if(c!='1'){
				possible = 1;
				levelArray[(position.y/62)*20+position.x/62+1]='2';
				levelArray[(position.y/62)*20+position.x/62]='0';
				position.x += 62;
				redraw();
			}	
			break;
		default: break;
	}
	return possible;
}