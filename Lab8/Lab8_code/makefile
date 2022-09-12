CC = g++
TARGET = testfiles
OBJ = main.o candybar.o 

CFLANGES = -c -Wall

$(TARGET) : $(OBJ)
	$(CC) -o $@ $(OBJ)

$.o : %.cpp
	$(CC) $(CFLANGES) $< -o $@

.PHONY : clean
clean:
	rm -f *.o $(TARGET)