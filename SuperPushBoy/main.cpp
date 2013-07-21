
/* Simple program:  Create a blank window, wait for keypress, quit.

   Please see the SDL documentation for details on using the SDL API:
   /Developer/Documentation/SDL/docs.html
*/
   
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Level.h"
#include <math.h>

#include <iostream>
using namespace std;

#include "SDL.h"

int main(int argc, char *argv[])
{
	Uint32 initflags = SDL_INIT_VIDEO;  /* See documentation for details */
	SDL_Surface *screen;
	Uint8  video_bpp = 0;
	Uint32 videoflags = SDL_SWSURFACE;

	/* Initialize the SDL library */
	if ( SDL_Init(initflags) < 0 ) {
		fprintf(stderr, "Couldn't initialize SDL: %s\n",
			SDL_GetError());
		exit(1);
	}

	/* Set 1280x720 video mode */
	screen=SDL_SetVideoMode(1240,682, video_bpp, videoflags);
        if (screen == NULL) {
		fprintf(stderr, "Couldn't set 640x480x%d video mode: %s\n",
                        video_bpp, SDL_GetError());
		SDL_Quit();
		exit(2);
	}
	SDL_WM_SetCaption("Super pushboy !", NULL);
	SDL_EnableKeyRepeat(200, 200);
	
	
	Level level("/Users/alex/Documents/sdlgame/levels/level1.level", screen);
	
	/* Clean up the SDL library */
	SDL_Quit();
	return(0);
}
