#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

int y = 15;
int x = 15;

int size_y;
int size_x;

int apple_y;
int apple_x;

int snake_len = 0;

int check_collision(int tail_y[], int tail_x[], int y, int x){
    for (int i = 0; i < snake_len; i++){
        if (tail_x[i] == x && tail_y[i] == y){
            return 1;
        }
    }
    return 0;
}

void set_apple_pos(int tail_y[], int tail_x[]){
    do {
        apple_y = rand()% size_y;
        apple_x = rand()% size_x;
    } while (check_collision(tail_y, tail_x, apple_y, apple_x));
}

void draw_snake(int tail_y[], int tail_x[]){
    for (int i = 0; i < snake_len; i++){
        mvaddstr(tail_y[i],tail_x[i],"x");
    }
}

void grow_snake(int tail_y[], int tail_x[]){
    tail_y[snake_len] = y;
    tail_x[snake_len] = x;
    snake_len += 1;
}

void snake_len_cut(int tail_y[], int tail_x[]){
    for (int i = 0; i < snake_len; i++){
    tail_y[i] = tail_y[i+1];
    tail_x[i] = tail_x[i+1];
    }
    snake_len -= 1;
}

int main(){

    srand(time(NULL));
    initscr();
    getmaxyx(stdscr,size_y,size_x);

    int size_yx = size_x * size_y;
    int tail_y[size_yx];
    int tail_x[size_yx];

    set_apple_pos(tail_y, tail_x);
    grow_snake(tail_y, tail_x);

    while (1){
        erase();
        mvaddstr(y,x,"x");
        mvaddstr(apple_y,apple_x,"o");
        draw_snake(tail_y, tail_x);
        char key = getch();
        if (key == 'd'){
            x = x + 1;
        }
        else if (key == 'a'){
            x = x - 1;
        }
        else if (key == 'w'){
            y = y - 1;
        }
        else if (key == 's'){
            y = y + 1;
        }
        if (y >= size_y){
            y = 0;
        }
        else if (y < 0){
            y = size_y - 1;
        }
        else if (x >= size_x){
            x = 0;
        }
        else if (x < 0){
            x = size_x - 1;
        }

        if (check_collision(tail_y, tail_x, y, x)){
            endwin();
            exit(0);
        }

        grow_snake(tail_y, tail_x);

        if (x == apple_x && y == apple_y){
            set_apple_pos(tail_y, tail_x);
        }
        else {
            snake_len_cut(tail_y, tail_x);
        }
    }
    endwin();

    return 0;
}

// посмотреть видео по C - Хирьянов youtube лекции по C
// закодировать змейку при помощи ring buffer в новом файле
