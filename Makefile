TARGET=add-nbo

all: $(TARGET)

$(TARGET): add-nbo.o
	gcc -o $(TARGET) add-nbo.o

add-nbo.o:
	gcc -c add-nbo.cpp
clean:
	rm -f $(TARGET)
	rm -f *.o

