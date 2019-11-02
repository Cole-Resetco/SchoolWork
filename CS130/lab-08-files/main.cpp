// Name:
// Quarter, Year:
// Lab:
//
// This file is to be modified by the student.
// main.cpp
////////////////////////////////////////////////////////////
#ifndef __APPLE__
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif

#include <vector>
#include <cstdio>
#include <math.h>
#include "vec.h"
#include <iostream>

using namespace std;
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;
vector<vec2> CollectPoints;


vec2 Bezier(float t)
{
	//cout << "starting bezier calc" << endl;
	int n = CollectPoints.size()-1;
	float N_over_I;
	vec2 b;
	for( int i = 0; i <=n; i++)
	{
		float top = 1;
		for(int j=i+1; j <= n; j++)
			top = top*j;
		
		int bot=1;
		for(int k = 1; k<= n-i; k++)
			bot = bot*k;
		
		
		
		//cout << "N over I calculated" << endl;
		
		N_over_I = top/bot;
		cout << "raw multiple :" << ( N_over_I * pow((1 - t), n - i) * pow(t, i)) << endl;
		b+= CollectPoints.at(i)*( N_over_I * pow((1 - t), n - i) * pow(t, i));
		
	}
			//cout << "end bezier calculation" << endl;
			return b;
}




void GL_render()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();

    glBegin(GL_LINE_STRIP);
    glColor3f(1.0f,1.0f,1.0f);
    // just for example, remove if desired

	if(CollectPoints.size() > 1)
	{
		for(float t = 0.00; t <= 1; t+= 0.01)
		{
			vec2 b=Bezier(t);
			glVertex2f(b[0], b[1]);
			cout << "wrote point at: " << b[0] << " " << b[1] << endl;
		}
	}
    glEnd();
    glFlush();
}

void GL_mouse(int button,int state,int x,int y)
{
	
    y=WINDOW_HEIGHT-y;
    GLdouble mv_mat[16];
    GLdouble proj_mat[16];
    GLint vp_mat[4];
    glGetDoublev(GL_MODELVIEW_MATRIX,mv_mat);
    glGetDoublev(GL_PROJECTION_MATRIX,proj_mat);
    glGetIntegerv(GL_VIEWPORT,vp_mat);

    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN){
        double px,py,dummy_z; // we don't care about the z-value but need something to pass in
        gluUnProject(x,y,0,mv_mat,proj_mat,vp_mat,&px,&py,&dummy_z);
        CollectPoints.push_back(vec2(px, py));
        cout << " pushing back: " << px << " " << py << endl;
        glutPostRedisplay();
    }
}

//Initializes OpenGL attributes
void GLInit(int* argc, char** argv)
{
    glutInit(argc, argv);
    //glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);

    //glMatrixMode(GL_PROJECTION_MATRIX);
    //glOrtho(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT, -1, 1);
    glutCreateWindow("CS 130 - <Insert Name Here>");
    glutDisplayFunc(GL_render);
    glutMouseFunc(GL_mouse);
}

int main(int argc, char** argv)
{
    GLInit(&argc, argv);
    glutMainLoop();
    return 0;
}
