main: funkcijos.o Studentas.o main.o
	g++ -o main main.cpp funkcijos.cpp Studentas.cpp
build:
	g++ -o main main.cpp funkcijos Studentas.cpp
clean:
	rm *.o main 