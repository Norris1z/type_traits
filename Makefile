# janor type_traits makefile
INCLUDE_DIR := -Iinclude
CXX_FLAGS := -Wall -Wextra -pedantic -std=c++11
MAIN_FILE := main.cpp

install:
	$(CXX) $(MAIN_FILE) $(INCLUDE_DIR) $(CXX_FLAGS)

clean:
	rm *.exe
