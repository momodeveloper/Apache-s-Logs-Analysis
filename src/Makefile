all : main clear

clear:
	rm *.o

debug:
	valgrind --leak-check=full ./main

main : main.o Log.o Flux.o Graphe.o
	g++ -o main main.o Log.o Graphe.o Flux.o -g

Log.o : Log.cpp Log.h
	g++ -c Log.cpp -ansi -pedantic -Wall -std=c++11 -g

Flux.o : Flux.cpp Flux.h
	g++ -c Flux.cpp -ansi -pedantic -Wall -std=c++11 -g

Graphe.o : Graphe.cpp Graphe.h
	g++ -c Graphe.cpp -ansi -pedantic -Wall -std=c++11 -g

main.o :  main.cpp
	g++ -c main.cpp -ansi -pedantic -Wall -std=c++11 -g
