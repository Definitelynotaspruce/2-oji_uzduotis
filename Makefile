main:  funkcijos.o Studentas.o main2.o
	g++ -o main main2.cpp funkcijos.cpp Studentas.cpp 
clean:
	rm *.o *.txt main
