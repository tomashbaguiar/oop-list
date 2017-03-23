all: classe main clean

classe: classe.h
	g++ -Wall -Werror -std=c11 -c classe.cpp
main: classe.o main.cpp
	g++ -Wall -Werror -std=c11 -o main classe.o main.cpp
clean: classe.o
	rm classe.o
