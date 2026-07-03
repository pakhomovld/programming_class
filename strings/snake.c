#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

int y = 10;
int x = 10;

void check_self_eat(int snake_len, int tail_y[], int tail_x[]){
    for (int i = 0; i < snake_len; i++){
        if (tail_x[i] == x && tail_y[i] == y){
            endwin();
            exit(0);
        }
    }
}

int main(){

    srand(time(NULL));

    int size_y;
    int size_x;

    int snake_len = 0;

    initscr();
    getmaxyx(stdscr,size_y,size_x);

    int size_yx = size_x * size_y;
    int tail_y[size_yx];
    int tail_x[size_yx];

    int apple_y = rand()% size_y;
    int apple_x = rand()% size_x;

    while (1){
        mvaddstr(y,x,"x");
        mvaddstr(apple_y,apple_x,"o");
        for (int i = 0; i <= snake_len; i++){
            mvaddstr(tail_y[i],tail_x[i],"x");
        }
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

        check_self_eat(snake_len, tail_y, tail_x);

        tail_y[snake_len] = y;
        tail_x[snake_len] = x;
        snake_len += 1;

        if (x == apple_x && y == apple_y){
            apple_x = rand()% size_x;
            apple_y = rand()% size_y;
        }
        else {
            for (int i = 0; i < snake_len; i++){
                tail_y[i] = tail_y[i+1];
                tail_x[i] = tail_x[i+1];
            }
            snake_len -= 1;
        }
        erase();
    }
    endwin();

    return 0;
}

// посмотреть видео по C - Хирьянов youtube лекции по C
