#include <iostream>
#include <graphics.h>
#include <time.h>

using namespace std;

//Defining the width and height of the window
#define WIDTH 800
#define HEIGHT 600

//The main object
class GObject{
public:
    int x,y;

    //The update function is what is going to draw the different object on the screen, every time it is being called
    void update();

};

//The ball object inherits the properties of GObject
class Ball : public GObject{

public:

    Ball(){
        //Assigning the start x and y values for the ball
        this->x = 50;
        this->y = 50;
        //Assigning the balls radius
        this->r = 25;
        //Assigning the speed variables to the ball
        //srand adds a seed to the random number, so that the random number is random
        srand ( time(NULL) );
        //the + 1 is in place so that the speed never is 0, so the ball will always move, no matter what the random number is
        this->speed_x = (rand() % 5 + 1);
        this->speed_y = (rand() % 5 + 1);
    }

    void update(){

        //Checks if the ball hits the left or right side of the window
        //When the ball hits either side, the direction is changed
        if(this->x > (WIDTH - this->r) || this->x < this->r){
            this->speed_x = this->speed_x * -1;
        }
        //Checks if the balls hits the paddle placement or if the ball hits the roof of the window
        if((this->y > (HEIGHT - 75)) || ((this->y < this->r))){
            this->speed_y = this->speed_y * -1;
        }

        //The speed of the ball is added to the coordinates, so that the ball moves
        this->x += this->speed_x;
        this->y += this->speed_y;
        //The function that draws the circle
        circle(this->x, this->y, this->r);
    }

private:

    //Private variables that only belong to the ball class
    int r, speed_x, speed_y;

};

//The paddle object inherits the properties of GObject
class Paddle : public GObject{

public:

    Paddle(){
        //Determines the position of the paddle
        this->y = HEIGHT - 50;
        //A placeholder number for the x value of the paddle
        this->x = 0;
    }

    void update();

};

//The initialization of the ball and paddle
Ball mainBall;
Paddle mainPaddle;

//The drawing function for the paddle is written outside its class because it needs to access the x-value
//from the ball class. The position of the paddle is based on the centre of the ball.
void Paddle :: update(){
    this->x = mainBall.x;
    line(this->x + 50, this->y, this->x-50, this->y);
}

int main(){



    //Initializes the windows using the width and height defined above
    initwindow(WIDTH,HEIGHT);
    //Sets the drawing colour to yellow
    setcolor(YELLOW);

    //The main loop that continuously draws the paddle and ball
    while(true){
        //A delay so that the ball movement is not too fast
        Sleep(5);
        //To avoid the path of the paddle and ball to be drawn, the window needs to be cleared every time something new is drawn
        cleardevice();

        //The update functions are called to re-draw the ball and paddle with new x and y values.
        mainBall.update();
        mainPaddle.update();

    }

    //If the loop had an end, then this code would be needed:
    //getch();
    //closegraph();
    return 0;

}
