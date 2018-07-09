#include <windows.h>
#include <gl/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>

void myInit(void){
	gluOrtho2D(0.0, 900.0, 700.0, 0.0);
	glColor3i(0,0,0);
	glClearColor(0.529, 0.808, 0.980,0);
}

void bgGrass(){
	glColor3f(0.196, 0.804, 0.196);
	glRecti(0,300,900,700);
}

void sun(){
	int i;
	int x = 300;
	int y = 100;
	int triangleAmount = 20;
	GLfloat radius = 50.0f;
	GLfloat twicePi = 2.0f * 3.14;
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(1,1,0);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) { 
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)), 
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
}

void mountain(){
	glBegin(GL_TRIANGLES);
		glColor3f(0.420, 0.557, 0.137);
		glVertex2i(0,300);
		glVertex2i(300,300);
		glVertex2i(150,100);
		glColor3f(0.333, 0.420, 0.184);
		glVertex2i(250,300);
		glVertex2i(600,300);
		glVertex2i(425,100);
		
		glVertex2i(600,300);
		glVertex2i(900,300);
		glVertex2i(750,100);
	glEnd();
}

void house(int x, int y){
	int dimensionX = 120;
	int dimensionY = 80;
	int roofHeight = 40;
	int windowDim = 20;
	glColor3f(0.722, 0.525, 0.043);
	// house
	glRecti(x,y, x + dimensionX, y + dimensionY);
	// roof
	glBegin(GL_TRIANGLES);
		glColor3f(0.412, 0.412, 0.412);
		glVertex2i(x,y);
		glVertex2i(x + dimensionX, y);
		glVertex2i(x + (dimensionX/2), y - roofHeight);
	glEnd();
	// windows
	glColor3f(1,1,1);
	glRecti(x + 10, y + 30, x + 10 + windowDim, y + 30 + windowDim);
	glRecti(x + dimensionX - 10 - windowDim, y + 30, x + dimensionX - 10, y + 30 + windowDim);
	// door
	glRecti(x + (dimensionX/2) - (windowDim/2), y + (dimensionY/2), x + (dimensionX/2) + (windowDim/2), y + dimensionY);
}

void road(){
	glColor3f(0.663, 0.663, 0.663);
	glRecti(0,460,900,530);
	int stripSize = 30;
	int stripCnt = 22;
	int i, x = 0, y = 495;
	glColor3f(1,1,1);
	for(i=0;i<stripCnt;i++){
		glRecti(x + 10, y - 3, x + 10 + stripSize, y + 3);
		x = x + stripSize + 10;
	}
}

void tree(int x, int y){
	int height = 50;
	glColor3f(0.502, 0.502, 0.000);
	glBegin(GL_TRIANGLES);
		glVertex2i(x, y);
		glVertex2i(x - 15, y + height);
		glVertex2i(x + 15, y + height);
	glEnd();
	int i;
	int x1 = x, y1 = y - 10;
	int triangleAmount = 20;
	GLfloat radius = 18.0f;
	GLfloat twicePi = 2.0f * 3.14;
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.000, 0.392, 0.000);
		glVertex2f(x1, y1);
		for(i = 0; i <= triangleAmount;i++) { 
			glVertex2f(
		            x1 + (radius * cos(i *  twicePi / triangleAmount)), 
			    y1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
}

void river(){
	glColor3f(0.529, 0.808, 0.980);
	glRecti(0,580,900,700);
	GLubyte wave[] = {
						0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      					0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      					0x00, 0x80, 0x01, 0x00, 0x00, 0xC0, 0x03, 0x00, 
      					0x00, 0x60, 0x06, 0x00, 0x00, 0x30, 0x0C, 0x00, 
      					0x00, 0x18, 0x18, 0x00, 0x00, 0x0C, 0x30, 0x00,
      					0x00, 0x06, 0x60, 0x00, 0x00, 0x03, 0xC0, 0x00,
      					0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  
      					0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      					0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      					0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      					0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      					0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      					0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      					0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      					0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      					0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    				};
	glColor3f(0.255, 0.412, 0.882);
	glEnable (GL_POLYGON_STIPPLE);
	glPolygonStipple (wave);
	glRecti(1,581,899,699);
	glDisable (GL_POLYGON_STIPPLE);
}

void myDisplay(){
	glClear(GL_COLOR_BUFFER_BIT);
	bgGrass();
	mountain();
	sun();
	road();
	river();
	house(50,350);
	tree(200,380);
	house(230,350);
	tree(380,380);
	tree(420,380);
	tree(460,380);
	house(730,350);
	tree(700,380);
	house(550,350);
	tree(520,380);
	glFlush();
}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(900,700);
	glutCreateWindow("Homework 1 Village");
	glutDisplayFunc(myDisplay);
	
	myInit();
	glutMainLoop();
	return 0;
}

