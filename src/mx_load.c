#include "../inc/header.h"

void mx_load_digits(SDL_Texture ***digits, SDL_Renderer **rend) {
    SDL_Surface *nextDigit = NULL;
    nextDigit = IMG_Load("resource/img/digits/0.png");
    (*digits)[0] = SDL_CreateTextureFromSurface(*rend, nextDigit);
    SDL_FreeSurface(nextDigit);
    nextDigit = IMG_Load("resource/img/digits/1.png");
    (*digits)[1] = SDL_CreateTextureFromSurface(*rend, nextDigit);
    SDL_FreeSurface(nextDigit);
    nextDigit = IMG_Load("resource/img/digits/2.png");
    (*digits)[2] = SDL_CreateTextureFromSurface(*rend, nextDigit);
    SDL_FreeSurface(nextDigit);
    nextDigit = IMG_Load("resource/img/digits/3.png");
    (*digits)[3] = SDL_CreateTextureFromSurface(*rend, nextDigit);
    SDL_FreeSurface(nextDigit);
    nextDigit = IMG_Load("resource/img/digits/4.png");
    (*digits)[4] = SDL_CreateTextureFromSurface(*rend, nextDigit);
    SDL_FreeSurface(nextDigit);
    nextDigit = IMG_Load("resource/img/digits/5.png");
    (*digits)[5] = SDL_CreateTextureFromSurface(*rend, nextDigit);
    SDL_FreeSurface(nextDigit);
    nextDigit = IMG_Load("resource/img/digits/6.png");
    (*digits)[6] = SDL_CreateTextureFromSurface(*rend, nextDigit);
    SDL_FreeSurface(nextDigit);
    nextDigit = IMG_Load("resource/img/digits/7.png");
    (*digits)[7] = SDL_CreateTextureFromSurface(*rend, nextDigit);
    SDL_FreeSurface(nextDigit);
    nextDigit = IMG_Load("resource/img/digits/8.png");
    (*digits)[8] = SDL_CreateTextureFromSurface(*rend, nextDigit);
    SDL_FreeSurface(nextDigit);
    nextDigit = IMG_Load("resource/img/digits/9.png");
    (*digits)[9] = SDL_CreateTextureFromSurface(*rend, nextDigit);
    SDL_FreeSurface(nextDigit);
    nextDigit = IMG_Load("resource/img/digits/$.png");
    (*digits)[10] = SDL_CreateTextureFromSurface(*rend, nextDigit);
    SDL_FreeSurface(nextDigit);
    nextDigit = IMG_Load("resource/img/digits/d.png");
    (*digits)[11] = SDL_CreateTextureFromSurface(*rend, nextDigit);
    SDL_FreeSurface(nextDigit);
    nextDigit = IMG_Load("resource/img/digits/x.png");
    (*digits)[12] = SDL_CreateTextureFromSurface(*rend, nextDigit);
    SDL_FreeSurface(nextDigit);
}

void mx_item_texture(SDL_Texture ***s, SDL_Renderer **rend) {
    SDL_Surface *item = NULL;
    item = SDL_LoadBMP("resource/img/GameSprites/Cases/1.bmp");
    (*s)[0] = SDL_CreateTextureFromSurface(*rend, item);
    SDL_FreeSurface(item);
    item = SDL_LoadBMP("resource/img/GameSprites/Cases/2.bmp");
    (*s)[1] = SDL_CreateTextureFromSurface(*rend, item);
    SDL_FreeSurface(item);
    item = SDL_LoadBMP("resource/img/GameSprites/Cases/3.bmp");
    (*s)[2] = SDL_CreateTextureFromSurface(*rend, item);
    SDL_FreeSurface(item);
    item = SDL_LoadBMP("resource/img/GameSprites/Cases/4.bmp");
    (*s)[3] = SDL_CreateTextureFromSurface(*rend, item);
    SDL_FreeSurface(item);
    item = SDL_LoadBMP("resource/img/GameSprites/CPU/1.bmp");
    (*s)[4] = SDL_CreateTextureFromSurface(*rend, item);
    SDL_FreeSurface(item);
    item = SDL_LoadBMP("resource/img/GameSprites/CPU/2.bmp");
    (*s)[5] = SDL_CreateTextureFromSurface(*rend, item);
    SDL_FreeSurface(item);
    item = SDL_LoadBMP("resource/img/GameSprites/CPU/3.bmp");
    (*s)[6] = SDL_CreateTextureFromSurface(*rend, item);
    SDL_FreeSurface(item);
    item = SDL_LoadBMP("resource/img/GameSprites/Graphics cards/1.bmp");
    (*s)[7] = SDL_CreateTextureFromSurface(*rend, item);
    SDL_FreeSurface(item);
    item = SDL_LoadBMP("resource/img/GameSprites/Graphics cards/2.bmp");
    (*s)[8] = SDL_CreateTextureFromSurface(*rend, item);
    SDL_FreeSurface(item);
    item = SDL_LoadBMP("resource/img/GameSprites/Graphics cards/3.bmp");
    (*s)[9] = SDL_CreateTextureFromSurface(*rend, item);
    SDL_FreeSurface(item);
    item = SDL_LoadBMP("resource/img/GameSprites/Graphics cards/4.bmp");
    (*s)[10] = SDL_CreateTextureFromSurface(*rend, item);
    SDL_FreeSurface(item);
    item = SDL_LoadBMP("resource/img/GameSprites/HDD or SSD/1.bmp");
    (*s)[11] = SDL_CreateTextureFromSurface(*rend, item);
    SDL_FreeSurface(item);
    item = SDL_LoadBMP("resource/img/GameSprites/HDD or SSD/2.bmp");
    (*s)[12] = SDL_CreateTextureFromSurface(*rend, item);
    SDL_FreeSurface(item);
    item = SDL_LoadBMP("resource/img/GameSprites/HDD or SSD/3.bmp");
    (*s)[13] = SDL_CreateTextureFromSurface(*rend, item);
    SDL_FreeSurface(item);
    item = SDL_LoadBMP("resource/img/GameSprites/Motherboards/1.bmp");
    (*s)[14] = SDL_CreateTextureFromSurface(*rend, item);
    SDL_FreeSurface(item);
    item = SDL_LoadBMP("resource/img/GameSprites/Motherboards/2.bmp");
    (*s)[15] = SDL_CreateTextureFromSurface(*rend, item);
    SDL_FreeSurface(item);
    item = SDL_LoadBMP("resource/img/GameSprites/Motherboards/3.bmp");
    (*s)[16] = SDL_CreateTextureFromSurface(*rend, item);
    SDL_FreeSurface(item);
    item = SDL_LoadBMP("resource/img/GameSprites/Motherboards/4.bmp");
    (*s)[17] = SDL_CreateTextureFromSurface(*rend, item);
    SDL_FreeSurface(item);
    item = SDL_LoadBMP("resource/img/GameSprites/Motherboards/5.bmp");
    (*s)[18] = SDL_CreateTextureFromSurface(*rend, item);
    SDL_FreeSurface(item);
    item = SDL_LoadBMP("resource/img/GameSprites/Power Supplies/1.bmp");
    (*s)[19] = SDL_CreateTextureFromSurface(*rend, item);
    SDL_FreeSurface(item);
    item = SDL_LoadBMP("resource/img/GameSprites/Power Supplies/2.bmp");
    (*s)[20] = SDL_CreateTextureFromSurface(*rend, item);
    SDL_FreeSurface(item);
    item = SDL_LoadBMP("resource/img/GameSprites/Power Supplies/3.bmp");
    (*s)[21] = SDL_CreateTextureFromSurface(*rend, item);
    SDL_FreeSurface(item);
    item = SDL_LoadBMP("resource/img/GameSprites/RAM/1.bmp");
    (*s)[22] = SDL_CreateTextureFromSurface(*rend, item);
    SDL_FreeSurface(item);
    item = SDL_LoadBMP("resource/img/GameSprites/RAM/2.bmp");
    (*s)[23] = SDL_CreateTextureFromSurface(*rend, item);
    SDL_FreeSurface(item);
    item = SDL_LoadBMP("resource/img/GameSprites/RAM/3.bmp");
    (*s)[24] = SDL_CreateTextureFromSurface(*rend, item);
    SDL_FreeSurface(item);
    item = SDL_LoadBMP("resource/img/GameSprites/RAM/4.bmp");
    (*s)[25] = SDL_CreateTextureFromSurface(*rend, item);
    SDL_FreeSurface(item);
    item = SDL_LoadBMP("resource/img/GameSprites/Cooler/1.bmp");
    (*s)[26] = SDL_CreateTextureFromSurface(*rend, item);
    SDL_FreeSurface(item);
    item = SDL_LoadBMP("resource/img/GameSprites/Cooler/2.bmp");
    (*s)[27] = SDL_CreateTextureFromSurface(*rend, item);
    SDL_FreeSurface(item);
    item = SDL_LoadBMP("resource/img/GameSprites/Cooler/3.bmp");
    (*s)[28] = SDL_CreateTextureFromSurface(*rend, item);
    SDL_FreeSurface(item);
    item = SDL_LoadBMP("resource/img/ATB/coffee.bmp");
    (*s)[29] = SDL_CreateTextureFromSurface(*rend, item);
    SDL_FreeSurface(item);
    item = SDL_LoadBMP("resource/img/ATB/nrj.bmp");
    (*s)[30] = SDL_CreateTextureFromSurface(*rend, item);
    SDL_FreeSurface(item);
    item = SDL_LoadBMP("resource/img/ATB/atb1.bmp");
    (*s)[31] = SDL_CreateTextureFromSurface(*rend, item);
    SDL_FreeSurface(item);
    item = SDL_LoadBMP("resource/img/ATB/atb2.bmp");
    (*s)[32] = SDL_CreateTextureFromSurface(*rend, item);
    SDL_FreeSurface(item);
}

void mx_load_batteries(SDL_Texture ***tex_battery, SDL_Renderer **rend) {
    SDL_Surface *battery = NULL;
    battery = IMG_Load("resource/img/battery/battery0.png");
    (*tex_battery)[0] = SDL_CreateTextureFromSurface(*rend, battery);
    SDL_FreeSurface(battery);
    battery = IMG_Load("resource/img/battery/battery1.png");
    (*tex_battery)[1] = SDL_CreateTextureFromSurface(*rend, battery);
    SDL_FreeSurface(battery);
    battery = IMG_Load("resource/img/battery/battery2.png");
    (*tex_battery)[2] = SDL_CreateTextureFromSurface(*rend, battery);
    SDL_FreeSurface(battery);
    battery = IMG_Load("resource/img/battery/battery3.png");
    (*tex_battery)[3] = SDL_CreateTextureFromSurface(*rend, battery);
    SDL_FreeSurface(battery);
    battery = IMG_Load("resource/img/battery/battery4.png");
    (*tex_battery)[4] = SDL_CreateTextureFromSurface(*rend, battery);
    SDL_FreeSurface(battery);
}

void mx_load_instruction(SDL_Texture ***screen, SDL_Renderer **rend){
    SDL_Surface* this = NULL;
    this = IMG_Load("resource/img/Instructions/0.png");
    (*screen)[0] = SDL_CreateTextureFromSurface(*rend, this);
    SDL_FreeSurface(this);
    this = IMG_Load("resource/img/Instructions/1.png");
    (*screen)[1] = SDL_CreateTextureFromSurface(*rend, this);
    SDL_FreeSurface(this);
}