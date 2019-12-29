#include "../inc/header.h"

void mx_drawmoney(int n, SDL_Renderer **rend, SDL_Texture** t_digits, bool mode) {
    SDL_Rect r_digit;
    r_digit.h = 25;
    r_digit.w = 15;
    if (mode) {
        r_digit.x = 353;
        r_digit.y = 1048;
    }
    else {
        r_digit.x = 695;
        r_digit.y = 880;
    }
    int i = 1;
    SDL_RenderCopy(*rend, t_digits[10], NULL, &r_digit);
    while (n / i != 0 || i == 1) {
        int index = n / i % 10;
        r_digit.x -= 15;
        SDL_RenderCopy(*rend, t_digits[index], NULL, &r_digit);
        i *= 10;
    }
}

void mx_drawamount(int n, SDL_Renderer **rend, SDL_Texture** t_digits, int x, int y) {
    SDL_Rect r_digit;
    r_digit.h = 25;
    r_digit.w = 15;
    r_digit.x = x;
    r_digit.y = y;
    int i = 1;
    while (n / i != 0 || i == 1) {
        int index = n / i % 10;
        SDL_RenderCopy(*rend, t_digits[index], NULL, &r_digit);
        r_digit.x -= 15;
        i *= 10;
    }
    SDL_RenderCopy(*rend, t_digits[12], NULL, &r_digit);
}

void mx_drawordernum(int n, SDL_Renderer **rend, SDL_Texture** t_digits) {
    SDL_Rect r_digit;
    r_digit.h = 25;
    r_digit.w = 15;
    r_digit.x = 975;
    r_digit.y = 827;
    int i = 1;
    while (n / i != 0 || i == 1) {
        int index = n / i % 10;
        SDL_RenderCopy(*rend, t_digits[index], NULL, &r_digit);
        r_digit.x -= 15;
        i *= 10;
    }
}

void mx_drawtime(int n, SDL_Renderer **rend, SDL_Texture** t_digits, bool mode) {
    SDL_Rect r_time;
    r_time.h = 25;
    r_time.w = 15;
    r_time.x = 60;
    r_time.y = 1048;
    if (mode) {
        r_time.x = 60;
        r_time.y = 1048;
    }
    else {
        r_time.x = 595;
        r_time.y = 955;
    }
    n %= 24 * 60;
    SDL_RenderCopy(*rend,t_digits[n / 600],NULL, &r_time);
    r_time.x += 15;
    SDL_RenderCopy(*rend,t_digits[(n / 60) % 10],NULL, &r_time);
    r_time.x += 15;
    SDL_RenderCopy(*rend,t_digits[11],NULL, &r_time);
    r_time.x += 15;
    SDL_RenderCopy(*rend,t_digits[(n % 60) / 10],NULL, &r_time);
    r_time.x += 15;
    SDL_RenderCopy(*rend, t_digits[n % 60 % 10], NULL, &r_time);
}

void mx_draw_battery(float energy, SDL_Texture **tex_batteries, SDL_Texture** t_digits, SDL_Renderer **rend) {
    SDL_Rect r_bat;
    r_bat.h = 25;
    r_bat.w = 25;
    r_bat.x = 170;
    r_bat.y = 1048;
    SDL_RenderCopy(*rend, tex_batteries[(int) ceil(energy / 25)], NULL, &r_bat);

    int energy_i = ceil(energy);
    r_bat.h = 12;
    r_bat.w = 7;
    r_bat.x = 162;
    r_bat.y = 1060;
    int i = 1;
    while (energy_i / i != 0 || i == 1) {
        int index = energy_i / i % 10;
        SDL_RenderCopy(*rend, t_digits[index], NULL, &r_bat);
        r_bat.x -= 7;
        i *= 10;
    }
}

void mx_set_prices(int **Price) {
    (*Price)[0] = 10;
    (*Price)[1] = 20;
    (*Price)[2] = 50;
    (*Price)[3] = 100;
    (*Price)[4] = 8;
    (*Price)[5] = 8;
    (*Price)[6] = 10;
    (*Price)[7] = 30;
    (*Price)[8] = 50;
    (*Price)[9] = 100;
    (*Price)[10] = 150;
    (*Price)[11] = 20;
    (*Price)[12] = 150;
    (*Price)[13] = 700;
    (*Price)[14] = 30;
    (*Price)[15] = 50;
    (*Price)[16] = 70;
    (*Price)[17] = 80;
    (*Price)[18] = 100;
    (*Price)[19] = 20;
    (*Price)[20] = 30;
    (*Price)[21] = 45;
    (*Price)[22] = 15;
    (*Price)[23] = 25;
    (*Price)[24] = 40;
    (*Price)[25] = 60;
    (*Price)[26] = 5;
    (*Price)[27] = 7;
    (*Price)[28] = 10;
    (*Price)[29] = 10;
    (*Price)[30] = 100;
    (*Price)[31] = 20000;
    (*Price)[32] = 500000;
    // {10, 20, 50, 100,
    // 8, 8, 10,
    // 30, 50, 100, 150,
    // 20, 150, 700,
    // 30, 50, 70, 80, 100,
    // 20, 30, 45,
    // 15, 25, 40, 60,
    // 5, 7, 10,
    // 10, 100};
}