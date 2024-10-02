CC = gcc

CFLAGS = -Wall -Wextra -O2

LDFLAGS = -lncurses

TARGET = remote

SRCS = main.c menu.c

OBJS = $(SRCS:.c=.o)

all: $(TARGET)

# Link the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: all clean
