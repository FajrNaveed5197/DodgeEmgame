//============================================================================
// Name        : game.cpp
// Author      : Hassan Mustafa
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Dodge 'Em...
//============================================================================

#ifndef DODGE_CPP_
#define DODGE_CPP_
#include "util.h"
#include <iostream>
#include<time.h>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;
void fooddrawing(),foodeating();
bool pausehi = false, startmenu = true;
int Score = 0;
int food1x = 350;
int food2x = 455;
int food3x = 560;
int food4x = 665;
int food5x = 770;
int food6x = 875;
int food7x = 980;
int food8x = 1085;
int lives = 3;
int level = 1;
int width=11,height=11;


float position1=145,position2=150,position3=750,position4=40;

int foodrow1x[8]= {0};
int foodrow2x[8]= {0};
int foodrow3x[8]= {0};
int foodrow4x[8]= {0};
int foodrow5x[8]= {0};
int foodrow6x[8]= {0};
int foodrow7x[8]= {0};
int foodrow8x[8]= {0};

void UpDownmovement()
{
int a=rand()%1;
if(a==0)
{
if(position4<=780 && position4>=50 && position3 >= 380 && position3 <= 450)
{
int b=rand()%6;
	if(position4==750 && b==1)
	{
	position4=650;
	}
	else if(position4==650 && b==2)
	{
	position4=560;
	}
	else if(position4==560 && b==3)
	{
	position4=455;
	}
	else if(position4==305 && b==4)
	{
	position4=220;
	}
	else if(position4==220 && b==5)
	{
	position4=140;
	}
	else if(position4==140 && b==6)
	{
	position4=50;
	}
}
}
else if(a==1)
{
if(position4<=780 && position4>=50 && position3 >= 380 && position3 <= 450)
{
int c=rand()%6;
	if(position4==50 && c==1)
	{
	position4=140;
	}
	else if(position4==140 && c==2)
	{
	position4=220;
	}
	else if(position4==220 && c==3)
	{
	position4=305;
	}
	else if(position4==455 && c==4)
	{
	position4=560;
	}
	else if(position4==560 && c==5)
	{
	position4=650;
	}
	else if(position4==650 && c==6)
	{
	position4=750;
	}
}
}
cout<<position3<<endl<<position4<<endl;
}
void Highscore()
{
			glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors

			DrawRectangle(0 , 0 , 1000 , 1000 , colors[BLACK] );
			DrawString( 350, 700, "HIGH SCORE=" , colors[rand() % 50]);
			DrawString( 350, 900, "192" , colors[rand() % 50]);
}
void LeftRightmovement()
{
int a=rand()%1;
if(a==0)
{
if(position4>=350 && position4<=430 )
{
int d=rand()%6;
	if(position3==30 && d==1)
	position3=140;
	else if(position3==140 && d==2)
	position3=220;
	else if(position3==220 && d==3)
	position3=335;
	else if(position3==460 && d==4)
	position3=560;
	else if(position3==560 && d==5)
	position3=670;
	else if(position3==670 && d==6)
	position3=755;
}
}
if(a==1)
{
int e=rand()%6;
	if(position3==755 && e==1)
	position3=670;
	else if(position3==670 && e==2)
	position3=560;
	else if(position3==560 && e==3)
	position3=460;
	else if(position3==335 && e==4)
	position3=220;
	else if(position3==220 && e==5)
	position3=140;
	else if(position3==140 && e==6)
	position3=30;
}

}
void foodsaving()
{
food1x = 350;
food2x = 455;
food3x = 560;
food4x = 665;
food5x = 770;
food6x = 875;
food7x = 980;
food8x = 1085;
for (int i=0;i<8; i++){
foodrow1x[i]= 0;
foodrow2x[i]= 0;
foodrow3x[i]= 0;
foodrow4x[i]= 0;
foodrow5x[i]= 0;
foodrow6x[i]= 0;
foodrow7x[i]= 0;
foodrow8x[i]= 0;
}
int xinc = 50;

	for (int i = 0 ; i < 8 ; i++)
	{
		foodrow1x[i] += xinc;
		xinc += 105;
	}xinc = 50;
	for (int i = 0 ; i < 8 ; i++)
	{
		foodrow2x[i] += xinc;
		xinc += 105;
	}xinc = 50;
	for (int i = 0 ; i < 8 ; i++)
	{
		foodrow3x[i] += xinc;
		xinc += 105;
	}xinc = 50;
	for (int i = 0 ; i < 8 ; i++)
	{
		foodrow4x[i] += xinc;
		xinc += 105;
	}xinc = 50;
	for (int i = 0 ; i < 8 ; i++)
	{
		foodrow5x[i] += xinc;
		xinc += 105;
	}xinc = 50;
	for (int i = 0 ; i < 8 ; i++)
	{
		foodrow6x[i] += xinc;
		xinc += 105;
	}xinc = 50;
	for (int i = 0 ; i < 8 ; i++)
	{
		foodrow7x[i] += xinc;
		xinc += 105;
	}xinc = 50;
	for (int i = 0 ; i < 8 ; i++)
	{
		foodrow8x[i] += xinc;
		xinc += 105;
	}xinc = 50;
}

void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}




 void playercarmovement()
 {
    //player's car movement
	//outer most path
        if(position2<740 && position1>=30 && position1 == 35)
        { position2+=5;

	}
	else if(position1>30 &&  position2 ==740  && position1 <= 750)
        { position1+=5;

	}
	else if(position2>50 && position1==755 && position2<=740)
	{ position2-=5;

	}
	else if(position1>=34 && position1<=770 && position2==50)
        { position1-=5;

	}
	
	// player movement.... mid path
	if(position2==140 && (position1>145 && position1<=665 ) )
	{
	position1-=5;
	}	
	else if(position1==665 && (position2>=140 && position2<=650 ) )
	{
	position2-=5;
	}	
	else if(position2==650 && (position1>=145 && position1<665 ) )
	{
	position1+=5;
	}	
	else if(position1==145 && (position2>=140 && position2<650 ) )
	{
	position2+=5;
	}
	// player movement .. inner path
	else if(position2==560 && position1>=230 && position1<=555)
	{
	position1+=5;
	}
	else if(position1==560 && position2>=225 && position2<=560)
	{
	position2-=5;
	}	
	else if(position2==220 && position1>=240 && position1<=560)
	{
	position1-=5;
	}
	else if(position1==235 && position2>=220 && position2<= 555)
	{
	position2+=5;
	}
	//inner most movement
	else if(position1>=340 && position1<=455 && position2==455)
	{
	position1+=5;
	}
	else if(position1==460 && position2>=310 && position2<=455)
	{
	position2-=5;
	}
	else if(position2==305 && position1>=345 && position1<=460)
	{
	position1-=5;
	}
	else if(position1==340 && position2>=305 && position2<=455)
	{
	position2+=5;
	}


  }
 void opponentcarmovement()
{
// opponent movement..
	if(position3 >=750 && position4>=40 && position4<=745)
	{
	position4+=5;
	}
	else if(position3<=760 && position3>=35 && position4 >=750)
	{
	position3-=5;

	}
	else if(position4<=755 && position4>=50 && position3<=30)
	{
	position4-=5;
	
	}
	else if(position3>=25 && position3<=760 && position4 <= 50)
	{
	position3+=5;
	}
	//inner 1
	// opponent movement.... mid path
	if(position4==140 && (position3>=135 && position3<=665 ) )
	{
	position3+=5;
	}	
	else if(position3>=665 && (position4>=140 && position4<=660 ) )
	{
	position4+=5;
	}	
	else if(position4>=650 && (position3>=145 && position3<=670 ) )
	{
	position3-=5;
	}	
	else if(position3<=145 && (position4>=140 && position4<=665 ) )
	{
	position4-=5;
	}
	// opponent movement .. inner path
	else if(position4>=560 && position3>=225 && position3<=560)
	{
	position3-=5;
	}
	else if(position3==560 && position4>=220 && position4<=560)
	{
	position4+=5;
	}	
	else if(position4<=220 && position3>=220 && position3<=555)
	{
	position3+=5;
	}
	else if(position3<=235 && position4>=220 && position4<= 560)
	{
	position4-=5;
	}
	//opponent movement.....inner most movement
	else if(position3>=340 && position3<=460 && position4>=455)
	{
	position3-=5;
	}
	else if(position3>=460 && position4>=300 && position4<=455)
	{
	position4+=5;
	}
	else if(position4==305 && position3>=335 && position3<=460)
	{
	position3+=5;
	}
	else if(position3>=335 && position4>=305 && position4<=455)
	{
	position4-=5;
	}

}

void startupmenu()
{
DrawRectangle(0 , 0 , 1000 , 1000 , colors[BLACK] );
	DrawString( 350, 900, "DODGE 'EM" , colors[rand() % 50]);
	DrawString( 350, 600, "START GAME" , colors[rand() % 50]);
	DrawString( 350, 500, "HIGH SCORE=192" ,colors[rand() % 50]);
	DrawString( 350, 400, "EXIT" , colors[rand() % 50]);
}


void carscollision()
{
if (sqrt(pow (position1 - position3 , 2) + pow (position2 - position4 , 2)   ) < 30 )
	{
	position1=145;
	position2=150;
	position3=750;
	position4=40;
	lives--;
	Score=0;
	foodsaving();
	fooddrawing();
	foodeating();
	
	}

}

void fooddrawing()
{

for (int i = 0 ; i < 8 ; i++){
	DrawSquare(foodrow1x[i] , 70 ,  10 ,  colors[rand()%50]  );
}
for (int i = 0; i < 8 ; i++){
	DrawSquare(foodrow2x[i] , 160 ,  10 ,  colors[rand()%50]  );
}
for (int i = 0 ; i < 8 ; i++){
	DrawSquare(foodrow3x[i] , 250 ,  10 ,  colors[rand()%50]  );

}
for (int i = 0 ; i < 8 ; i++){
	DrawSquare(foodrow4x[i] , 340 ,  10 ,  colors[rand()%50]  );
}
for (int i = 0 ; i < 8 ; i++){
	DrawSquare(foodrow5x[i] , 500 ,  10 ,  colors[rand()%50]  );
}
for (int i = 0 ; i < 8 ; i++){
	DrawSquare(foodrow6x[i] , 590 ,  10 ,  colors[rand()%50]  );
}
for (int i = 0 ; i < 8 ; i++){
	DrawSquare(foodrow7x[i] , 680 ,  10 ,  colors[rand()%50]  );

}
for (int i = 0 ; i < 8 ; i++){
	DrawSquare(foodrow8x[i] , 770 ,  10 ,  colors[rand()%50]  );
}

}

void foodeating()
{
for (int i = 0 ; i < 8 ; i++){
if (sqrt(pow (position1 - foodrow1x[i] , 2) + pow (position2 - 50 , 2)   ) < 50 )
	{foodrow1x[i] = -100;
	Score++;}
if (sqrt(pow (position1 - foodrow2x[i] , 2) + pow (position2 - 160 , 2)   ) < 50 )
	{foodrow2x[i] = -100;
	Score++;}
if (sqrt(pow (position1 - foodrow3x[i] , 2) + pow (position2 - 250 , 2)   ) < 50 )
	{foodrow3x[i] = -100;
	Score++;}
if (sqrt(pow (position1 - foodrow4x[i] , 2) + pow (position2 - 340 , 2)   ) < 50 )
	{foodrow4x[i] = -100;
	Score++;}
if (sqrt(pow (position1 - foodrow5x[i] , 2) + pow (position2 - 500 , 2)   ) < 50 )
	{foodrow5x[i] = -100;
	Score++;}
if (sqrt(pow (position1 - foodrow6x[i] , 2) + pow (position2 - 590 , 2)   ) < 50 )
	{foodrow6x[i] = -100;
	Score++;}
if (sqrt(pow (position1 - foodrow7x[i] , 2) + pow (position2 - 680 , 2)   ) < 50 )
	{foodrow7x[i] = -100;
	Score++;}
if (sqrt(pow (position1 - foodrow8x[i] , 2) + pow (position2 - 770 , 2)   ) < 50 )
	{foodrow8x[i] = -100;
	Score++;}

}

}
void hints()
{
DrawString( 40, 900, "Score = " + to_string (Score), colors[MISTY_ROSE]);
	DrawString( 40, 930, "Lives = " + to_string (lives), colors[MISTY_ROSE]);
	DrawString( 40, 850, "LEVEL = " + to_string (level), colors[MISTY_ROSE]);
	DrawString( 600, 920, "Press: " , colors[MISTY_ROSE]);
	DrawString( 600, 890, "p to play and pause " , colors[DARK_BLUE]);
	DrawString( 600, 850, "Esc to end game " , colors[DARK_BLUE]);

}

void opponentcar()
{
// Drawing opponent car
	//float x = 100;
       	//float y = 100;

	float width = 11;
	float height = 11;
	float* color = colors[YELLOW];
	float radius = 5.0;
	DrawRoundRect(position1,position2,width,height,color,radius); // bottom left tyre
	DrawRoundRect(position1+width*3,position2,width,height,color,radius); // bottom right tyre
	DrawRoundRect(position1+width*3,position2+height*4,width,height,color,radius); // top right tyre
	DrawRoundRect(position1,position2+height*4,width,height,color,radius); // top left tyre
	DrawRoundRect(position1, position2+height*2, width, height, color, radius/2); // body left rect
	DrawRoundRect(position1+width, position2+height, width*2, height*3, color, radius/2); // body center rect
	DrawRoundRect(position1+width*3, position2+height*2, width, height, color, radius/2); // body right rect

}


void controlledcar()
{
//for controlled car by player
	//float x = 100;
       	//float y = 100;
	float player_width = 11;
	float player_height = 11;
	float* player_color = colors[BLUE_VIOLET];
	float player_radius = 5.0;
	DrawRoundRect(position3,position4,player_width,player_height,player_color,player_radius); // bottom left tyre
	DrawRoundRect(position3+width*3,position4,player_width,player_height,player_color,player_radius); // bottom right tyre
	DrawRoundRect(position3+width*3,position4+player_height*4,player_width,player_height,player_color,player_radius); // top right tyre
	DrawRoundRect(position3,position4+player_height*4,player_width,player_height,player_color,player_radius); // top left tyre
	DrawRoundRect(position3, position4+player_height*2, player_width, player_height, player_color, player_radius/2); // body left rect
	DrawRoundRect(position3+player_width, position4+player_height, player_width*2, player_height*3, player_color, player_radius/2); // body center rect
	DrawRoundRect(position3+player_width*3, position4+player_height*2, player_width, player_height, player_color, player_radius/2); // body right rect

}

void arena()
{
// Drawing Arena
	int gap_turn = 80;
	int sx = 20;
	int sy = 10;
	int swidth = 800/2 - gap_turn/2; // half width
	int sheight = 10;
	float *scolor = colors[ORANGE];
	DrawRectangle(sx, sy, swidth, sheight, scolor); // bottom left
	DrawRectangle(sx + swidth + gap_turn, sy, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*2, swidth, scolor); // right down
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up
	DrawRectangle(sx + swidth + gap_turn, sy+810, swidth, sheight, scolor); // top left
	DrawRectangle(sx, sy+810, swidth, sheight, scolor); // top right
	DrawRectangle(sx-sheight*2, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up
	DrawRectangle(sx-sheight*2, sy+sheight, sheight*2, swidth, scolor); // left down

	int gap_turn1 = 80;
	int sx1 = 20;
	int sy1 = 10;
	int swidth1 = 800/2 - gap_turn1/2; // half width
	int sheight1 = 10;
	float *scolor1 = colors[DARK_BLUE];
	DrawRectangle(sx1+100, sy1+100, swidth1-100, sheight1, scolor1); // bottom left
	DrawRectangle(sx1 + swidth1 + gap_turn1, sy1+100, swidth1-100, sheight1, scolor1); // bottom right
	DrawRectangle(sx1-100 + swidth1*2+gap_turn1, sy1+100+sheight1, sheight1*2, swidth1-100, scolor1); // right down
	DrawRectangle(sx1-100 + swidth1*2+gap_turn1, sy1+sheight1+swidth1+gap_turn1, sheight1*2, swidth1-100, scolor1); // right up
	DrawRectangle(sx1 + swidth1 + gap_turn1, sy1-100+810, swidth1-100, sheight1, scolor1); // top left
	DrawRectangle(sx1+100, sy1-100+810, swidth1-100, sheight1, scolor1); // top right
	DrawRectangle(sx1+100-sheight1*2, sy1+sheight1+swidth1+gap_turn1, sheight1*2, swidth1-100, scolor1); // left up
	DrawRectangle(sx1+100-sheight1*2, sy1+100+sheight1, sheight1*2, swidth1-100, scolor1); // left down

	int gap_turn2 = 80;
	int sx2 = 20;
	int sy2 = 10;
	int swidth2 = 800/2 - gap_turn2/2; // half width
	int sheight2 = 10;
	float *scolor2 = colors[ORANGE];
	DrawRectangle(sx2+200, sy2+200, swidth2-200, sheight2, scolor2); // bottom left
	DrawRectangle(sx2 + swidth2 + gap_turn2, sy2+200, swidth2-200, sheight2, scolor2); // bottom right
	DrawRectangle(sx2-200 + swidth2*2+gap_turn2, sy2+200+sheight2, sheight2*2, swidth2-200, scolor2); // right down
	DrawRectangle(sx2-200 + swidth2*2+gap_turn2, sy2+sheight2+swidth2+gap_turn2, sheight2*2, swidth2-200, scolor2); // right up
	DrawRectangle(sx2 + swidth2 + gap_turn2, sy2-200+810, swidth2-200, sheight2, scolor2); // top left
	DrawRectangle(sx2+200, sy2-200+810, swidth2-200, sheight2, scolor2); // top right
	DrawRectangle(sx2+200-sheight2*2, sy2+sheight2+swidth2+gap_turn2, sheight2*2, swidth2-200, scolor2); // left up
	DrawRectangle(sx2+200-sheight2*2, sy2+200+sheight2, sheight2*2, swidth2-200, scolor2); // left down

	int gap_turn3 = 80;
	int sx3 = 20;
	int sy3 = 10;
	int swidth3 = 800/2 - gap_turn1/2; // half width
	int sheight3 = 10;
	float *scolor3 = colors[DARK_BLUE];
	DrawRectangle(sx3+300, sy3+300, swidth3-300, sheight3, scolor3); // bottom left
	DrawRectangle(sx3 + swidth3 + gap_turn3, sy3+300, swidth3-300, sheight3, scolor3); // bottom right
	DrawRectangle(sx3-300 + swidth3*2+gap_turn3, sy3+300+sheight3, sheight3*2, swidth3-300, scolor3); // right down
	DrawRectangle(sx3-300 + swidth3*2+gap_turn3, sy3+sheight3+swidth3+gap_turn3, sheight3*2, swidth3-300, scolor3); // right up
	DrawRectangle(sx3 + swidth3 + gap_turn3, sy3-300+810, swidth3-300, sheight3, scolor3); // top left
	DrawRectangle(sx3+300, sy3-300+810, swidth3-300, sheight3, scolor3); // top right
	DrawRectangle(sx3+300-sheight3*2, sy3+sheight3+swidth3+gap_turn3, sheight3*2, swidth3-300, scolor3); // left up
	DrawRectangle(sx3+300-sheight3*2, sy3+300+sheight3, sheight3*2, swidth3-300, scolor3); // left down

	int gap_turn4 = 80;
	int sx4 = 20;
	int sy4 = 10;
	int swidth4 = 800/2 - gap_turn1/2; // half width
	int sheight4 = 10;
	float *scolor4 = colors[ORANGE];
	//DrawRectangle(sx4+400, sy4+400, swidth4-400, sheight4, scolor4); // bottom left
	//DrawRectangle(sx4 + swidth4 + gap_turn4, sy4+400, swidth4-400, sheight4, scolor4); // bottom right
	DrawRectangle(sx4+370, sy4-430+825, swidth4-320, sheight4+10, scolor4); // top left
	DrawRectangle(sx4+370, sy4-400+805, swidth4-320, sheight4+10, scolor4); // top right
}


void GameDisplay()/**/{

 glutPostRedisplay();



	
	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	carscollision();
	// calling some functions from util.cpp file to help students
	if (pausehi){
	playercarmovement();
	opponentcarmovement();

}// end of movement..

	//cout<<position3<<endl<<position4<<endl;
	//Square at 400,20 position

	//Square at 250,250 position
	//DrawSquare( 250 , 250 ,20,colors[GREEN]);

	if (startmenu)
	{
	startupmenu();
	}
	else{
	arena();
	if(level==1)
{
	

	if (lives>0)
	{
	UpDownmovement();
	fooddrawing();
	foodeating();
	hints();

	opponentcar();
	controlledcar();

	}
	else
	{
	
	startmenu=true;
	}
}
else if(level==2)
{
if (lives>0)
	{
	LeftRightmovement();
	
	fooddrawing();
	foodeating();
	hints();

	opponentcar();
	controlledcar();

	}
	else
	{
	
	startmenu=true;
	}
}
else if(level==3)
{
if (lives>0)
	{
	UpDownmovement();
	LeftRightmovement();
	fooddrawing();
	foodeating();
	hints();

	opponentcar();
	controlledcar();

	}
	else
	{
	
	startmenu=true;
	}
}
else if(level==4)
{
if (lives>0)
	{
	fooddrawing();
	foodeating();
	hints();

	opponentcar();
	controlledcar();

	}
	else
	{
	
	startmenu=true;
	}
}
	}

if(Score>=64 && Score<=128)
{
level=2;


}
else if(Score>=128 && Score<=192)
{
level=3;

}
else if(Score>=192)
{
level=4;

}


	glutSwapBuffers(); // do not modify this line.. or draw anything below this line
}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	//LEFT..........
	if (key == GLUT_KEY_LEFT && position1>=35 && position1<=755 && position2>=350 && position2<=430)
	{		if(position1==755)
			position1=665;
			else if(position1==665)
			position1=560;
			else if(position1==560)
			position1=460;
			else if(position1==340)
			position1=235;
			else if(position1==235)
			position1=145;
			else if(position1==145)
			position1=35;
	//RIGHT........
	}
	 else if (key == GLUT_KEY_RIGHT && position2>=360 && position2<=440 && position1>=35 && position1<=770 ) 
	{		if(position1==35)
			position1=145;
			else if(position1==145)
			position1=235;
			else if(position1==460)
			position1=560;
			else if(position1==235)
			position1=340;
			else if(position1==560)
			position1=665;
			else if(position1==665)
			position1=755;
	}
	//UP.........
	else if (key == GLUT_KEY_UP && position1 >= 335 && position1 <= 420 && position2>=50 && position2<=740) 
	{		if(position2==50)
			position2=140;
			else if(position2==140)
			position2=220;
			else if(position2==220)
			position2=305;
			else if(position2==455)
			position2=465;
			else if(position2==465)
			position2=560;
			else if(position2==560)
			position2=650;
			else if(position2==650)
			position2=740;
	}
	//DOWN.......
	else if (key == GLUT_KEY_DOWN && position1 >= 380 && position1 <= 450) 
	{
		 	if ( position2==740 )
			position2 = 650;
			else if(position2==650)
			position2 =560;
			else if(position2==560)
			position2=455;
			else if(position2==305)
			position2=220;
			else if(position2==455)
			position2=220;
			else if(position2==220)
			position2=140;
			else if(position2==140)
			position2=50;
	}
			 

	

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
int pausec = 1  ;
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27 /* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 'p' || key == 'P')
	{
	 pausec++;
		if (pausec % 2 == 0)
		pausehi = true;
		else pausehi = false ;
		cout << "p pressed" << endl;

	}
	if (key == '1' )
	startmenu = false;
	glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {


GameDisplay ();

	// implement your functionality here

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(10.0, Timer, 0);
glutPostRedisplay();
}


/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	//cout << x << " " << y << endl;
	//glutPostRedisplay();
}
void MouseMoved(int x, int y) {

	//glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON ) // dealing only with left button
			{

		if (startmenu)
		{
			if(x>=353 && x<=505 && y>=251 && y<=268)//start game
			{	lives=3;
				startmenu=false;
			}
			else if((y>=313 && y<=345) && (x>=354 && x<=501))//High score
			{
				
				Highscore();
			}
			else if(x>=352 && x<=402 && y>=391 && y<=409)
			{
				startmenu=false;
			}
		}
			
		cout << x << " " << y << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {
srand(time(NULL));
foodsaving();
	//b = new Board(60, 60); // create a new board object to use in the Display Function ...

	int width = 840, height = 950; // i have set my window size to be 800 x 600
	//b->InitalizeBoard(width, height);
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Dodge 'em by Fajr Naveed"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */
