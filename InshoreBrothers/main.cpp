#ifdef APPLE
#include<windows.h>
#include <GLUT/glut.h>
#else
#include<windows.h>
#include <GL/glut.h>
#endif-
#include<stdio.h>
#include <stdlib.h>
#include<math.h>
#define SCENE 10
GLfloat angle1 = 160.0;
GLfloat angle2 = 200.0;
GLfloat angle3 = 200.0; 

float m=0;
float mount=0;
float mm=500;
float flag=0;
float flag2=500;
int F=0;
float b2_speed=5;
float ba_posion=0;
int counter=0;
float scale_cloud;
void sceenario(void);
void cloud();
void circle(GLdouble rad);
void boat1();
void front_page();
void boat1_broken();
#define PI 3.1416
void drawLeftCircle() // the filled one
{
 /*-----------Head ------------*/
 glPushMatrix();
 glColor3f(1,0.7,0.3);
 glScalef(.5,.7,.5);
 glTranslatef(118+350,250,1);
 circle(20);//head
 glPopMatrix();
 glPushMatrix();
 glColor3f(0,0,0);
 glScalef(.5,.7,.5);
 glTranslatef(120+360,245,1);
 circle(4);//eye
 glPopMatrix();
 /*-----------shirt-----------*/
 glPushMatrix();
 glColor3f(0.7,0.3,0.5);
 glScalef(.5,.7,.5);
 glTranslatef(210+350,180,1);
 glRotatef(30,0,0,1);
 glBegin(GL_TRIANGLES);
 glVertex3f(-70,100,1); //upper point
 glVertex3f(-90,50,1);
 glVertex3f(-50,70,1); //man hand
 //glVertex3f(-50,90,1);
 glEnd();
 glPopMatrix(); 

 /*-----------Boat-----------------*/
 glPushMatrix();
 float radius = 100;
 float twoPI = 2 * PI;
 glColor3f(0.7,0.2,0);
 glScalef(.5,0.7,.5);
 glTranslatef(200+350,200,1);
 //glTranslatef(550,150,1);
 glRotatef(180,180,180,0);
 glBegin(GL_TRIANGLE_FAN);
 for (float i = PI; i <= twoPI; i += 0.001)
 glVertex2f((sin(i)*radius), (cos(i)*radius));
 glEnd();
 glPopMatrix();
 /*-----------stick-----------------*/
 glPushMatrix();
 glColor3f(0.6,0.2,0);
 glScalef(.5,.7,.5);
 glTranslatef(210+350,180,1);
 glRotatef(30,0,0,1);
 glLineWidth(10);
 glBegin(GL_LINES);
 glVertex2f(-50,70);
 glVertex2f(-60,-70);
 //glVertex2f(-15,90);
 glVertex2f(-35,65);
 glEnd();
 glPopMatrix();
}
void* fonts[] =
{
 GLUT_BITMAP_9_BY_15,
 GLUT_BITMAP_TIMES_ROMAN_10,
 GLUT_BITMAP_TIMES_ROMAN_24,
 GLUT_BITMAP_HELVETICA_12,
 GLUT_BITMAP_HELVETICA_10,
 GLUT_BITMAP_HELVETICA_18,
 GLUT_BITMAP_8_BY_13,
 GLUT_STROKE_ROMAN,
};
void output(int x, int y, const char* string, int j)
{
 int len, i;
 glColor3f(0.0f, 0.0f, 0.0f); 
 
 glRasterPos2f(x, y);
 len = (int)strlen(string);
 for (i = 0; i < len; i++)
 glutBitmapCharacter(fonts[j], string[i]);
}
void front_page()
{
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 glMatrixMode(GL_MODELVIEW);
 glPushMatrix();
 glClearColor(0.9f, 0.9f, 0.4f, 1.0f);
 output(200, 460, "SAHYADRI COLLEGE OF ENGINEERING AND
MANAGEMENT", 2);
 output(275, 440, "SUBJECT: COMPUTER GRAPHICS", 5);
 output(350, 420, "6C", 5);
 output(310, 390, "MINI PROJECT ON", 5);
 glColor3f(0.30, 1.00, 0.65);
 glBegin(GL_QUADS);
 //To create a highlight in the background
 glEnd();
 output(235, 350, "INSHORE RURAL REGATTA BROTHERS", 2);
 output(100, 200, "Guide:", 5);
 output(135, 180, "ABCD", 5);
 output(450, 200, "By:", 5);
 output(475, 180, "Name1", 5);
 output(475, 150, "Name 2", 5);
 glColor3f(0.80, 1.00, 0.65);
 glBegin(GL_QUADS);
 //To create a highlight in the background
 glVertex2f(300, 30.0);
 glVertex2f(400, 30.0);
 glVertex2f(400, 80.0);
 glVertex2f(300, 80.0);
 glEnd();
 output(305, 50, "->Press s to start", 2);
 glutPostRedisplay();
 glFlush();
 glCallList(SCENE);
 glPopMatrix();
 glutSwapBuffers();
 glPushMatrix();
 glTranslatef(0, 0, 0);
 glBegin(GL_POLYGON);
 glColor3f(.8,.89,1);
 glVertex2i(0,350); 
 
 glColor3f(.8,.89,1);
 glVertex2i(700,350);
 glColor3f(.2,.58,1);
 glVertex2i(700,500);
 glColor3f(.2,.58,1);
 glVertex2i(0,500);
 glEnd();
 glPopMatrix();
}
void drawstring(float x, float y, float z, char *string)
{
 char *ct;
 glRasterPos3f(x,y,z);
 for(ct=string; *ct!='\0'; ct++)
 {
 glColor3f(0.0, 0.0, 0.0);
 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *ct);
 }
}
void myInit(void)
{
 glColor3f(1.0f,0.0f,0.0f);
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}
 /**-------------------------------------Eye starts---------------------------
 glColor3f(.5,.5,.1);
 glPushMatrix();
 glScalef(.2,0.2,0.2);
 //glTranslatef(1000, 500, 0);
 glTranslatef(78, 300, 0);
 glBegin(GL_LINE_LOOP);
 glVertex2i(200, 350); 
 INSHORE REGATTA BROTHERS
DEPT OF CSE,SCEM MANGALURU 13
 glVertex2i(220, 345);
 glVertex2i(230, 360);
 glEnd();
 glPopMatrix();
 /-------------------------------------Eye ends---------------------------*/
void sceenario()
{
 /*River------------------*/
 glColor3f(0.3,0.7,1);
 glPushMatrix();
 glTranslatef(0, 0, 0);
 glBegin(GL_POLYGON);
 glVertex2i(0,20);
 glVertex2i(700,20);
 glVertex2i(700,300);
 glVertex2i(0,300);
 glEnd();
 glPopMatrix();
 /*--------grass2----------*/
 glColor3f(.5,1,0.5);
 glPushMatrix();
 glTranslatef(0, 0, 0);
 glBegin(GL_POLYGON);
 glVertex2i(0,20);
 glVertex2i(700,20);
 glVertex2i(700,0);
 glVertex2i(0,0);
 glEnd();
 glPopMatrix();
/*-----------Border river --------*/
 glColor3f(0.3,0.7,1);
 glPushMatrix();
 glTranslatef(0, 0, 0);
 glBegin(GL_POLYGON);
 glVertex2i(0,160);
 glVertex2i(700,160);
 glVertex2i(700,155);
 glVertex2i(0,155);
 glEnd();
 glPopMatrix();
 /*-------------tree---------------*/
 glColor3f(.1,0.2,0.1);
 glPushMatrix();
 glTranslatef(-m, 0, 0); 
 
 glBegin(GL_POLYGON);
 glVertex2i(72,300);
 glVertex2i(78,300);
 glVertex2i(78,405);
 glVertex2i(72,405);
 glEnd();
 glColor3f(.1,0.5,0.1);
 glBegin(GL_TRIANGLES);
 glVertex2i(75,450);
 glVertex2i(100,390);
 glVertex2i(50,390);
 glVertex2i(75,420);
 glVertex2i(100,360);
 glVertex2i(50,360);
 glVertex2i(75,400);
 glVertex2i(100,340);
 glVertex2i(50,340);
 glEnd();
 glPopMatrix();
 /*-------------tree2---------------*/
 glPushMatrix();
 glTranslatef(-m, 0, 0);
 glColor3f(.1,0.2,0.1);
 glTranslatef(250, 0, 0);
 glBegin(GL_POLYGON);
 glVertex2i(72,300);
 glVertex2i(78,300);
 glVertex2i(78,405);
 glVertex2i(72,405);
 glEnd();
 glColor3f(.1,0.5,0.1);
 glBegin(GL_POLYGON);
 glVertex2i(75,450);
 glVertex2i(100,390);
 glVertex2i(50,390);
 glEnd();
 glBegin(GL_POLYGON); 
 
 glVertex2i(75,420);
 glVertex2i(100,360);
 glVertex2i(50,360);
 glEnd();
 glBegin(GL_POLYGON);
 glVertex2i(75,400);
 glVertex2i(100,340);
 glVertex2i(50,340);
 glEnd();
 glPopMatrix();
 /*-------------tree3---------------*/
 glPushMatrix();
 glColor3f(.1,0.2,0.1);
 glTranslatef(150-m, 150, 0);
 glScalef(.5,.5,.5);
 glBegin(GL_POLYGON);
 glVertex2i(72,300);
 glVertex2i(78,300);
 glVertex2i(78,405);
 glVertex2i(72,405);
 glEnd();
 glColor3f(.1,0.5,0.1);
 glBegin(GL_POLYGON);
 glVertex2i(75,450);
 glVertex2i(100,390);
 glVertex2i(50,390);
 glEnd();
 glBegin(GL_POLYGON);
 glVertex2i(75,420);
 glVertex2i(100,360);
 glVertex2i(50,360);
 glEnd();
 glBegin(GL_POLYGON);
 glVertex2i(75,400);
 glVertex2i(100,340);
 glVertex2i(50,340);
 glEnd();
 glPopMatrix(); 

}
void mountain()
{
 /*----------Sky----*/
 glPushMatrix();
 glTranslatef(0, 0, 0);
 glBegin(GL_POLYGON);
 glColor3f(.8,.89,1);
 glVertex2i(0,350);
 glColor3f(.8,.89,1);
 glVertex2i(700,350);
 glColor3f(.2,.58,1);
 glVertex2i(700,500);
 glColor3f(.2,.58,1);
 glVertex2i(0,500);
 glEnd();
 glPopMatrix();
 /*----------Grass----*/
 glColor3f(.5,1,0.5);
 glPushMatrix();
 glTranslatef(0, 0, 0);
 glBegin(GL_POLYGON);
 glVertex2i(0,350);
 glVertex2i(700,350);
 glVertex2i(700,300);
 glVertex2i(0,300);
 glEnd();
 glPopMatrix();
 glPushMatrix();
 int k=1,i;
 for (i=0;i<10;i++){
 glTranslatef(+mount*k-600*i*.5, -10, 0);
 k=k*.05;
 cloud();
glColor3f(.2,.8,.2);
 glBegin(GL_TRIANGLES);
 glVertex2i(0,360);
 glVertex2i(50,400);
 glVertex2i(100,360);
 glVertex2i(80,350); 

 glVertex2i(200,450);
 glVertex2i(300,350);
 glVertex2i(280,360);
 glVertex2i(360,430);
 glVertex2i(450,360);
 glVertex2i(480,340);
 glVertex2i(560,430);
 glVertex2i(640,340);
 glEnd();
 }
 glPopMatrix();
}
void sceenario2()
{
 /*-------------tree---------------*/
 glColor3f(.1,0.2,0.1);
 glPushMatrix();
 glTranslatef(-mm, 0, 0);
 glBegin(GL_POLYGON);
 glVertex2i(72,300);
 glVertex2i(78,300);
 glVertex2i(78,405);
 glVertex2i(72,405);
 glEnd();
 glColor3f(.1,0.5,.1);
 glBegin(GL_POLYGON);
 glVertex2i(75,450);
 glVertex2i(100,390);
 glVertex2i(50,390);
 glEnd();
 glBegin(GL_POLYGON);
 glVertex2i(75,420);
 glVertex2i(100,360);
 glVertex2i(50,360);
 glEnd();
 glBegin(GL_POLYGON);
 glVertex2i(75,400);
 glVertex2i(100,340);
 glVertex2i(50,340); 
 
 glEnd();
 glPopMatrix();
 /*-------------tree2---------------*/
 glPushMatrix();
 glTranslatef(-mm, 0, 0);
 glColor3f(.1,0.2,.1);
 glTranslatef(250, 0, 0);
 glBegin(GL_POLYGON);
 glVertex2i(72,300);
 glVertex2i(78,300);
 glVertex2i(78,405);
 glVertex2i(72,405);
 glEnd();
 glColor3f(.1,0.5,.1);
 glBegin(GL_POLYGON);
 glVertex2i(75,450);
 glVertex2i(100,390);
 glVertex2i(50,390);
 glEnd();
 glBegin(GL_POLYGON);
 glVertex2i(75,420);
 glVertex2i(100,360);
 glVertex2i(50,360);
 glEnd();
 glBegin(GL_POLYGON);
 glVertex2i(75,400);
 glVertex2i(100,340);
 glVertex2i(50,340);
 glEnd();
 glPopMatrix();
 /*-------------tree3---------------*/
 glPushMatrix();
 glColor3f(.1,0.2,.1);
 glTranslatef(150-mm, 150, 0);
 glScalef(.5,.5,.5);
 glBegin(GL_POLYGON);
 glVertex2i(72,300); 
 INSHORE REGATTA BROTHERS
DEPT OF CSE,SCEM MANGALURU 19
 glVertex2i(78,300);
 glVertex2i(78,405);
 glVertex2i(72,405);
 glEnd();
 glColor3f(.1,0.5,0.1);
 glBegin(GL_POLYGON);
 glVertex2i(75,450);
 glVertex2i(100,390);
 glVertex2i(50,390);
 glEnd();
 glBegin(GL_POLYGON);
 glVertex2i(75,420);
 glVertex2i(100,360);
 glVertex2i(50,360);
 glEnd();
 glBegin(GL_POLYGON);
 glVertex2i(75,400);
 glVertex2i(100,340);
 glVertex2i(50,340);
 glEnd();
 glPopMatrix();
}
void my_control_func()
{
 counter++;
 if(counter>16800||counter<3800)
 {
 m=m;
 mm=mm;
 mount=mount;
 //boat1();
 }
 else{
 mount+=.2;
 if(flag>-800){
 m-=.2;
 flag-=.2;
 }
 else{ 
 INSHORE REGATTA BROTHERS
DEPT OF CSE,SCEM MANGALURU 20
 m=350;
 flag=700;
 F++;
 }
 if(flag2>-1200)
 {
 mm-=.2;
 flag2-=.2;
 }
 else
 {
 mm=350;
 flag2=700;
 }
 if (F==2)
 {
 b2_speed=10;
 }
 }
}
void starting()
{
 /*sinboard*/
 glColor3f(0.9,0,0);
 glPushMatrix();
 glTranslatef(200-m, 00, 0);
 glBegin(GL_POLYGON);
 glVertex2i(10,20);
 glVertex2i(40,20);
 glVertex2i(40,300);
 glVertex2i(10,300);
 glEnd();
 glPopMatrix();
}
void victory()
{
 /*Victory sinboard*/
 glColor3f(0.9,0,0);
 glPushMatrix();
 glTranslatef(300-m, 25, 0);
 glBegin(GL_POLYGON);
 glVertex2i(10,100); 
 INSHORE REGATTA BROTHERS
DEPT OF CSE,SCEM MANGALURU 21
 glVertex2i(40,50);
 glVertex2i(40,250);
 glVertex2i(10,300);
 glEnd();
 glPopMatrix();
 /*pole 1*/
 glColor3f(0.9,0,0);
 glPushMatrix();
 glTranslatef(300-m, 0, 0);
 glBegin(GL_POLYGON);
 glVertex2i(10,360);
 glVertex2i(50,290);
 glVertex2i(50,300);
 glVertex2i(10,370);
 glEnd();
 glPopMatrix();
 /*Pole 2*/
 glColor3f(0.9,0,0);
 glPushMatrix();
 glTranslatef(300-m, -270, 0);
 glBegin(GL_POLYGON);
 glVertex2i(10,360);
 glVertex2i(50,290);
 glVertex2i(50,300);
 glVertex2i(10,370);
 glEnd();
 glPopMatrix();
 /*Rope1*/
 glColor3f(0.9,0.2,0.1);
 glPushMatrix();
 glTranslatef(300-m, 0, 0);
 glBegin(GL_LINE_LOOP);
 glVertex2i(10,360);
 glVertex2i(10,325);
 glVertex2i(40,275);
 glVertex2i(50,290);
 glEnd();
 glPopMatrix();
 /* Rope 2 */
 glColor3f(0.9,0.2,0.1);
 glPushMatrix();
 glTranslatef(300-m, -260, 0);
 glBegin(GL_LINE_LOOP);
 glVertex2i(10,360);
 glVertex2i(10,385);
 glVertex2i(40,335);
 glVertex2i(50,290);
 glEnd(); 
 INSHORE REGATTA BROTHERS
DEPT OF CSE,SCEM MANGALURU 22
 glPopMatrix();
}
void texts()
{
 glColor3f(1.0, 1.0, 1.0);
 //glScalef(2,2,2);
 if(counter>400&& counter<800)
 drawstring(80, 280, 0.0, "Yo my bro!nervous for your first regatta??");//1
 if(counter>800&& counter<1200)
 drawstring(80, 280, 0.0, "should be.Afterall you're facing me.");//2
 if(counter>2400&& counter<2800)
 drawstring(80, 280, 0.0, "Ha ha ha..your brother has never lost regatta.");//6
 if(counter>3200&& counter<3600)
 drawstring(130, 280, 0.0, "lets see YOU or ME");//8
 if(counter>1200&& counter<1600)
 drawstring(100, 195, 0.0, "Hey brother!I have done my side of practice.");//3
 if(counter>1600&& counter<2000)
 drawstring(100, 195, 0.0, "Seems like you're overconfident.");//4
 glColor3f(1.0, 1.0, 1.0);
 if(counter>2000&& counter<2400)
 drawstring(90, 190, 0.0,"lets wait for the regatta to begin.");//5
 if(counter>2800&& counter<3200)
 drawstring(80, 195, 0.0, "I know you are too good at it. Lets see!!");//7
 if (counter>17300){
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(.8,0.9,1);
 glPushMatrix();
 glTranslatef(0, 0, 0);
 glBegin(GL_POLYGON);
 glVertex2i(0,0);
 glVertex2i(700,0);
 glVertex2i(700,1350);
 glVertex2i(0,1350);
 glEnd();
 glPopMatrix();
 glColor3f(0.0, 0.0, 1);
 drawstring(270, 335, 0.0, "++++++++++++++++");
 glColor3f(0.0, 0.0, 1);
 drawstring(270, 350, 0.0, "+ Moral of this story +");
 glColor3f(0.0, 0.0, 1);
 drawstring(270, 365, 0.0, "++++++++++++++++"); 
 INSHORE REGATTA BROTHERS
DEPT OF CSE,SCEM MANGALURU 23
 glColor3f(0.0, 0.0, 1);
 drawstring(90, 315, 0.0,
"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++");
 glColor3f(0.0, 0.0, 1);
 drawstring(90, 300, 0.0, "+ Confidence is based on evidence and doing the work.
Arrogance is based on wishful thinking and talking about the work +");
 glColor3f(0.0, 0.0, 1);
 drawstring(90, 285, 0.0,
"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++");
 glColor3f(1.0, 0, 1);
 drawstring(340, 100, 0.0, "PRESENTED BY:");
 glColor3f(1.0, 0, 1);
 drawstring(340, 80, 0.0, "VINUTA S.BADAMI - 4SF18CS182 ");
 glColor3f(1.0, 0, 1);
 drawstring(340, 60, 0.0, "DIVYA N - 4SF18CS040");
 glColor3f(1.0, 0, 1);
 drawstring(340, 40, 0.0, "DEPARTMENT: CSE");
 glColor3f(1.0, 0, 1);
 drawstring(340, 20, 0.0, "SAHYADRI COLLEGE OF ENGINEERING AND
MANAGEMENT");
 }
}
void display()
{
 glClear(GL_COLOR_BUFFER_BIT);
 mountain();
 sceenario();
 sceenario2();
 if(F==0){
 starting();
 //boat2();
 boat1();
 }
 //boat1();
 if(F==1){
 // boat1_broken();
 boat1_broken();
 }
 drawLeftCircle(); 
 INSHORE REGATTA BROTHERS
DEPT OF CSE,SCEM MANGALURU 24
 if(F==2){
 // boat2();
 boat1();
 victory();
 ba_posion=1500;
 }
 texts();
 //boat1();
 glFlush();
 glutPostRedisplay();
 my_control_func();
//front page
 glClearColor(0.0, 0.0, 0.0, 0.0);
 glClear(GL_COLOR_BUFFER_BIT);
 glClearColor(1.0, 1.0, 1.0, 1.0);
 glFlush();
 glutSwapBuffers();
}
void key(unsigned char key, int x, int y)
{
 switch (key) {
 case 'S':
 case 's':glutDisplayFunc(display);
 break;
 glutPostRedisplay();
}
}
int main(int argc, char **argv)
{
 glutInit(&argc , argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize(1350,700);
 glutCreateWindow("INSHORE RURAL REGATTA BROTHERS");
glutKeyboardFunc(key);
 glutDisplayFunc(front_page);
 myInit();
 glutMainLoop();
} 
 INSHORE REGATTA BROTHERS
DEPT OF CSE,SCEM MANGALURU 25
void cloud(){
 float scale_cloud=.3;
 int trns_x=-1000;
 int trns_y=1150;
 glColor3f(0.8,.9,1);
 /*-----------------Cloud 1---------------*/
glPushMatrix(); // tree leaves
 //glColor3f(0,.5,0);
 glScalef(scale_cloud,scale_cloud,scale_cloud);
 glTranslatef(250+trns_x,360+trns_y,0);
 circle(60);
glPopMatrix();
glPushMatrix();
 //glColor3f(0,.5,0);
 glScalef(scale_cloud,scale_cloud,scale_cloud);
 glTranslatef(260+trns_x,400+trns_y,0);
 circle(60);
glPopMatrix();
glPushMatrix();
 glScalef(scale_cloud,scale_cloud,scale_cloud);
 glTranslatef(300+trns_x,370+trns_y,0);
 circle(50);
glPopMatrix();
glPushMatrix();
 glScalef(scale_cloud,scale_cloud,scale_cloud);
 //glColor3f(0,.5,0);
 glTranslatef(330+trns_x,450+trns_y,0);
 circle(50);
glPopMatrix();
 glPushMatrix();
 glScalef(scale_cloud,scale_cloud,scale_cloud);
 //glColor3f(0,.5,0);
 glTranslatef(350+trns_x,350+trns_y,0);
 circle(40);
glPopMatrix();
 glPushMatrix();
 glScalef(scale_cloud,scale_cloud,scale_cloud);
 //glColor3f(0,.5,0); 
 INSHORE REGATTA BROTHERS
DEPT OF CSE,SCEM MANGALURU 26
 glTranslatef(365+trns_x,400+trns_y,0);
 circle(40);
glPopMatrix();
glPushMatrix();
 glScalef(scale_cloud,scale_cloud,scale_cloud);
 //glColor3f(0,.5,0);
 glTranslatef(370+trns_x,430+trns_y,0);
 circle(40);
glPopMatrix();
 glPushMatrix();
 glScalef(scale_cloud,scale_cloud,scale_cloud);
 //glColor3f(0,.5,0);
 glTranslatef(390+trns_x,350+trns_y,0);
 circle(40);
glPopMatrix();
 glPushMatrix();
 glScalef(scale_cloud,scale_cloud,scale_cloud);
 //glColor3f(0,.5,0);
 glTranslatef(390+trns_x,400+trns_y,0);
 circle(40);
 glPopMatrix();
/*-----------------Cloud 2---------------*/
trns_x=-500;
glPushMatrix(); // tree leaves
 //glColor3f(0,.5,0);
 glScalef(scale_cloud,scale_cloud,scale_cloud);
 glTranslatef(250+trns_x,360+trns_y,0);
 circle(60);
glPopMatrix();
glPushMatrix();
 //glColor3f(0,.5,0);
 glScalef(scale_cloud,scale_cloud,scale_cloud);
 glTranslatef(260+trns_x,400+trns_y,0);
 circle(60);
glPopMatrix();
glPushMatrix();
 glScalef(scale_cloud,scale_cloud,scale_cloud);
 glTranslatef(300+trns_x,370+trns_y,0); 
 INSHORE REGATTA BROTHERS
DEPT OF CSE,SCEM MANGALURU 27
 circle(50);
glPopMatrix();
glPushMatrix();
 glScalef(scale_cloud,scale_cloud,scale_cloud);
 //glColor3f(0,.5,0);
 glTranslatef(330+trns_x,450+trns_y,0);
 circle(50);
glPopMatrix();
 glPushMatrix();
 glScalef(scale_cloud,scale_cloud,scale_cloud);
 //glColor3f(0,.5,0);
 glTranslatef(350+trns_x,350+trns_y,0);
 circle(40);
glPopMatrix();
 glPushMatrix();
 glScalef(scale_cloud,scale_cloud,scale_cloud);
 //glColor3f(0,.5,0);
 glTranslatef(365+trns_x,400+trns_y,0);
 circle(40);
glPopMatrix();
glPushMatrix();
 glScalef(scale_cloud,scale_cloud,scale_cloud);
 //glColor3f(0,.5,0);
 glTranslatef(370+trns_x,430+trns_y,0);
 circle(40);
glPopMatrix();
 glPushMatrix();
 glScalef(scale_cloud,scale_cloud,scale_cloud);
 //glColor3f(0,.5,0);
 glTranslatef(390+trns_x,350+trns_y,0);
 circle(40);
glPopMatrix();
 glPushMatrix();
 glScalef(scale_cloud,scale_cloud,scale_cloud);
 //glColor3f(0,.5,0);
 glTranslatef(390+trns_x,400+trns_y,0);
 circle(40);
 glPopMatrix();
/*-----------------Cloud 3---------------*/ 
 INSHORE REGATTA BROTHERS
DEPT OF CSE,SCEM MANGALURU 28
trns_x=-1200;
glPushMatrix(); // tree leaves
 //glColor3f(0,.5,0);
 glScalef(scale_cloud,scale_cloud,scale_cloud);
 glTranslatef(250+trns_x,360+trns_y,0);
 circle(60);
glPopMatrix();
glPushMatrix();
 //glColor3f(0,.5,0);
 glScalef(scale_cloud,scale_cloud,scale_cloud);
 glTranslatef(260+trns_x,400+trns_y,0);
 circle(60);
glPopMatrix();
glPushMatrix();
 glScalef(scale_cloud,scale_cloud,scale_cloud);
 glTranslatef(300+trns_x,370+trns_y,0);
 circle(50);
glPopMatrix();
glPushMatrix();
 glScalef(scale_cloud,scale_cloud,scale_cloud);
 //glColor3f(0,.5,0);
 glTranslatef(330+trns_x,450+trns_y,0);
 circle(50);
glPopMatrix();
 glPushMatrix();
 glScalef(scale_cloud,scale_cloud,scale_cloud);
 //glColor3f(0,.5,0);
 glTranslatef(350+trns_x,350+trns_y,0);
 circle(40);
glPopMatrix();
 glPushMatrix();
 glScalef(scale_cloud,scale_cloud,scale_cloud);
 //glColor3f(0,.5,0);
 glTranslatef(365+trns_x,400+trns_y,0);
 circle(40);
glPopMatrix();
glPushMatrix();
 glScalef(scale_cloud,scale_cloud,scale_cloud); 
 INSHORE REGATTA BROTHERS
DEPT OF CSE,SCEM MANGALURU 29
 //glColor3f(0,.5,0);
 glTranslatef(370+trns_x,430+trns_y,0);
 circle(40);
glPopMatrix();
 glPushMatrix();
 glScalef(scale_cloud,scale_cloud,scale_cloud);
 //glColor3f(0,.5,0);
 glTranslatef(390+trns_x,350+trns_y,0);
 circle(40);
glPopMatrix();
 glPushMatrix();
 glScalef(scale_cloud,scale_cloud,scale_cloud);
 //glColor3f(0,.5,0);
 glTranslatef(390+trns_x,400+trns_y,0);
 circle(40);
 glPopMatrix();
}
int i;
void circle(GLdouble rad)
{
 GLint points = 50;
 GLdouble delTheta = (2.0 * PI) / (GLdouble)points;
 GLdouble theta = 0.0;
 glBegin(GL_POLYGON);
 {
 for( i = 0; i <=50; i++, theta += delTheta )
 {
 glVertex2f(rad * cos(theta),rad * sin(theta));
 }
 }
 glEnd();
}
void boat1()
{
 /*-----------Head------------*/
 glPushMatrix();
 glColor3f(1,0.9,0.5);
 glScalef(.5,.7,.5);
 glTranslatef(110+360+2*m,245+130,1);
 circle(20);
 glPopMatrix(); 
 INSHORE REGATTA BROTHERS
DEPT OF CSE,SCEM MANGALURU 30
 glPushMatrix();
 glColor3f(0,0,0);
 glScalef(.5,.7,.5);
 glTranslatef(150+327+2*m,269+100,1);
 circle(4);
 glPopMatrix();
 /*-----------shirt-----------*/
 glPushMatrix();
 glColor3f(0.9,1,0.1);
 glScalef(.5,.7,.5);
 glTranslatef(210+360+2*m,200+100,1);
 glRotatef(30,0,0,1);
 glBegin(GL_TRIANGLES);
 glVertex3f(-70,100,1); //upper point
 glVertex3f(-90,50,1);
 glVertex3f(-50,70,1); //man hand
 glEnd();
 glPopMatrix();
 /*-----------Boat-----------------*/
 glPushMatrix();
 float radius = 100;
 float twoPI = 2 * PI;
 glColor3f(0.7,0.3,0);
 glScalef(.5,0.7,.5);
 glTranslatef(300+200+2*m,120+200,1);
 //glTranslatef(550,150,1);
 glRotatef(180,180,180,0);
 glBegin(GL_TRIANGLE_FAN);
 for (float i = PI; i <= twoPI; i += 0.001)
 glVertex2f((sin(i)*radius), (cos(i)*radius));
 glEnd();
 glPopMatrix();
 /*-----------stick-----------------*/
 glPushMatrix();
 glColor3f(0.6,0.2,0);
 glScalef(.5,.7,.5);
 glTranslatef(310+260+2*m,100+200,1);
 glRotatef(30,0,0,1);
 glLineWidth(10);
 glBegin(GL_LINES);
 glVertex2f(-50,70);
 glVertex2f(-60,-70);
 //glVertex2f(-15,90);
 glVertex2f(-35,65); 
 INSHORE REGATTA BROTHERS
DEPT OF CSE,SCEM MANGALURU 31
 glEnd();
 glPopMatrix();
 /*-------------------------------------Eye starts---------------------------
 glColor3f(0.7,0.3,0.5);
 glPushMatrix();
 glScalef(.2,0.2,0.2);
 glTranslatef(300+260+2*m,100+200,1);
 glBegin(GL_LINE_LOOP);
 glVertex2i(200, 350);
 glVertex2i(220, 345);
 glVertex2i(230, 360);
 glEnd();
 glPopMatrix();
 /-------------------------------------Eye ends---------------------------*/
}
void boat1_broken()
{
 /*-----------Head------------*/
 glPushMatrix();
 glColor3f(1,0,0);
 glScalef(.5,.5,1);
 glTranslatef(110+60-2*m,640,1);
 circle(20);
 glPopMatrix();
 glPushMatrix();
 glColor3f(0,0,0);
 glScalef(.5,.5,1);
 glTranslatef(110+50-2*m,630,1);
 circle(2);
 glPopMatrix();
 /*-----------shirt-----------*/
 glPushMatrix();
 glColor3f(0.9,1,0.1);
 glScalef(.5,.5,1);
 glTranslatef(200-2*m,620,1);
 glRotatef(20,0,0,1);
 glBegin(GL_TRIANGLES);
 glVertex3f(50-m,420,1);
 glVertex3f(100-m,500,1);
 glVertex3f(130-m,500,1); 
 INSHORE REGATTA BROTHERS
DEPT OF CSE,SCEM MANGALURU 32
 glEnd();
 glPopMatrix();
 /*-----------Boat-----------------*/
 glPushMatrix();
 float radius = 70;
 float twoPI = 2 * PI;
 glColor3f(0.7,0.3,0);
 glScalef(.5,0.7,.5);
 glTranslatef(200-2*m,440,1);
 glRotatef(180,180,180,0);
 glBegin(GL_TRIANGLE_FAN);
 for (float i = PI; i <= twoPI; i += 0.001)
 glVertex2f((sin(i)*radius), (cos(i)*radius));
 glEnd();
 glPopMatrix();
 glPushMatrix();
 glColor3f(0.3,0.7,1);
 glScalef(.5,.7,.5);
 glTranslatef(200-2*m,390,1);
 circle(5);
 glPopMatrix();
 /*-----------stick-----------------*/
 glPushMatrix();
 glColor3f(0.6,0.2,0);
 glScalef(.5,.7,.5);
 glTranslatef(200-2*m,440,1);
 glRotatef(30,0,0,1);
 glLineWidth(10);
 glBegin(GL_LINES);
 glVertex2f(-50,65);
 glVertex2f(-60,-65);
 glVertex2f(-35,65);
 glEnd();
 glPopMatrix();
 glPushMatrix();
 glColor3f(0,0,0);
 glTranslatef(-m,0,1);
 drawstring(55, 340, 0.0, "He is getting ahead.");
 drawstring(45, 360, 0.0, "I have to fix this one.");
 drawstring(35, 380 , 0.0, "Oh no!! there is a hole in my boat!");
 glPopMatrix(); 
