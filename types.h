#ifndef TYPES_H_INCLUDED
#define TYPES_H_INCLUDED

#include <SDL2\SDL.h>
#include <stdbool.h>

#define UP      0
#define DOWN    1
#define LEFT    2
#define RIGHT   3

#define LEFT_SIDE    0
#define RIGHT_SIDE   1

//const int SCREEN_WIDTH = 500,SCREEN_HEIGHT= 500;

typedef struct
{
    char*           Name;
    int             Cell;
    bool            In_cell;
    int             Side;
    int             Position;
    int             Last_Position;
    unsigned int    Move_Time, Break_Time, Rand_Time;
    int x, y;
}Inmate;

typedef struct
{
    int Side;
    int Position;
    int x, y;
//    int Cell;
}Warden;

Warden LEFT_WARDEN;
Warden RIGHT_WARDEN;

Inmate INMATE_01;
Inmate INMATE_02;
Inmate INMATE_03;


unsigned int currentTime;
unsigned int rand_move;

unsigned int escaped_inmates, inmates_out;


//void afficherImage (int x, int y, SDL_Renderer* renderer, char* nomFichier);

void keys_move (SDL_Event event);

void Warden_movements (Warden* w, int direction);

void Warden_position (Warden* w);

void Inmate_position (Inmate* i);

void Inmate_passive_movements (Inmate* i);

void Inmate_jail_break (Inmate* i, Inmate* a, Inmate* b, Warden* RIGHT_W, Warden* LEFT_W);

void Inmate_common_area (Inmate* i, Warden* RIGHT_W, Warden* LEFT_W);

void rencontre (Inmate* i, Warden* RIGHT_W, Warden* LEFT_W);

void fin (SDL_Event* S_E);


#endif // TYPES_H_INCLUDED
