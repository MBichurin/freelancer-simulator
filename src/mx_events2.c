#include "../inc/header.h"
void mx_shop_events(SDL_Event* e, int *scene, int *category, int *time_saved,
int *money, int *item_index, int **Price, int **Amount, int *frame) {
    if (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_ESCAPE) {
        *scene = 0;
        *time_saved = SDL_GetTicks();
    }
    if (e->type == SDL_KEYUP && e->key.keysym.sym == SDLK_1) {
        *category = 0;
        *item_index = -1;
    }
    if (e->type == SDL_KEYUP && e->key.keysym.sym == SDLK_2) {
        *category = 1;
        *item_index = -1;
    }
    if (e->type == SDL_KEYUP && e->key.keysym.sym == SDLK_3) {
        *category = 2;
        *item_index = -1;
    }
    if (e->type == SDL_KEYUP && e->key.keysym.sym == SDLK_4) {
        *category = 3;
        *item_index = -1;
    }
    if (e->type == SDL_KEYUP && e->key.keysym.sym == SDLK_5) {
        *category = 4;
        *item_index = -1;
    }
    if (e->type == SDL_KEYUP && e->key.keysym.sym == SDLK_6) {
        *category = 5;
        *item_index = -1;
    }
    if (e->type == SDL_KEYUP && e->key.keysym.sym == SDLK_7) {
        *category = 6;
        *item_index = -1;
    }
    if (e->type == SDL_KEYUP && e->key.keysym.sym == SDLK_8) {
        *category = 7;
        *item_index = -1;
    }

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

        // Cases
        if(x > 4 && y > 63 && x < 202 && y < 87 && e->button.button == SDL_BUTTON_LEFT) {
            *category = 0;
            *item_index = -1;
        }
        // CPU
        if(x > 4 && y > 87 && x < 202 && y < 120 && e->button.button == SDL_BUTTON_LEFT) {
            *category = 1;
            *item_index = -1;
        }
        // Graphics cards
        if(x > 4 && y > 120 && x < 202 && y < 157 && e->button.button == SDL_BUTTON_LEFT) {
            *category = 2;
            *item_index = -1;
        }
        // HDD/SSD
        if(x > 4 && y > 157 && x < 202 && y < 173 && e->button.button == SDL_BUTTON_LEFT) {
            *category = 3;
            *item_index = -1;
        }
        // Motherboards
        if(x > 4 && y > 173 && x < 202 && y < 210 && e->button.button == SDL_BUTTON_LEFT) {
            *category = 4;
            *item_index = -1;
        }
        // Power Supplies
        if(x > 4 && y > 210 && x < 202 && y < 247 && e->button.button == SDL_BUTTON_LEFT) {
            *category = 5;
            *item_index = -1;
        }
        // RAM
        if(x > 4 && y > 247 && x < 202 && y < 284 && e->button.button == SDL_BUTTON_LEFT) {
            *category = 6;
            *item_index = -1;
        }
        // Cooler
        if(x > 4 && y > 284 && x < 202 && y < 321 && e->button.button == SDL_BUTTON_LEFT) {
            *category = 7;
            *item_index = -1;
        }
    }

    // item 0
    if (*category == 0 && x > 244 && y > 129 && x < 394 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 0;
        *frame = 1;
    }
    // item 1
    if (*category == 0 && x > 404 && y > 129 && x < 554 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 1;
        *frame = 2;
    }
    // item 2
    if (*category == 0 && x > 564 && y > 129 && x < 714 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 2;
        *frame = 3;
    }
    // item 3
    if (*category == 0 && x > 724 && y > 129 && x < 874 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 3;
        *frame = 4;
    }
    // item 4
    if (*category == 1 && x > 244 && y > 129 && x < 394 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 4;
        *frame = 1;
    }
    // item 5
    if (*category == 1 && x > 404 && y > 129 && x < 554 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 5;
        *frame = 2;
    }
    // item 6
    if (*category == 1 && x > 564 && y > 129 && x < 714 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 6;
        *frame = 3;
    }
    // item 7
    if (*category == 2 && x > 244 && y > 129 && x < 394 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 7;
        *frame = 1;
    }
    // item 8
    if (*category == 2 && x > 404 && y > 129 && x < 554 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 8;
        *frame = 2;
    }
    // item 9
    if (*category == 2 && x > 564 && y > 129 && x < 714 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 9;
        *frame = 3;
    }
    // item 10
    if (*category == 2 && x > 724 && y > 129 && x < 874 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 10;
        *frame = 4;
    }
    // item 11
    if (*category == 3 && x > 244 && y > 129 && x < 394 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 11;
        *frame = 1;
    }
    // item 12
    if (*category == 3 && x > 404 && y > 129 && x < 554 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 12;
        *frame = 2;
    }
    // item 13
    if (*category == 3 && x > 564 && y > 129 && x < 714 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 13;
        *frame = 3;
    }
    // item 14
    if (*category == 4 && x > 244 && y > 129 && x < 394 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 14;
        *frame = 1;
    }
    // item 15
    if (*category == 4 && x > 404 && y > 129 && x < 554 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 15;
        *frame = 2;
    }
    // item 16
    if (*category == 4 && x > 564 && y > 129 && x < 714 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 16;
        *frame = 3;
    }
    // item 17
    if (*category == 4 && x > 724 && y > 129 && x < 874 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 17;
        *frame = 4;
    }
    // item 18
    if (*category == 4 && x > 884 && y > 129 && x < 1034 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 18;
        *frame = 5;
    }
    // item 19
    if (*category == 5 && x > 244 && y > 129 && x < 394 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 19;
        *frame = 1;
    }
    // item 20
    if (*category == 5 && x > 404 && y > 129 && x < 554 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 20;
        *frame = 2;
    }
    // item 21
    if (*category == 5 && x > 564 && y > 129 && x < 714 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 21;
        *frame = 3;
    }
    // item 22
    if (*category == 6 && x > 244 && y > 129 && x < 394 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 22;
        *frame = 1;
    }
    // item 23
    if (*category == 6 && x > 404 && y > 129 && x < 554 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 23;
        *frame = 2;
    }
    // item 24
    if (*category == 6 && x > 564 && y > 129 && x < 714 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 24;
        *frame = 3;
    }
    // item 25
    if (*category == 6 && x > 724 && y > 129 && x < 874 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 25;
        *frame = 4;
    }
    // item 26
    if (*category == 7 && x > 244 && y > 129 && x < 394 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 26;
        *frame = 1;
    }
    // item 27
    if (*category == 7 && x > 404 && y > 129 && x < 554 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 27;
        *frame = 2;
    }
    // item 28
    if (*category == 7 && x > 564 && y > 129 && x < 714 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 28;
        *frame = 3;
    }
    // Buy
    if (*item_index != -1 && x > 1600 && y > 870 && x < 1801 && y < 979 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *money -= (*Price)[*item_index];
        bool sound1 = true;
            if(sound1) {
                Audio * music = createAudio("resource/sounds/buy.wav", 0, SDL_MIX_MAXVOLUME);
                playSoundFromMemory(music, SDL_MIX_MAXVOLUME);
                sound1 = false;
                freeAudio(music);
            }
        (*Amount)[*item_index]++;
        *item_index = -1;
    }
}

void mx_comp_event(SDL_Event* e, int *scene, int *category, int *time_saved,
int *money, int *item_index, int **Price, int **Amount, int *frame, bool *finished, bool *welldone,
bool *wannaEnd, int price_order){
    if (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_ESCAPE) {
        *scene = 0;
        *time_saved = SDL_GetTicks();
        *wannaEnd = 0;
        *item_index = -1;
    }
    if (e->type == SDL_KEYUP && e->key.keysym.sym == SDLK_1) {
        *category = 0;
        *wannaEnd = 0;
        *item_index = -1;
    }
    if (e->type == SDL_KEYUP && e->key.keysym.sym == SDLK_2) {
        *category = 1;
        *wannaEnd = 0;
        *item_index = -1;
    }
    if (e->type == SDL_KEYUP && e->key.keysym.sym == SDLK_3) {
        *category = 2;
        *wannaEnd = 0;
    }
    if (e->type == SDL_KEYUP && e->key.keysym.sym == SDLK_4) {
        *category = 3;
        *wannaEnd = 0;
        *item_index = -1;
    }
    if (e->type == SDL_KEYUP && e->key.keysym.sym == SDLK_5) {
        *category = 4;
        *wannaEnd = 0;
        *item_index = -1;
    }
    if (e->type == SDL_KEYUP && e->key.keysym.sym == SDLK_6) {
        *category = 5;
        *wannaEnd = 0;
        *item_index = -1;
    }
    if (e->type == SDL_KEYUP && e->key.keysym.sym == SDLK_7) {
        *category = 6;
        *wannaEnd = 0;
        *item_index = -1;
    }
    if (e->type == SDL_KEYUP && e->key.keysym.sym == SDLK_8) {
        *wannaEnd = 0;
        *category = 7;
        *item_index = -1;
    }
    if (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_ESCAPE) {
        *scene = 0;
        *time_saved = SDL_GetTicks();
        *item_index = -1;
        *category = 0;
        *wannaEnd = 0;
    }
    // Get mouse position
    int x, y;
    SDL_GetMouseState(&x, &y);
    if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP) {
        // Toroom
        if(x > 1870 && y > 0 && x < 1920 && y < 48 && e->button.button == SDL_BUTTON_LEFT) {
            *scene = 1;
            *item_index = -1;
            *category = 0;
            *wannaEnd = 0;
        }
        // Pause
        if(x > 17 && y > 1053 && x < 37 && y < 1074 && e->button.button == SDL_BUTTON_LEFT) {
            *scene = 0;
            *time_saved = SDL_GetTicks();
            *item_index = -1;
            *category = 0;
            *wannaEnd = 0;
        }
        // Cases
        if(x > 4 && y > 63 && x < 202 && y < 87 && e->button.button == SDL_BUTTON_LEFT) {
            *category = 0;
            *item_index = -1;
            *wannaEnd = 0;
        }
        // CPU
        if(x > 4 && y > 87 && x < 202 && y < 120 && e->button.button == SDL_BUTTON_LEFT) {
            *category = 1;
            *item_index = -1;
            *wannaEnd = 0;
        }
        // Graphics cards
        if(x > 4 && y > 120 && x < 202 && y < 157 && e->button.button == SDL_BUTTON_LEFT) {
            *category = 2;
            *item_index = -1;
            *wannaEnd = 0;
        }
        // HDD/SSD
        if(x > 4 && y > 157 && x < 202 && y < 173 && e->button.button == SDL_BUTTON_LEFT) {
            *category = 3;
            *item_index = -1;
            *wannaEnd = 0;
        }
        // Motherboards
        if(x > 4 && y > 173 && x < 202 && y < 210 && e->button.button == SDL_BUTTON_LEFT) {
            *category = 4;
            *item_index = -1;
            *wannaEnd = 0;
        }
        // Power Supplies
        if(x > 4 && y > 210 && x < 202 && y < 247 && e->button.button == SDL_BUTTON_LEFT) {
            *category = 5;
            *item_index = -1;
            *wannaEnd = 0;
        }
        // RAM
        if(x > 4 && y > 247 && x < 202 && y < 284 && e->button.button == SDL_BUTTON_LEFT) {
            *category = 6;
            *item_index = -1;
            *wannaEnd = 0;
        }
        // Cooler
        if(x > 4 && y > 284 && x < 202 && y < 321 && e->button.button == SDL_BUTTON_LEFT) {
            *category = 7;
            *item_index = -1;
            *wannaEnd = 0;
        }
    }
    // item 0
    if (*category == 0 && x > 244 && y > 129 && x < 394 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 0;
        *frame = 1;
        *wannaEnd = 0;
    }
    // item 1
    if (*category == 0 && x > 404 && y > 129 && x < 554 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 1;
        *frame = 2;
        *wannaEnd = 0;
    }
    // item 2
    if (*category == 0 && x > 564 && y > 129 && x < 714 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 2;
        *frame = 3;
        *wannaEnd = 0;
    }
    // item 3
    if (*category == 0 && x > 724 && y > 129 && x < 874 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 3;
        *frame = 4;
        *wannaEnd = 0;
    }
    // item 4
    if (*category == 1 && x > 244 && y > 129 && x < 394 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 4;
        *frame = 1;
        *wannaEnd = 0;
    }
    // item 5
    if (*category == 1 && x > 404 && y > 129 && x < 554 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 5;
        *frame = 2;
        *wannaEnd = 0;
    }
    // item 6
    if (*category == 1 && x > 564 && y > 129 && x < 714 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 6;
        *frame = 3;
        *wannaEnd = 0;
    }
    // item 7
    if (*category == 2 && x > 244 && y > 129 && x < 394 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 7;
        *frame = 1;
        *wannaEnd = 0;
    }
    // item 8
    if (*category == 2 && x > 404 && y > 129 && x < 554 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 8;
        *frame = 2;
        *wannaEnd = 0;
    }
    // item 9
    if (*category == 2 && x > 564 && y > 129 && x < 714 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 9;
        *frame = 3;
        *wannaEnd = 0;
    }
    // item 10
    if (*category == 2 && x > 724 && y > 129 && x < 874 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 10;
        *frame = 4;
        *wannaEnd = 0;
    }
    // item 11
    if (*category == 3 && x > 244 && y > 129 && x < 394 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 11;
        *frame = 1;
        *wannaEnd = 0;
    }
    // item 12
    if (*category == 3 && x > 404 && y > 129 && x < 554 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 12;
        *frame = 2;
        *wannaEnd = 0;
    }
    // item 13
    if (*category == 3 && x > 564 && y > 129 && x < 714 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 13;
        *frame = 3;
        *wannaEnd = 0;
    }
    // item 14
    if (*category == 4 && x > 244 && y > 129 && x < 394 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 14;
        *frame = 1;
        *wannaEnd = 0;
    }
    // item 15
    if (*category == 4 && x > 404 && y > 129 && x < 554 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 15;
        *frame = 2;
        *wannaEnd = 0;
    }
    // item 16
    if (*category == 4 && x > 564 && y > 129 && x < 714 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 16;
        *frame = 3;
        *wannaEnd = 0;
    }
    // item 17
    if (*category == 4 && x > 724 && y > 129 && x < 874 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 17;
        *frame = 4;
        *wannaEnd = 0;
    }
    // item 18
    if (*category == 4 && x > 884 && y > 129 && x < 1034 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 18;
        *frame = 5;
        *wannaEnd = 0;
    }
    // item 19
    if (*category == 5 && x > 244 && y > 129 && x < 394 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 19;
        *frame = 1;
        *wannaEnd = 0;
    }
    // item 20
    if (*category == 5 && x > 404 && y > 129 && x < 554 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 20;
        *frame = 2;
        *wannaEnd = 0;
    }
    // item 21
    if (*category == 5 && x > 564 && y > 129 && x < 714 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 21;
        *frame = 3;
        *wannaEnd = 0;
    }
    // item 22
    if (*category == 6 && x > 244 && y > 129 && x < 394 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 22;
        *frame = 1;
        *wannaEnd = 0;
    }
    // item 23
    if (*category == 6 && x > 404 && y > 129 && x < 554 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 23;
        *frame = 2;
        *wannaEnd = 0;
    }
    // item 24
    if (*category == 6 && x > 564 && y > 129 && x < 714 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 24;
        *frame = 3;
        *wannaEnd = 0;
    }
    // item 25
    if (*category == 6 && x > 724 && y > 129 && x < 874 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 25;
        *frame = 4;
        *wannaEnd = 0;
    }
    // item 26
    if (*category == 7 && x > 244 && y > 129 && x < 394 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 26;
        *frame = 1;
        *wannaEnd = 0;
    }
    // item 27
    if (*category == 7 && x > 404 && y > 129 && x < 554 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 27;
        *frame = 2;
        *wannaEnd = 0;
    }
    // item 28
    if (*category == 7 && x > 564 && y > 129 && x < 714 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 28;
        *frame = 3;
        *wannaEnd = 0;
    }
    // Sell
    if (*item_index != -1 && x > 1500 && y > 870 && x < 1806 && y < 1176 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        if ((*Amount)[*item_index]) {
            bool sound1 = true;
            if(sound1) {
                Audio * music = createAudio("resource/sounds/buy.wav", 0, SDL_MIX_MAXVOLUME);
                playSoundFromMemory(music, SDL_MIX_MAXVOLUME);
                sound1 = false;
                freeAudio(music);
            }
            *money += (*Price)[*item_index] >> 1;
            (*Amount)[*item_index]--;
        }
        *item_index = -1;
        *wannaEnd = 0;
    }
    // Complete
    if (x > 1506 && y > 765 && x < 1796 && y < 865 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *wannaEnd = 1;
    }
    //No
    if (*wannaEnd && x > 1056 && y > 594 && x < 1131 && y < 614 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *wannaEnd = 0;
    }

    // Yes
    if (*wannaEnd && x > 971 && y > 594 && x < 1046 && y < 614 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        bool cases = (*Amount)[0] || (*Amount)[1] || (*Amount)[2] || (*Amount)[3];
        bool cpu = (*Amount)[4] || (*Amount)[5] || (*Amount)[6];
        bool graphics_cards = (*Amount)[7] || (*Amount)[8] || (*Amount)[9] || (*Amount)[10];
        bool hddSsd = (*Amount)[11] || (*Amount)[12] || (*Amount)[13];
        bool motherboards = (*Amount)[14] || (*Amount)[15] || (*Amount)[16] || (*Amount)[17] || (*Amount)[18];
        bool power = (*Amount)[19] || (*Amount)[20] || (*Amount)[21];
        bool ram = (*Amount)[22] || (*Amount)[23] || (*Amount)[24] || (*Amount)[25];
        bool cooler = (*Amount)[26] || (*Amount)[27] || (*Amount)[28];
        int spent = 0;
        for (int i = 0; i < 29; i++) {
            spent += (*Amount)[i] * (*Price)[i];
        }
        if (cases && cpu && graphics_cards && hddSsd && motherboards && power && ram && cooler && price_order <= spent * 2) {
            *welldone = 1;
            for (int i = 0; i < 29; i++) {
                (*Amount)[i] = 0;
            }
        }
        else {
            *welldone = 0;
        }
        *finished = 1;
        *wannaEnd = 0;
    }
}

void mx_xolodos_event(SDL_Event* e, int *scene, int *time_saved,
int *money, int *item_index, int **Price, int **Amount, float *energy,int *frame){
    if (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_ESCAPE) {
        *scene = 0;
        *item_index = -1;
        *time_saved = SDL_GetTicks();
    }
    // Get mouse position
    int x, y;
    SDL_GetMouseState(&x, &y);
    if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP) {
        // Toroom
        if(x > 1870 && y > 0 && x < 1920 && y < 48 && e->button.button == SDL_BUTTON_LEFT) {
            *scene = 1;
            *item_index = -1;
        }
        // Pause
        if(x > 17 && y > 1053 && x < 37 && y < 1074 && e->button.button == SDL_BUTTON_LEFT) {
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

    // Sell
    if (*item_index != -1 && x > 1500 && y > 870 && x < 1806 && y < 1176 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        if ((*Amount)[*item_index]) {
            bool sound4 = true;
            if(sound4) {
                Audio * music = createAudio("resource/sounds/buy.wav", 0, SDL_MIX_MAXVOLUME);
                playSoundFromMemory(music, SDL_MIX_MAXVOLUME);
                sound4 = false;
                freeAudio(music);
            }
            *money += (*Price)[*item_index] >> 1;
            (*Amount)[*item_index]--;
        }
        *item_index = -1;
    }

    // Use
    if (*item_index != -1 && x > 1506 && y > 765 && x < 1796 && y < 865 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        if ((*Amount)[*item_index]) {
            *energy += (*item_index == 30 ? 100. : 5.);
            (*Amount)[*item_index]--;
        }
        *item_index = -1;
    }
}

void mx_secret_events(SDL_Event* e, int *scene, int *category, int *time_saved,
int *money, int *item_index, int **Price, int *end, int*frame){
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
        // Tomenu
        if(x > 1870 && y > 0 && x < 1920 && y < 48 && e->button.button == SDL_BUTTON_LEFT) {
            *category = 0;
            *item_index = -1;
            *scene = 0;
        }
        // Pause
        if(x > 17 && y > 1053 && x < 37 && y < 1074 && e->button.button == SDL_BUTTON_LEFT) {
            *category = 0;
            *scene = 0;
            *item_index = -1;
            *time_saved = SDL_GetTicks();
        }
    }
    // Item 31
    if (x > 244 && y > 129 && x < 394 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 31;
        *frame = 1;
    }
    // Item 32
    if (x > 404 && y > 129 && x < 554 && y < 279 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *item_index = 32;
        *frame = 2;
    }
    // Buy
    if (*item_index != -1 && x > 1600 && y > 870 && x < 1801 && y < 979 && e->button.button == SDL_BUTTON_LEFT && e->type == SDL_MOUSEBUTTONDOWN) {
        *money -= (*Price)[*item_index];
        bool sound3 = true;
            if(sound3) {
                Audio * music = createAudio("resource/sounds/buy.wav", 0, SDL_MIX_MAXVOLUME);
                playSoundFromMemory(music, SDL_MIX_MAXVOLUME);
                sound3 = false;
                freeAudio(music);
            }
        if(*item_index == 31)
            *end = 1;
        if(*item_index == 32)
            *end = 2;
        *item_index = -1;
    }
}
