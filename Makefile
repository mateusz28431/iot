CXX = g++
SRC = $(wildcard ./src/*.cpp)
OBJ = $(SRC:.cpp=.o)
CXXFLAGS = -std=c++11
LDFLAGS = -lmosquitto

iot: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(OBJ) iot