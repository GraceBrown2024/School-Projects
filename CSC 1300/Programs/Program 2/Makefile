
# 	Name		: Grace Brown
#	Last Edited	: 6 March 2026
#	File name	: Makefile
#	Purpose		: Compilation instructions for Program2.cpp

### Hooray I love makefiles and headerfiles :)

all:		Diceprog									

Diceprog:	Program2.cpp functions.cpp 						#compile with just "make"
			g++ -Wall -o prog Program2.cpp functions.cpp

run:		Diceprog										#run with "make run"
			./prog

clean:		Diceprog										#delete .exe with "make clean"
			rm -f prog