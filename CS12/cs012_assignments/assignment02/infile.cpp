
#include <iostream>
#include <cstdlib>
#include <fstring> 

using namespace std;

int main(int argc, char *argv[])

cout << "Count: " << argc << endl;
cout << argv[0] << ' ' << argv[1] << endl;

// in terminal ./a.out mklk.txt


//structs//
// #include iostream, vector
struct Exam
{
    string usrname; // names (initialized as empty)
    double score;   // scores (initialized as garbage)
}; // semicolin is neccisary

int main()
{
    Exam exam1;
    exam1.usrname = "kmiller";
    exam1.score = 66.7;
    cout << exam1.usrname << endl;
    cout << exam1.score << endl
}