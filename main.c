#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2\SDL.h>
#include <SDL2\SDL_ttf.h>
//#include <SDL/SDL_image.h>

#include "types.h"
#include "map.h"


int main( int argc, char* args[] )  // variables sdl en global ?
 {
//    SDL_Init(SDL_INIT_VIDEO);		// prepare SDL
//
//	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
//    {
//        SDL_Log("SDL_Error: %s \n", SDL_GetError());
//        SDL_Quit();
//        exit(-1);
//    }

//------------------------------------------------------
    TTF_Init();

    TTF_Font* font = TTF_OpenFont("upheavtt.ttf", 25);
    SDL_Color color = { 255, 255, 255 };

//------------------------------------------------------

    window = SDL_CreateWindow("THE PRISON",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              TILE_SIZE * MAP_LARGEUR,
                              TILE_SIZE * MAP_HAUTEUR,
                              SDL_WINDOW_SHOWN);   // SDL_WINDOW_OPENGL

    if (window == NULL)
    {
        SDL_Log("Could not create a window: %s \n", SDL_GetError());
        SDL_Quit();
        exit(-1);
//        return -1;
    }

//    SDL_Renderer* renderer = SDL_CreateRenderer ( window, -1, SDL_RENDERER_ACCELERATED);
//
//    afficherImage (0, 0, renderer, "Lvl_01_MAP_V2.bmp");
//
//    SDL_RenderPresent (renderer);

//    SDL_Surface* BG      = IMG_Load("Menu.jpg");
    screen  = SDL_GetWindowSurface(window);
    tileset = SDL_LoadBMP("Tileset.bmp");
    if (!tileset)
    {
        printf("Echec de chargement Tileset.bmp\n");
        SDL_Quit();
        exit(-1);
    }

    tile_P  = SDL_LoadBMP("Tile_P.bmp");
    if (!tile_P)
    {
        printf("Echec de chargement Tile_P.bmp\n");
        SDL_Quit();
        exit(-1);
    }

//----------------------------------------//

    LEFT_WARDEN.Side        = LEFT_SIDE;
    LEFT_WARDEN.Position    = 11;
    LEFT_WARDEN.x           = 7;
    LEFT_WARDEN.y           = 2;

    RIGHT_WARDEN.Side       = RIGHT_SIDE;
    RIGHT_WARDEN.Position   = 11;
    RIGHT_WARDEN.x          = 7;
    RIGHT_WARDEN.y          = 14;

    INMATE_01.Name          = "JACK";
    INMATE_01.Cell          = 1;
    INMATE_01.In_cell       = true;
    INMATE_01.Position      = 3;
    INMATE_01.Side          = NULL;
    INMATE_01.Move_Time     = 0;
    INMATE_01.Break_Time    = 0;
    INMATE_01.Rand_Time     = rand() % 10 + 3;  //15 + 5
    INMATE_01.x             = 3;
    INMATE_01.y             = 8;

    INMATE_02.Name          = "BOB";
    INMATE_02.Cell          = 2;
    INMATE_02.In_cell       = true;
    INMATE_02.Position      = 3;
    INMATE_02.Side          = NULL;
    INMATE_02.Move_Time     = 0;
    INMATE_02.Break_Time    = 0;
    INMATE_02.Rand_Time     = rand() % 10 + 3;  //15 + 5
    INMATE_02.x             = 7;
    INMATE_02.y             = 8;

    INMATE_03.Name          = "JEAN";
    INMATE_03.Cell          = 3;
    INMATE_03.In_cell       = true;
    INMATE_03.Position      = 3;
    INMATE_03.Side          = NULL;
    INMATE_03.Move_Time     = 0;
    INMATE_03.Break_Time    = 0;
    INMATE_03.Rand_Time     = rand() % 10 + 3;  //15 + 5
    INMATE_03.x             = 11;
    INMATE_03.y             = 8;

    escaped_inmates = 0;
    inmates_out     = 0;
//    rand_move       = rand() % 9 + 3;

    sprite[LEFT_WARDEN.x][LEFT_WARDEN.y]    = 'W';
    sprite[RIGHT_WARDEN.x][RIGHT_WARDEN.y]  = 'W';
    sprite[INMATE_01.x][INMATE_01.y]        = 'I';
    sprite[INMATE_02.x][INMATE_02.y]        = 'I';
    sprite[INMATE_03.x][INMATE_03.y]        = 'I';

//--------------------//

//    while(entrer != true){
//
//    }

    do {
        currentTime = SDL_GetTicks();

        if (currentTime > mil + 1000){
            sec++;
            sprintf(temps, "Time : %d", sec);
            timer_texte = TTF_RenderText_Solid(font, temps, color);
            mil = currentTime;
        }

        sprintf(out_c, "Inmates out : %d", inmates_out);
        out_s = TTF_RenderText_Solid(font, out_c, color);

        sprintf(escape_c, "Escaped : %d", escaped_inmates);
        escape_s = TTF_RenderText_Solid(font, escape_c, color);

        Afficher();

        if (INMATE_01.In_cell == true && INMATE_01.Position < 6){
            Inmate_jail_break(&INMATE_01, &INMATE_02, &INMATE_03, &RIGHT_WARDEN, &LEFT_WARDEN);
        }else{
            Inmate_common_area(&INMATE_01, &RIGHT_WARDEN, &LEFT_WARDEN);
        }

        if (INMATE_02.In_cell == true && INMATE_02.Position < 6){
            Inmate_jail_break(&INMATE_02, &INMATE_01, &INMATE_03, &RIGHT_WARDEN, &LEFT_WARDEN);
        }else{
            Inmate_common_area(&INMATE_02, &RIGHT_WARDEN, &LEFT_WARDEN);
        }

        if (INMATE_03.In_cell == true && INMATE_03.Position < 6){
            Inmate_jail_break(&INMATE_03, &INMATE_01, &INMATE_02, &RIGHT_WARDEN, &LEFT_WARDEN);
        }else{
            Inmate_common_area(&INMATE_03, &RIGHT_WARDEN, &LEFT_WARDEN);
        }

        fin (&event);

        if (event.type == SDL_QUIT){
                break;
        }

        if (SDL_PollEvent(&event))        // while
        {
            if (event.type == SDL_KEYDOWN){
                keys_move(event);
                rencontre(&INMATE_01, &RIGHT_WARDEN, &LEFT_WARDEN);
                rencontre(&INMATE_02, &RIGHT_WARDEN, &LEFT_WARDEN);
                rencontre(&INMATE_03, &RIGHT_WARDEN, &LEFT_WARDEN);
            }
        }
    } while(event.type != SDL_QUIT);

    TTF_CloseFont(font);
    TTF_Quit();

    SDL_DestroyWindow(window);
    SDL_Quit();

  return EXIT_SUCCESS;
 }
