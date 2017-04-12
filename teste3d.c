#include <GL/glut.h>
#include <stdio.h>
#include <math.h>


GLuint eixos;

int x = 0;
int e = 0;



void desenhaeixos(){


	glBegin(GL_LINES);
		glColor3d(1,0,0);		
		glVertex3d(0, 0, 0);
		glVertex3d(50, 0, 0);
		
		glColor3d(0,1,0);
		glVertex3d(0, 0, 0);
		glVertex3d(0, 50, 0);

		glColor3d(0,0,1);
		glVertex3d(0, 0, 0);
		glVertex3d(0, 0, 50);

	glEnd();

}





void init(){
glClearColor(0.0,0.0,0.0,1.0);

eixos = glGenLists(1);  //gera indice da lista
glNewList(eixos,GL_COMPILE); //cria a lista
	glPushMatrix();
	desenhaeixos();
	glPopMatrix();
glEndList();


}


void ABACAXI()

{
//glClearColor(0.0,0.0,0.0,1.0);
glClear(GL_COLOR_BUFFER_BIT);

//viewport 1

glViewport(0,0,500,500);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-50.0,50.0,-50.0,50.0,0.1,100);

glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glTranslated(0,0,-30);
glRotated(-30,0,1,0);
glCallList(eixos);
glColor3d(1,1,1);
glutWireCube(5);


//viewport 2
glViewport(501,0,1,500);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,50.0,0.0,50.0);

glMatrixMode(GL_MODELVIEW);
glLoadIdentity();

glBegin(GL_LINES);

	glColor3d(1,1,1); //BRANCO
	glVertex2d(0,0);
	glVertex2d(0,50);

glEnd();


//viewport3
glViewport(502,0,500,500);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glFrustum(-1.0,1.0,-1.0,1.0,0.1,100);

glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glTranslated(e,0,-5); //0,0,-5
glRotated(x,0,1,0); //-30,0,1,0
glCallList(eixos);
glColor3d(1,1,1);
glutWireCube(5);




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
		glutInitWindowSize(1000, 500);
		glutCreateWindow("Alo!");
		init();
		glutDisplayFunc(ABACAXI);
		glutKeyboardFunc(TECLADO);
		glutMainLoop();
}
