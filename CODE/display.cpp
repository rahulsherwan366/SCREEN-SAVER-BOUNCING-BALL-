#include "display.h"
#include"main.h"

//char key;
float w=0.5 ;
void display::cube(){

     moving_terrain();
	   glEnable(GL_BLEND);   

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

  
     glColor4f(1.0,1.0,0.0,w);
        glBegin(GL_QUADS);
        glNormal3f(0, 1, 0);
        glVertex3f(-1.0,-1.0,-1.0);
        glVertex3f(1.0,-1.0,-1.0);
        glVertex3f(1.0,-1.0,-6.0);
        glVertex3f(-1.0,-1.0,-6.0);
        glEnd();
        

     glColor4f(1.0,0.0,0.0,w);
        glBegin(GL_QUADS);
        glNormal3f(0, 1, 0);
        glVertex3f(-1.0,-1.0,-0.9);
        glVertex3f(-1.0,-1.0,-6.0);
        glVertex3f(-1.0,1.0,-6.0);
        glVertex3f(-1.0,1.0,-0.9);
        glEnd();

   
        
    glColor4f(1.0,0.0,0.0,w);
        glBegin(GL_QUADS);
        glNormal3f(0, 1, 0);
        glVertex3f(1.0,-1.0,-0.9);
        glVertex3f(1.0,-1.0,-6.0);
        glVertex3f(1.0,1.0,-6.0);
        glVertex3f(1.0,1.0,-0.9);
        glEnd();
       
   glColor4f(1.0,1.0,1.0,w);
        glBegin(GL_QUADS);
        glNormal3f(0, 1, 0);
        glVertex3f(-1.0,1.0,-1.0);
        glVertex3f(1.0,1.0,-1.0);
        glVertex3f(1.0,1.0,-6.0);
        glVertex3f(-1.0,1.0,-6.0);
        glEnd();

glColor4f(0.0,0.0,1.0,w);
        glBegin(GL_QUADS);
        glNormal3f(0, 1, 0);
        glVertex3f(-1.0,-1.0,-6.0);
        glVertex3f(-1.0,1.0,-6.0);
        glVertex3f(1.0,1.0,-6.0);
        glVertex3f(1.0,-1.0,-6.0);
 glEnd();
        

glColor4f(0.0,0.0,1.0,w);
        glBegin(GL_QUADS);
        glNormal3f(0, 1, 0);
        glVertex3f(-1.0,-1.0,-0.9);
        glVertex3f(-1.0,1.0,-0.9);
        glVertex3f(1.0,1.0,-0.9);
        glVertex3f(1.0,-1.0,-0.9);
 glEnd();


      
        glDisable(GL_BLEND);   
}


void display :: moving_terrain(){
     glEnable(GL_BLEND);   
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
  
     glTranslatef(0.0,0.0,x);
      glColor4f(0.0,1.0,0.0,1.0);
        glBegin(GL_QUADS);
        glNormal3f(0, 1, 0);
        glVertex3f(-200.0,-1.1,200.0);
        glVertex3f(-200.0,-1.1,-200.0);
        glVertex3f(200.0,-1.1,-200.0);
        glVertex3f(200.0,-1.1,200.0);
        glEnd();

       glColor4f(0.5,0.5,0.5,0.5);
        glBegin(GL_QUADS);
        glNormal3f(0, 1, 0);
        glVertex3f(-2.0,-1.01,200.0);
        glVertex3f(-2.0,-1.01,-200.0);
        glVertex3f(2.0,-1.01,-200.0);
        glVertex3f(2.0,-1.01,200.0);
        glEnd();

        glColor4f(0.5,0.5,0.5,0.5);
        glBegin(GL_QUADS);
        glNormal3f(0, 1, 0);
        glVertex3f(-2.0,1.1,200.0);
        glVertex3f(-2.0,1.1,-200.0);
        glVertex3f(2.0,1.1,-200.0);
        glVertex3f(2.0,1.1,200.0);
        glEnd();
        float y=-190.0;


        for(int i=0;i<40;i++){
       glColor4f(1.0,1.0,0.0,1.0);
        glBegin(GL_TRIANGLES);
        glNormal3f(0, 1, 0);
        glVertex3f(-6.0,2.9,0.0+y);
        glVertex3f(-4.0,-1.1,-4.0+y);
        glVertex3f(-4.0,-1.1,4.0+y);

         glColor4f(1.0,0.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glNormal3f(0, 1, 0);
        glVertex3f(-6.0,2.9,0.0+y);
        glVertex3f(-8.0,-1.1,4.0+y);
        glVertex3f(-4.0,-1.1,4.0+y); 


         glColor4f(0.0,1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glNormal3f(0, 1, 0);
        glVertex3f(-6.0,2.9,0.0+y);
        glVertex3f(-8.0,-1.1,-4.0+y);
        glVertex3f(-4.0,-1.1,-4.0+y);

          glColor4f(0.0,1.0,0.0,1.0);
        glBegin(GL_TRIANGLES);
        glNormal3f(0, 1, 0);
        glVertex3f(-6.0,2.9,0.0+y);
        glVertex3f(-8.0,-1.1,4.0+y);
        glVertex3f(-8.0,-1.1,-4.0+y);    
          y +=9.0;
        glEnd();}


}