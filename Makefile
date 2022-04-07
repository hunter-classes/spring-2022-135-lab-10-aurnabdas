main: main.o time.o 
	g++ -o main main.o time.o
tests: test.o time.o
	g++ -o test test.o time.o


main.o: main.cpp time.h 
	g++ -std=c++11  -c main.cpp

time.o: time.cpp time.h 
	g++ -std=c++11  -c time.cpp

test.o: test.cpp doctest.h time.h
	g++ -std=c++11  -c test.cpp


clean:
	rm main.o time.o test.o