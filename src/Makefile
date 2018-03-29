CC = g++ -std=c++0x

main: main.o
	${CC} main.o -o main ../vendor/libpng/lib/libpng16.a ../vendor/zlib/lib/libz.a 
	rm main.o

main.o: main.cc
	${CC} -c main.cc -I../vendor/png++-0.2.9/ -I../vendor/libpng/include/libpng16/

cyg:
	${CC} -c main.cc -I../vendor/png++-0.2.9/ -I../vendor/libpngCYG/include/libpng16/
	${CC} main.o -o main ../vendor/libpngCYG/lib/libpng.a ../vendor/zlibCYG/lib/libz.a 
	rm main.o
	
