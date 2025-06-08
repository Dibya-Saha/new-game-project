#include "iGraphics.h"
#include <stdlib.h> 
double x1=0,y11=0; 
char hab[10][13]={"hab001_1.png","hab002_1.png","hab003_1.png","hab004_1.png","hab005_1.png","hab006_1.png","hab007_1.png","hab008_1.png","hab009_1.png","hab010_1.png"};
char cloud[7][12]={"cloud1.png","cloud2.png","cloud3.png","cloud4.png","cloud5.png","cloud6.png","cloud7.png"};
int i=0;
int x=200,y=70;
void move()
{
    if(isSpecialKeyPressed(GLUT_KEY_RIGHT))x+=30;
    if(isSpecialKeyPressed(GLUT_KEY_LEFT)) x -=30;
    if(x > 460) x = -40;
    if(x < -40) x = 460;
}

int c1=00,c2=150,c3=200,c4=400,c5=250,c6=320,c7=425;
void incmnt()
{
    i++;
    if(i>=10)
     i=0;
}
void cld()
{
    c1+=10;
    if(c1>490)c1=-150;
    c2-=10;
    if(c2<-100)c2=550;
    c3-=15;
    if(c3<-100)c3=550;
    c4+=8;
    if(c4>490)c4=-150;
    c5+=12;
    if(c5>490)c5=-150;
    c6-=7;
    if(c6<-100)c6=550;
    c7+=15;
    if(c7>490)c7=-150;
}
void iDraw()
{
    // place your drawing codes here
    iClear();
    iShowImage(0,0,"sky.jpg");
    iShowImage(c1,600,cloud[0]);
    iShowImage(c2,690,cloud[1]);
    iShowImage(c3,520,cloud[2]);
    iShowImage(c4,370,cloud[3]);
    iShowImage(c5,450,cloud[4]);
    iShowImage(c6,550,cloud[5]);
    iShowImage(c7,500,cloud[6]);
    if(x>460)
       x=-40;
    if(x<-40)
       x=460;
    iShowImage(x,y,hab[i]);
}

/*
function iMouseMove() is called when the user moves the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
    // place your codes here
}

/*
function iMouseDrag() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouseDrag(int mx, int my)
{
    // place your codes here
}

/*
function iMouse() is called when the user presses/releases the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        // place your codes here
    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        // place your codes here
    }
}

/*
function iMouseWheel() is called when the user scrolls the mouse wheel.
dir = 1 for up, -1 for down.
*/
void iMouseWheel(int dir, int mx, int my)
{
    // place your code here
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
    switch (key)
    {
    case 'q':
        // do something with 'q'
        break;
    // place your codes for other keys here
    default:
        break;
    }
}

/*
function iSpecialKeyboard() is called whenver user hits special keys likefunction
keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11,
GLUT_KEY_F12, GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN,
GLUT_KEY_PAGE_UP, GLUT_KEY_PAGE_DOWN, GLUT_KEY_HOME, GLUT_KEY_END,
GLUT_KEY_INSERT */
void iSpecialKeyboard(unsigned char key)
{
   // start moving left
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    // place your own initialization codes here.
    iSetTimer(50,incmnt);
    iSetTimer(1,cld);
    iSetTimer(1, move); 
    iInitialize(500, 800, "demooo");        
    return 0;
}