LINK	= @echo linking $@ && g++
GCC		= @echo compiling $@ && g++
FLAGS	= -g -DDEBUG -W -Wall -fPIC 
GCCFLAGS= 
DEFINES = 
HEADER	= -I./
LIBS	= 
LINKFLAGS = 

HEADER += -I./pair
#链接的时候从lib目录下找libpair.so
LIBS	+= -L../lib -lpair

OBJECT := main.o \

#加入了lib的相对路径，编写完的main会install到lib下面
LIB_PATH = ../lib/

TARGET = main

$(TARGET) : $(OBJECT)
	$(LINK) $(FLAGS) $(LINKFLAGS) -o $@ $^ $(LIBS)

.cpp.o:
	$(GCC) -c $(HEADER) $(FLAGS) $(GCCFLAGS) -fpermissive -o $@ $<

install: $(TARGET)
	cp $(TARGET) $(LIB_PATH)

clean:
	rm -rf $(TARGET) *.o *.so


