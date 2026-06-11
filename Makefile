CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRC = src/main.c src/shell.c
OBJ = $(SRC:.c=.o)
TARGET = addu-sh

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean