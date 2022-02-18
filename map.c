#include "map.h"


char map[MAP_HAUTEUR][MAP_LARGEUR] = {
                    "65555555555555559",//0
                    "09999900000999991",//1
                    "09999939994999991",//2
                    "09999499999399991",//3
                    "09999939994999991",//4
                    "09990000000009991",//5
                    "79999939994999998",//6
                    "59999499999399996",//7
                    "79999939994999998",//8
                    "09990000000009991",//9
                    "09999939994999991",//10
                    "09999499999399991",//11
                    "09999939994999991",//12
                    "09999900000999991",//13
                    "75555555555555558" //14
                 };//01234567890123456

char mur[MAP_HAUTEUR][MAP_LARGEUR] = {
                    "73333333333333338",
                    "0               1",
                    "0               1",
                    "0               1",
                    "0               1",
                    "0               1",
                    "                 ",
                    "                 ",
                    "                 ",
                    "0               1",
                    "0               1",
                    "0               1",
                    "0               1",
                    "0               1",
                    "64444444444444449"
                 };

void Afficher()
//              int direction);     // tout en global ?
{
	char temp;
	SDL_Rect Rect_dest;
	SDL_Rect Rect_source;

	Rect_source.w = TILE_SIZE;
	Rect_source.h = TILE_SIZE;

	for(int i = 0; i < MAP_LARGEUR; i++)
	{
		for(int j = 0; j < MAP_HAUTEUR; j++)
		{
            Rect_dest.x = i*TILE_SIZE;
            Rect_dest.y = j*TILE_SIZE;

			if (mur[j][i] != ' '){
                Rect_source.x = (mur[j][i]-'0')*TILE_SIZE;
                Rect_source.y = TILE_SIZE;
//                SDL_BlitSurface(tileset, &Rect_source, screen, &Rect_dest);
			}
			else{
                Rect_source.x = (map[j][i]-'0')*TILE_SIZE;
                Rect_source.y = 0;
			}

            SDL_BlitSurface(tileset, &Rect_source,screen, &Rect_dest);

            temp = sprite[j][i];

            switch(temp){
                case 'W':   Rect_source.x = 0;
                            Rect_source.y = 0;
                            SDL_BlitSurface(tile_P, &Rect_source, screen, &Rect_dest);
                            break;
                case 'I':   Rect_source.x = TILE_SIZE;
                            Rect_source.y = 0;
                            SDL_BlitSurface(tile_P, &Rect_source, screen, &Rect_dest);
                            break;
            }

//            if (sprite[j][i] == 'P'){
//                Rect_source.x = 0;  //direction*TILE_SIZE;
//                Rect_source.y = 0;
//                SDL_BlitSurface(tile_P, &Rect_source, screen, &Rect_dest);
//			}
		}
	}
	Rect_dest.x = 10;
    Rect_dest.y = 10;
	SDL_BlitSurface(timer_texte, NULL, screen, &Rect_dest);

	Rect_dest.x = 600;
    Rect_dest.y = 10;
	SDL_BlitSurface(out_s, NULL, screen, &Rect_dest);

	Rect_dest.x = 900;
    Rect_dest.y = 10;
	SDL_BlitSurface(escape_s, NULL, screen, &Rect_dest);

	SDL_UpdateWindowSurface(window);
}

//void Afficher_Warden (SDL_Window* window,
//                      SDL_Surface* screen,
//                      SDL_Surface* tileset,
//                      int position)
//{
//    SDL_Rect Rect_dest;     // surface de destination
//	SDL_Rect Rect_source;   // texture source
//
////	Rect_dest.x     = TILE_SIZE;
////	Rect_dest.y     = TILE_SIZE;
//	Rect_source.w   = TILE_SIZE;
//	Rect_source.h   = TILE_SIZE;
//	Rect_source.x   = 0;
//	Rect_source.y   = 0;
//
//    switch(position){
//        case 11:Rect_dest.x = 2*TILE_SIZE; Rect_dest.y = 5*TILE_SIZE; break;
//	}
//	printf("Pos : %d", position);
//    SDL_BlitSurface(tileset,&Rect_source,screen,&Rect_dest);
//    SDL_UpdateWindowSurface(window);
//}
