CC=g++
CFLAGS=-Isrc/

.PHONY: seine debug asm

seine: src/seine.cc
	g++ -o seine src/seine.cc -O3

debug: src/seine.cc
	g++ -o seine -g src/seine.cc
	gdb seine
