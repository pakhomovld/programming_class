#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

int main(){

    srand(time(NULL));

    int size_y;
    int size_x;
    int y = 10;
    int x = 10;

    initscr();
    getmaxyx(stdscr,size_y,size_x);

    int apple_y = rand()% size_y;
    int apple_x = rand()% size_x;

    while (1){
        mvaddstr(y,x,"x");
        mvaddstr(apple_y,apple_x,"o");
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
        if (x == apple_x && y == apple_y){
            apple_x = rand()% size_x;
            apple_y = rand()% size_y;
        }
        erase();
    }
    endwin();

    return 0;
}

// посмотреть видео по C - Хирьянов youtube лекции по C
