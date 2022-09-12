#libpair.so : pair.cpp
#	mkdir lib
#	g++ -shared -fPIC -o ./lib/libpair.so pair.cpp 
#	g++ -o main main.cpp ./lib/libpair.so 

GCC = g++
TARGET = libpair.so
OBJECT = pair.cpp
LIB_PATH = ./lib/

$(TARGET) : $(OBJECT)
	mkdir lib
	$(GCC) -shared -fPIC -o $(LIB_PATH)$(TARGET) $(OBJECT)
	$(GCC) -o main main.cpp $(LIB_PATH)$(TARGET)

