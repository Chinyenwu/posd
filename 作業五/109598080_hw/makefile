.PHONY: dirs clean

all: dirs ut_main

ut_main: test/ut_main.cpp test/ut_rectangle.h test/ut_triangle.h src/rectangle.h src/triangle.h src/shape.h test/ut_ellipse.h src/ellipse.h test/ut_compound_shape.h src/compound_shape.h \
					src/iterator.h src/null_iterator.h src/shape_iterator.h src/utility.h test/ut_iterator.h test/ut_utility.h
	g++ -std=c++11 -o ./bin/ut_main ./src/shape.cpp ./test/ut_main.cpp -lgtest -lpthread
dirs:
	mkdir -p bin
	mkdir -p obj

clean:
	rm -f bin/*
