#include <iostream>
#include <cstdlib>
#include "Music_collection.h"

using namespace std;

Music_collection::Music_collection()
{
    number = 0;
    max = 100;
    collection = new Tune[max];
}

Music_collection::Music_collection(int n)
{
    number = 0;
    max = n;
    collection = new Tune[max];
}

Music_collection::Music_collection(const Music_collection &m)
{
    collection = new Tune[m.max];
    number = m.number;
    max = m.max;

    for(int i = 0; i < number; ++i)
    {
        collection[i] = m.collection[i];
    }
}

bool Music_collection::add_tune( const Tune &t)
{
 
    if (number >= max)
    {
        return false;
    }
        ++number;
        collection[number - 1] = t;
        return true;

    
}

bool Music_collection::set_tune(int index, const Tune &t)
{
    if (index >= number)
    {
        return false;
    }
    else
    {
        collection[index] = t;
        return true;
    }
}

Music_collection & Music_collection::operator=( const Music_collection &m)
{
	collection = new Tune[m.max];
	
	number = m.number;
	max = m.max;
	for(int i=0; i<m.number; i++)
		collection[i] = m.collection[i];
	return *this;
}

Music_collection::~Music_collection()
{
    delete [] collection;
    collection = 0;
}
 
ostream & operator<<( ostream &out, const Music_collection &m)
{
    for(int i=0; i<m.number; i++)
		out << m.collection[i].get_title() << '\n';
	return out;
}

Tune::Tune()
{
    title;
}

Tune::Tune( const string &n)
{
    title = n;
}

const string & Tune::get_title() const
{
    return title;
}
