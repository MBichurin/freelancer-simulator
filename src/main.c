#include "../inc/header.h"
int main () {
    int scene = 0, sleepi = 0, category = 0, menu_frame = 0, item_index = -1, shops_frame = 0,
    money = 1500, time_begin = SDL_GetTicks(), time_cur = SDL_GetTicks(), time_saved = 0,
    screen_index = 0, end = 0, num_order = 1, time_order = time_cur - time_begin + 4 * 60 * 1000;
    float energy = 100.;
    bool finished = 0, welldone = 0, wannaEnd = 0;
    srand(time(0));
    int price_order = rand() % 1300 + 201;
    if( SDL_Init( SDL_INIT_EVERYTHING ) != 0 )
    {
        return 1;
    }
    int k = 0;

    const int SCREEN_WIDTH = 1920;
    const int SCREEN_HEIGHT = 1080;
    SDL_Window *window = NULL;
    SDL_Renderer *rend;

    SDL_Surface *room = NULL;
    SDL_Surface *menu = NULL;
    SDL_Surface *map = NULL;
    SDL_Surface *toolbar = NULL;
    SDL_Surface *shop = NULL;
    SDL_Surface *atb = NULL;
    SDL_Surface *sleep = NULL;
    SDL_Surface *secret = NULL;
    SDL_Surface *order = NULL;
    SDL_Surface *sure = NULL;
    SDL_Surface *end1 = NULL;
    SDL_Surface *end2 = NULL;
    SDL_Surface *gameover1 = NULL;
    SDL_Surface *gameover2 = NULL;
    SDL_Surface *shop_frame = NULL;
    SDL_Surface *square_frame = NULL;
    SDL_Surface *buy = NULL;
    SDL_Surface *sell = NULL;
    SDL_Surface *use = NULL;
    SDL_Surface *complete = NULL;

    window = SDL_CreateWindow("PC Building Simulator (ATB)",SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    
    if (!window) {
        return 1;
    }
    
    Uint32 render_flags = SDL_RENDERER_ACCELERATED;
    rend = SDL_CreateRenderer(window, -1, render_flags);
    if(!rend){
        return 1;
    }

    gameover1 = SDL_LoadBMP("resource/img/gameover1.bmp");
    gameover2 = SDL_LoadBMP("resource/img/gameover2.bmp");
    end1 = IMG_Load("resource/img/end1.jpg");
    end2 = IMG_Load("resource/img/end2.jpg");
    sleep = IMG_Load("resource/img/sleep.png");
    room = SDL_LoadBMP("resource/img/room.bmp");
    menu = SDL_LoadBMP("resource/img/background_menu_small.bmp");
    map = SDL_LoadBMP("resource/img/map.bmp");
    toolbar = SDL_LoadBMP("resource/img/toolbar.bmp");
    shop = SDL_LoadBMP("resource/img/shop.bmp");
    atb = SDL_LoadBMP("resource/img/atb_shop.bmp");
    secret = SDL_LoadBMP("resource/img/secret_shop.bmp");
    order = SDL_LoadBMP("resource/img/order.bmp");
    sure = SDL_LoadBMP("resource/img/sure.bmp");
    shop_frame = IMG_Load("resource/img/shop_frame.png");
    square_frame = IMG_Load("resource/img/square_frame.png");
    buy = SDL_LoadBMP("resource/img/buy.bmp");
    sell = SDL_LoadBMP("resource/img/sell.bmp");
    use = SDL_LoadBMP("resource/img/use.bmp");
    complete = SDL_LoadBMP("resource/img/complete.bmp");

    SDL_Texture **tex_items = malloc(sizeof(SDL_Texture *) * 33);
    mx_item_texture(&tex_items, &rend);
    SDL_Texture **tex_digits = malloc(sizeof(SDL_Texture *) * 13);
    mx_load_digits(&tex_digits, &rend);
    SDL_Texture **tex_batteries = malloc(sizeof(SDL_Texture *) * 5);
    mx_load_batteries(&tex_batteries, &rend);
    SDL_Texture **tex_instruction = malloc(sizeof(SDL_Texture *) * 2);
    mx_load_instruction(&tex_instruction, &rend); 
    SDL_Texture* texgameover1 = SDL_CreateTextureFromSurface(rend, gameover1);
    SDL_Texture* texgameover2 = SDL_CreateTextureFromSurface(rend, gameover2);
    SDL_Texture* texend1 = SDL_CreateTextureFromSurface(rend, end1);
    SDL_Texture* texend2 = SDL_CreateTextureFromSurface(rend, end2);
    SDL_Texture* texsleep = SDL_CreateTextureFromSurface(rend, sleep);
    SDL_Texture* texroom = SDL_CreateTextureFromSurface(rend, room);
    SDL_Texture* texmenu = SDL_CreateTextureFromSurface(rend, menu);
    SDL_Texture* texmap = SDL_CreateTextureFromSurface(rend, map);
    SDL_Texture* textool = SDL_CreateTextureFromSurface(rend, toolbar);
    SDL_Texture* texshop = SDL_CreateTextureFromSurface(rend, shop);
    SDL_Texture* texatb = SDL_CreateTextureFromSurface(rend, atb);
    SDL_Texture* texsecret = SDL_CreateTextureFromSurface(rend, secret);
    SDL_Texture* texorder = SDL_CreateTextureFromSurface(rend, order);
    SDL_Texture* texsure = SDL_CreateTextureFromSurface(rend, sure);
    SDL_Texture* tex_shop_frame = SDL_CreateTextureFromSurface(rend, shop_frame);
    SDL_Texture* tex_square_frame = SDL_CreateTextureFromSurface(rend, square_frame);
    SDL_Texture* texbuy = SDL_CreateTextureFromSurface(rend, buy);
    SDL_Texture* texsell = SDL_CreateTextureFromSurface(rend, sell);
    SDL_Texture* texuse = SDL_CreateTextureFromSurface(rend, use);
    SDL_Texture* texcomplete = SDL_CreateTextureFromSurface(rend, complete);

    SDL_FreeSurface(room);
    SDL_FreeSurface(menu);
    SDL_FreeSurface(map);
    SDL_FreeSurface(toolbar);
    SDL_FreeSurface(shop);
    SDL_FreeSurface(atb);
    SDL_FreeSurface(sleep);
    SDL_FreeSurface(secret);
    SDL_FreeSurface(order);
    SDL_FreeSurface(sure);
    SDL_FreeSurface(end1);
    SDL_FreeSurface(end2);
    SDL_FreeSurface(gameover1);
    SDL_FreeSurface(gameover2);
    SDL_FreeSurface(shop_frame);
    SDL_FreeSurface(square_frame);
    SDL_FreeSurface(buy);
    SDL_FreeSurface(sell);
    SDL_FreeSurface(use);
    SDL_FreeSurface(complete);

    SDL_Rect tool;
    tool.h = 35;
    tool.w = 370;
    tool.x = 0;
    tool.y = 1045;

    SDL_Rect item_rect;
    item_rect.h = 150;
    item_rect.w = 150;
    item_rect.y = 129;

    SDL_Rect square_frame_rect;
    
    SDL_RenderClear(rend);

    SDL_Rect sure_rect;
    sure_rect.x = 880;
    sure_rect.y = 450;
    sure_rect.h = 206;
    sure_rect.w = 295;

    SDL_Rect sell_rect;
    sell_rect.x = 1500;
    sell_rect.y = 870;
    sell_rect.h = 117;
    sell_rect.w = 306;

    SDL_Rect order_rect;
    order_rect.x = 350;
    order_rect.y = 770;
    order_rect.h = 274;
    order_rect.w = 700;

    SDL_Rect buy_rect;
    buy_rect.x = 1600;
    buy_rect.y = 870;
    buy_rect.h = 109;
    buy_rect.w = 201;

    SDL_Rect use_rect;
    use_rect.x = 1506;
    use_rect.y = 765;
    use_rect.h = 100;
    use_rect.w = 290;

    int l, r;
    SDL_Rect shop_frame_rect;
    shop_frame_rect.x = 6;
    shop_frame_rect.h = 30;
    shop_frame_rect.w = 205;

    // Prices
    int *Price = malloc(33 * 4);
    mx_set_prices(&Price);

    // Amount
    int *Amount = malloc(31 * 4);
    for (int i = 0; i < 31; i++) {
        Amount[i] = 0;
    }

    initAudio();

    bool quit = false;
    SDL_Event e;
    while (!quit) {
        if(!quit) {
            Audio * music = createAudio("resource/sounds/2.wav", 1, SDL_MIX_MAXVOLUME);
            playMusicFromMemory(music, SDL_MIX_MAXVOLUME / 5);
            freeAudio(music);
        }
        while (SDL_PollEvent(&e) || 1) {
            if (e.type == SDL_QUIT || scene == -1) {
                quit = true;
                break;
            }

            switch(scene) {
            // Menu
            case 0:
                screen_index = 0;
                square_frame_rect.h = 156;
                square_frame_rect.w = 156;
                switch (menu_frame) {
                case 1:
                    square_frame_rect.x = 67;
                    square_frame_rect.y = 52;
                break;
                case 2:
                    square_frame_rect.x = 69;
                    square_frame_rect.y = 205;
                break;
                case 3:
                    square_frame_rect.x = 1685;
                    square_frame_rect.y = 840;
                break;
                }
                SDL_RenderCopy(rend, texmenu, NULL, NULL);
                if (menu_frame) {
                    SDL_RenderCopy(rend, tex_square_frame, NULL, &square_frame_rect);
                }
                time_cur = SDL_GetTicks() % (24 * 60000);
                time_begin += time_cur - time_saved;
                time_saved = time_cur;
                SDL_RenderPresent(rend);
                mx_menu_events(&e, &scene, &menu_frame);
            break;
            // Room
            case 1:
                SDL_RenderCopy(rend, texroom, NULL, NULL);
                SDL_RenderCopy(rend, textool, NULL, &tool);
                mx_drawmoney(money, &rend, tex_digits, 1);
                time_cur = SDL_GetTicks() % (24 * 60000);
                mx_drawtime((time_cur - time_begin) / 1000, &rend, tex_digits, 1);
                mx_draw_battery(energy, tex_batteries, tex_digits, &rend);
                SDL_RenderPresent(rend);
                mx_room_events(&e, &scene, &sleepi, &time_saved, time_begin, &energy);
                if (energy > 100.) {
                    energy = 100.;
                }
            break;
            if(sleepi == 1) {
                break;
            }
            //Instruction
            case 100:
                switch(screen_index){
                    case 0:
                        SDL_RenderCopy(rend, tex_instruction[screen_index], NULL, NULL);
                    break;
                    case 1:
                        SDL_RenderCopy(rend, tex_instruction[screen_index], NULL, NULL);
                    break;
                }
                SDL_RenderPresent(rend);
                mx_instruction_event(&e, &scene, &screen_index);
            break;
            // Map
            case 10:
                SDL_RenderCopy(rend, texmap, NULL, NULL);
                SDL_RenderCopy(rend, textool, NULL, &tool);
                mx_drawmoney(money, &rend, tex_digits, 1);
                time_cur = SDL_GetTicks() % (24 * 60000);
                mx_drawtime((time_cur - time_begin) / 1000, &rend, tex_digits, 1);
                mx_draw_battery(energy, tex_batteries, tex_digits, &rend);
                SDL_RenderPresent(rend);
                mx_map_events(&e, &scene, &time_saved);
            break;
            // Shop
            case 2:
                SDL_RenderCopy(rend,texshop, NULL, NULL);                
                shop_frame_rect.y = 63 + 30 * category;
                switch (category) {
                case 0:
                    l = 0, r = 4;
                break;
                case 1:
                    l = 4, r = 7;
                break;
                case 2:
                    l = 7, r = 11;
                break;
                case 3:
                    l = 11, r = 14;
                break;
                case 4:
                    l = 14, r = 19;
                break;
                case 5:
                    l = 19, r = 22;
                break;
                case 6:
                    l = 22, r = 26;
                break;
                case 7:
                    l = 26, r = 29;
                break;
                }
                for (int i = l; i < r; i++) {
                    item_rect.x = 244 + (i - l) * 160;
                    SDL_RenderCopy(rend, tex_items[i], NULL, &item_rect);
                }

                switch (shops_frame) {
                case 1:
                    square_frame_rect.x = 240;
                    square_frame_rect.y = 125;
                break;
                case 2:
                    square_frame_rect.x = 400;
                    square_frame_rect.y = 125;
                break;
                case 3:
                    square_frame_rect.x = 560;
                    square_frame_rect.y = 125;
                break;
                case 4:
                    square_frame_rect.x = 720;
                    square_frame_rect.y = 125;
                break;
                case 5:
                    square_frame_rect.x = 880;
                    square_frame_rect.y = 125;
                break;
                }
                if (shops_frame && item_index > -1) {
                    SDL_RenderCopy(rend, tex_square_frame, NULL, &square_frame_rect);
                }

                SDL_RenderCopy(rend, tex_shop_frame, NULL, &shop_frame_rect);
                SDL_RenderCopy(rend, textool, NULL, &tool);
                mx_drawmoney(money, &rend, tex_digits, 1);
                time_cur = SDL_GetTicks() % (24 * 60000);
                mx_drawtime((time_cur - time_begin) / 1000, &rend, tex_digits, 1);
                mx_draw_battery(energy, tex_batteries, tex_digits, &rend);
                SDL_RenderCopy(rend, texbuy, NULL, &buy_rect);
                SDL_RenderPresent(rend);
                mx_shop_events(&e, &scene, &category, &time_saved, &money, &item_index, &Price, &Amount, &shops_frame);
            break;
            // ATB
            case 322:
                SDL_RenderCopy(rend,texatb, NULL, NULL);

                for (int i = 0; i < 2; i++) {
                    item_rect.x = 244 + i * 160;
                    SDL_RenderCopy(rend, tex_items[29 + i], NULL, &item_rect);
                }
                
                    switch (shops_frame) {
                    case 1:
                    square_frame_rect.x = 240;
                    square_frame_rect.y = 125;
                    break;
                    case 2:
                    square_frame_rect.x = 400;
                    square_frame_rect.y = 125;
                    break;
                    }
                    if (shops_frame && item_index > -1) {
                    SDL_RenderCopy(rend, tex_square_frame, NULL, &square_frame_rect);
                    }
                SDL_RenderCopy(rend, textool, NULL, &tool);
                mx_drawmoney(money, &rend, tex_digits, 1);
                time_cur = SDL_GetTicks() % (24 * 60000);
                mx_drawtime((time_cur - time_begin) / 1000, &rend, tex_digits, 1);
                SDL_RenderCopy(rend, texbuy, NULL, &buy_rect);
                mx_draw_battery(energy, tex_batteries, tex_digits, &rend);
                SDL_RenderPresent(rend);
                mx_atb_events(&e, &scene, &category, &time_saved, &money, &item_index, &Price, &Amount,&shops_frame);
            break;
            // PC
            case 60:
                SDL_RenderCopy(rend, texshop, NULL, NULL);
                shop_frame_rect.y = 63 + 30 * category;
                switch (category) {
                case 0:
                    l = 0, r = 4;
                break;
                case 1:
                    l = 4, r = 7;
                break;
                case 2:
                    l = 7, r = 11;
                break;
                case 3:
                    l = 11, r = 14;
                break;
                case 4:
                    l = 14, r = 19;
                break;
                case 5:
                    l = 19, r = 22;
                break;
                case 6:
                    l = 22, r = 26;
                break;
                case 7:
                    l = 26, r = 29;
                break;
                }
                for (int i = l; i < r; i++) {
                    item_rect.x = 244 + (i - l) * 160;
                    SDL_RenderCopy(rend, tex_items[i], NULL, &item_rect);
                    mx_drawamount(Amount[i], &rend, tex_digits, 244 + (i - l) * 160 + 135, 129 + 150);
                }

                switch (shops_frame) {
                case 1:
                    square_frame_rect.x = 240;
                    square_frame_rect.y = 125;
                break;
                case 2:
                    square_frame_rect.x = 400;
                    square_frame_rect.y = 125;
                break;
                case 3:
                    square_frame_rect.x = 560;
                    square_frame_rect.y = 125;
                break;
                case 4:
                    square_frame_rect.x = 720;
                    square_frame_rect.y = 125;
                break;
                case 5:
                    square_frame_rect.x = 880;
                    square_frame_rect.y = 125;
                break;
                }
                if (shops_frame && item_index > -1) {
                    SDL_RenderCopy(rend, tex_square_frame, NULL, &square_frame_rect);
                }

                SDL_RenderCopy(rend, tex_shop_frame, NULL, &shop_frame_rect);
                SDL_RenderCopy(rend, textool, NULL, &tool);
                mx_drawmoney(money, &rend, tex_digits, 1);
                time_cur = SDL_GetTicks() % (24 * 60000);
                mx_drawtime((time_cur - time_begin) / 1000, &rend, tex_digits, 1);
                SDL_RenderCopy(rend, texsell, NULL, &sell_rect);
                SDL_RenderCopy(rend, texcomplete, NULL, &use_rect);
                mx_draw_battery(energy, tex_batteries, tex_digits, &rend);
                SDL_RenderCopy(rend, texorder, NULL, &order_rect);
                mx_drawtime(time_order / 1000, &rend, tex_digits, 0);
                mx_drawmoney(price_order, &rend, tex_digits, 0);
                mx_drawordernum(num_order, &rend, tex_digits);
                if (wannaEnd) {
                    SDL_RenderCopy(rend, texsure, NULL, &sure_rect);
                }
                SDL_RenderPresent(rend);
                mx_comp_event(&e, &scene, &category, &time_saved, &money, &item_index, &Price, &Amount,
                &shops_frame, &finished, &welldone, &wannaEnd, price_order);
            break;
            // Xolodos
            case 228:
                SDL_RenderCopy(rend, texatb, NULL, NULL);

                for (int i = 0; i < 2; i++) {
                    item_rect.x = 244 + i * 160;
                    SDL_RenderCopy(rend, tex_items[29 + i], NULL, &item_rect);
                    mx_drawamount(Amount[29 + i], &rend, tex_digits, 244 + i * 160 + 135, 129 + 150);
                }
                
                    switch (shops_frame) {
                    case 1:
                    square_frame_rect.x = 240;
                    square_frame_rect.y = 125;
                    break;
                    case 2:
                    square_frame_rect.x = 400;
                    square_frame_rect.y = 125;
                    break;
                    }
                    if (shops_frame && item_index > -1) {
                    SDL_RenderCopy(rend, tex_square_frame, NULL, &square_frame_rect);
                    }
                SDL_RenderCopy(rend, textool, NULL, &tool);
                mx_drawmoney(money, &rend, tex_digits, 1);
                time_cur = SDL_GetTicks() % (24 * 60000);
                mx_drawtime((time_cur - time_begin) / 1000, &rend, tex_digits, 1);

                SDL_RenderCopy(rend, texsell, NULL, &sell_rect);
                SDL_RenderCopy(rend, texuse, NULL, &use_rect);
                mx_draw_battery(energy, tex_batteries, tex_digits, &rend);
                SDL_RenderPresent(rend);
                mx_xolodos_event(&e, &scene, &time_saved, &money, &item_index, &Price, &Amount, &energy, &shops_frame);
                if (energy > 100.) {
                    energy = 100.;
                }
            break;
            //Secret
            case 666:
                if(end == 1){
                    SDL_RenderCopy(rend, texend1, NULL, NULL);
                    SDL_RenderPresent(rend);
                    SDL_Delay(10000);
                    scene = -1;
                }
                else if(end == 2){
                    for(int i = 0; i < 15000; i++){
                        SDL_RenderCopy(rend, texend2, NULL, NULL);
                        SDL_RenderPresent(rend);
                        SDL_RenderClear(rend);
                        SDL_RenderPresent(rend);
                    }
                    scene = -1;
                }
                else{
                    SDL_RenderCopy(rend, texsecret, NULL,NULL);
                        for (int i = 0; i < 2; i++) {
                            item_rect.x = 244 + i * 160;
                            SDL_RenderCopy(rend, tex_items[31 + i], NULL, &item_rect);
                        }
                    SDL_RenderCopy(rend, textool, NULL, &tool);
                    mx_drawmoney(money, &rend, tex_digits, 1);
                    time_cur = SDL_GetTicks() % (24 * 60000);
                    mx_drawtime((time_cur - time_begin) / 1000, &rend, tex_digits, 1);
                    SDL_RenderCopy(rend, texbuy, NULL, &buy_rect);
                    mx_draw_battery(energy, tex_batteries, tex_digits, &rend);
                    switch (shops_frame) {
                    case 1:
                    square_frame_rect.x = 240;
                    square_frame_rect.y = 125;
                    break;
                    case 2:
                    square_frame_rect.x = 400;
                    square_frame_rect.y = 125;
                    break;
                    }
                    if (shops_frame && item_index > -1) {
                    SDL_RenderCopy(rend, tex_square_frame, NULL, &square_frame_rect);
                    }
                    SDL_RenderPresent(rend);
                
                    mx_secret_events(&e, &scene, &category, &time_saved, &money, &item_index, &Price, &end, &shops_frame);
                }
            break;
            }
            if (sleepi) {
                welldone = 0;
                finished = 0;
                SDL_RenderCopy(rend, texsleep, NULL, NULL);
                SDL_RenderPresent(rend);
                SDL_Delay(500);
                bool sound4 = true;
                if(sound4) {
                    Audio * music = createAudio("resource/sounds/snoop.wav", 1, SDL_MIX_MAXVOLUME);
                    playSoundFromMemory(music, SDL_MIX_MAXVOLUME);
                    sound4 = false;
                    freeAudio(music);
                }
                SDL_Delay(2500);
                time_begin -= 6 * 60000 - 3000;
                mx_drawtime((time_cur - time_begin) / 1000, &rend, tex_digits, 1);
                SDL_RenderPresent(rend);
                sleepi = 0;
            }

            if (time_order < time_cur - time_begin || finished) {
                if (welldone) {
                    money += price_order;
                }
                else {
                    money -= price_order / 3;
                }
                num_order++;
                time_order = time_cur - time_begin + 4 * 60 * 1000;
                price_order = rand() % 1300 + 201;
                finished = 0;
            }
            if (money < 1) {
                SDL_RenderCopy(rend, texgameover1, NULL, NULL);
                SDL_RenderPresent(rend);
                SDL_Delay(7000);
                scene = -1;
            }
            if (energy < 0) {
                SDL_RenderCopy(rend, texgameover2, NULL, NULL);
                SDL_RenderPresent(rend);
                SDL_Delay(7000);
                scene = -1;
            }
            energy -= 0.00148;
            SDL_Delay(1000/60);
        }
    }
    SDL_DestroyTexture(texgameover1);
    SDL_DestroyTexture(texgameover2);
    SDL_DestroyTexture(texend1);
    SDL_DestroyTexture(texend2);
    SDL_DestroyTexture(texsleep);
    SDL_DestroyTexture(texroom);
    SDL_DestroyTexture(texmenu);
    SDL_DestroyTexture(texmap);
    SDL_DestroyTexture(textool);
    SDL_DestroyTexture(texshop);
    SDL_DestroyTexture(texatb);
    SDL_DestroyTexture(texsecret);
    SDL_DestroyTexture(texorder);
    SDL_DestroyTexture(texsure);
    SDL_DestroyTexture(tex_shop_frame);
    SDL_DestroyTexture(tex_square_frame);
    SDL_DestroyTexture(texbuy);
    SDL_DestroyTexture(texsell);
    SDL_DestroyTexture(texuse);
    SDL_DestroyTexture(texcomplete);
    for (int i = 0; i < 33; i++) {
        SDL_DestroyTexture(tex_items[i]);
    }
    for (int i = 0; i < 13; i++) {
        SDL_DestroyTexture(tex_digits[i]);
    }
    for (int i = 0; i < 5; i++) {
        SDL_DestroyTexture(tex_batteries[i]);
    }
    for (int i = 0; i < 2; i++) {
        SDL_DestroyTexture(tex_items[i]);
    }
    free(tex_items);
    free(tex_digits);
    free(tex_batteries);
    free(tex_instruction);
    free(Price);
    free(Amount);
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
