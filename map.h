#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include <SDL2\SDL.h>

#define TILE_SIZE 62
#define MAP_LARGEUR 17
#define MAP_HAUTEUR 15

SDL_Window *window;
SDL_Event event;
//SDL_Surface* screen, tileset, tile_P, timer;
SDL_Surface* screen;
SDL_Surface* tileset;
SDL_Surface* tile_P;
SDL_Surface* timer_texte;
SDL_Surface* out_s;
SDL_Surface* escape_s;

unsigned int mil, sec;

char temps[20], out_c[20], escape_c[20];

//SDL_Rect position;

char map[MAP_HAUTEUR][MAP_LARGEUR];

char sprite[MAP_HAUTEUR][MAP_LARGEUR];

void Afficher();

// void Afficher_Warden (SDL_Window* window,
//                       SDL_Surface* screen,
//                       SDL_Surface* tileset,
//                       int position);


#endif // MAP_H_INCLUDED
