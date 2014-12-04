#include <iostream>
#include <graphics.h>

using namespace std;

#define WIDTH 800
#define HEIGHT 600

class GObject{
public:
    int x,y;
    void update();

};
class Ball : public GObject{
public:
    Ball(){
        this->x = 50;
        this->y = 50;

        this->r = 25;
        this->speed_x = (rand() % 6);
        this->speed_y = (rand() % 6);
    }
    void update(){
        if(this->x > (WIDTH - this->r) || this->x < this->r){
            this->speed_x = this->speed_x * -1;
        }
        if((this->y > (HEIGHT - 75)) || ((this->y < this->r))){
            this->speed_y = this->speed_y * -1;
        }
        this->x += this->speed_x;
        this->y += this->speed_y;
        circle(this->x, this->y, this->r);
    }
private:
    int r, speed_x, speed_y;
};

class Paddle : public GObject{
public:
    Paddle(){
        this->y = HEIGHT - 50;
        this->x = 0;
    }
    void update();
};

Ball mainBall;
Paddle mainPaddle;

void Paddle :: update(){
    this->x = mainBall.x;
    line(this->x + 50, this->y, this->x-50, this->y);
}

int main(){


    initwindow(WIDTH,HEIGHT);
    setcolor(YELLOW);

    while(true){
        Sleep(5);
        cleardevice();

        mainBall.update();
        mainPaddle.update();

    }

    getch();
    closegraph();
    return 0;

}
