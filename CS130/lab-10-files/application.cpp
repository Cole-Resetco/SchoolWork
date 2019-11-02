#include "application.h"

#include <iostream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>

#ifndef __APPLE__
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#endif

using namespace std;
enum { NONE, AMBIENT, DIFFUSE, SPECULAR, NUM_MODES };


struct Particle
{

	public:
		vec3 pos; // position of particle#
		vec3 posold;
		vec3 vel; //velocity of particle#
		vec3 force; // force accumulator#
		float m; //mass of the particle#
		vec3 col; //color of particle
		
	void Euler_Step(float h)
	{
		pos[0] =pos[0] + h*vel[0];
		pos[1] =pos[1] + h*vel[1];
		pos[2] =pos[2] + h*vel[2];
		vel[0] = vel[0] + (h/m)*force[0]; 
		vel[1] = vel[1] + (h/m)*force[1]; 
		vel[2] = vel[2] + (h/m)*force[2]; 
	}
	
	void Force_Reset()
	{
		force[0] = 0;
		force[1] = 1;
		force[2] = 2;
	}
	
	void Boundry(float damping, float coeff_restitution)
	{
		if (pos[1] <= 0)
		{
			pos[1] = -pos[1];
			if(vel[1] < 0)
			{
				vel[1] = -coeff_restitution * vel[1];
			}
			vel[0] = vel[0] * damping;
			vel[2] = vel[2] * damping;
		}
	}
	
};

vector<Particle> particles;

float random(float k, float j)
{
		return (static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/ (j -k)))) + k;
}

void Add_Particle (int n)
{
	for(int i = 1; i <= n; i++)
	{
		Particle Temp;

		Temp.pos[0] = random(-0.2, 0.2);
		Temp.pos[1] = 0.05;
		Temp.pos[2] = random(-.2, .2);
		
		Temp.vel[0] = 10*Temp.pos[0];
		Temp.vel[1] = random(1, 10);
		Temp.vel[2] = 10*Temp.pos[2];
		
		Temp.col[0] = 1;
		Temp.col[1] = 1;
		Temp.col[2] = 1;
		
		Temp.m = 1;
		
		Temp.force[0] = 0;
		Temp.force[1] = 0;
		Temp.force[2] = 0; 
		
		particles.push_back(Temp);
		
	}
}
		
void draw_grid(int dim);
void draw_obj(obj *o, const gl_image_texture_map& textures);

void set_pixel(int x, int y, float col[3])
{
    // write a 1x1 block of pixels of color col to framebuffer
    // coordinates (x, y)
    //glRasterPos2i(x, y);
    //glDrawPixels(1, 1, GL_RGB, GL_FLOAT, col);

    // use glVertex instead of glDrawPixels (faster)
    glBegin(GL_POINTS);
    glColor3fv(col);
    glVertex2f(x, y);
    glEnd();
}

application::application()
    : raytrace(false), rendmode(SPECULAR), paused(false), sim_t(0.0)
{
}

application::~application()
{
}

// triggered once after the OpenGL context is initialized
void application::init_event()
{

    cout << "CAMERA CONTROLS: \n  LMB: Rotate \n  MMB: Move \n  RMB: Zoom" << endl;
    cout << "KEYBOARD CONTROLS: \n  ' ': Pause simulation" << endl;

    const GLfloat ambient[] = { 0.0, 0.0, 0.0, 1.0 };
    const GLfloat diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    const GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0 };

    // enable a light
    glLightfv(GL_LIGHT1, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, specular);
    glEnable(GL_LIGHT1);

    // set global ambient lighting
    GLfloat amb[] = { 0.4, 0.4, 0.4, 1.0 };
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, amb);

    // enable depth-testing, colored materials, and lighting
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glDisable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    // normalize normals so lighting calculations are correct
    // when using GLUT primitives
    glEnable(GL_RESCALE_NORMAL);

    // enable smooth shading
    glShadeModel(GL_SMOOTH);

    glClearColor(0,0,0,0);

    set_camera_for_box(vec3(-3,-2,-3),vec3(3,5,3));

    t.reset();
    o.load("crater.obj");

    // loads up all the textures referenced by the .mtl file
    const std::map<std::string, obj::material>& mats = o.get_materials();
    for (std::map<std::string, obj::material>::const_iterator i = mats.begin();
        i != mats.end(); ++i
        )
    {
        if (!i->second.map_kd.empty()) {
            string filename = i->second.map_kd;

            // add texture if we have not already loaded it
            if (texs.find(filename) == texs.end()) {
                gl_image_texture *tex = new gl_image_texture();
                if (tex->load_texture(filename) != SUCCESS) {
                    cout << "could not load texture file: " << filename << endl;
                    exit(0);
                }
                texs[filename] = tex;
            }
        }
    }
}

// triggered each time the application needs to redraw
void application::draw_event()
{
    apply_gl_transform();

    const GLfloat light_pos1[] = { 0.0, 10.0, 0.0, 1 };
    glLightfv(GL_LIGHT1, GL_POSITION, light_pos1);

    if (!paused) {
        //
        // DO SIM STUFF HERE.
        //
        // You'll want to simulate for 1/60th of a second.
        // That does not mean your step size should be
        // 1/60th. Simply that if you integrate multiple
        // times within this draw_event,
        // h * #of integration steps = 0.015
        //
        
        Add_Particle(150);
        for(int i = 0; i < particles.size(); i++)
        {
			particles.at(i).force[1] = particles.at(i).m * (-9.81);
			particles.at(i).Euler_Step(0.015);
			particles.at(i).Boundry(0.5, 0.5);
		}
    }

    glLineWidth(2.0);
    glEnable(GL_COLOR_MATERIAL);
    glBegin(GL_LINES);
        //
        //
        // DRAW YOUR PARTICLE USING GL_LINES HERE
        //
        for(int i = 0; i < particles.size(); i++)
        {
			glVertex3f(particles.at(i).pos[0], particles.at(i).pos[1], particles.at(i).pos[2]);
			glVertex3f(particles.at(i).pos[0] + (particles.at(i).vel[0]*0.04), particles.at(i).pos[1] + (particles.at(i).vel[1]*0.04), particles.at(i).pos[2] + (particles.at(i).vel[2]*0.04));
        }
        //
        
        //
    glEnd();

    // draw the volcano
    glEnable(GL_LIGHTING);
    glPushMatrix();
    glScalef(0.2,0.3,0.2);
    draw_obj(&o, texs);
    glPopMatrix();
    glDisable(GL_LIGHTING);


    glColor3f(0.15, 0.15, 0.15);
    draw_grid(40);

    //
    // This makes sure that the frame rate is locked to close to 60 fps.
    // For each call to draw_event you will want to run your integrate for 0.015s
    // worth of time.
    //
    float elap = t.elapsed();
    if (elap < 0.015) {
        usleep(1e6*(0.015-elap));
    }
    t.reset();
}

// triggered when mouse is clicked
void application::mouse_click_event(int button, int button_state, int x, int y)
{
}

// triggered when mouse button is held down and the mouse is
// moved
void application::mouse_move_event(int x, int y)
{
}

// triggered when a key is pressed on the keyboard
void application::keyboard_event(unsigned char key, int x, int y)
{

    if (key == 'r') {
        sim_t = 0;
    } else if (key == ' ') {
        paused = !paused;
    } else if (key == 'q') {
        exit(0);
    }
}

void draw_grid(int dim)
{
    glLineWidth(2.0);


    //
    // Draws a grid along the x-z plane
    //
    glLineWidth(1.0);
    glBegin(GL_LINES);

    int ncells = dim;
    int ncells2 = ncells/2;

    for (int i= 0; i <= ncells; i++)
    {
        int k = -ncells2;
        k +=i;
        glVertex3f(ncells2,0,k);
        glVertex3f(-ncells2,0,k);
        glVertex3f(k,0,ncells2);
        glVertex3f(k,0,-ncells2);
    }
    glEnd();

    //
    // Draws the coordinate frame at origin
    //
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    glBegin(GL_LINES);

    // x-axis
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(1.0, 0.0, 0.0);

    // y-axis
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 1.0, 0.0);

    // z-axis
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 1.0);
    glEnd();
    glPopMatrix();
}

void draw_obj(obj *o, const gl_image_texture_map& textures)
{
    glDisable(GL_COLOR_MATERIAL);

    // draw each polygon of the mesh
    size_t nfaces = o->get_face_count();
    for (size_t i = 0; i < nfaces; ++i)
    {
        const obj::face& f = o->get_face(i);

        // sets the material properties of the face
        const obj::material& mat = o->get_material(f.mat);
        if (!mat.map_kd.empty()) {
            gl_image_texture_map::const_iterator it = textures.find(mat.map_kd);
            if (it != textures.end()) {
                gl_image_texture* tex = it->second;
                tex->bind();
            }
            GLfloat mat_amb[] = { 1, 1, 1, 1 };
            GLfloat mat_dif[] = { mat.kd[0], mat.kd[1], mat.kd[2], 1 };
            GLfloat mat_spec[] = { mat.ks[0], mat.ks[1], mat.ks[2], 1 };
            glMaterialfv(GL_FRONT, GL_AMBIENT, mat_amb);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_dif);
            glMaterialfv(GL_FRONT, GL_SPECULAR, mat_spec);
        } else {
            GLfloat mat_amb[] = { mat.ka[0], mat.ka[1], mat.ka[2], 1 };
            GLfloat mat_dif[] = { mat.kd[0], mat.kd[1], mat.kd[2], 1 };
            GLfloat mat_spec[] = { mat.ks[0], mat.ks[1], mat.ks[2], 1 };
            glMaterialfv(GL_FRONT, GL_AMBIENT, mat_amb);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_dif);
            glMaterialfv(GL_FRONT, GL_SPECULAR, mat_spec);
        }
        glMaterialf(GL_FRONT, GL_SHININESS, mat.ns);

        if (!glIsEnabled(GL_TEXTURE_2D)) glEnable(GL_TEXTURE_2D);

        // draws a single polygon
        glBegin(GL_POLYGON);
        for (size_t j = 0; j < f.vind.size(); ++j)
        {
            // vertex normal
            if (f.nind.size() == f.vind.size()) {
                const float *norm = o->get_normal(f.nind[j]);
                glNormal3fv(norm);
            }

            // vertex UV coordinate
            if (f.tex.size() > 0) {
                const float* tex = o->get_texture_indices(f.tex[j]);
                glTexCoord2fv(tex);
            }

            // vertex coordinates
            const float *vert = o->get_vertex(f.vind[j]);
            glVertex3fv(vert);
        }
        glEnd();
    }
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_COLOR_MATERIAL);
}
