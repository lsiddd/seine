CC=g++
CFLAGS=-Isrc/ -Iinclude/ -std=c++11

.PHONY: seine debug

seine: src/seine.cc
	g++ -o seine src/seine.cc -O3 $(CFLAGS)

debug: src/seine.cc
	g++ -o seine -g src/seine.cc $(CFLAGS)
	gdb seine
