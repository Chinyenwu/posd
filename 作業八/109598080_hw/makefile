.PHONY: dirs clean

all: dirs ut_main

ut_main:
	g++ -std=c++11 -o ./bin/ut_main ./src/node.cpp ./test/ut_main.cpp -lgtest -lpthread
dirs:
	mkdir -p bin
	mkdir -p obj

clean:
	rm -f bin/*
