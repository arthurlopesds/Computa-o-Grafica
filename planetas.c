#include <GL/glut.h>
#include <stdlib.h>

int rotateY = 0, rotateX = 0, rotateZ = 0, translatX= 0, translatY=0,translatZ=0;

void teclado(unsigned char tecla, int a, int b){
    switch(tecla){
        case 'a':
            rotateX += 10;
            break;
        case 's':
            rotateY += 10;
            break;
        case 'd':
            rotateZ += 10;
            break;
	case 'x':
            translatX += 10;
	    break;
	case 'y':
	    translatY += 10;
	    break;
	case 'z':
	    translatZ += 10;
	    break;
	
		
    }
    glutPostRedisplay();
}

void display(void)
{
    glDrawBuffer(GL_BACK);
    glClearColor(1.0,1.0,1.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-50.0,50.0,-50.0,50.0, 0, 100);
    glRotated(-20,1,0,0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glBegin(GL_LINES);
        glColor3d(0,1,0);
        glVertex3d(0,0,0);
        glVertex3d(80,0,0);
    glEnd();

    glBegin(GL_LINES);
        glColor3d(0,0,1);
        glVertex3d(0,0,0);
        glVertex3d(0,80,0);
    glEnd(); 

    /*glBegin(GL_LINES);
        glColor3d(0,0,1);
        glVertex3d(0,0,0);
        glVertex3d(0,0,80);
    glEnd();*/

    /*glRotated(rotateY,0,1,0);
    glRotated(rotateX,1,0,0);
    glRotated(rotateZ,0,0,1);*/
    
    //glTranslated(translatX,translatY,translatZ);
    glPushMatrix();
        glColor3d(1,1,0);
	
        glTranslated(0,30,0);
        glutSolidSphere(5.0,10,10);
    glPopMatrix();
    

    glRotated(rotateY,0,1,0);
    glRotated(rotateX,1,0,0);
    glRotated(rotateZ,0,0,1); 
    glTranslated(translatX,translatY,translatZ);
    glPushMatrix();
        glColor3d(0,0,1);
        glTranslated(30,30,0);
        glutSolidSphere(3.0,10,10);
    glPopMatrix();

    glutSwapBuffers();
}


int main(int argc, char *argv[])
{
    glutInit (&argc,argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(50,100);
	glutInitWindowSize(600,480);
	glutCreateWindow("Planetas");
	glutKeyboardFunc(teclado);
	glutDisplayFunc(display);
	glutMainLoop();

    return EXIT_SUCCESS;
}
