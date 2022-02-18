#include "types.h"
#include "map.h"

#include <stdio.h>
#include <stdlib.h>


//void afficherImage (int x, int y, SDL_Renderer* renderer, char* nomFichier)
//{
//    SDL_Surface* surface_image = SDL_LoadBMP (nomFichier);
//    if ( surface_image )
//    {
//    SDL_Texture* image = SDL_CreateTextureFromSurface ( renderer , surface_image );
//    if ( image )
//    {
//        SDL_SetRenderTarget ( renderer , image );
//        SDL_Rect r;
//        r.x = x;
//        r.y = y;
//        SDL_QueryTexture ( image, NULL, NULL, &(r.w), &(r.h));
////        printf ("On rend l'image dans le rectangle %d %d %d %d\n", r.x, r.y, r.w, r.h);
//        SDL_RenderCopy ( renderer , image , NULL , &r);
//        SDL_SetRenderTarget ( renderer , NULL );
//        SDL_DestroyTexture (image);
//        }
//        else {
//            fprintf (stderr, "Erreur de création de la texture\n");
//        }
//        SDL_FreeSurface (surface_image);
//    }
//    else {
//        fprintf (stderr, "Erreur de chargement de l'image %s\n", nomFichier);
//    }
//}

void keys_move (SDL_Event event)
{
     switch(event.key.keysym.sym){
        case SDLK_UP:    Warden_movements (&RIGHT_WARDEN, UP); break;
        case SDLK_DOWN:  Warden_movements (&RIGHT_WARDEN, DOWN); break;
        case SDLK_LEFT:  Warden_movements (&RIGHT_WARDEN, LEFT); break;
        case SDLK_RIGHT: Warden_movements (&RIGHT_WARDEN, RIGHT); break;

        case SDLK_z: Warden_movements (&LEFT_WARDEN, UP); break;
        case SDLK_s: Warden_movements (&LEFT_WARDEN, DOWN); break;
        case SDLK_q: Warden_movements (&LEFT_WARDEN, RIGHT); break;
        case SDLK_d: Warden_movements (&LEFT_WARDEN, LEFT); break;

        case SDLK_ESCAPE: event.type = SDL_QUIT; break;
    }
}

void Warden_movements (Warden* w, int direction)
{
    switch (direction){
        case UP:    switch (w->Position){
//                        case 10: w->Position = 8 ; break;
//                        case 12: w->Position = 10; break;
                        case 11: w->Position = 9 ; break;
                        case 13: w->Position = 11; break;
                    } break;
        case DOWN:  switch (w->Position){
//                        case 8 : w->Position = 10; break;
//                        case 10: w->Position = 12; break;
                        case 0 : w->Position = 11; break;
                        case 9 : w->Position = 11; break;
                        case 11: w->Position = 13; break;
                    } break;
        case LEFT:  switch (w->Position){
                        case 0 : w->Position = 11; break;
                        case 9 : w->Position = 8 ; break;
                        case 11: w->Position = 10; break;
                        case 13: w->Position = 12; break;
                    } break;
        case RIGHT: switch (w->Position){
                        case 0 : w->Position = 11; break;
                        case 8 : w->Position = 9 ; break;
                        case 10: w->Position = 11; break;
                        case 12: w->Position = 13; break;
                    } break;
    }

    Warden_position(w);
}

void Warden_position (Warden* w)
{
    sprite[w->x][w->y] = ' ';
    if (w->Side == LEFT_SIDE){
        switch (w->Position){
            case 0 :w->x = 6;  w->y = 1; break;
            case 8 :w->x = 3;  w->y = 5; break;
            case 9 :w->x = 3;  w->y = 2; break;
            case 10:w->x = 7;  w->y = 5; break;
            case 11:w->x = 7;  w->y = 2; break;
            case 12:w->x = 11; w->y = 5; break;
            case 13:w->x = 11; w->y = 2; break;
        }
    }
    if (w->Side == RIGHT_SIDE){
        switch (w->Position){
            case 0 :w->x = 6;  w->y = 15; break;
            case 8 :w->x = 3;  w->y = 11; break;
            case 9 :w->x = 3;  w->y = 14; break;
            case 10:w->x = 7;  w->y = 11; break;
            case 11:w->x = 7;  w->y = 14; break;
            case 12:w->x = 11; w->y = 11; break;
            case 13:w->x = 11; w->y = 14; break;
        }
    }
    sprite[w->x][w->y] = 'W';
}

void Inmate_position (Inmate* i)
{
    sprite[i->x][i->y] = ' ';
    if (i->Side == LEFT_SIDE){
        switch (i->Position){
            case 8 :i->x = 3;  i->y = 4; break;
            case 9 :i->x = 3;  i->y = 2; break;
            case 10:i->x = 7;  i->y = 4; break;
            case 11:i->x = 7;  i->y = 2; break;
            case 12:i->x = 11; i->y = 4; break;
            case 13:i->x = 11; i->y = 2; break;
        }
    }
    if (i->Side == RIGHT_SIDE){
        switch (i->Position){
            case 8 :i->x = 3;  i->y = 12; break;
            case 9 :i->x = 3;  i->y = 14; break;
            case 10:i->x = 7;  i->y = 12; break;
            case 11:i->x = 7;  i->y = 14; break;
            case 12:i->x = 11; i->y = 12; break;
            case 13:i->x = 11; i->y = 14; break;
        }
    }

//    if(i->Side == NULL){      // necessaire ?
//
//    }

    switch(i->Position){
        case 1: i->x = 2 + (4*(i->Cell-1)); i->y = 7 ; break;
        case 2: i->x = 2 + (4*(i->Cell-1)); i->y = 9 ; break;
        case 3: i->x = 3 + (4*(i->Cell-1)); i->y = 8 ; break;
        case 4: i->x = 4 + (4*(i->Cell-1)); i->y = 9 ; break;
        case 5: i->x = 4 + (4*(i->Cell-1)); i->y = 7 ; break;
        case 6: i->x = 3 + (4*(i->Cell-1)); i->y = 6 ; break;
        case 7: i->x = 3 + (4*(i->Cell-1)); i->y = 10; break;
        // pas de defaults à cause des des position au dessus de 7, sinon : i->x = i->x + (4*(i->Cell-1));
    }

    if (i->Position == 0){          // peux faire un case 0
        i->x = NULL; i->y = NULL;
    }
    else{
        sprite[i->x][i->y] = 'I';
    }
}

void Inmate_passive_movements (Inmate* i)
{
    i->Position = rand() % 5 + 1;
//    printf("Inmate %d position : %2d     |      Time : %d \n", i->Cell, i->Position, (currentTime/1000));

//    sprite[i->x][i->y] = ' ';
//
//    switch(i->Position){
//        case 1: i->x = 2; i->y = 7; break;
//        case 2: i->x = 2; i->y = 9; break;
//        case 3: i->x = 3; i->y = 8; break;
//        case 4: i->x = 4; i->y = 9; break;
//        case 5: i->x = 4; i->y = 7; break;
//    }
//
//    i->x = i->x + (4*(i->Cell-1));  // i->x + (4*i->Cell)   si modif
//
//    sprite[i->x][i->y] = 'I';

    Inmate_position(i);     // aurais pu faire manuellement mais j'ai fais une fonction pour pouvoir être rappeler dans d'autres

    i->Move_Time = currentTime;
}

void Inmate_jail_break (Inmate* i, Inmate* a, Inmate* b, Warden* RIGHT_W, Warden* LEFT_W)
{
    if (currentTime > i->Move_Time + 1000){     // currentTime > lastTime + (rand_move * 1000)
        if ((currentTime > i->Break_Time + (i->Rand_Time * 1000)))
//         && (a->In_cell == true || b->In_cell == true ||
//             a->Position == 0 || b->Position == 0))
        {
//            i->Last_Position = i->Position;

//            sprite[i->x][i->y] = ' ';

            switch(i->Position){
                case 1: i->Position = 6; break;
                case 5: i->Position = 6; break;
                case 2: i->Position = 7; break;
                case 4: i->Position = 7; break;
                case 3: i->Position = rand() % 2 + 6; break;
            }

            for(int v = 0; v < 2; v++){     // SDL_Delay à modif pour la présentation ??
                if (i->Position == 6){
                    if ((i->Cell == 1 && LEFT_W->Position == 8 ) ||
                        (i->Cell == 2 && LEFT_W->Position == 10) ||
                        (i->Cell == 3 && LEFT_W->Position == 12))
                    {
                        if (v == 0){
                            Inmate_position(i);     // avant c'était manuel
                            Afficher();
                            SDL_Delay (200);

                            i->Position = 3;
                            Inmate_position(i);
                            Afficher();
                            SDL_Delay (200);

                            i->Position = 7;
                            Inmate_position(i);
                            Afficher();
                            SDL_Delay (200);

                            printf("bloqué");
                        }
                        else{
                            i->Side = NULL;
                            i->Position = 3;
                            printf("sort pas");
                        }
                    }
                    else{
                        i->Side = LEFT_SIDE;
                        map[3 + (4*(i->Cell-1))][5] = '2';
                    }
                }
                else {
                    if ((i->Cell == 1 && RIGHT_W->Position == 8 ) ||
                        (i->Cell == 2 && RIGHT_W->Position == 10) ||
                        (i->Cell == 3 && RIGHT_W->Position == 12))
                    {
                        if (v == 0){
                            Inmate_position(i);
                            Afficher();
                            SDL_Delay (200);

                            i->Position = 3;
                            Inmate_position(i);
                            Afficher();
                            SDL_Delay (200);

                            i->Position = 6;
                            Inmate_position(i);
                            Afficher();
                            SDL_Delay (200);

                            printf("bloqué");
                        }
                        else{
                            i->Side = NULL;
                            i->Position = 3;
                            printf("sort pas");
                        }
                    }
                    else{
                        i->Side = RIGHT_SIDE;
                        map[3 + (4*(i->Cell-1))][11] = '2';
                    }
                }
            }

            Inmate_position(i);
            Afficher();
            SDL_Delay (200);

//               printf("ESCAPE POSITION = %d : Inmate %d \n", i->Position, i->Cell);

            i->Rand_Time = rand() % 9 + 5;
            i->Break_Time = currentTime;
        }
        else{
            Inmate_passive_movements(i);
        }
    }
}

void Inmate_common_area (Inmate* i, Warden* RIGHT_W, Warden* LEFT_W)
{
    if (currentTime > i->Move_Time + 500){     // à modifier pour changer la vitesse de déplacement des prisonniers
        switch(i->Position){                   // gros changement à parler
            case 6 :
            case 7 : i->Last_Position = i->Position;
                     i->Position = 8 + (2*(i->Cell-1));
                     i->In_cell = false;
                     inmates_out++;
                     printf("\nLe prisonnier %d est sorti de sa cellule ! \n", i->Cell);
                     break;
            case 8 : i->Last_Position = i->Position;
                     i->Position = 9;
                     break;
            case 9 :
            case 10: i->Last_Position = i->Position;
                     i->Position = 11;
                     break;
            case 11: i->Last_Position = 0;
                     i->Position = 0;
                     escaped_inmates++;
                     inmates_out--;
                     printf("\nLe prisonnier %d : %s, s'est echappee \n", i->Cell, i->Name);
                     break;
            case 12: i->Last_Position = i->Position;
                     i->Position = 13;
                     break;
            case 13: i->Last_Position = i->Position;
                     i->Position = 11;
                     break;
        }
        rencontre(i, RIGHT_W, LEFT_W);
        Inmate_position (i);
        i->Move_Time = currentTime;
    }
}

void rencontre (Inmate* i, Warden* RIGHT_W, Warden* LEFT_W)
{
    if ((i->Side == RIGHT_SIDE && RIGHT_W->Position == i->Position) ||
        (i->Side == LEFT_SIDE && LEFT_W->Position == i->Position))
        {
            if (
                (INMATE_01.Cell != i->Cell && INMATE_01.Side == i->Side && INMATE_01.Position == 9)  ||
                (INMATE_02.Cell != i->Cell && INMATE_02.Side == i->Side && INMATE_02.Position == 10) ||
                (INMATE_03.Cell != i->Cell && INMATE_03.Side == i->Side && INMATE_03.Position == 13))
            {
                for(int v = 0; v < 5; v++){
//                    sprite[i->x][i->y] = ' ';
//                    switch(i->Cell){
//                        case 1: i->x++; break;
//                        case 2: if(i->Side == RIGHT_SIDE){
//                                    i->y++;}
//                                else{
//                                    i->y--;}
//                                break;
//                        case 3: i->x--; break;
//                    }
//                    sprite[i->x][i->y] = 'I';
                    if (INMATE_01.Side == i->Side && v != 0){
                        sprite[INMATE_01.x][INMATE_01.y] = ' ';
                        INMATE_01.x++;
                        sprite[INMATE_01.x][INMATE_01.y] = 'I';
                    }
                    if (INMATE_02.Side == i->Side && v > 1){
                        sprite[INMATE_02.x][INMATE_02.y] = ' ';
                        if(i->Side == RIGHT_SIDE){
                            INMATE_02.y++;
                        }
                        else{
                            INMATE_02.y--;
                        }
                        sprite[INMATE_02.x][INMATE_02.y] = 'I';
                    }
                    if (INMATE_03.Side == i->Side && v != 0){
                        sprite[INMATE_03.x][INMATE_03.y] = ' ';
                        INMATE_03.x--;
                        sprite[INMATE_03.x][INMATE_03.y] = 'I';
                    }

                    switch(v){
                        case 3 :if (i->Side == RIGHT_SIDE){
                                    sprite[RIGHT_W->x][RIGHT_W->y] = ' ';
                                    RIGHT_W->y++;
                                    sprite[RIGHT_W->x][RIGHT_W->y] = 'W';
                                }
                                else{
                                    sprite[LEFT_W->x][LEFT_W->y] = ' ';
                                    LEFT_W->y--;
                                    sprite[LEFT_W->x][LEFT_W->y] = 'W';
                                } break;
                        case 4 :if (i->Side == RIGHT_SIDE){
                                    RIGHT_W->Position = 0;
                                    Warden_position(RIGHT_W);
                                }
                                else{
                                    LEFT_W->Position = 0;
                                    Warden_position(LEFT_W);
                                } break;
                    }
                    Afficher();
                    SDL_Delay(50);  // changer la vitesse de l'animation (correction bug ?)
                }
            }
            else{
                while(i->Position != i->Last_Position){
                    i->Position = i->Last_Position;
                    i->Move_Time = currentTime;
                }

                Inmate_position (i);

                switch(i->Position){
                    case 6 :
                    case 7 :i->In_cell = true;
                            i->Position = 3;
                            i->Side = NULL;
                            inmates_out--;
                            i->Break_Time = currentTime;
                            printf ("Retour en cellule : Prisonnier : %d \n", i->Cell);
                            map[i->x][5] = '4';    //if?
                            map[i->x][11] = '3';
                            break;
                    case 8 :if (i->Side == LEFT_SIDE){
                                i->Last_Position = 6 ;
                            }
                            else{
                                i->Last_Position = 7 ;
                            } break;
                    case 9 : i->Last_Position = 8 ; break;
                    case 10: i->Last_Position = 7 ; break;
                    case 12: i->Last_Position = 7 ; break;
                    case 13: i->Last_Position = 12; break;
                }
            }
    }
}

void fin (SDL_Event* S_E)
{
    if (currentTime > 60000 || escaped_inmates == 3){ // à modifier pour plus de temps
        printf("escaped : %d    |    out : %d \n", escaped_inmates, inmates_out);
        switch(escaped_inmates){
            case 0: switch(inmates_out){
                        case 0: printf("\n Tous les prisonniers sont dans leur cellule. \n Bravo vous avez maitrise la revolte à la perfection ! \n");
                                break;
                        case 1: printf("\n Un prisonnier est hors de sa cellule mais personne ne s'est evadee. Vous avez bien fait votre travail. \n");
                                break;
                        case 2: printf("\n Deux prisonniers sont hors de leur cellule mais personne ne s'est evadee. Bon travail, mais vous auriez pu faire mieux. \n");
                                break;
                        case 3: printf("\n Tous les prisonniers sont hors de leurs cellules mais personne ne s'est evadee. C'est du travail de debutant. Que cela ne se reproduise plus ! \n");
                                break;
                    } break;
            case 1: switch(inmates_out){
                        case 0: printf("\n Un prisonnier s'est evade mais vous avez quand meme maitrise la revolte. \n");
                                SDL_Delay (2000);
                                printf("\n Cependant vous etes quand meme vire \n");
                                break;
                        case 1: printf("\n Un prisonnier s'est evade et un autre est hors de sa cellule ! \n");
                                SDL_Delay (2000);
                                printf("\n Vous etes vire. \n");
                                break;
                        case 2: printf("\n Un prisonnier s'est evade et deux autres sont hors de leurs cellules ! \n");
                                SDL_Delay (1000);
                                printf("\n Clairement... \n");
                                SDL_Delay (2000);
                                printf("\n Vous etes vire ! \n");
                                break;
                    } break;
            case 2: switch(inmates_out){
                        case 0: printf("\n Deux prisonniers se sont evades... \n");
                                SDL_Delay (2000);
                                printf("\n Vous faisiez une pause ou quoi ? \n");
                                SDL_Delay (2000);
                                printf("\n Vous etes vire ! \n");
                                break;
                        case 1: printf("\n Deux prisonniers se sont evades et un est hors de sa cellule... \n");
                                SDL_Delay (2000);
                                printf("\n Comment avez-vous eu ce job ? \n");
                                SDL_Delay (2000);
                                printf("\n Vous etes vire ! \n");
                                break;
                    } break;
            case 3: printf("\n Tous les prisonniers se sont echappes... Vous etes VIRE ! \n");
                    SDL_Delay (2000);
                    printf("\n Vous etes le pire gardien que ces murs ont jamais vu...");
                    break;
        }
//        SDL_Delay (3000);
        S_E->type = SDL_QUIT;
    }
}
