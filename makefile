OBJECTS = main.o
SRC = main.cpp

CC = g++
CPPFLAGS = -g -c

TARGET = main

$(TARGET): $(OBJECTS) LinkedList.h
			 $(CC) -o $(TARGET) $(OBJECTS)
clean:
	rm $(OBJECTS) $(TARGET)
