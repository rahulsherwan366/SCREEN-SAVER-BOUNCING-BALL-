#include <iostream>
#include <GL/glut.h>
#include <random>
using namespace std;

typedef uniform_real_distribution<> urd;

class balls{
private: float radius;	//radius of the ball
	 float *vel;   // velocity of balls in 3 coordinates
	 float *color; //color of the ball
	 float *cord; //coordinates of the ball 
public:
	balls();
	void velocity(float vty[][50],int flag , int i );
	void com(float cm[][50],int flag,int i);
	float ball_radius();
	void ball_color(float clr[][50],int flag, int i);
	void mass();
	void coordinate();
	};

extern float p,y;
	//extern int key;