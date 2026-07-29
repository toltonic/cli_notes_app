CC = gcc
CFLAGS = -Wall -Wextra -I include

TARGET = notes

SRC = src/main.c \
      src/notes.c

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -rf $(TARGET)
