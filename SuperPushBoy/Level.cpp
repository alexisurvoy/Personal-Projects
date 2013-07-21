/*
 *  Level.cpp
 *  sdlgame
 *
 *  Created by Alexis Urvoy on 26/12/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */ 
#include "Level.h"

Level::Level(char* path, SDL_Surface* _screen):screen(_screen), theEnd(0){
	charact = new Character(screen);
	box = new Box(screen);
	loadLevel(path);
	drawLevel();
	startLevel();
}

Level::~Level(){}

void Level::startLevel(){
	SDL_Event event;
	
	while(!theEnd){
		SDL_WaitEvent(&event);
		
		switch(event.type){
            case SDL_QUIT: theEnd = 1; break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym){
					case SDLK_UP:	if(charact->canMove(levelArray, Character::UP)==1) charact->move(Character::UP);
									else if(charact->canMove(levelArray, Character::UP)==2){
										int x = box->canMove(Character::UP);
										if(x)charact->move(Character::UP);
										if(x==2) theEnd=1;
									}
									break;
					case SDLK_DOWN: if(charact->canMove(levelArray, Character::DOWN)==1)charact->move(Character::DOWN);
									else if(charact->canMove(levelArray, Character::DOWN)==2){if(box->canMove(Character::DOWN))charact->move(Character::DOWN);}
									break;
					case SDLK_RIGHT: if(charact->canMove(levelArray, Character::RIGHT)==1)charact->move(Character::RIGHT);
									else if(charact->canMove(levelArray, Character::RIGHT)==2){if(box->canMove(Character::RIGHT))charact->move(Character::RIGHT);}
									break;
					case SDLK_LEFT:if(charact->canMove(levelArray, Character::LEFT)==1)charact->move(Character::LEFT); 
									else if(charact->canMove(levelArray, Character::LEFT)==2){if(box->canMove(Character::LEFT))charact->move(Character::LEFT);}
									break;
				}
                break;
        }
	}
}

void Level::loadLevel(char* path){
	
	ifstream level;
	int i=0,j=0;
	level.open(path, ifstream::in);
	
	if(level){
		//Read the file and store the output in our array
		string line;
		
		while(getline(level, line)){
			for(j=0; j<20;j++)levelArray[i][j] = line[j];
			i++;
		}

		//close the file
		level.close();
		box->setLevelArray(*levelArray);
	}else cerr << "File not found ! " << path << "\n";
}

void Level::drawLevel(){

	SDL_Rect pos;
	
	//image loading
	SDL_Surface *wallIm, *floorIm, *objectifIm;
	wallIm = IMG_Load("/Users/alex/Documents/sdlgame/images/wall.png");
	floorIm = IMG_Load("/Users/alex/Documents/sdlgame/images/floor.png");
	objectifIm = IMG_Load("/Users/alex/Documents/sdlgame/images/objective.png");
	
	for(int i=0;i<11;i++){
		for(int j=0;j<20;j++){
			char c = levelArray[i][j];
			pos.x = j*62;
			pos.y = i*62;
			//If this is the floor
			if(c=='0'){
				SDL_BlitSurface(floorIm, NULL, screen, &pos);
			}//if this is a wall
			else if(c == '1'){
				SDL_BlitSurface(wallIm, NULL, screen, &pos);
			}//If this is the box
			else if(c== '2'){
				box->setPosition(pos);
				box->redraw();
			}//if this is the character
			else if(c== '3'){
				SDL_BlitSurface(floorIm, NULL, screen, &pos);
				charact->setPosition(pos);
				charact->redraw();
			}//If this is the objectif
			else if(c== '4'){
				SDL_BlitSurface(floorIm, NULL, screen, &pos);
				SDL_BlitSurface(objectifIm, NULL, screen, &pos);
			}
		}	
	}
	
	SDL_Flip(screen);
}