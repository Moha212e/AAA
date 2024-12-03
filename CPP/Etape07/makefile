# Définition des fichiers objets
OBJS = Event.o Time.o Timing.o Exception.o TimeException.o TimingException.o Classroom.o Schedulable.o XmlFileSerializerException.o

# Règles pour les exécutables
Test07: Test7.cpp $(OBJS)
	g++ Test7.cpp $(OBJS) -o Test07

Test06: Test6.cpp $(OBJS)
	g++ Test6.cpp $(OBJS) -o Test06

Test05: Test5.cpp $(OBJS)
	g++ Test5.cpp $(OBJS) -o Test05

Test04: Test4.cpp Professor.o Group.o Classroom.o Schedulable.o
	g++ Test4.cpp Professor.o Group.o Classroom.o Schedulable.o -o Test04

Test03: Test3.cpp Event.o Time.o Timing.o
	g++ Test3.cpp Event.o Time.o Timing.o -o Test03

Test02: Test2.cpp Event.o Time.o Timing.o
	g++ Test2.cpp Event.o Time.o Timing.o -o Test02

# Compilation des fichiers .cpp en .o
XmlFileSerializerException.o: XmlFileSerializerException.cpp XmlFileSerializerException.h
	g++ -c XmlFileSerializerException.cpp -o XmlFileSerializerException.o

TimingException.o: TimingException.cpp TimingException.h
	g++ -c TimingException.cpp -o TimingException.o

TimeException.o: TimeException.cpp TimeException.h
	g++ -c TimeException.cpp -o TimeException.o

Exception.o: Exception.cpp Exception.h
	g++ -c Exception.cpp -o Exception.o

Classroom.o: Classroom.cpp Classroom.h
	g++ -c Classroom.cpp -o Classroom.o

Group.o: Group.cpp Group.h
	g++ -c Group.cpp -o Group.o

Professor.o: Professor.cpp Professor.h
	g++ -c Professor.cpp -o Professor.o

Schedulable.o: Schedulable.cpp Schedulable.h
	g++ -c Schedulable.cpp -o Schedulable.o

Event.o: Event.cpp Event.h
	g++ -c Event.cpp -o Event.o

Time.o: Time.cpp Time.h
	g++ -c Time.cpp -o Time.o

Timing.o: Timing.cpp Timing.h
	g++ -c Timing.cpp -o Timing.o

# Nettoyage des fichiers objets et exécutables
clean:
	rm -f *.o Test07 Test06 Test05 Test04 Test03 Test02
