LINK	= @echo linking $@ && g++
GCC		= @echo compiling $@ && g++
FLAGS	= -g -DDEBUG -W -Wall -fPIC 
GCCFLAGS= 
DEFINES = 
HEADER	= -I./
LIBS	= 
LINKFLAGS = -shared

#HEADER += -I./pair
#链接的时候从bin目录下找libpair.so

OBJECT := pair.o 	#编译pair.cpp

#指出bin的相对路径
LIB_PATH = ../../lib/	
#生成的文件libpair.so
TARGET = libpair.so

$(TARGET) : $(OBJECT)
	$(LINK) $(FLAGS) $(LINKFLAGS) -o $@ $^ $(LIBS)

.cpp.o:
	$(GCC) -c $(HEADER) $(FLAGS) $(GCCFLAGS) -fpermissive -o $@ $<

install: $(TARGET)
	cp $(TARGET) $(LIB_PATH)

clean:
	rm -rf $(TARGET) *.o *.so


