/**
 * minigl.cpp
 * -------------------------------
 * Implement miniGL here.
 *
 * You may include minigl.h and any of the standard C++ libraries.
 * No other includes are permitted.  Other preprocessing directives
 * are also not permitted.  These requirements are strictly
 * enforced.  Be sure to run a test grading to make sure your file
 * passes the sanity tests.
 *
 * The behavior of the routines your are implenting is documented here:
 * https://www.opengl.org/sdk/docs/man2/
 * Note that you will only be implementing a subset of this.  In particular,
 * you only need to implement enough to pass the tests in the suite.
 */

#include "minigl.h"
#include "vec.h"
#include "mat.h"
#include <iostream>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <vector>
#include <cstdio>
#include <stack>
#include <deque>


using namespace std;

/**
 * Useful data types
 */
typedef mat<MGLfloat,4,4> mat4; //data structure storing a 4x4 matrix, see mat.h
typedef mat<MGLfloat,3,3> mat3; //data structure storing a 3x3 matrix, see mat.h
typedef vec<MGLfloat,4> vec4;   //data structure storing a 4 dimensional vector, see vec.h
typedef vec<MGLfloat,3> vec3;   //data structure storing a 3 dimensional vector, see vec.h
typedef vec<MGLfloat,2> vec2;   //data structure storing a 2 dimensional vector, see vec.h


//globals

struct vertex
{
	public:
		vec3 color;
		vec4 pos;
		vec4 oldPos;
		
		vertex()
		{
			color = vec3(0, 0, 0);
			pos = vec4(0, 0, 0, 1);
			oldPos = vec4(0, 0, 0, 1);
			
		}
		
		vertex(vec3 color, vec4 pos)
			:color(color), pos(pos)
		{}
		
		vec4 Matrix_convert(mat4 matrix)
		{
			cout << "starting calculations" << endl;
			float val1;
			float val2;
			float val3;
			float val4;
			vec4 finalvec;
			
			cout << "Calculaing matrix convert" << endl;
			
			val1 = matrix(0, 0) * pos[0] + matrix(0, 1) * pos[1] + matrix(0, 2) * pos[2] + matrix(0, 3) * pos[3];
			val2 = matrix(1, 0) * pos[0] + matrix(1, 1) * pos[1] + matrix(1, 2) * pos[2] + matrix(1, 3) * pos[3];
			val3 = matrix(2, 0) * pos[0] + matrix(2, 1) * pos[1] + matrix(2, 2) * pos[2] + matrix(2, 3) * pos[3];
			val4 = matrix(3, 0) * pos[0] + matrix(3, 1) * pos[1] + matrix(3, 2) * pos[2] + matrix(3, 3) * pos[3];
			
			
			cout << "finished matrix convert" << endl;
			
			finalvec[0] = val1;
			finalvec[1] = val2;
			finalvec[2] = val3;
			finalvec[3] = val4;
			
			return finalvec;
			
			
		}
		
		void ScreenConvert(MGLsize width, MGLsize height)
		{
			pos[0] = (pos[0] + 1) * (width/2) - 0.5;
			pos[1] = (pos[1] + 1) * (height/2) - 0.5;
		}
		
		void Normalconvert()
		{
			//oldPos[0] = pos[0];
			//oldPos[1] = pos[1];
			//oldPos[2] = pos[2];
			//oldPos[3] = pos[3];
			
			pos[0] = pos[0] / pos[3];
			pos[1] = pos[1] / pos[3];
			pos[2] = pos[2] / pos[3];
			//pos[3] = pos[3] / pos[3];
		}
		
};

struct triangles
{
	vertex a;
	vertex b;
	vertex c;
	
	triangles()
	{
			a = vertex();
			b = vertex();
			c = vertex();
	}
	
	triangles(vertex x, vertex y, vertex z)
	{
			a = x;
			b = y;
			c = z;
	}

	
};

struct trianglecoord
{
	int x;
	int y;
};
//Golbals
bool opened = false;
bool checkflag = false;
string beginMode = "";
vector <vector<unsigned>> pointveclist;
vector<vertex> Vlist;
vector<triangles> Trilist;

vec3 Currcolor;
stack <mat4> mods(deque<mat4>(1));
stack <mat4> projs(deque<mat4>(1));
vector <vertex> pointvec1;
vector <vertex> pointvec2;
float ptop = -1;
float pbot = -1;
float pleft = -1;
float pright = -1; 
MGLpoly_mode pDraw_mode;
MGLmatrix_mode mDraw_mode;


/**
 * Standard macro to report errors
 */
inline void MGL_ERROR(const char* description) {
    printf("%s\n", description);
    exit(1);
}



/**
 * Read pixel data starting with the pixel at coordinates
 * (0, 0), up to (width,  height), into the array
 * pointed to by data.  The boundaries are lower-inclusive,
 * that is, a call with width = height = 1 would just read
 * the pixel at (0, 0).
 *
 * Rasterization and z-buffering should be performed when
 * this function is called, so that the data array is filled
 * with the actual pixel values that should be displayed on
 * the two-dimensional screen.
 */
 
 float mglBarycentric(float pointAx, float pointAy, float pointBx, float pointBy, float x, float y)
{
	float valA;
	float valB;
	float valC;
	
	valC = (pointAx * pointBy) - (pointBx * pointAy);
	valB = (pointAx * y) - (x * pointAy);
	valA = (pointBx * y) - (x * pointBy);
	
	return valA - valB + valC;
}

void mglRasterize( MGLpixel*data, MGLsize width, MGLsize height, vector<vertex> pointvec, MGLfloat * zBuffer)
{
	
	//cout << "rasterize called" << endl;

	MGLint ymax = 0;
	MGLint xmax = 0;
	MGLint ymin = 0;
	MGLint xmin = 0;
	MGLfloat finalp1 = 0;
	MGLfloat finalp2 = 0;
	MGLfloat finalp3 = 0; 
	
	//cout << pointvec.at(0).pos[0] << endl;
	//cout << pointvec.at(1).pos[0] << endl;
	//cout << pointvec.at(2).pos[0] << endl;
	
	pointvec1.at(0).ScreenConvert(width, height);
	//cout << "First Tricord x: " << pointvec1.at(0).pos[0] << endl;
	//cout << "First Tricord y: " << pointvec1.at(0).pos[1] << endl;
	
	pointvec1.at(1).ScreenConvert(width, height);
	//cout << "2nd Tricord x: " << pointvec1.at(1).pos[0] << endl;
	//cout << "2nd Tricord y: " << pointvec1.at(1).pos[1] << endl;
	
	pointvec1.at(2).ScreenConvert(width, height);
	//cout << "3rd Tricord x: " << pointvec1.at(2).pos[0] << endl;
	//cout << "3rd Tricord y: " << pointvec1.at(2).pos[1] << endl;
	
	ymax = max(pointvec1.at(0).pos[1], max(pointvec1.at(1).pos[1], pointvec1.at(2).pos[1]));
	ymin = min(pointvec1.at(0).pos[1], min(pointvec1.at(1).pos[1], pointvec1.at(2).pos[1]));
	xmax = max(pointvec1.at(0).pos[0], max(pointvec1.at(1).pos[0], pointvec1.at(2).pos[0]));
	xmin = min(pointvec1.at(0).pos[0], min(pointvec1.at(1).pos[0], pointvec1.at(2).pos[0]));
	

	MGLfloat w1 = pointvec1.at(0).pos[3];
	MGLfloat w2 = pointvec1.at(1).pos[3];
	MGLfloat w3 = pointvec1.at(2).pos[3];
	MGLfloat z1 = pointvec1.at(0).pos[2]/pointvec1.at(0).pos[3];
	MGLfloat z2 = pointvec1.at(1).pos[2]/pointvec1.at(1).pos[3];
	MGLfloat z3 = pointvec1.at(2).pos[2]/pointvec1.at(2).pos[3];
	for(MGLfloat x = xmin; x < xmax; x++)
	{
		//cout << "first loop" << endl;
		
		for(MGLfloat y = ymin; y < ymax; y++)
		{
			if((x > 0) && (y > 0))
			{ 
				//cout << "second loop" << endl;
				//cout << mglBarycentric(pointvec1.at(0).pos[0], pointvec1.at(0).pos[1], pointvec1.at(1).pos[0], pointvec1.at(1).pos[1], x ,y) << endl;
				//cout <<  mglBarycentric(pointvec1.at(1).pos[0], pointvec1.at(1).pos[1], pointvec1.at(2).pos[0], pointvec1.at(2).pos[1], pointvec1.at(0).pos[0], pointvec1.at(0).pos[1]) << endl;
				
				finalp1 = mglBarycentric(pointvec1.at(1).pos[0], pointvec1.at(1).pos[1], pointvec1.at(2).pos[0], pointvec1.at(2).pos[1], x ,y) / mglBarycentric(pointvec1.at(1).pos[0], pointvec1.at(1).pos[1], pointvec1.at(2).pos[0], pointvec1.at(2).pos[1], pointvec1.at(0).pos[0], pointvec1.at(0).pos[1]);
				//cout << "final1: " << finalp1 << endl;
				finalp2 = mglBarycentric(pointvec1.at(2).pos[0], pointvec1.at(2).pos[1], pointvec1.at(0).pos[0], pointvec1.at(0).pos[1], x, y) / mglBarycentric(pointvec1.at(2).pos[0], pointvec1.at(2).pos[1], pointvec1.at(0).pos[0], pointvec1.at(0).pos[1], pointvec1.at(1).pos[0], pointvec1.at(1).pos[1]);
				finalp3 = mglBarycentric(pointvec1.at(0).pos[0], pointvec1.at(0).pos[1], pointvec1.at(1).pos[0], pointvec1.at(1).pos[1], x, y) / mglBarycentric(pointvec1.at(0).pos[0], pointvec1.at(0).pos[1], pointvec1.at(1).pos[0], pointvec1.at(1).pos[1], pointvec1.at(2).pos[0], pointvec1.at(2).pos[1]);
				
				//cout << "f1: " << finalp1 << "f2: " << finalp2 << "f3: " << finalp3 << endl;

				if((finalp1 >= 0) && (finalp2 >= 0) && (finalp3 >= 0))
				{ 
					MGLint place = x + y * width;
					MGLint tot = width * height;
					if (place < tot)
					{
					
						float modColor = (finalp1/w1) + (finalp2/w2) + (finalp3/w3);
						
						MGLfloat red = (pointvec1.at(0).color[0] * (finalp1/w1)     +   pointvec1.at(1).color[0] * (finalp2/w2)      +    pointvec1.at(2).color[0] * (finalp3/w3)) / modColor * 255;
						MGLfloat green = (pointvec1.at(0).color[1] * (finalp1 /w1)    +   pointvec1.at(1).color[1] * (finalp2/w2)     +    pointvec1.at(2).color[1] * (finalp3/w3)) / modColor * 255;
						MGLfloat blue = (pointvec1.at(0).color[2] * (finalp1/w1)    +   pointvec1.at(1).color[2] * (finalp2/w2)     +    pointvec1.at(2).color[2] * (finalp3/w3)) / modColor * 255;
						
						MGLfloat depth = (z1*finalp1) +  (z2*finalp2) + (z3*finalp3);
						
						if((x > 0) && (x < width) && (y > 0) && (y < height) && (depth > -1) && (depth < 1))
						{
							
							
							if(zBuffer[place] >= depth)
							{
								zBuffer[place] = depth;
								data[place] = Make_Pixel(red, green, blue);
								//data[place] = 0xffffffff;
								
							}
							
						}
					}
				} 
			}	
		}
	} 
	
	
cout << "rastarize finished"<< endl;
	
	
	
}
 
void mglReadPixels(MGLsize width,
                   MGLsize height,
                   MGLpixel *data)
    //Conceptual vertex
    //glVertex2 0.25 0.25
	//glVertex2 0.75 0.25
	//glVertex2 0.75 0.75
	//height= 240
	//width = 320
	
	
{   //Y-Line representation at the far left of the screen
	/*
	cout << "beginning read pixels" << endl;
	int v1 = 0.25;
	int v2 = 0.25;


	if(ptop == -1) 
		ptop = 1;
	
	if(pbot == -1)
		pbot = -1  ;
	if(pleft == -1)
		pleft= -1;
	
	if(pright == -1)	
		pright = 1; 


	//string finalColor = 0x;
	//int colorInput;
	//string colorOutput;
	
	for(unsigned int i = 0; i < width*height; i+=width)
	{
		data[i] = 0xffffffff;
	}
	//X-Line representation at the middle of the screen
	for(unsigned int i = (width*height)/2; i < ((width*height)/2) + width; i+=1)
	{
		data[i] = 0x33ff33ff;
	}
	//Y-Line representation at the middle of the screen
	for(unsigned int i = (width/2); i < (width*height); i+=width)
	{
		data[i] = 0x33ff33ff;
	}
	
	cout << Vlist.size() << endl;
	
	cout << "before draw mode" << endl;
	
	if (draw_mode == MGL_TRIANGLES)
	{ 
	
		for(unsigned j = 0; j < Vlist.size(); j++)
		{
			cout << "triangle call" << endl;
		
			// ortho; left = -2; right = 2; bottom = -2; top = 2
			cout << "loop number " << j << endl;
			int i =   ((abs(pbot)/(ptop - pbot))*(height))*width  +  (((((Vlist.at(j)).position[1])/ptop)*(height*(ptop/(ptop - pbot))))*width);
			int k = ((((Vlist.at(j).position[0]/pright))) *(width* (pright/(pright -pleft))))+ (abs(pleft)/(pright-pleft))*width;
			cout << "Jay: " << k << endl;
			//data[i + k] = 0xffffffff;
			pointvec1.push_back(i + k);
	

		}
		pointveclist.push_back(pointvec1);
		mglRasterize(data, width, height, pointvec1);
	}
	
	if (draw_mode == MGL_QUADS)
	{
		for(unsigned j = 0; j < Vlist.size(); j++)
		{
			cout << "quad call" << endl;
		
			// ortho; left = -2; right = 2; bottom = -2; top = 2
			cout << "loop number " << j << endl;
			int i =   ((abs(pbot)/(ptop - pbot))*(height))*width  +  (((((Vlist.at(j)).position[1])/ptop)*(height*(ptop/(ptop - pbot))))*width);
			int k = ((((Vlist.at(j).position[0]/pright))) *(width* (pright/(pright -pleft))))+ (abs(pleft)/(pright-pleft))*width;
			cout << "Jay: " << k << endl;
			//data[i + k] = 0xffffffff;
			if(j != 2)
			{
				pointvec1.push_back(i + k);
			}
			if(j != 0)
			{
				pointvec2.push_back(i + k);
			}

		}	
		mglRasterize(data, width, height, pointvec1);
		mglRasterize(data, width, height, pointvec2);
	}
	
	*/
	
	MGLfloat zBuffer[width * height];
	for(unsigned int j = 0; j < (width * height); j++)
	{
		zBuffer[j] = 9999999;
	}
	
	for (unsigned int i = 0; i < Trilist.size(); i++)
	{
		pointvec1.clear();
		pointvec1.push_back(Trilist.at(i).a);
		pointvec1.push_back(Trilist.at(i).b);
		pointvec1.push_back(Trilist.at(i).c);
		
		cout << "Raw Point 1 x: " << pointvec1.at(0).pos[0] << endl;
		cout << "Raw Point 1 y: " << pointvec1.at(0).pos[1] << endl;
		
		cout << "Raw Point 2 x: " << pointvec1.at(1).pos[0] << endl;
		cout << "Raw Point 2 y: " << pointvec1.at(1).pos[1] << endl;
	
		cout << "Raw Point 3 x: " << pointvec1.at(2).pos[0] << endl;
		cout << "Raw Point 3 y: " << pointvec1.at(2).pos[1] << endl;
		
		mglRasterize(data, width, height, pointvec1, zBuffer); 

	}
	
	
	
/*	
	cout << "Ortho Top: " << ptop << endl;
	cout << "Ortho Bot: " << pbot << endl;
	cout << "Ortho left: " << pleft << endl;
	cout << "Ortho right: " << pright << endl;
	
	
	cout << pointvec.at(0) << endl;
	cout << pointvec.at(1) << endl;
	cout << pointvec.at(2) << endl;
	
	tricord1.y = pointvec.at(0)/width;
	tricord1.x = pointvec.at(0)%width;
	cout << "First Tricord x: " << tricord1.x << endl;
	cout << "First Tricord y: " << tricord1.y << endl;
	
	tricord2.y = pointvec.at(1)/width;
	tricord2.x = pointvec.at(1)%width;
	cout << "2nd Tricord x: " << tricord2.x << endl;
	cout << "2nd Tricord y: " << tricord2.y << endl;
	
	tricord3.y = pointvec.at(2)/width;
	tricord3.x = pointvec.at(2)%width;
	cout << "3rd Tricord x: " << tricord3.x << endl;
	cout << "3rd Tricord y: " << tricord3.y << endl;
	*/
	/*
	int i = (((width*height)/2) + ((0.25*(height/2))*width) + (0.25*(width/2)))+ (width/2);
	data[i] = 0x88ff33ff;
	
	i = (((width*height)/2) + ((0.25*(height/2))*width) + (0.75*(width/2))) + (width/2);
	data[i] = 0x88ff33ff;
	
	i = (((width*height)/2) + ((0.75*(height/2))*width) + (0.75*(width/2))) + (width/2);
	data[i] = 0x88ff33ff;
	*/
	
	//a(abc) = Ax(By-Cy)+Ay(Cx-Bx)+(BxCy-ByCx)
}



/**
 * Start specifying the vertices for a group of primitives,
 * whose type is specified by the given mode.
 */
void mglBegin(MGLpoly_mode mode)
{
	if(opened == true)
	{
		//cout << "mode already set" << endl;
	}
	pDraw_mode = mode;
	Vlist.clear();
	opened= true;

}


/**
 * Stop specifying the vertices for a group of primitives.
 */
void mglEnd()
{
	if(pDraw_mode == MGL_TRIANGLES)
	{
		for ( unsigned i = 0; i < Vlist.size(); i+=3)
		{
			Trilist.push_back(triangles(Vlist.at(i), Vlist.at(i+1), Vlist.at(i+2)));
			//cout << "Vlist: " << Vlist.at(i).pos[0] << " " << Vlist.at(i).pos[1] << endl;
			//cout << "Trilist: " << Trilist.at(0).a.pos[0] << " " << Trilist.at(0).a.pos[1] <<endl;

		}
	}
	else if(pDraw_mode == MGL_QUADS)
	{
		for(unsigned j = 0; j < Vlist.size(); j+=4)
		{
			Trilist.push_back(triangles(Vlist.at(j), Vlist.at(j+1), Vlist.at(j+2)));
			Trilist.push_back(triangles(Vlist.at(j), Vlist.at(j+2), Vlist.at(j+3)));
		}
		
	}
} 

/**
 * Specify a two-dimensional vertex; the x- and y-coordinates
 * are explicitly specified, while the z-coordinate is assumed
 * to be zero.  Must appear between calls to mglBegin() and
 * mglEnd().
 */
void mglVertex2(MGLfloat x,
                MGLfloat y)
{
	mglVertex3(x, y, 0);
}

/**
 * Specify a three-dimensional vertex.  Must appear between
 * calls to mglBegin() and mglEnd().
 */
void mglVertex3(MGLfloat x,
                MGLfloat y,
                MGLfloat z)
{
	vertex CurrVert;
	
	CurrVert.color = Currcolor;
	CurrVert.pos = vec4(x, y, z ,1);
	//cout << "Pushing current vector " << x << " " << y << endl;
	

	
	//cout << "finished mods" << endl;
	
	mat4 temp = projs.top() * mods.top();
	CurrVert.pos = CurrVert.Matrix_convert(temp);
	
	//CurrVert.pos = CurrVert.Matrix_convert(projs.top());
	
	//cout << "normal converting" << endl;
	//CurrVert.pos = CurrVert.Matrix_convert(mods.top());
	
	CurrVert.Normalconvert();
	
	//cout << "pushing back" << endl;
	
	Vlist.push_back(CurrVert);
	
	//cout << "Vlist pushed back" << endl;
	
	//Adds vector to the vector list
}

/**
 * Set the current matrix mode (modelview or projection).
 */
void mglMatrixMode(MGLmatrix_mode mode)
{
	
	
	if(mode == MGL_PROJECTION || mode == MGL_MODELVIEW)
	{
		mDraw_mode = mode;
	}
	else
	{
		cout<< "error in matrix mode" << endl;
	}
}

/**
 * Push a copy of the current matrix onto the stack for the
 * current matrix mode.
 */
void mglPushMatrix()
{
	if(mDraw_mode == MGL_MODELVIEW)
	{
		if(!mods.empty())
		{
				mods.push(mods.top());
		}
	}
	else if(mDraw_mode == MGL_PROJECTION)
	{
		if(!projs.empty())
		{
				projs.push(projs.top());
		}
	}
}

/**
 * Pop the top matrix from the stack for the current matrix
 * mode.
 */
void mglPopMatrix()
{
	if(mDraw_mode == MGL_MODELVIEW)
	{
		if(!mods.empty())
		{
				mods.pop();
		}
	}
	else if(mDraw_mode == MGL_PROJECTION)
	{
		if(!projs.empty())
		{
				projs.pop();
		}
	}
}

/**
 * Replace the current matrix with the identity.
 */
void mglLoadIdentity()
{
	mat4 identity;
	identity.make_zero();
	identity(0, 0) = 1;
	identity(1, 1) = 1;
	identity(2, 2) = 1;
	identity(3, 3) = 1;
	
	if(mDraw_mode == MGL_MODELVIEW)
	{
			mods.push(identity);
	}
	else if(mDraw_mode == MGL_PROJECTION)
	{
			projs.push(identity);
	}
}

/**
 * Replace the current matrix with an arbitrary 4x4 matrix,
 * specified in column-major order.  That is, the matrix
 * is stored as:
 *
 *   ( a0  a4  a8  a12 )
 *   ( a1  a5  a9  a13 )
 *   ( a2  a6  a10 a14 )
 *   ( a3  a7  a11 a15 )
 *
 * where ai is the i'th entry of the array.
 */
void mglLoadMatrix(const MGLfloat *matrix)
{
	mat4 matLoad;
    for(int j = 0; j < 16; ++j) 
		matLoad.values[j]=matrix[j];
        
        
    

    if(mDraw_mode == MGL_MODELVIEW) 
    {
        mods.top()=matLoad;
    } 
    else 
    {
        projs.top()=matLoad;
    }
}

/**
 * Multiply the current matrix by an arbitrary 4x4 matrix,
 * specified in column-major order.  That is, the matrix
 * is stored as:
 *
 *   ( a0  a4  a8  a12 )
 *   ( a1  a5  a9  a13 )
 *   ( a2  a6  a10 a14 )
 *   ( a3  a7  a11 a15 )
 *
 * where ai is the i'th entry of the array.
 */
void mglMultMatrix(const MGLfloat *matrix)
{
	mat4 matMult;
    for(int j = 0; j < 16; ++j) 
		matMult.values[j]=matrix[j];
    

    if(mDraw_mode == MGL_MODELVIEW) 
    {
        mods.top() = mods.top() * matMult;
    }
    
    else
    {
        projs.top() = projs.top() * matMult;
    }
}

/**
 * Multiply the current matrix by the translation matrix
 * for the translation vector given by (x, y, z).
 */
void mglTranslate(MGLfloat x,
                  MGLfloat y,
                  MGLfloat z)
{
	mat4 matTrans;
    matTrans.make_zero();

    matTrans(0,0) = 1;
    matTrans(1,1) = 1;
    matTrans(2,2) = 1;
    matTrans(3,3) = 1;
    matTrans(0,3) = x;
    matTrans(1,3) = y;
    matTrans(2,3) = z;

    if(mDraw_mode == MGL_MODELVIEW) 
    {
        mods.top() = matTrans * mods.top();
    } 
    else 
    {
        projs.top() = matTrans * projs.top();
    }
}

/**
 * Multiply the current matrix by the rotation matrix
 * for a rotation of (angle) degrees about the vector
 * from the origin to the point (x, y, z).
 */
void mglRotate(MGLfloat angle,
               MGLfloat x,
               MGLfloat y,
               MGLfloat z)
{
	vec3 vector = vec3(x,y,z).normalized();
        x = vector[0];
        y = vector[1];
        z = vector[2];
    

    mat4 matRot;
    matRot.make_zero();

    MGLfloat a = angle * M_PI / 180;
	MGLfloat myCos = cos(a);
	MGLfloat mySin = sin(a);

    matRot(0,0) = x * x * (1 - myCos) + myCos;
    matRot(0,1) = x * y * (1 - myCos) - z * mySin;
    matRot(0,2) = x * z * (1 - myCos) + y * mySin;
    matRot(0,3) = 0;

    matRot(1,0) = y * x * (1 - myCos) + z * mySin;
    matRot(1,1) = y * y * (1 - myCos) + myCos;
    matRot(1,2) = y * z * (1 - myCos) - x * mySin;
    matRot(1,3) = 0;

    matRot(2,0) = x * z * (1 - myCos) - y * mySin;
    matRot(2,1) = y * z * (1 - myCos) + x * mySin;
    matRot(2,2) = z * z * (1 - myCos) + myCos;
    matRot(2,3) = 0;

    matRot(3,0) = 0;
    matRot(3,1) = 0;
    matRot(3,2) = 0;
    matRot(3,3) = 1;

    if(mDraw_mode == MGL_MODELVIEW) 
    {
        mods.top() = mods.top() * matRot;
    } 
    else 
    {
        projs.top() = projs.top() * matRot;
    }

}

/**
 * Multiply the current matrix by the scale matrix
 * for the given scale factors.
 */
void mglScale(MGLfloat x,
              MGLfloat y,
              MGLfloat z)
{
	mat4 MatScale;
	
	MatScale.make_zero();
	
	MatScale(0, 0) = x;
	MatScale(1, 1) = y;
	MatScale(2, 2) = z;
	MatScale(3, 3) = 1;
	
	if(mDraw_mode == MGL_MODELVIEW)
	{
			mods.top() = mods.top() * MatScale;
	}
	else if(mDraw_mode == MGL_PROJECTION)
	{
			projs.top() = projs.top() * MatScale;
	}
}

/**
 * Multiply the current matrix by the perspective matrix
 * with the given clipping plane coordinates.
 */
void mglFrustum(MGLfloat left,
                MGLfloat right,
                MGLfloat bottom,
                MGLfloat top,
                MGLfloat near,
                MGLfloat far)
{
	mat4 MatFrus;
	
	MatFrus.make_zero();
	
	MatFrus(0, 0) = (2 * near) / (right - left);
	MatFrus(1, 1) = (2 * near) / (top - bottom);
	MatFrus(0, 2) = (right + left) / (right - left);
	MatFrus(1, 2) = (top + bottom) / (top - bottom);
	MatFrus(2, 2) = -(far + near) / (far - near);
	MatFrus(3, 2) = -1;
	MatFrus(2, 3) = (-2 * far * near) / (far - near);

	if(mDraw_mode == MGL_MODELVIEW)
	{
			mods.top() = MatFrus * mods.top();
	}
	else if(mDraw_mode == MGL_PROJECTION)
	{
			projs.top() = MatFrus * projs.top();
	}
	
}

/**
 * Multiply the current matrix by the orthographic matrix
 * with the given clipping plane coordinates.
 */
void mglOrtho(MGLfloat left,
              MGLfloat right,
              MGLfloat bottom,
              MGLfloat top,
              MGLfloat near,
              MGLfloat far)
{
	mat4 MatOrtho;
	
	MatOrtho.make_zero();
	
	MatOrtho(0, 0) = 2/(right - left);
	MatOrtho(1, 1) = 2/(top - bottom);
	MatOrtho(2, 2) = -2/(far - near);
	MatOrtho(3, 3) = 1;
	MatOrtho(0, 3) = -(right + left) / (right - left);
	MatOrtho(1, 3) = -(top + bottom) / (top - bottom);
	MatOrtho(2, 3) = -(near + far) / (near - far);

	if(mDraw_mode == MGL_MODELVIEW)
	{
			mods.top() = MatOrtho * mods.top();
	}
	else if(mDraw_mode == MGL_PROJECTION)
	{
			projs.top() = MatOrtho * projs.top();
	}
	
	cout << "finished ortho" << endl;
}

/**
 * Set the current color for drawn shapes.
 */
void mglColor(MGLfloat red,
              MGLfloat green,
              MGLfloat blue)
{
	Currcolor = vec3(red, green, blue);
}
/*
void hexConverter (int colorInput, string colorInput)
{
	
}
*/
