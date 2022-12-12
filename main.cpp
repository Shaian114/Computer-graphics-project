#include<windows.h>
#include<GL\glut.h>
#include <GL/glu.h>
#include<math.h>
#include <stdlib.h>
#include<stdio.h>
#define PI 3.1416

GLint i, j, k;
GLfloat sun_spin=0, sun_x=0, sun_y=0;
GLfloat ax=0,bx=0,cx=0,dx=0,str=500.0,mn=500.0;
GLfloat sr=0.0,sg=0.749,sb=1.0;
GLfloat spin = 0.0;

void init(void)
{
	glClearColor(0.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 1000.0, 0.0, 500.0);
}


/* Circle_Model*/
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

/*Cloud_Model*/

void cloud_model()
{
    glColor3f(1.25, 0.924, 0.930);

    ///Left_Part
    glPushMatrix();
    glTranslatef(305,205,0);
    circle(10);
    glPopMatrix();

    ///Top

    glPushMatrix();
    glTranslatef(320,210,0);
    circle(15);
    glPopMatrix();

    ///Right_Part
    glPushMatrix();
    glTranslatef(334,207,0);
    circle(10);
    glPopMatrix();

    ///Bottom_Part
    glPushMatrix();
    glTranslatef(320,207,0);
    circle(10);
    glPopMatrix();

}

/* Hill_Model*/
void hill_model()
{
    ///Hill
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.41, 0.36);
	glVertex2i(70, 70);
	glVertex2i(200, 225);
	glVertex2i(330, 70);

	glEnd();

	///Hill_Snow
    glBegin(GL_POLYGON);
    glColor3f(1.25, 0.924, 0.930);

	glVertex2i(200, 225);
	glVertex2i(230, 190);
	glVertex2i(220, 180);
	glVertex2i(200, 190);
	glVertex2i(190, 180);
	glVertex2i(170, 190);

	glEnd();

}

/* Tilla_Model */
void Tilla_Model()
{
	glBegin(GL_POLYGON);
	glColor3f(0.1, 1.293, 0.0);
	glVertex2i(125, 70);
	glVertex2i(150, 80);
	glVertex2i(160, 90);
	glVertex2i(170, 90);
	glVertex2i(180, 100);
	glVertex2i(190, 105);
	glVertex2i(200, 108);
	glVertex2i(300, 110);
	glVertex2i(300, 70);

	glEnd();

}

/* House_Model */
void house()
{
    ///House_Roof
	glBegin(GL_POLYGON);
    glColor3f(0.1, 0.0, 0.0);
	glVertex2i(285, 105);
	glVertex2i(285, 130);
	glVertex2i(380, 115);
	glVertex2i(380, 105);

	glEnd();

    ///House_Roof_Shadow
	glBegin(GL_POLYGON);
    glColor3f(0.1, 0.1, 0.1);
	glVertex2i(285, 105);
	glVertex2i(285, 120);
	glVertex2i(380, 105);
	glVertex2i(380, 105);

	glEnd();

    ///House_Fence
	glBegin(GL_POLYGON);
    glColor3f(1.0, 0.5, 0.0);
	glVertex2i(290, 70);
	glVertex2i(290, 104);
	glVertex2i(375, 104);
	glVertex2i(375, 70);

	glEnd();

    ///House_Door
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.41, 0.36);
	glVertex2i(330, 70);
	glVertex2i(330, 100);
	glVertex2i(350, 100);
	glVertex2i(350, 70);

	glEnd();

    ///House_Window1
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2i(295, 75);
	glVertex2i(295, 90);
	glVertex2i(310, 90);
	glVertex2i(310, 75);

	glEnd();


    ///House_Window2
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2i(355, 75);
	glVertex2i(355, 90);
	glVertex2i(370, 90);
	glVertex2i(370, 75);

	glEnd();

}
/* Field_Model */
void field()
{
    ///Field
	glBegin(GL_POLYGON);
    glColor3f(0.5, 1.5, 0.0);
	glVertex2i(0, 50);
	glVertex2i(0, 70);
	glVertex2i(1000, 70);
	glVertex2i(1000, 50);

	glEnd();


  ///Field_Shadow
	glBegin(GL_POLYGON);
	glColor3f(0., 1.0, 0.0);
	glVertex2i(0, 0);
	glVertex2i(0, 50);
	glVertex2i(1000, 50);
	glVertex2i(1000, 0);

	glEnd();

}
/* Tree_Model */
void Tree_Model()
{
    glPushMatrix();
    glTranslatef(110,110,0);
    circle(15);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(110,100,0);
    circle(15);
    glPopMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2f(109, 70);
	glVertex2f(109, 90);
	glVertex2f(111, 90);
	glVertex2f(111, 70);

    glEnd();

}

/* Windmill_Stand_Model */
void Windmill_Stand_Model()
{

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(375, 100);
    glVertex2i(380, 240);
    glVertex2i(384, 240);
    glVertex2i(390, 100);
    glEnd();
}

/* Windmill_Blades_Model */

void Windmill_Blade()
{

    ///Blade_One
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(-5, 0);
    glVertex2i(-85, -36);
    glVertex2i(-83, -37);
    glVertex2i(-3, -8);
    glEnd();
    glPopMatrix();

    ///Blade_Two
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(0, 5);
    glVertex2i(45, 70);
    glVertex2i(50, 73);
    glVertex2i(5, 0);
    glEnd();
    glPopMatrix();

    ///Blade_Three
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(68, -78);
    glVertex2i(0,0);
    glVertex2i(5, 5);
    glVertex2i(70, -77);
    glEnd();
    glPopMatrix();

}
/* Windmill_Final_Model */
void Windmill()
{
        ///Windmill_Stand
    glColor3f(0.0, 0.0, 0.0);
    glPushMatrix();
    Windmill_Stand_Model();
    glPopMatrix();

    ///Windmill_Motor
    glColor3f(0.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(380,250,0);
    circle(10);
    glPopMatrix();

    ///Windmill_Rotary_Blades
    glColor3f(0.0, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(380,251,0);
    Windmill_Blade();
    glPopMatrix();

}
///Model_End


///***   Object  ***///

/* Cloud_one */

void cloud_one()
{
    glPushMatrix();
    glTranslatef(bx+100,150,0);
    cloud_model();
    glPopMatrix();

}

/* Cloud_Two */

void cloud_two()
{
    glPushMatrix();
    glTranslatef(ax-80,80,0);
    cloud_model();
    glPopMatrix();

}
/* Cloud_Three */

void cloud_three()
{
    glPushMatrix();
    glTranslatef(dx+300,125,0);
    cloud_model();
    glPopMatrix();

}
/* Cloud_Four*/
void cloud_four()
{
    glPushMatrix();
    glTranslatef(ax+-300,170,0);
    cloud_model();
    glPopMatrix();
}

/* House_One */
void house_one()
{
    glPushMatrix();
    glTranslatef(0,0,0);
    house();
    glPopMatrix();
}
/* House_Two */
void house_two()
{
    glPushMatrix();
    glTranslatef(450,0,0);
    house();
    glPopMatrix();
}
/* House_Three */
void house_three()
{
    glPushMatrix();
    glTranslatef(320, 37,0);
    house();
    glPopMatrix();
}
/* Hill_One */
void Hill_One()
{
    glPushMatrix();
    glTranslatef(0,0,0);
    hill_model();
    glPopMatrix();
}
/* Hill_Two */
void Hill_Two()
{
    glPushMatrix();
    glTranslatef(550,-20,0);
    hill_model();
    glPopMatrix();
}
/* Hill_Three */
void Hill_Three()
{
    glPushMatrix();
    glTranslatef(250,0,0);
    hill_model();
    glPopMatrix();

}
/* Tilla_One */

void Tilla_One()
{
    glPushMatrix();
    glTranslatef(0,0,0);
    Tilla_Model();
    glPopMatrix();

}
/* Tilla_Two */
void Tilla_Two()
{
    glPushMatrix();
    glTranslatef(200,0,0);
    Tilla_Model();
    glPopMatrix();
}
/* Tilla_Three */
void Tilla_Three()
{
    glPushMatrix();
    glTranslatef(400,0,0);
    Tilla_Model();
    glPopMatrix();
}

/* Tree_1 */
void Tree_One()
{
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(0,0,0);
    Tree_Model();
    glPopMatrix();
}

/* Tree_2 */
void Tree_Two()
{
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(750,0,0);
    Tree_Model();
    glPopMatrix();
}
/* Tree_3 */
void Tree_Three()
{
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(300,0,0);
    Tree_Model();
    glPopMatrix();
}

/* Tree_4 */
void Tree_Four()
{
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(50,-10,0);
    Tree_Model();
    glPopMatrix();
}
/* Tree_5 */
void Tree_Five()
{
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(400,0,0);
    Tree_Model();
    glPopMatrix();
}

/* Tree_6 */
void Tree_Six()
{
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(125,0,0);
    Tree_Model();
    glPopMatrix();
}

/* Windmill */
void Windmill_One()
{
    glColor3f(0.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(0,-10,0);
    Windmill();
    glPopMatrix();

}

void Windmill_Two()
{
    glColor3f(1.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(508,-70,0);
    Windmill();
    glPopMatrix();
}
void Windmill_Three()
{
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(-300,-50,0);
    Windmill();
    glPopMatrix();
}
///Object_End

///*** Display Function ***///

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);

    ///*** Object_Layer ***///

    Windmill_Three();

    Hill_One();

    house_three();


    Hill_Three();
    Hill_Two();

    cloud_one();
    cloud_two();

    Windmill_One();
    Windmill_Two();




    Tilla_One();
    Tilla_Two();
    Tilla_Three();


    house_one();
    house_two();


    Tree_One();
    Tree_Two();
    Tree_Three();
    Tree_Four();
    Tree_Five();
    Tree_Six();

    cloud_three();
    cloud_four();
    field();

	glFlush();
}
///*** Speed & Movement ***///

void move_right()
{
    spin = spin +.1;
    ax = ax + .05;
    bx = bx + .08;
    cx = cx + .10;
    dx = dx + .15;

    if(cx>1000)
    {
        cx = -300;
    }
    if(bx>1000)
    {
            bx= -400;

    }
    if(cx>1000)
    {
            cx= -400;

    }
    if(dx>1000)
    {
            dx= -500;

    }

    glutPostRedisplay();
}

void mouse(int key, int state, int x, int y)
{
    switch (key)
    {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN)
        {
            glutIdleFunc(move_right);
        }
        break;
    case GLUT_MIDDLE_BUTTON:
    case GLUT_RIGHT_BUTTON:
        if (state == GLUT_DOWN)
        {
            glutIdleFunc(NULL);
        }
        break;
    default:
        break;
    }
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(1900, 1900);
	glutCreateWindow("Project: Smart Village");
	init();
	glutDisplayFunc(display);
    glutMouseFunc(mouse);
	glutMainLoop();
}
