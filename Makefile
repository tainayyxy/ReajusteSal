CXX ?= g++
CXXFLAGS ?= -std=c++17 -Wall -Wextra -Wpedantic -O2
TARGET = ReajusteSal
SOURCE = src/main.cpp

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CXX) $(CXXFLAGS) $(SOURCE) -o $(TARGET)

clean:
	rm -f $(TARGET) $(TARGET).exe
