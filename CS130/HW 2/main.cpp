#include <iostream>
#include <iomanip>
#include "vec.h"
#include <cmath>

using namespace std;

void Dump_png(unsigned int* data,int width,int height,const char* filename);

/*
  Problems 1-4

  Rewrite each loop so that only addition and subtraction occur inside any loop.
  This includes operations performed on the vec3 vectors.  Ignore the operations
  that occur while printing the results.

  Each problem is worth 10 points.  Note that for Problem 4, you must clear the
  multiplications and divisions from both loops.  If you are able to clear the
  multiplications and divisions from only the inner loop, you will still get 5
  points.
*/

void Problem_1(int n, float x, float y)
{
	float stnd = x * (-n - 1);
    for(int i = -n ; i <= n ; i++)
    {
		float z = stnd + x + y;
        
		//float z = i * x + y;
        
		cout << z << endl;
		stnd  +=  x;
    }
}

void Problem_2(int n, float x, float dx)
{
	float dxtrk = (x + x + dx)*dx;
    float xtrk = (x*x);
	float mtpl = (dx * dx)*2;
    for(int i = 0 ; i < n ; i++)
    {
        //float y = x + dx * i;
        //float z = y * y;
        cout << xtrk << endl;
		xtrk += dxtrk;
        dxtrk += mtpl;
    }
}

void Problem_3(int n, vec3 u, vec3 v, vec3 du)
{
    float z = dot(u,v)/dot(v,v);
    float a = dot(v,du)/dot(v,v);
    for(int i = 0 ; i < n ; i++)
    {
        //vec3 w = u + du * i;
        
        cout << z << endl;
        z += a;
    }
}

void Problem_4(int n, vec3 w, vec3 u, vec3 v)
{
    vec3 vbas = v;
    //cout << "test 1/5: " << 1.0/5.0 << endl;
    //cout << "n: " << n << endl;
    vec3 cons = (float)(1.0/n) * u;
    //cout << "one over n "<< cons << endl;
    vec3 sbas = (float)(1.0/n) * v;
    //cout << sbas << endl;
    vec3 bas = (float)(1.0/n) * w; 
    //cout << bas << endl;
    vec3 tsbas = (float)(1.0/n) * v;
    for(int i = 0 ; i <= n ; i++)
    {
        vec3 tem = vbas;
        //cout << "curr bas: " << bas << endl;
        for(int j = 0 ; i + j <= n ; j++)
        {
            cout << tem << endl;
            tem += cons - sbas;
        }
        //cout << "-------Ended inner loop-----" << endl;
        vbas += bas - tsbas;
        
    }
}

/*
  Problem 5
  Draw a white circle centered at (x,y) with radius r.
  For example, data[y][x]=0xffffffff; would set the center of the circle to white.
  The circle should not have gaps.
  You may assume that the circle does not cross the edges of the circle.

  20 points.

  Extra credit options:
  A = you don't use any floating point.
  B = you do not use * or / in any loop, including in the loop condition.
  C = you fill the circle red (0xff0000ff) while keeping the outline white.

  A = 2% extra credit
  A + B = 5% extra credit
  A + B + C = 10% extra credit
*/
void draw_circle(int x, int y, int r)
{
    unsigned int data[512][512];
    for(int i = 0 ; i < 512; i++)
        for(int j = 0 ; j < 512; j++)
            data[i][j] = 0xff000000; // set all pixels to (0,0,0,1) = black.

    // TODO: your code here
    //data[x][y]  = 0xffffffff;
    int xn;
	int yn;
    //int yn = 0;
    //int e = 0;
    //float csqrd;
    //float chsqrd;
    //csqrd = sqrt((xn * xn) + (yn * yn));
    
    for(int cnts = y-r; cnts < y+r; cnts++)
    {
        xn = sqrt(pow(r,2) - pow((cnts-y), 2)) ;
        data[cnts][xn] = 0xffffffff;
    }
   
    for(int cnts = y-r; cnts < y+r; cnts++)
    {
        xn = x - sqrt(pow(r,2) - pow((cnts-y), 2));
        data[cnts][xn] = 0xffffffff;
    }
   
    
    for(int cnts = x-r; cnts < x+r; cnts++)
    {
        yn = sqrt(pow(r,2) - pow((cnts-x), 2)) ;
        data[yn][cnts] = 0xffffffff;
    }
   
    for(int cnts = x-r; cnts < x+r; cnts++)
    {
        yn = y - sqrt(pow(r,2) - pow((cnts-x), 2));
        data[yn][cnts] = 0xffffffff;
    }
    Dump_png(&data[0][0],512,512,"circle.png");
}

int main()
{
    cout << std::setprecision(4);

    cout << "== Problem 1 ==" << endl;
    
    Problem_1(5, -0.123, 2.114);

    cout << "== Problem 2 ==" << endl;

    Problem_2(5, -0.123, 2.114);

    cout << "== Problem 3 ==" << endl;

    Problem_3(5, vec3(.1,.2,.3), vec3(0.9,0.2,0.8), vec3(0.0,0.1,0.6));

    cout << "== Problem 4 ==" << endl;

    Problem_4(5, vec3(.1,.2,.3), vec3(0.9,0.2,0.8), vec3(0.0,0.1,0.6));

    cout << "== Problem 5 ==" << endl;

    draw_circle(220, 260, 200);

    return 0;
}

