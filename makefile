.PHONY: clean

all: Mastermind

Mastermind: Main.o Menu.o Logic.o
	g++ -std=c++11 -Wall -Werror build/Main.o build/Menu.o build/Logic.o -o bin/Mastermind

Main.o:
	g++ -std=c++11 -Wall -Werror -c src/Main.cpp -o build/Main.o 

Menu.o:
	g++ -std=c++11 -Wall -Werror -c src/Menu.cpp -o build/Menu.o

Logic.o:
	g++ -std=c++11 -Wall -Werror -c src/Logic.cpp -o build/Logic.o

clean:
	rm -rf build/test/*.o build/src/*.o bin/Mastermind bin/Test
