#include "../inc/header.h"

void mx_menu_events(SDL_Event* e, int *scene, int *menu_frame) {
    if (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_q) {
        *scene = -1;
        *menu_frame = 0;
    }
    //Get mouse position
    int x, y;
    SDL_GetMouseState(&x, &y);
    if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONUP) {
        //Game
        if(x > 87 && y > 67 && x < 192 && y < 195) {
            *menu_frame = 1;
        }
        //Instruction
        else if(x > 69 && y > 215 && x < 225 && y < 327.5) {
            *menu_frame = 2;
        }
        //end game
        else if(x > 1695 && y > 842 && x < 1828.5 && y < 991) {
            *menu_frame = 3;
        }
        else {
            *menu_frame = 0;
        }
    }
    if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP)
    {
        //Game
        if(x > 87 && y > 67 && x < 192 && y < 195 && e->button.button == SDL_BUTTON_LEFT) {
            *scene = 1;
            *menu_frame = 0;
        }
        //Instruction
        if(x > 69 && y > 215 && x < 225 && y < 327.5 && e->button.button == SDL_BUTTON_LEFT){
            *scene = 100;
            *menu_frame = 0;
        }
        //end game
        if(x > 1695 && y > 842 && x < 1828.5 && y < 991 && e->button.button == SDL_BUTTON_LEFT) {
            *scene = -1;
            *menu_frame = 0;
        }
        //secret
        if(x > 1521 && y > 736 && x < 1548 && y < 750 && e->button.button == SDL_BUTTON_LEFT) {
            *scene = 666;
            *menu_frame = 0;
        }
    }
}

void mx_room_events(SDL_Event* e, int *scene, int *sleep, int *time_saved, int time_begin, float *energy) {

    if (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_ESCAPE) {
        *scene = 0;
        *time_saved = SDL_GetTicks();
    }
    if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP)
    {
        //Get mouse position
        int x, y;
        SDL_GetMouseState(&x, &y);
        //Map
        if(x > 780 && y > 0 && x < 1132 && y < 30 && e->button.button == SDL_BUTTON_LEFT) {
            *scene = 10;
        }
        //Pause
        if(x > 17 && y > 1053 && x < 37 && y < 1074 && e->button.button == SDL_BUTTON_LEFT) {
            *scene = 0;
            *time_saved = SDL_GetTicks();
        }
        //Sleep
        if((((SDL_GetTicks() - time_begin) % (24 * 60000) >= 22 * 60000) || (SDL_GetTicks() -  time_begin) % (24 * 60000) < 4 * 60000) 
        && x > 1232 && y > 467 && x < 1852 && y < 720 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
            *sleep = 1;
            *energy += 50;
        }
        //Comp
        if(x > 60 && y > 543 && x < 286 && y < 782 && e->button.button == SDL_BUTTON_LEFT ) {
            *scene = 60;
        }
        //Xolodos
        if(x > 200 && y > 232 && x < 414 && y < 378 && e->button.button == SDL_BUTTON_LEFT ) {
            *scene = 228;
        }
    }
}

void mx_map_events(SDL_Event* e, int *scene, int *time_saved) {
    if (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_ESCAPE) {
        *scene = 0;
        *time_saved = SDL_GetTicks();
    }
    if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP) {
        //Get mouse position
        int x, y;
        SDL_GetMouseState(&x, &y);
        //Toroom
        if (x > 61 && y > 850 && x < 362 && y < 1047 && e->button.button == SDL_BUTTON_LEFT) {
            *scene = 1;
        }
        //Pause
        if (x > 17 && y > 1053 && x < 37 && y < 1074 && e->button.button == SDL_BUTTON_LEFT) {
            *scene = 0;
            *time_saved = SDL_GetTicks();
        }
        //Shop
        if (x > 50 && y > 460 && x < 520 && y < 697 && e->button.button == SDL_BUTTON_LEFT){
            *scene = 2;
        }
        //ATB
        if (x > 1119 && y > 622 && x < 1590 && y < 854 && e->button.button == SDL_BUTTON_LEFT){
            *scene = 322;
        } 
 }
}

void mx_atb_events(SDL_Event* e, int *scene, int *category, int *time_saved,
int *money, int *item_index, int **Price, int **Amount, int*frame) {
    if (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_ESCAPE) {
        *category = 0;
        *scene = 0;
        *item_index = -1;
        *time_saved = SDL_GetTicks();
    }
    // Get mouse position
    int x, y;
    SDL_GetMouseState(&x, &y);
    if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP) {
        // Tomap
        if(x > 1870 && y > 0 && x < 1920 && y < 48 && e->button.button == SDL_BUTTON_LEFT) {
            *category = 0;
            *item_index = -1;
            *scene = 10;
        }
        // Pause
        if(x > 17 && y > 1053 && x < 37 && y < 1074 && e->button.button == SDL_BUTTON_LEFT) {
            *category = 0;
            *scene = 0;
            *item_index = -1;
            *time_saved = SDL_GetTicks();
        }
    }

     // Item 29
    if (x > 244 && y > 129 && x < 394 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 29;
        *frame = 1;
    }

    // Item 30
    if (x > 404 && y > 129 && x < 554 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 30;
        *frame = 2;
    }

    // Buy
    if (*item_index != -1 && x > 1600 && y > 870 && x < 1801 && y < 979 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *money -= (*Price)[*item_index];
        bool sound = true;
        if(sound) {
            Audio *music = createAudio("resource/sounds/buy.wav", 0, SDL_MIX_MAXVOLUME);
            playSoundFromMemory(music, SDL_MIX_MAXVOLUME);
            sound = false;
            freeAudio(music);
        }
        (*Amount)[*item_index]++;
        *item_index = -1;
    }
}

void mx_instruction_event(SDL_Event* e, int *scene, int *screen_index){
    if (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_ESCAPE) {
        *scene = 0;
    }
    if(*screen_index == 2){
        *scene = 0;
    }
    if(*screen_index == -1)
        *scene = 0;
    if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP) {
        int x, y;
        SDL_GetMouseState(&x, &y);
        //Tonext
        if (x > 1770 && y > 960 && x < 1845 && y < 1035 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN){
            (*screen_index)++;
            SDL_Delay(500);
        }
        //Toprev
        if (x > 1693 && y > 960 && x < 1770 && y < 1035 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN){
            (*screen_index)--;
            SDL_Delay(500);
        }
    }
}
