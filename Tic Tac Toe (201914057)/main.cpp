#include<iostream>
#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include<fstream>

using namespace std;

void Drawlines(int x1, int y1, int x2, int y2);
void DrawBox(int x1, int x2, int y1, int y2);

static GLfloat spin = 0.0;
static float	tx	=  0.0;
static float	ty	=  0.0;
int flag = 0;
int turns = 0;
int state[4][4] = {0};
int player = 1;
bool gameover = false;

///Used to write text in the opengl window
void drawString (void * font, char *s, float x, float y){
    unsigned int i;
    glRasterPos2f(x, y);
    for (i = 0; i < strlen (s); i++)
        glutBitmapCharacter (font, s[i]);
    }

void renderbitmap(float x, float y, void *font, char *Xtring){
    char *c;
    glRasterPos2f(x,y);
    for(c=Xtring; *c!='\0'; c++)    glutBitmapCharacter(font,*c);
}

void writeText(char *a, float x, float y, void *font){
    char buf[100] = {0};
    sprintf(buf,a);
    renderbitmap(x,y,font,buf);
}

void writeIntText(int a, float x, float y, void *font){
    char buf[100] = {0};
    sprintf(buf, "%d" ,a);
    renderbitmap(x,y,font,buf);
}


void writeCharText(char a, float x, float y, void *font){
    glColor3f(0.5, 0.5, 0.5);
    char buf[100] = {0};
    sprintf(buf, "%c" ,a);
    renderbitmap(x,y,font,buf);
}

void putnuminarray(int x){
    if(x == 1)  if(state[0][0] == 0)   {state[0][0] = player;    (player == 1) ? player = 2 : player = 1;   turns++;}
    if(x == 2)  if(state[0][1] == 0)   {state[0][1] = player;    (player == 1) ? player = 2 : player = 1;   turns++;}
    if(x == 3)  if(state[0][2] == 0)   {state[0][2] = player;    (player == 1) ? player = 2 : player = 1;   turns++;}
    if(x == 4)  if(state[0][3] == 0)   {state[0][3] = player;    (player == 1) ? player = 2 : player = 1;   turns++;}
    if(x == 5)  if(state[1][0] == 0)   {state[1][0] = player;    (player == 1) ? player = 2 : player = 1;   turns++;}
    if(x == 6)  if(state[1][1] == 0)   {state[1][1] = player;    (player == 1) ? player = 2 : player = 1;   turns++;}
    if(x == 7)  if(state[1][2] == 0)   {state[1][2] = player;    (player == 1) ? player = 2 : player = 1;   turns++;}
    if(x == 8)  if(state[1][3] == 0)   {state[1][3] = player;    (player == 1) ? player = 2 : player = 1;   turns++;}
    if(x == 9)  if(state[2][0] == 0)   {state[2][0] = player;    (player == 1) ? player = 2 : player = 1;   turns++;}
    if(x == 10)  if(state[2][1] == 0)   {state[2][1] = player;   (player == 1) ? player = 2 : player = 1;   turns++;}
    if(x == 11)  if(state[2][2] == 0)   {state[2][2] = player;   (player == 1) ? player = 2 : player = 1;   turns++;}
    if(x == 12)  if(state[2][3] == 0)   {state[2][3] = player;   (player == 1) ? player = 2 : player = 1;   turns++;}
    if(x == 13)  if(state[3][0] == 0)   {state[3][0] = player;   (player == 1) ? player = 2 : player = 1;   turns++;}
    if(x == 14)  if(state[3][1] == 0)   {state[3][1] = player;   (player == 1) ? player = 2 : player = 1;   turns++;}
    if(x == 15)  if(state[3][2] == 0)   {state[3][2] = player;   (player == 1) ? player = 2 : player = 1;   turns++;}
    if(x == 16)  if(state[3][3] == 0)   {state[3][3] = player;   (player == 1) ? player = 2 : player = 1;   turns++;}

}

void PrintinBox(int i, int j)
{
            glColor3f(0.65, 0.62, 0.610);
            DrawBox(-220+(j*120),-140+(j*120),220-(i*120),140-(i*120));
            glColor3f(0.0, 0.0, 0.0);
            Drawlines(-220+(j*120),220-(i*120), -140+(j*120), 140-(i*120));
            Drawlines(-220+(j*120),140-(i*120), -140+(j*120), 220-(i*120));
}

void drawCircle(float rx, float ry, int half, int xp, int yp){
    glPushMatrix();
    glPointSize(3);
    glBegin(GL_POLYGON);
    int i;
    int len = 360;
    if(half == 1)   len = 180;
    for(i=0; i<len; i++){
        float theta = (i*3.1416)/180.0;
        glVertex2f(rx*cos(theta)  + xp, ry*sin(theta) + yp);
    }
    glEnd();
    glPopMatrix();
}


void DrawBox(int x1, int x2, int y1, int y2){
    glPushMatrix();
    glBegin(GL_POLYGON);

    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);
    glVertex2f(x1, y2);

    glEnd();
    glPopMatrix();
}

void Drawlines(int x1, int y1, int x2, int y2){
    glBegin(GL_LINE_LOOP);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
    glEnd();
}

void DrawGameArea(){

    glColor3f(0.65, 0.62, 0.610);
    DrawBox(-240,240,-240,240);

    glColor3f(0.15, 0.12, 0.10);
    Drawlines(-120, 240,-120,-240);///for vertical lines
    Drawlines(-0, 240,-0,-240);
    Drawlines(120, 240,120,-240);

    Drawlines(-240, 120,240,120);///for horizontal lines
    Drawlines(-240, 0,240,0);
    Drawlines(-240, -120,240,-120);
}
/*
int isOver()
{
    for(int i = 0; i<4; i++){
    if(state[i][1] == state[i][0] && state[i][2] == state[i][3] && state[i][1] == state[i][2] && state[i][2] != 0) return player;

    }
}*/

void display(void)//Draw anything
{
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);

    ///Game area
    DrawGameArea();
    int c = 0;
    for(int p = 0; p <4; p++){
        for(int q = 0; q < 4; q++){
                writeCharText((char)(c+'a'), -185+(120*q), 170-(120*p), GLUT_BITMAP_TIMES_ROMAN_24);        c++;
        }
    }


    ///If any of the box is not filled, fill it with the input
    for(int p = 0; p <4; p++){
        for(int q = 0; q < 4; q++){
            if(state[p][q] == 1)    PrintinBox(p,q);
            else if(state[p][q] == 2){
                glColor3f(0.15, 0.12, 0.10);
                drawCircle(50, 50, 0, -180+(120*q), 180-(120*p));
                glColor3f(0.65, 0.62, 0.610);
                drawCircle(45, 45, 0, -180+(120*q), 180-(120*p));

            }
        }
    }

    ///Check if any field matches
    int i = -1, j = -1, k = -1;
    //Horizontal
    for(i = 0; i<4; i++){
        if(state[i][0] == state[i][1] && state[i][2] == state[i][1] && state[i][0] == state[i][3] && state[i][2] == state[i][3] && state[i][0] != 0) {
            glColor3f(0.5, 0, 0.75);
            Drawlines(-220, 180-(120*i) ,220, 180-(120*i));
            gameover = true;
            break;
        }
    }

    //Vertical
    for(j = 0; j<4;j++){
        if(state[0][j] == state[1][j] && state[2][j] == state[1][j] && state[0][j] == state[3][j] && state[2][j] == state[3][j] && state[0][j] != 0) {
            gameover = true;
            glColor3f(0.5, 0, 0.75);
            Drawlines(-180+(120*j), -220 ,-180+(120*j), 220);
            break;
        }
    }

    //Diagonal
        if(state[0][0] == state[1][1] && state[2][2] == state[1][1] && state[2][2] == state[3][3] && state[0][0] == state[3][3] &&state[0][0] != 0) {

            glColor3f(0.5, 0, 0.75);
            Drawlines(220, -220 ,-220, 220);
            gameover = true;
            k = 1;
        }else if(state[0][3] == state[1][2] && state[2][1] == state[1][2] && state[2][1] == state[3][0] && state[0][3] == state[3][0] &&state[0][3] != 0) {
            glColor3f(0.5, 0, 0.75);
            Drawlines(-220, -220 ,220, 220);
            gameover = true;
            k = 2;
        }
    if(turns==16 && !gameover){
        glColor3f(1,1,1);
        drawString(GLUT_BITMAP_HELVETICA_18,"ITS A DRAW!",-420,150);
    }

    glColor3f(1,1,1);
    if(gameover==true){
        drawString(GLUT_BITMAP_HELVETICA_18,"Game Over",-420,150);
        if(player == 1){
            drawString(GLUT_BITMAP_HELVETICA_18,"Congratulations!",-420,130);
            drawString(GLUT_BITMAP_HELVETICA_18,"Player 2 wins",-420,100);
        }
        if(player ==2){
            drawString(GLUT_BITMAP_HELVETICA_18,"Congratulations!",-420,130);
            drawString(GLUT_BITMAP_HELVETICA_18,"Player 1 wins",-420,100);
        }


    }



    ///Write some texts
    glColor3f(1,1,1);
    writeText("TIC TAC TOE", -75, 265, GLUT_BITMAP_TIMES_ROMAN_24);
    writeText("Turns = ", -400, 0, GLUT_BITMAP_HELVETICA_18);
    writeText("Use alphabets from a to p to play the game", -240,-260, GLUT_BITMAP_HELVETICA_18);
    writeIntText(turns, -330, 0, GLUT_BITMAP_HELVETICA_18);
    writeText("X for Player 1", 250,230 , GLUT_BITMAP_HELVETICA_18);
    writeText("O for player 2", 250,200, GLUT_BITMAP_HELVETICA_18);
    writeText("Player ", -400, -100, GLUT_BITMAP_HELVETICA_18);
    writeIntText(player, -330, -100, GLUT_BITMAP_HELVETICA_18);
    //cout << isOver() << endl;



	glFlush();
}


void init(void)
{
	glClearColor (.095,.095,.095, 0.0);
	PlaySound(("bgmt.wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);

}


void my_keyboard(unsigned char key, int x, int y)
{

	switch (key) {

		case 's':
			 glutIdleFunc(NULL);
			 break;

	  default:
			break;
	}
    if((int)key- 'a' + 1< 1 && (int)key- 'A' + 1 > 16){
        printf("Invalid input, try again\n");
    }else{
        if(!gameover)
        putnuminarray((int)key-'a' + 1);
    }

}

void my_mouse(int button, int state, int x, int y)
{
   switch (button) {
      case GLUT_LEFT_BUTTON:
         if (state == GLUT_DOWN)
            ///glutIdleFunc(spinDisplay_left);
         break;
      case GLUT_MIDDLE_BUTTON:
      case GLUT_RIGHT_BUTTON:
         if (state == GLUT_DOWN)
			///glutIdleFunc(spinDisplay_right);
          //glutIdleFunc(NULL); // make idle function inactive
         break;
      default:
         break;
   }
}


void my_reshape(int w, int h)
{
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-450,450,-300,300);
    glMatrixMode(GL_MODELVIEW);

}

void timer(int){
    glutPostRedisplay();
    glutTimerFunc(1000/60, timer, 0);
}

int main()
{
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (900, 600);
	glutCreateWindow ("It's a game of Tic Tac Toe");
	init();

	glutDisplayFunc(display);
	glutKeyboardFunc(my_keyboard);
	glutReshapeFunc(my_reshape);
	glutTimerFunc(0, timer,0);
	glutMouseFunc(my_mouse);
	glutMainLoop();
	return 0;

}


