#include <iostream>
#include "cpp.h"
#include <string.h>
#include <vector>

using namespace std;

#define NUM_SEATS 6
#define TINY 1.e-20
#define TERMNL 1
#define CARLOT 0

facility_set *buttons;
facility_set *terminals;
facility rest("rest");

//vector <long> termianls;
//variable declerations 
int T;
int S;
int M;

vector <string> places;
vector <string> people;
vector <long> count;
 

//event declerations
event_set *get_off;
event_set *hop_on;
event boarded("boarded");
event_set *shuttle_called;

mailbox_set *pass;

//function declarations
void make_passengers(long whereami);
long group_size();
void passengers(long whoami, long go);
void shuttle(long ID);
void loop_around_airport(long & seats_used, long Shuttle_ID);
void load_shuttle(long whereami, long & on_board, long Shuttle_ID);
qtable shuttle_occ1("bus 1 occupancy");
qtable shuttle_occ2("bus 2 occupancy");
extern "C" void sim(int argc, char *argv[])
{
	create("sim");
	if(argc > 3)
	{
		T = atoi(argv[1]) + 1;
		S = atoi(argv[2]);
		M = atoi(argv[3]);
	}
	else 
	{
		T = 2;
		S = 1;
		M = 10;
	}
 buttons = new facility_set("Call", T);
 terminals = new facility_set("Terminal", T);

 hop_on = new event_set("hop_on", T*S);

 pass = new mailbox_set((char*)"mail", T);

 shuttle_called = new event_set ("call button" , T);

 get_off = new event_set("get_off", S*T);
 
 

 shuttle_occ1.add_histogram(NUM_SEATS+1,0,NUM_SEATS);       
 shuttle_occ2.add_histogram(NUM_SEATS+1,0,NUM_SEATS);

 places.push_back("CARLOT");
 make_passengers(CARLOT);
 people.push_back("arr_pass");
 count.push_back(0);
 for (long j = 0; j < S; j++)
 {	count.push_back(0);
	
        shuttle(j);
 }

 for (long i = 0; i < T; i++)
 { 
	
	people.push_back("dep_pass" + i);
	places.push_back("Terminal" + i);
	//cout << "making passengers" << endl;
  	make_passengers(i);
 }
                                                                              
 hold(1440);
 report();
 status_facilities();
}

void make_passengers(long whereami)
{
	const char* myName = places[whereami].c_str();
	create(myName);

	while(clock < 1440)
	{
	
	hold(expntl(M+10));
		long group = group_size();	
		for (long i = 0; i < group; i++)
		{
			if (whereami < 1)
			{
		passengers(whereami, rand()%(T- 1) + 1);
			}
			else
			{
		passengers(whereami, 0);
			}
		}
	}
}

void passengers(long whoami, long go)
{	
	//cout << "entered pass" << endl;	
        const char * myName = people[whoami].c_str();

	
	create(myName);


	long id;
 	//cout << "receiving buss ID" << endl;

	
	//cout << "whats good" << endl;	
	(*buttons)[whoami].reserve();
	//cout << "reserved buttons" << endl;
	(*shuttle_called)[whoami].set();
	(*pass)[whoami].receive(&id);
	//cout << "Passenger create" << endl;
	long whoWoke = id;
	//cout << "Passenger created: this is who woke: "  << whoWoke << endl;
	(*shuttle_called)[whoami].clear();
	
	count.at(whoWoke) += 0;
	//cout << "person entered bus, current bus seats: " << count.at(whoWoke) << endl;
	hold(uniform(0.5,1.0));
	boarded.set();
	(*buttons)[whoami].release();
	//cout << "finding who woke " << whoWoke*go+go << "where am i going: " << go << endl;
	(*get_off)[go*whoWoke+go].wait();
	//cout << "found who woke" << endl;
	count.at(whoWoke) -= 1;
	//cout << "person left, current bus seats: " << count.at(whoWoke) << endl;
}

void shuttle(long ID) {
	create("shuttle");
	while(1) {  //Looping forever
		bool flag = true;
		//cout << "sup im a shuttle" << endl;
		rest.reserve();
		//cout << "reserved rest" << endl;
		long who_pushed = (*shuttle_called).wait_any();
		//cout <<"push found"  << who_pushed << endl;
		(*shuttle_called)[who_pushed].set();
		rest.release();

		long seats_used = 0;
		if(ID == 0)
		{ 
			shuttle_occ1.note_value(count.at(ID));
		}
		else if(ID == 1)
		{
			shuttle_occ2.note_value(count.at(ID));
		}
		hold(10);
		

 	 	while(flag)
	 	{
			flag = false;
			for(int i = 0; i < T; i++)
			{
			  if((*shuttle_called)[i].state() == OCC || count.at(ID) > 0)
			  {
				flag = true;
			  }
			}
			if (flag == true)
			{
		//cout << "in shuttle" << endl;
				loop_around_airport(count.at(ID), ID);
			}
		}
	}
}

long group_size() { //Determoning the number of people in each generation
	double x = prob();
	if (x < 0.3) return 1;
	else {
	   if (x < 0.7) return 2;
	   else return 5;
   } 
}

void loop_around_airport(long & seats_used, long Shuttle_ID)
{
	for(long i = 0; i < T; i++)
	{
	(*terminals)[i].reserve();
	//cout << "in loop around" << endl;
		if(count.at(Shuttle_ID) > 0)
		{
			//cout << "getting off" << endl;
			(*get_off)[i*Shuttle_ID+i].set();
			//cout << "got off" << endl;
			//cout << "custumer left" << endl;
			if(Shuttle_ID == 0)
			{ 
				shuttle_occ1.note_value(count.at(Shuttle_ID));
			}
			else if(Shuttle_ID == 1)
			{
				shuttle_occ2.note_value(count.at(Shuttle_ID));
			}
		
			
		}
	
	load_shuttle(i, count.at(Shuttle_ID), Shuttle_ID);
			if(Shuttle_ID == 0)
			{ 
				shuttle_occ1.note_value(count.at(Shuttle_ID));
			}
			else if(Shuttle_ID == 1)
			{
				shuttle_occ2.note_value(count.at(Shuttle_ID));
			}
	(*terminals)[i].release();
	hold(uniform(3,5));
}
}

void load_shuttle(long whereami, long & on_board, long Shuttle_ID)
{
	while((on_board < NUM_SEATS) && ((*buttons)[whereami].num_busy() + 
		(*buttons)[whereami].qlength() > 0))
	{  
	 	//cout << "hopping on" << endl;
		//cout << "Shuttle ID: " << Shuttle_ID << endl;
		//cout << "Current Location: " << whereami << endl;
		(*pass)[whereami].send(Shuttle_ID);
		//cout << "sent shuttle id" << endl;
		(*hop_on)[whereami*Shuttle_ID+ whereami].set();
		//cout << "hopped on" << endl;
		boarded.wait();
		on_board++;
		hold(TINY);
	}
}

