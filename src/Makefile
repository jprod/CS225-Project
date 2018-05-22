CC = g++ -std=c++0x
CCCYG = g++

CCCL = cl

# Compiler flags:
#   -Wall (most warnings enabled)
#   -g (for debugging with gdb)
CFLAGS = -Wall 

vend_prefix = ../vendor
pngppdir = $(vend_prefix)/png++-0.2.9
libpngdir = $(vend_prefix)/libpng/include/libpng16
libpng = $(vend_prefix)/libpng/lib/libpng16.a
libz = $(vend_prefix)/zlib/lib/libz.a 
cyglibpngdir = $(vend_prefix)/libpngCYG/include/libpng16
cyglibpng = $(vend_prefix)/libpngCYG/lib/libpng16.a
cyglibz = $(vend_prefix)/zlibCYG/lib/libz.a
cllibpngdir = C:\CLibs\MVS\libpng-1.6.34
cllibpng = C:\CLibs\MVS\libpng-1.6.34\libpng.lib
cllibz = C:\CLibs\MVS\zlib

OBJ = main.o GradientAlgorithm.o ColorPoint.o HorizontalGradient.o CurveGradient.o Point.o TriRadialGradient.o
GOBJ = GradientAlgorithm.o

main: $(OBJ)
	$(CC)  $(CFLAGS) $(OBJ) -o main $(libpng) $(libz)
	rm $(OBJ)

main.o: main.cc
	$(CC)  $(CFLAGS) -c main.cc -I $(libpngdir)

GradientAlgorithm.o: GradientAlgorithm.hpp GradientAlgorithm.cc
	$(CC)  $(CFLAGS) -c GradientAlgorithm.cc -I $(libpngdir)

ColorPoint.o: ColorPoint.hpp ColorPoint.cc
	$(CC)  $(CFLAGS) -c ColorPoint.cc -I $(libpngdir)

HorizontalGradient.o: HorizontalGradient.hpp HorizontalGradient.cc
	$(CC)  $(CFLAGS) -c HorizontalGradient.cc -I $(libpngdir)

CurveGradient.o: CurveGradient.hpp CurveGradient.cc
	$(CC)  $(CFLAGS) -c CurveGradient.cc -I $(libpngdir)

Point.o: Point.hpp Point.cc
	$(CC)  $(CFLAGS) -c Point.cc -I $(libpngdir)

TriRadialGradient.o: TriRadialGradient.hpp TriRadialGradient.cc
	$(CC)  $(CFLAGS) -c TriRadialGradient.cc -I $(libpngdir)

cyg:
	$(CCCYG)  $(CFLAGS) -c main.cc -I $(cyglibpngdir)
	$(CCCYG)  $(CFLAGS) -c GradientAlgorithm.cc  -I $(cyglibpngdir)
	$(CCCYG)  $(CFLAGS) -c ColorPoint.cc  -I $(cyglibpngdir)
	$(CCCYG)  $(CFLAGS) -c HorizontalGradient.cc -I $(cyglibpngdir)
	$(CCCYG)  $(CFLAGS) -c CurveGradient.cc  -I $(cyglibpngdir)
	$(CCCYG)  $(CFLAGS) -c Point.cc  -I $(cyglibpngdir)
	$(CCCYG)  $(CFLAGS) -c TriRadialGradient.cc  -I $(cyglibpngdir)
	$(CCCYG)  $(CFLAGS) $(OBJ) -o main $(cyglibpng) $(cyglibz)
	rm $(OBJ)
	
cl:
	$(CCCL)  $(CFLAGS) -c main.cc -I $(cllibpngdir)
	$(CCCL)  $(CFLAGS) -c GradientAlgorithm.cc  -I $(cllibpngdir)
	$(CCCL)  $(CFLAGS) -c ColorPoint.cc  -I $(cllibpngdir)
	$(CCCL)  $(CFLAGS) -c HorizontalGradient.cc -I $(cllibpngdir)
	$(CCCL)  $(CFLAGS) -c CurveGradient.cc  -I $(cllibpngdir)
	$(CCCL)  $(CFLAGS) -c Point.cc  -I $(cllibpngdir)
	$(CCCL)  $(CFLAGS) -c TriRadialGradient.cc  -I $(cllibpngdir)
	$(CCCL)  $(CFLAGS) $(OBJ) -o main $(cllibpng) $(cllibz)
	rm $(OBJ)
	
	
clean: 
	rm -f $(OBJ)
