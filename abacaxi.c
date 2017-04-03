#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

int x = 0;
int e = 0;

void display(){
//	if(!x){
		glClearColor(1.0, 1.0, 1.0, 0.0);
		glClear(GL_COLOR_BUFFER_BIT);		
//	}	
	

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(-50.0, 50.0, -50.0, 50.0, 0.1, 50);
	glFrustum(-50.0, 50.0, -50.0, 50.0, 0.1, 50);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslated(0, 0, -20);

	glRotated(-20, 1, 0, 0);
	glRotated(-20, 0, 1, 0);

	glColor3d(1, 0,0);
	glBegin(GL_LINES);
		glVertex3d(0, 0, 0);
		glVertex3d(20, 0, 0);
	glEnd();
	glColor3d(0, 1,0);
	glBegin(GL_LINES);
		glVertex3d(0, 0, 0);
		glVertex3d(0, 20, 0);
	glEnd();
	glColor3d(0, 0,1);
	glBegin(GL_LINES);
		glVertex3d(0, 0, 0);
		glVertex3d(0, 0, 20);
	glEnd();

	glTranslated(e, 0, 0);
	glRotated(x, 1, 0, 0);
	
	/*glBegin(GL_LINE_LOOP);
		glVertex3d(0, 0, -5);
		glVertex3d(0, 0, 5);
		glVertex3d(5, 0, 5);
		glVertex3d(5, 0, -5);
	glEnd();
	glPopMatrix();*/
	glutWireTeapot(10.0f);

	glFlush();
}


void TECLADO(unsigned char tecla, int x1, int y1){
	switch(tecla){
		case 'a':
			x+=10;
			break;
		
		case 'q':
			exit(1);
			break;
	}
		
	glutPostRedisplay();
}

void ESPECIAL(int tecla, int xx, int yy){
	switch(tecla){
		case GLUT_KEY_LEFT:
			e+=2;
			break;
		case GLUT_KEY_RIGHT:
			e-=2;
			break;
	}
	glutPostRedisplay();
}

int main(int argc, char **argv){
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
		glutInitWindowSize(500, 500);
		glutCreateWindow("Alo!");
		glutKeyboardFunc(TECLADO);
		glutSpecialFunc(ESPECIAL);
		glutDisplayFunc(display);
		glutMainLoop();
}
