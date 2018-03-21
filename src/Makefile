main: main.o
	g++ main.o -o main
	rm main.o

main.o: main.cc
	g++ -c main.cc -I../vendor/png++-0.2.9/ -I../vendor/lpng1632/
