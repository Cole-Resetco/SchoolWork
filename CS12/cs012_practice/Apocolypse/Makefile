

#BBoard makefile

#variables
COMPILE = g++
FLAGS = -W -Wall -Werror -ansi -pedantic
DEBUG = -g -W -Wall -Werror -ansi -pedantic
OBJS = Interface.o Items.o Guns.o Melee.o Armor.o Food.o

#Targets

all: main.cpp $(OBJS)
	$(COMPILE) $(FLAGS) -o a.out main.cpp $(OBJS)

Interface.o: Interface.cpp Interface.h
	$(COMPILE) $(FLAGS) -c Interface.cpp

Items.o: Items.cpp Items.h
	$(COMPILE) $(FLAGS) -c Items.cpp

Guns.o: Guns.cpp Guns.h
	$(COMPILE) $(FLAGS) -c Guns.cpp
    
Melee.o: Melee.cpp Melee.h
	$(COMPILE) $(FLAGS) -c Melee.cpp
    
Armor.o: Armor.cpp Armor.h
	$(COMPILE) $(FLAGS) -c Armor.cpp
	
Food.o: Food.cpp Food.h
	$(COMPILE) $(FLAGS) -c Food.cpp

clean:
	rm -rf *~ *.o a.out

tar:
	tar -czvf assn6.tgz *.cpp *.h Makefile

debug: main.cpp $(OBJS)
	$(COMPILE) $(DEBUG) -o a.out main.cpp $(OBJS)