CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

TARGET = test

SRC = src/main.c \
	  src/notes.c

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -rf $(TARGET)
