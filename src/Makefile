CC = g++ -std=c++0x
CCCYG = g++

# Compiler flags:
#   -Wall (most warnings enabled)
#   -g (for debugging with gdb)
CFLAGS = -Wall

main: main.o
	${CC}  $(CFLAGS) main.o -o main ../vendor/libpng/lib/libpng16.a ../vendor/zlib/lib/libz.a 
	rm main.o

main.o: main.cc
	${CC}  $(CFLAGS) -c main.cc -I../vendor/png++-0.2.9/ -I../vendor/libpng/include/libpng16/

cyg:
	${CCCYG}  $(CFLAGS) -c main.cc -I../vendor/png++-0.2.9/ -I../vendor/libpngCYG/include/libpng16/
	${CCCYG}  $(CFLAGS) main.o -o main ../vendor/libpngCYG/lib/libpng.a ../vendor/zlibCYG/lib/libz.a 
	rm main.o
	
