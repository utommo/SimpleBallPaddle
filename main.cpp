#include <iostream>
#include <graphics.h>

using namespace std;

#define WIDTH 800
#define HEIGHT 600
#define TRUE 1
#define FALSE 0

int main(){

    int circle_x, circle_y, circle_r, speed_x, speed_y;

    circle_x = 50;
    circle_y = 100;
    circle_r = 25;
    speed_x = (rand() % 3);
    speed_y = (rand() % 2);

    //For memory purpose:
    //ballstate = 0 ++
    //ballstate = 1 +-
    //ballstate = 2 -+
    //ballstate = 3 --


    initwindow(WIDTH,HEIGHT);
    setcolor(YELLOW);

    while(TRUE){
        Sleep(5);
        cleardevice();

        circle_x = circle_x + speed_x;
        circle_y = circle_y + speed_y;

        if(circle_x > (WIDTH - circle_r) || circle_x < circle_r){
            speed_x = speed_x * -1;
        }
        if((circle_y > (HEIGHT - 75)) || ((circle_y < circle_r))){
            speed_y = speed_y * -1;
        }

        //Draws the ball
        circle(circle_x, circle_y, circle_r);
        //Draws the paddle
        line((circle_x + 50), (HEIGHT - 50), (circle_x - 50), (HEIGHT - 50));
    }

    getch();
    closegraph();
    return 0;

}