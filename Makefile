# Compiler settings
CXX = g++
CXXFLAGS = -std=c++2a

# Find all .cpp files in the current directory
SOURCES := $(wildcard **/*.cpp)

# Generate corresponding .out file names
TARGETS := $(SOURCES:.cpp=.out)

# Rule to compile .cpp files to .out files
all: $(TARGETS)

%.out: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f $(TARGETS)
