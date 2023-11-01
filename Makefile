CC = g++
CFLAGS = -Wall -c
TARGET = cpusim
SRC = *.cpp

# linker flags
LDFLAGS = -Wall

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(LDFLAGS) -o $(TARGET) $(SRC)

# Clean target to remove executable
clean:
	rm -f $(TARGET) .*~ *~

