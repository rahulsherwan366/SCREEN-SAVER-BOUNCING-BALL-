#include <iostream>
#include <GL/glut.h>
#include <pthread.h>
#include <math.h>
#include <unistd.h>


#include "balls.h"
#include "physics.h"
#include "display.h"
using namespace std;




float z=-5.0;
float q=0;
float x=0;
pthread_mutex_t lock;
balls b[frequency];
display d;
float cm[3][50];
float veli[3][50];
int flag=0;
int flag1=0;

float u=0.0;
int f=0;


void draw()
{    
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
     glLoadIdentity();
     for(int j=0;j<frequency;j++){      
      b[j].mass(); 
      }
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
glTranslatef(0.0,-1.0,-3.5);
        glPushMatrix();
        glColor4f(1.0,0.0,1.0,1.0);
        glutSolidSphere(0.5,100,100);
        glPopMatrix();   
      glClearColor(1.0,1.0,1.0,0.5);
      if(f==0)
     {glDisable(GL_FOG);}
      if(f==1)
        {  glClearColor(0.0,0.0,0.0,0.5);
          glEnable(GL_FOG);
        GLfloat fogColor[] = {0.5f, 0.5f, 0.5f, 1}; 
  glFogfv(GL_FOG_COLOR, fogColor);
  glFogi(GL_FOG_MODE, GL_LINEAR);
  glFogf(GL_FOG_START, 0.0f);
  glFogf(GL_FOG_END, 20.0f);}
    
        
        d.cube();

if(flag==0)
      z+=0.01;
    if(flag==1)
      z-=0.01;
    if(z>-1.0)
      flag=1;
    if(z< -5.0)
      flag=0;
    
if(flag1==0)
      x+=0.1;
    if(flag1==1)
      x-=0.1;
    if(x>194.0)
      flag1=1;
    if(x< -200.0)
      flag1=0;
      


     
   	glutSwapBuffers();

}



void reshape(int w, int h)
{
    glViewport(0,0,w,h);
  	glMatrixMode(GL_PROJECTION);
	  glLoadIdentity();
	  gluPerspective(45.0,(float)w/ (float)h,1.0, 400.0);
	  glMatrixMode(GL_MODELVIEW);
}



void *prh(void *arg){
  
  long i= (long) arg;
  
  b[i].com(cm,0,i);
  b[i].velocity(veli,0,i); 
  while(true){ 
  usleep(2000);
  pthread_mutex_lock(&lock);  
    if(i<14){
    for(int k=i+1;k<frequency;k++){
      double dis;
      dis=(( (cm[0][k]-cm[0][i])*(cm[0][k]-cm[0][i]) ) +  ( (cm[1][k]-cm[1][i])*(cm[1][k]-cm[1][i]) ) + ( (cm[2][k]-cm[2][i])*(cm[2][k]-cm[2][i]) )   ); 
    
     float r1=b[i].ball_radius();
     float r2=b[k].ball_radius();
      if(dis<=(4*r1*r2))
     {   
       
         
         float step=0.001;
     
                 
          
             overlap(cm,i,k,r1,r2);
              b[k].com(cm,1,k); 
              b[i].com(cm,1,i);   
        
           
         ball_collision(cm,veli,cm,veli,i,k);

         b[i].velocity(veli,1,i);
              
         b[k].velocity(veli,1,k);
    


    }
  }
  
 
}
 float cmj[3]={0.0,-1.0,-3.5};
  float vel[3]={0.0,0.0,0.0};
  float dist=(( (cmj[0]-cm[0][i])*(cmj[0]-cm[0][i]) ) +  ( (cmj[1]-cm[1][i])*(cmj[1]-cm[1][i]) ) + ( (cmj[2]-cm[2][i])*(cmj[2]-cm[2][i]) )   ); 
    if(dist<=(4*0.5*0.2)){
  overlap_static_terrain(cm,i,cmj,0.2,0.5);
  col2 (cm,veli,cmj,vel,i);
         b[i].velocity(veli,1,i);}
 pthread_mutex_unlock(&lock);
  
     cm[0][i]+=veli[0][i];
     if(cm[0][i]>0.8)
    {
       cm[0][i]=0.8;
      veli[0][i]=-veli[0][i];
    
    }

     if(cm[0][i]<-0.8)
    {
       cm[0][i]=-0.8;
       veli[0][i]=abs(veli[0][i]);
    
    }


     cm[1][i]+=veli[1][i];
     if(cm[1][i]>0.8)
    {
       cm[1][i]=0.8;
       veli[1][i]=-veli[1][i];
    }

     if(cm[1][i]<-0.8)
    {
       cm[1][i]=-0.8;
       veli[1][i]=abs(veli[1][i]);
    }

   
     cm[2][i]+=veli[2][i];
     if(cm[2][i]>-1.2)
    {
       cm[2][i]=-1.2;
       veli[2][i]=-veli[2][i];
    }
    
     if(cm[2][i]<-5.8)
    {
       cm[2][i]=-5.8;
       veli[2][i]=abs(veli[2][i]);
    }
    b[i].velocity(veli,1,i);  
    b[i].com(cm,1,i); 
    
  }
  
}



void initialize()
{
    glClearColor(1.0,1.0,1.0,1.0);
    glEnable(GL_DEPTH_TEST );
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);     
    glEnable(GL_FOG);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    

}


void keyboard(unsigned char key,int x,int y)
{
  switch(key){
       case 'j' :{ w+=0.1;
                  if(w>0.0)
                    w=1.0;
                  break;}
        case 'l' : {w-=0.1;
                  if(w<0.0)
                    w=0.0;
                  break;}
       
        case 'i' : { p+=0.1;
                    if(p>1.0)
                      p=1.0;
                   break;}
          case 'k' :{p-=0.1;
                      if(p<0.0)
                        p=0.0;
                   break;}           
         case 'w' :{  q=2;                    
                   break;} 
          case 's' :{  q=3;                    
                   break;} 
         case 'd' :{
                        q=1;                    
                   break;}   
         case 'g' :{ f=0;                                                    
                   break;}

          case 'h' :{ f=1;                                                    
                   break;}         
           case 'a' :{ 
                     q=0;             
                                       
                   break;}  
             case 'q' :{ 
                     exit(0);             
                                       
                   break;}
                                            
        default: 
               break;
      }


}


int main(int argc,char **argv)
{    
     pthread_t id1;
     long j;
     glutInit(&argc,argv);
     glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_STENCIL );
     glutInitWindowPosition(0,0);
     glutInitWindowSize(1280,720);
     glutCreateWindow("screensaver");
     

     initialize();
    
     

     for(j=0;j<frequency;j++){
      pthread_create(&id1,NULL,prh,(void *)j);   
     }
     

     glutDisplayFunc(draw);
     glutIdleFunc(draw);
     glutReshapeFunc(reshape);
     glutKeyboardFunc(keyboard);
   
    
     glutMainLoop();
 
    return 0;
}