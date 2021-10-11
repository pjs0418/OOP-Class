main : student.o search.o sort.o main.o
	g++ student.o search.o sort.o main.o -o main

student.o : student.h student.cpp
	g++ -c student.cpp

search.o : search.h search.cpp
	g++ -c search.cpp

sort.o : sort.h sort.cpp
	g++ -c sort.cpp

clean :
	rm -f *.o main