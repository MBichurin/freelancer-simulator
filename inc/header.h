#ifndef HEADER_H
#define HEADER_H

#include <SDL.h>
#include <SDL_image.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <math.h>
#include "audio.h"
void mx_load_digits(SDL_Texture ***digits, SDL_Renderer **rend);
void mx_item_texture(SDL_Texture ***s, SDL_Renderer **rend);
void mx_load_batteries(SDL_Texture ***tex_battery, SDL_Renderer **rend);
void mx_load_instruction(SDL_Texture ***screen, SDL_Renderer **rend);
void mx_drawmoney(int n, SDL_Renderer **rend, SDL_Texture** t_digits, bool mode);
void mx_drawamount(int n, SDL_Renderer **rend, SDL_Texture** t_digits, int x, int y);
void mx_drawordernum(int n, SDL_Renderer **rend, SDL_Texture** t_digits);
void mx_drawtime(int n, SDL_Renderer **rend, SDL_Texture** t_digits, bool mode);
void mx_draw_battery(float energy, SDL_Texture **tex_batteries, SDL_Texture** t_digits, SDL_Renderer **rend);
void mx_set_prices(int **Price);
void mx_menu_events(SDL_Event* e, int *scene, int *menu_frame);
void mx_room_events(SDL_Event* e, int *scene, int *sleep, int *time_saved, int time_begin, float *energy);
void mx_map_events(SDL_Event* e, int *scene, int *time_saved);
void mx_atb_events(SDL_Event* e, int *scene, int *category, int *time_saved,
int *money, int *item_index, int **Price, int **Amount, int*frame);
void mx_instruction_event(SDL_Event* e, int *scene, int *screen_index);
void mx_shop_events(SDL_Event* e, int *scene, int *category, int *time_saved,
int *money, int *item_index, int **Price, int **Amount, int *frame);

void mx_comp_event(SDL_Event* e, int *scene, int *category, int *time_saved,
int *money, int *item_index, int **Price, int **Amount, int *frame, bool *finished, bool *welldone,
bool *wannaEnd, int price_order);

void mx_xolodos_event(SDL_Event* e, int *scene, int *time_saved,
int *money, int *item_index, int **Price, int **Amount, float *energy,int *frame);
void mx_secret_events(SDL_Event* e, int *scene, int *category, int *time_saved,
int *money, int *item_index, int **Price, int *end, int*frame);
#endif /* HEADER_H */
