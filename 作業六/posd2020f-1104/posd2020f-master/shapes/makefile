.PHONY: dirs clean

SRC = src/rectangle.h src/triangle.h src/shape.h src/mixed_shape.h src/shape_iterator.h \
			src/iterator.h src/null_iterator.h src/find_first_visitor.h src/shape_visitor.h
TEST = test/ut_rectangle.h test/ut_triangle.h test/ut_sort.h test/ut_mixed_shape.h \
				test/ut_iterator.h test/ut_visitor.h test/ut_string.h
OBJ = obj/find_first_visitor.o

all: dirs ut_main

ut_main: test/ut_main.cpp $(TEST) $(SRC) $(OBJ)
	g++ -std=c++11 -Wfatal-errors -Wall test/ut_main.cpp obj/find_first_visitor.o -o bin/ut_main -lgtest -lpthread

obj/find_first_visitor.o: src/find_first_visitor.cpp src/find_first_visitor.h
	g++ -std=c++11 -Wfatal-errors -Wall -c src/find_first_visitor.cpp -o obj/find_first_visitor.o

dirs:
	mkdir -p bin
	mkdir -p obj

clean:
	rm -f bin/* obj/*

stat:
	wc -l src/* test/*.h test/*.cpp
