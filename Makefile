OPTIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++11 -fno-extended-identifiers 

program.exe: program.o Cjt_estaciones.o Estacion.o Cjt_bicicletas.o Bicicleta.o 
	g++ $(OPTIONS) -o program.exe program.o Cjt_estaciones.o Estacion.o Cjt_bicicletas.o Bicicleta.o

program.o: program.cc
	g++ $(OPTIONS) -c program.cc

Cjt_bicicletas.o: Cjt_bicicletas.cc
	g++ $(OPTIONS) -c Cjt_bicicletas.cc

Cjt_estaciones.o: Cjt_estaciones.cc
	g++ $(OPTIONS) -c Cjt_estaciones.cc

Bicicleta.o: Bicicleta.cc
	g++ $(OPTIONS) -c Bicicleta.cc

Estacion.o: Estacion.cc
	g++ $(OPTIONS) -c Estacion.cc

clean:
		rm -f *.exe *.o

all:
		make clean
		make
		make tar
tar: Makefile program.cc Cjt_estaciones.cc Cjt_estaciones.hh Estacion.cc Estacion.hh Cjt_bicicletas.cc Cjt_bicicletas.hh Bicicleta.cc Bicicleta.hh
		tar -cvf practica.tar Makefile program.cc Cjt_estaciones.cc Cjt_estaciones.hh Estacion.cc Estacion.hh Cjt_bicicletas.cc Cjt_bicicletas.hh Bicicleta.cc Bicicleta.hh


