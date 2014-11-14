# Project: gtest_triangle

CPP       = g++
CC        = gcc
OBJ       = gtest_main.o triangle.o triangle_unittest.o
LINKOBJ   = gtest_main.o triangle.o triangle_unittest.o
LINKFLAGS = -lgtest -pthread -lgcov
BIN       = gtest_triangle
CXXFLAGS  = -Wall -O2 -fprofile-arcs -ftest-coverage
CFLAGS    = -Wall -O2 -fprofile-arcs -ftest-coverage
RM        = rm -f
GCOV_FILE = *.gcno *.gcda *.gcov

.PHONY: all all-before all-after clean clean-custom

all: all-before $(BIN) all-after

clean: clean-custom
	${RM} $(OBJ) $(BIN) $(GCOV_FILE)

$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o $(BIN) $(LINKFLAGS)

gtest_main.o: gtest_main.cc
	$(CPP) -c gtest_main.cc -o gtest_main.o $(CXXFLAGS)

triangle.o: triangle.c
	$(CPP) -c triangle.c -o triangle.o $(CXXFLAGS)

triangle_unittest.o: triangle_unittest.cc
	$(CPP) -c triangle_unittest.cc -o triangle_unittest.o $(CXXFLAGS)
