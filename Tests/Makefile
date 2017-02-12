#Janor type traits test

CXX:= g++-6
SOURCE_DIR:= -I/usr/local/src
INCLUDE_DIR:= -I/usr/local/include -I../include -Iinclude
LIB_DIR:= -L/usr/local/libs
LIBS:= -lgtest -lgtest_main -lpthread
MAIN_FILE:= Test_type_traits.cpp

install:
	$(CXX) $(MAIN_FILE) $(INCLUDE_DIR) $(SOURCE_DIR) $(LIB_DIR) $(LIBS) 

clean:
	rm *.out