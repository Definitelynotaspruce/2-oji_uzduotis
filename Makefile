main: funkcijos.o funkcijos2.o Studentas.o main.o
	g++ -o main main.cpp funkcijos.cpp Studentas.cpp funkcijos2.cpp
clean:
	rm *.o *.txt
