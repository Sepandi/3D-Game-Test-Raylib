all:
	clang++ main.cpp -framework IOKit -framework Cocoa -framework OpenGL -o GAME -O3 -Wall -std=c++2b -Wno-missing-braces -Linclude/lib -lraylib -I include/ -I Engine/
	./GAME