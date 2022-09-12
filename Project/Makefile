TARGET = ./main

SRCS := $(wildcard ./src/*.cpp ./*.cpp)

OBJS := $(patsubst %cpp,%o,$(SRCS))

CFLG = -g -Wall -I/opt/homebrew/Cellar/opencv/4.5.5_2/include/opencv4/opencv2 -Iinc -I./ -std=c++11

LDFG = -Wl, $(shell pkg-config opencv --cflags --libs)

CXX = g++

$(TARGET) : $(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LDFG)

%.o:%.cpp
	$(CXX) $(CFLG) -c $< -o $@ 

.PHONY : clean
clean:
	-rm ./*.o

