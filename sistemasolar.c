
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

int xa = 0;//rotação
int ys = 0;
int zd = 0;
int e = 0;//firar para a esquerda
int i = 0;
int w = 0;

void planetas(){
	glColor3f(1,0,0);
	glTranslated(0,0,10);
	glutSolidSphere(4,15,15);
	glColor3f(1,0.5,0);
	glTranslated(0,10,0);
	glutSolidSphere(1,15,15);
	glColor3f(1,0,1);
	glTranslated(15,3,0);
	glutSolidSphere(2,15,15);
	glColor3f(1,0.5,1);
	glTranslated(-40,18,0);
	glutSolidSphere(2,15,15);
	glColor3f(1,0,0.5);
	glTranslated(-4,-40,0);
	glutSolidSphere(3,15,15);
}
void eixos(){
	glBegin(GL_LINES);
	glColor3f(1,0,0);
	glVertex3f(0,0,0);
	glVertex3f(20,0,0);
	glColor3f(0,1,0);
	glVertex3f(0,0,0);
	glVertex3f(0,20,0);
	glColor3f(0,0,1);
	glVertex3f(0,0,0);
	glVertex3f(0,0,20);
	glEnd();
}

void TECLADO(unsigned char tecla , int xx, int y){
	switch(tecla){
		case 'a':
			xa+=10;
			glutPostRedisplay();	
			break;
		case 's':
			ys+=10;
			glutPostRedisplay();	
			break;
		case 'd':
			zd+=10;
			glutPostRedisplay();	
			break;

	        case 'e':
			glEnable(GL_DEPTH_TEST);
			glutPostRedisplay();
			break;
		case 'r':
			glDisable(GL_DEPTH_TEST);
			glutPostRedisplay();			
			break;
		
	}
	
}

void ESPECIAL(int tecla,int xx , int yy){
	switch(tecla){
		case GLUT_KEY_LEFT: e-=2;
				glutPostRedisplay();
				break; 
		case GLUT_KEY_RIGHT: e+=2;
				glutPostRedisplay();
				break;
		case GLUT_KEY_UP : i+=2;
				glutPostRedisplay();
				break;
		case GLUT_KEY_DOWN : i-=2;
				glutPostRedisplay();
				break;
	}
}

void desenhacirculo(GLint x, GLint y, GLint z, GLint raio, int num_linhas){
	float angulo;
	int i;
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);
		for (i = 0; i < num_linhas; ++i)
		{
			angulo = i*2*M_PI/num_linhas;
			glVertex3f(x+(cos(angulo)*raio),y+(sin(angulo)*raio),z);
		}
	glEnd();

}
void Desenha(){
	glClearColor(1.0,1.0,1.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    

	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-100.0,100.0,-100.0,100.0,0.1,200.0);
	//glFrustum(-50.0,50.0,-50.0,50.0,0.1,50.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
    
    glTranslated(0,0,-80);
	glRotated(170,1,0,0);
	eixos();

	//glTranslated(0,0,0);
	//glRotated(20,1,0,0);
	
	
	glTranslated(e,i,0);
	glRotated(xa,1,0,0);
	glRotated(zd,0,1,0);
	glRotated(ys,0,0,1);
	desenhacirculo(0,0,10,10,30);
	desenhacirculo(0,0,10,20,30);
	desenhacirculo(0,0,10,30,30);
	desenhacirculo(0,0,10,40,30);
	planetas();	

	glFlush();
}

int main(int argc,char** argv)
{
	glutInit (&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(100,300); 
	glutInitWindowSize(800,800);
	glutCreateWindow("Visualizacao 3D");
	glutDisplayFunc(Desenha);
    //glutReshapeFunc(AlteraTamanhoJanela);
	//glutMouseFunc(GerenciaMouse);
	glutKeyboardFunc(TECLADO);
	glutSpecialFunc(ESPECIAL);
	//Inicializa();
	glutMainLoop();

return 0;
}
