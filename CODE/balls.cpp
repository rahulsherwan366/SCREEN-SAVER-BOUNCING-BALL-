 #include <GL/glut.h>
 #include <cstdlib>
 #include <iostream>
 #include <random>
 #include <math.h>
 #include "balls.h"
#include  "main.h"

 using namespace std; 


float p=1.0,y;

 balls::balls()
{

		

	vel=new float[3];
	cord=new float[3];
	color=new float[3];	
	
	srand ( time(NULL) );
	int r = rand()%16000 - 8000;
    double random_num0 = r/10000.0;
    int p = rand()%16000 - 8000;
    double random_num1 = p/10000.0;

	
	vel[0]=(float)5000900/RAND_MAX;
	vel[1]=(float)5000900/RAND_MAX;
	vel[2]=(float)5000900/RAND_MAX;
	

	mt19937 generator((random_device())());
    uniform_real_distribution<double> distribution(-1.0,1.0);

    cord[0]=distribution(generator);
    cord[1]=distribution(generator);
    cord[2]=-(abs(distribution(generator)*4.5));
    

    color[0]= abs(distribution(generator));
	color[1]=abs(distribution(generator));
	color[2]=abs(distribution(generator));
		radius=0.2;
  	

	
}



void balls::velocity(float vty[][50],int flag,int i)
{
	if(flag==1)  //for updating data members
	{
		vel[0]=vty[0][i];
		vel[1]=vty[1][i];
		//vel[2]=vty[2][i];
		vel[2]=vty[2][i];
	}

	if(flag==0) //for providing data members
	{
		vty[0][i]=vel[0];
		vty[1][i]=vel[1];
		vty[2][i]=vel[2];
	}
}



void balls::com(float cm[][50],int flag,int i)
{
	if(flag==1)
	{
		cord[0]=cm[0][i];
		cord[1]=cm[1][i];
		cord[2]=cm[2][i];
	}

	if(flag==0)
	{
		cm[0][i]=cord[0];
		cm[1][i]=cord[1];
		cm[2][i]=cord[2];
	}
}


float balls::ball_radius(){
	return radius;
}
void balls::ball_color(float clr[][50],int flag,int i)
{
	if(flag==1)
	{
		color[0]=clr[0][i];
		color[1]=clr[1][i];
		color[2]=clr[2][i];
	}

	if(flag==0)
	{
		clr[0][i]=color[0];
		clr[1][i]=color[1];
		clr[2][i]=color[2];
	}
}



void balls::mass()
{//	float x;

    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };//open source lighting effect in ball
   GLfloat mat_shininess[] = { 50.0 };
   GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_SMOOTH);

   glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
   glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
   glLightfv(GL_LIGHT0, GL_POSITION, light_position);

   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
   glEnable(GL_DEPTH_TEST);
  
	
	glPushMatrix();
	  glLoadIdentity();
     glMatrixMode(GL_MODELVIEW);
  
             if(q==0){
 gluLookAt(0.0, 0.0, 0.0,  
    0.0, 0.0, -4.0,     
    0.0, 1.0, 0.0);}
if(q==1)
 {gluLookAt(5.0, 0.0, z, 
    0.0, 0.0, z,    
    0.0, 1.0, 0.0);}
if(q==2)
 {gluLookAt(-18.0,0.0,0.0,  
    0.0, 0.0, z,    
    0.0, 1.0, 0.0);}
 if(q==3)
 {gluLookAt(10.0,0.0,10.0,  
    0.0, 0.0, 0.0,     
    0.0, 1.0, 0.0);} 
 

	glTranslatef(cord[0],cord[1],cord[2]);
    glScalef(1, -1, 1);
	glEnable(GL_BLEND);
	glColor4f(color[0],color[1],color[2],p);
    glutSolidSphere(radius,25,25);
    glDisable(GL_BLEND);
    glPopMatrix();
  
	
}



void balls::coordinate()
{
	
    cout<< cord[0]<<" "<<cord[1]<<" "<<cord[2]<<endl;
}

