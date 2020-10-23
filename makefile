.PHONY: clean

all: Mastermind

Mastermind: Main.o Menu.o Logic.o
	g++ -std=c++11 -Wall -Werror build/Main.o build/Menu.o build/Logic.o -o bin/Mastermind

Main.o:
	g++ -std=c++11 -Wall -Werror -c src/Main.cpp -o build/Main.o 

Menu.o:
	g++ -std=c++11 -Wall -Werror -c src/Menu.cpp -o build/Menu.o

Logic.o:
	g++ -std=c++11 -Wall -Werror -c src/Logic.cpp -o build/Logic.o

clean:
	rm -rf build/test/*.o build/src/*.o bin/Mastermind bin/Test \
		$(GTEST_LIB_DIR)/lib/libgtest.a $(GTEST_LIB_DIR)/lib/libgtest_main.a $(GTEST_LIB_DIR)/lib/*.o
GTEST_LIB_DIR = thirdparty/googletest

USER_DIR = src

USER_DIR_O = build/test

USER_DIR_b = bin

CPPFLAGS += -isystem thirdparty/googletest/include

CXXFLAGS += -g -Wall -Wextra -pthread -std=c++11

GTEST_LIBS = libgtest.a libgtest_main.a

TESTS = unittest.cpp

GTEST_HEADERS = $(GTEST_LIB_DIR)/include/gtest/*.h \
                $(GTEST_LIB_DIR)/include/gtest/internal/*.h

GTEST_SRCS_ = $(GTEST_LIB_DIR)/src/*.cc $(GTEST_LIB_DIR)/src/*.h $(GTEST_HEADERS)

$(GTEST_LIB_DIR)/lib/gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_LIB_DIR) $(CXXFLAGS) -c \
            $(GTEST_LIB_DIR)/src/gtest-all.cc -o $(GTEST_LIB_DIR)/lib/gtest-all.o

$(GTEST_LIB_DIR)/lib/gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_LIB_DIR) $(CXXFLAGS) -c \
            $(GTEST_LIB_DIR)/src/gtest_main.cc -o $(GTEST_LIB_DIR)/lib/gtest_main.o

$(GTEST_LIB_DIR)/lib/libgtest.a : $(GTEST_LIB_DIR)/lib/gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

$(GTEST_LIB_DIR)/lib/libgtest_main.a : $(GTEST_LIB_DIR)/lib/gtest-all.o $(GTEST_LIB_DIR)/lib/gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

test: $(GTEST_LIB_DIR)/lib/libgtest_main.a $(GTEST_LIB_DIR)/lib/libgtest.a $(TESTS)

$(TESTS) : $(USER_DIR_O)/unittest.o $(USER_DIR_O)/Logic.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -L$(GTEST_LIB_DIR)/lib -lgtest_main -lpthread $^ -o $(USER_DIR_b)/Test

$(USER_DIR_O)/unittest.o : test/unittest.cpp $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c test/unittest.cpp -o $@

$(USER_DIR_O)/Logic.o : $(USER_DIR)/Logic.cpp $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/Logic.cpp -o $@
