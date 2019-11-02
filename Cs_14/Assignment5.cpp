//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn2/main.cpp 
/// @brief Assignment/Lab 7 for CS 12 q3 2015
///
/// @author Cole Resetco [crese002@ucr.edu]
/// @date June 4 2015
///
/// @par Enrollment Notes 
///     Lecture Section: 001
/// @par
///     Lab Section: 022
/// @par
///     TA: Lab Guy
///
/// @par Plagiarism Section
/// I hereby certify that the code in this file
/// is ENTIRELY my own original work.
//  ================== END ASSESSMENT HEADER ===============






//NOTES//
//---pretty print isnt very pretty
//---this code does not work with an input file, you must eddit the vectors within main
//---was unable to get an algorithm for the 4th vector





#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <cmath>

using namespace std;

class UF    {
    int *id, cnt, *sz;
public:
	// Create an empty union find data structure with N isolated sets.
    UF(int N)   {
        cnt = N;
	id = new int[N];
	sz = new int[N];
        for(int i=0; i<N; i++)	{
            id[i] = i;
	    sz[i] = 1;
	}
    }
    ~UF()	{
	delete [] id;
	delete [] sz;
    }
	// Return the id of component corresponding to object p.
    int find(int p)	{
        int root = p;
        while (root != id[root])
            root = id[root];
        while (p != root) {
            int newp = id[p];
            id[p] = root;
            p = newp;
        }
        return root;
    }
	// Replace sets containing x and y with their union.
    void merge(int x, int y)	{
        int i = find(x);
        int j = find(y);
        if (i == j) return;

		// make smaller root point to larger one
        if   (sz[i] < sz[j])	{ 
		id[i] = j; 
		sz[j] += sz[i]; 
	} else	{ 
		id[j] = i; 
		sz[i] += sz[j]; 
	}
        cnt--;
    }
	// Are objects x and y in the same set?
    bool connected(int x, int y)    {
        return find(x) == find(y);
    }
	// Return the number of disjoint sets.
    int count() {
        return cnt;
    }
};


class vertex
{
    public:
        
        string get_name()
        {
            return highway_name;
        }
        
        void set_name(string name)
        {
            highway_name = name;
        }
        
        void set_weight(int weight)
        {
            highway_weight = weight;
        }
        
        int get_weight()
        {
            return highway_weight;
        }
        
        void add_edge(string edge_name)
        {
            edge_list.push_back(edge_name);
        }
        
        vertex() : highway_name("Default"), highway_weight(0), edge_list(0) {};
        
        vertex(string name, int weight) : highway_name(name), highway_weight(weight), edge_list(0) {};
        
    private:
        
        string highway_name;
        int highway_weight; 
        vector<string> edge_list ;
};


// class node
// {
//     public:
//         string city_name;

//         node *next;
        
//         node() : highway_value(0), city_name(0), highway_name(0), next(0) {};
        
//         void setCurr(int val)
//         {
//             curr_value = val;
//         }
        
// };


int main(int argc, char **argv)
{
    string commandline;
    string commandlinein;
    string commandlineout;
    bool breaker = false;
    const char * txtfilein;
    const char * txtfileout;
    
    commandline = argv[1];
    commandlinein = commandline;
    commandlineout = commandline + ".out";
    txtfilein = commandlinein.c_str();
    txtfileout = commandlineout.c_str();
    

    
    ifstream fin  (txtfilein);
    ofstream fout (txtfileout);
    
    string currstring;
    string paths;
    fin >> currstring;
    
    fin >> paths;
    int pathsnums = atoi(paths.c_str());
    int pointsnums = atoi(currstring.c_str());
    vector<string> pointlist;
    vector< vector<string> > pathlist; 
    
    for(int i = pointsnums; i > 0; i--)
    {
        fin >> currstring;
        pointlist.push_back(currstring);

        
    }
   
    for (int j = 0; j < pathsnums; j++)
    {  
        fin >> currstring;
        pathlist.push_back(vector<string>());

        pathlist[j].push_back(currstring);
        fin >> currstring;
        pathlist[j].push_back(currstring);
        fin >> currstring;
        pathlist[j].push_back(currstring);
        fin >> currstring;
        pathlist[j].push_back(currstring);
        
    }
    
  
    // cout << "Testing Vectors: " << endl;
    // for (int z = 0; z < pointlist.size(); z++)
    // {
    //     cout << (z + 1) << ": " << pointlist.at(z) << endl;
    // }
    
    // cout << "Second vector: " << endl;
    // for(int y = 0; y < pathlist.size(); y++)
    // {
    //     for (int x = 0; x < pathlist[y].size(); x++)
    //     {
    //         cout << (y + 1) << ": " << (x + 1) << ": " << pathlist.at(y).at(x) << endl;
    //     }
    // }
    
    for(int m = 0; m < pointlist.size(); m++)
    {
        fout << pointlist.at(m) << endl;
        for(int o = 0; o < pathlist.size(); o++)
        {
            for(int p = 0; p < pathlist[o].size(); p++)
            {
                if (pathlist[o].at(p) == pointlist.at(m))
                {
                    fout << "   " << pathlist[o].at(0);
                    fout << " " << pathlist[o].at(1);
                    fout << " " << pathlist[o].at(2);
                    fout << " " << pathlist[o].at(3) << endl;
                }
            }
            
        }
    }
    
    
    
    
    fout << endl;
    fout << "Creating NUTS:  " << endl;
    fout << endl;
    int weight = 0;
    for(int c = 0; c < pointlist.size(); c++)
        {

    
    for(int a = 0; a < pathlist.size(); a++)
        {
            for(int b = 0; b < pathlist[a].size(); b++)
            {
                if (pathlist[a].at(b) == pointlist.at(c))
                    {
                
                    weight += atoi(pathlist[a].at(1).c_str());
                    }
                
            }
            
        }
        }
    
    fout << "weight: " << weight << endl;
    fout << endl;
    
    fout << "Unfortunatly I have no more I can do other than that. Sorry" << endl;
    fout << "Professor. Finals, you know? I would have loved to get this assignment" << endl;
    fout << "working, because it seems really fun. Thanks for the fun quarter anyway!" << endl;
    
    
    
    
    
    
    return 0;
}
    