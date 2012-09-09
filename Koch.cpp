#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>
#define PI 3.14159265
void drawLine(){
  glBegin(GL_LINES); 
    glVertex2f(0.5,0);
    glVertex2f(-0.5,0);
  glEnd();
}
void drawTriangleManual(){
  drawLine();
  glPushMatrix();
    glTranslatef(0.5,0,0);
    glRotatef(-60,0,0,1);
    glTranslatef(-0.5,0,0);
    drawLine();
  glPopMatrix();
  glPushMatrix();
    glTranslatef(-0.5,0,0);
    glRotatef(60,0,0,1);
    glTranslatef(0.5,0,0);
    drawLine();
  glPopMatrix();

}
void drawEqTriangle(float offsetx,float offsety,float factor,float blue){
  glBegin(GL_POLYGON);
    glColor3f(0,0,blue);
    glTranslatef(offsetx,offsety,0);
    glVertex2f(offsetx-factor*sin(60*PI/180),offsety -factor*cos(60*PI/180));
    glColor3f(1.0,1.0,blue);
    glVertex2f(offsetx+factor*sin(60*PI/180),offsety -factor*cos(60*PI/180));
    glColor3f(0,blue*.8,0.5);
    glVertex2f(offsetx,offsety+factor);
  glEnd();
}
void drawKoch(int n,float rad){
  if(n==0){
    return;
  }
  drawEqTriangle(0,0,rad,1-1/(1.0*n)*0.5);
  glPushMatrix();
    glTranslatef(-2*rad*cos(30*PI/180)/3,-2*rad*sin(30*PI/180)/3,0);
    drawKoch(n-1,rad/3);
  glPopMatrix();
  glPushMatrix();
    glTranslatef(2*rad*cos(30*PI/180)/3,-2*rad*sin(30*PI/180)/3,0);
    drawKoch(n-1,rad/3);
  glPopMatrix();
  glPushMatrix();
    glTranslatef(0,2*rad/3,0);
    drawKoch(n-1,rad/3);
  glPopMatrix();
  glRotatef(180,0,0,1);
  drawEqTriangle(0,0,rad,1-1/(1.0*n)*0.5);
  glPushMatrix();
    glTranslatef(-2*rad*cos(30*PI/180)/3,-2*rad*sin(30*PI/180)/3,0);
    drawKoch(n-1,rad/3);
  glPopMatrix();
  glPushMatrix();
    glTranslatef(2*rad*cos(30*PI/180)/3,-2*rad*sin(30*PI/180)/3,0);    
    drawKoch(n-1,rad/3);
  glPopMatrix();
  glPushMatrix();
    glTranslatef(0,2*rad/3,0);
    drawKoch(n-1,rad/3);
  glPopMatrix();
}
void myDisplay(){
    //glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(0,0,0,1);

    glLoadIdentity();
    drawKoch(7,0.5);
    glFlush();
}

int main(int argc, char* args[] )
{
    glutInit(&argc,args);
    glutInitWindowSize (600, 600);
    glutCreateWindow("bla");
    
    glutDisplayFunc(myDisplay);
    glutMainLoop();
}