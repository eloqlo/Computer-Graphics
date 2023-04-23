#include <stdio.h>
#include <gl/glut.h>
#include <gl/glu.h>
#include <gl/gl.h>

#define FIRST_LETTER_POSITION -32
#define SECOND_LETTER_POSITION 0
#define THIRD_LETTER_POSITION +31


BOOLEAN					reset = false;
BOOLEAN					token_x = false;
BOOLEAN					token_y = false;
BOOLEAN					token_z = false;
BOOLEAN					token_1 = false;
BOOLEAN					token_2 = false;
BOOLEAN					token_2_spd = false;
BOOLEAN					token_3 = false;
BOOLEAN					token_3_spd = false;
float					angle_x = 0.0f;
float					angle_y = 0.0f;
float					angle_z = 0.0f;
float					angle_1 = 0.0f; 
float					angle_2 = 0.0f;	
float					speed_3 = 0.0f;	


void Initialize(void)
{
	glEnable(GL_DEPTH_TEST);
	//Background Color Setting
	glClearColor(0.9f, 0.9, 0.9, 1.0f);
}

void drawSimpleCube() {
	glColor3f(0.3, 1.0, 0.5);
	glutWireCube(1);
	glColor3f(0.1, 0.8, 0.3);
	glutSolidCube(1);
}

void drawFullLetter(GLfloat x, GLfloat y, GLfloat z, GLfloat scale);	//overload above display()
void SecondTransformation(int n, int m);								//overload above display()


void drawFirstLetter_1() {
	//Draw 'し'
	glPushMatrix();
	glTranslatef(- 9, 0, 0);
	glScalef(1, 1.4, 1);
	glColor3f(0.3, 1.0, 0.5);
	glutWireTorus(2.7, 6, 20, 20);
	glColor3f(0.1, 0.8, 0.3);
	glutSolidTorus(2.7, 6, 20, 20);
	glPopMatrix();
}
void drawFirstLetter_2() {
	//Draw 'び'
	glPushMatrix();
	glTranslatef(+ 5, 0, 0);
	glScalef(4.5, 30, 5);
	drawSimpleCube();
	glPopMatrix();
}
void drawFirstLetter() {
	glPushMatrix();
	glTranslatef(FIRST_LETTER_POSITION, 0, 0);	//basic movement
	if (token_1) { glRotatef(angle_1, 3, 2, 5); }//1
	if (token_2) { SecondTransformation(50,2); }	//2 : back and forth rotation
	drawFirstLetter_1();
	drawFirstLetter_2();
	glPopMatrix();
}

void drawSecondLetter_1() {
	//draw "じ"
	glPushMatrix();
	glTranslatef(- 10.5, 10, 0);
	glScalef(16, 5, 5);
	drawSimpleCube();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(- 10.5, -2, 0);
	glRotatef(60, 0, 0, 1);
	glScalef(24, 4.6, 5);
	drawSimpleCube();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(- 7, -7, 0);
	glRotatef(132, 0, 0, 1);
	glScalef(12, 5, 5);
	drawSimpleCube();
	glPopMatrix();
}
void drawSecondLetter_2() {
	//draw "だ"
	glPushMatrix();
	glTranslatef(+ 3, 0, 0);
	glScalef(4.5, 30, 5);
	drawSimpleCube();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(+ 6.6, 0, 0);
	glScalef(2.7, 4, 5);
	drawSimpleCube();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(+ 10.3, 0, 0);
	glScalef(4.5, 30, 5);
	drawSimpleCube();
	glPopMatrix();
}
void drawSecondLetter() {
	glPushMatrix();
	glTranslatef(SECOND_LETTER_POSITION, 0, 0);	//basic movement
	if (token_1) { glRotatef(angle_1, 0.8, 0.4, 0.1); }//1
	if (token_2) { SecondTransformation(10,4); }	//2
	drawSecondLetter_1();
	drawSecondLetter_2();
	glPopMatrix();
}

void drawThirdLetter_1() {
	//draw "ぞ"
	glPushMatrix();
	glTranslatef(- 4, 13.5, 0);
	glScalef(10, 3.7, 5);
	drawSimpleCube();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(- 4, 8.7, 0);
	glScalef(14, 3.7, 5);
	drawSimpleCube();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(- 4, 1.6, 0);
	glScalef(1.4, 1, 1);
	glColor3f(0.3, 1.0, 0.5);
	glutWireTorus(1.6, 3, 20, 20);
	glColor3f(0.1, 0.8, 0.3);
	glutSolidTorus(1.6, 3, 20, 20);
	glPopMatrix();
}
void drawThirdLetter_2() {
	//draw "づ"
	glPushMatrix();
	glTranslatef(9.5, 5, 0);
	glScalef(3.6, 20, 5);
	drawSimpleCube();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(6.5, 0, 0);
	glScalef(3.8, 3.8, 5);
	drawSimpleCube();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(6.5, 5, 0);
	glScalef(3.8, 3.8, 5);
	drawSimpleCube();
	glPopMatrix();

}
void drawThirdLetter_3() {
	//draw "し"
	glPushMatrix();
	glTranslatef(1, -10, 0);
	glScalef(1.8, 1, 1);
	glColor3f(0.3, 1.0, 0.5);
	glutWireTorus(1.8, 4, 20, 20);
	glColor3f(0.1, 0.8, 0.3);
	glutSolidTorus(1.8, 4, 20, 20);
	glPopMatrix();
}
void drawThirdLetter() {
	glPushMatrix();
	glTranslatef(THIRD_LETTER_POSITION, 0, 0);	//basic movement
	if (token_1) { glRotatef(angle_1, 0.1, 0.2, 0.4); }//1
	if (token_2) { SecondTransformation(-50,2); }	//2
	drawThirdLetter_1();
	drawThirdLetter_2();
	drawThirdLetter_3();
	glPopMatrix();
}

void drawFullLetter(GLfloat x, GLfloat y, GLfloat z,GLfloat scale) {
	glPushMatrix();
	glTranslatef(x, y, z);
	glScalef(scale, scale, scale);
	drawFirstLetter();
	drawSecondLetter();
	drawThirdLetter();
	glPopMatrix();
}

//2: letter movement -> Translation, Rotation
void SecondTransformation(int n, int m) {
	glTranslatef(0, 0, (angle_2 - 100) / m);//m : make differences in velocity
	glRotatef(angle_2 + n, 0, 1, 0);	//n : gives different rotating visual
}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	//scene buffer clear
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity(); //Transformation matrix initialize
	glTranslatef(0, 0, -100);	//gives camera depth
	
	if (reset) { reset = false; }	//reset toggle
	if (token_x) { glRotatef(angle_x, 1, 0, 0); }	//x : x-axis rotation
	if (token_y) { glRotatef(angle_y, 0, 1, 0); }	//y : y-axis rotation
	if (token_z) { glRotatef(angle_z, 0, 0, 1); }	//z : z-axis rotation
	if (token_1) { glRotatef(angle_1, 1, 0, 0); }	//1 : arbitrary rotation + x-axis rotation
	if (token_3) { glTranslatef(0, 0, -speed_3); }		//3 : moving letters
	
	//default letter
	drawFirstLetter();
	drawSecondLetter();
	drawThirdLetter();
	
	if (token_3)	//3 : making number of letters
	{ 
	glTranslatef(0, 0, 70);
		drawFullLetter(60, 20, -200, 0.6); drawFullLetter(-74, 0, -100, 0.3);
		drawFullLetter(-57, 15, -160, 0.4); drawFullLetter(73, -5, -50, 0.5);
		drawFullLetter(18, 10, -210, 0.9); drawFullLetter(-72, -15, 0, 0.8);
		drawFullLetter(30, 25, -50, 0.8); drawFullLetter(-81, -20, -150, 1.1);
		drawFullLetter(22, 20, -10, 1.6); drawFullLetter(-49, 20, -20, 0.8); 
		drawFullLetter(-27, 15, 0, 0.1); drawFullLetter(38, -10, -100, 1.2); 
		drawFullLetter(-52, 10, -20, 0.5); drawFullLetter(-67, 29, 0, 0.2); 
		drawFullLetter(-19, 10, -100, 0.6); drawFullLetter(14, -30, -190, 0.8); 
	}

	glutSwapBuffers();
}

void Reshape(int w, int h)
{
	glViewport(0, 0, w, h);    // w: is width, h: is height
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, (float)w / h, 0.1, 500); // define view frustum
}

void Keyboard(unsigned char key, int x, int y)
{

	switch (key)
	{
	case 'q'://press"q" for exit program
		exit(0);
		break;
	case 'r'://press"r" for reset
		reset = true;
		angle_x = 0;
		angle_y = 0;
		angle_z = 0;
		angle_1 = 0;
		angle_2 = 0;
		speed_3 = 0;

		token_x = false;
		token_y = false;
		token_z = false;
		token_1 = false;
		token_2 = false;
		token_3 = false;
		token_2_spd = false;
		token_3_spd = false;

		glutPostRedisplay();
		break;
	case 'x': //press"x" for x-axis rotation
		token_x = true;
		angle_x += 5;
		glutPostRedisplay();
		break;
	case 'y': //press"x" for x-axis rotation
		token_y = true;
		angle_y += 5;
		glutPostRedisplay();
		break;
	case 'z': //press"x" for x-axis rotation
		token_z = true;
		angle_z += 5;
		glutPostRedisplay();
		break;
	case '1': //press"1" for Arbitrary axis rotation
		token_1 = true;
		angle_1 += 5;
		glutPostRedisplay();
		break;
	case '2':
		token_2 = true;
		//soft angle speed control
		if (!token_2_spd) {
			if (angle_2 < 20) { angle_2 += 1; }
			if (angle_2 >= 20 && angle_2 < 50) { angle_2 += 3; }
			if (angle_2 >= 50 && angle_2 < 180) { angle_2 += 6; }
			if (angle_2 >= 180 && angle_2 < 280) { angle_2 += 5; }
			if (angle_2 >= 280 && angle_2 < 330) { angle_2 += 3; }
			if (angle_2 >= 330 && angle_2 <= 360) { angle_2 += 1.5; }
			if (angle_2 > 360) { token_2_spd = !token_2_spd; }
		}
		//reverse the speed incresment
		if (token_2_spd) {
			if (angle_2 < 0) { token_2_spd = !token_2_spd; }
			if (angle_2 < 20) { angle_2 -= 1; }
			if (angle_2 >= 20 && angle_2 < 50) { angle_2 -= 3; }
			if (angle_2 >= 50 && angle_2 < 180) { angle_2 -= 6; }
			if (angle_2 >= 180 && angle_2 < 280) { angle_2 -= 5; }
			if (angle_2 >= 280 && angle_2 < 330) { angle_2 -= 3; }
			if (angle_2 >= 330) { angle_2 -= 1.5; }
		}
		glutPostRedisplay();
		break;
	case '3':
		token_3 = true;
		//dynamic speed control
		if (!token_3_spd) {
			if (speed_3 < 20) { speed_3 += 2; }
			if (speed_3 >= 20 && speed_3 < 50) { speed_3 += 4; }
			if (speed_3 >= 50 && speed_3 < 80) { speed_3 += 6; }
			if (speed_3 >= 80 && speed_3 < 120) { speed_3 += 7; }
			if (speed_3 > 120) { token_3_spd = true; }
		}
		//inverse process
		if (token_3_spd) {
			if (speed_3 < 0) { token_3_spd = false; }
			if (speed_3 >= 0  && speed_3 < 20) { speed_3 -= 2; }
			if (speed_3 >= 20 && speed_3 < 50) { speed_3 -= 4; }
			if (speed_3 >= 50 && speed_3 < 80) { speed_3 -= 6; }
			if (speed_3 >= 80) { speed_3 -= 7; }
		}
		glutPostRedisplay();
		break;
	}
}


int main(int argc, char* argv[]) {

	//Window generation
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);//double buffer -> faster
	glutInitWindowPosition(100, 100); //Window position
	glutInitWindowSize(1400, 800); //Window size
	glutCreateWindow("NAME"); //Window name

	//Initialize function
	Initialize();
	//callback function 
	glutDisplayFunc(display);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(Keyboard);
	glutSwapBuffers();

	glutMainLoop();

	return 0;
}