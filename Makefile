CXX = g++
CXXFLAGS = -std=c++17
LDFLAGS = -lsfml-window -lsfml-system

SRC = main.cpp
TARGET = coin_collector

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)

