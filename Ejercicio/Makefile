CXX = g++
CXXFLAGS = -std=c++11 -g -Wall
LDFLAGS = 

all: cripto

cripto: cripto.o funciones_cripto.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)
