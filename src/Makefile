main: main.o
	g++ main.o -o main ../vendor/libpng/lib/libpng16.a ../vendor/zlib/lib/libz.a
	rm main.o

main.o: main.cc
	g++ -c main.cc -I../vendor/png++-0.2.9/ -I../vendor/libpng/include/libpng16