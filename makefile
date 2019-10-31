ALL: Compile Run
Nesneler :=  ./lib/Error.o ./lib/Errors.o

Compile:
	g++ -I ./include/ -o ./lib/Error.o -c ./src/Error.cpp
	g++ -I ./include/ -o ./lib/Errors.o -c ./src/Errors.cpp
	g++ -I ./include/ -o ./bin/test $(Nesneler) ./src/test.cpp
	
Run:
	./bin/test