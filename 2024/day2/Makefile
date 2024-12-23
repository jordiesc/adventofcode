# Compiler and flags
CC = gcc
CFLAGS = -Wall -Werror -g

# Find all .c files and convert them to .o files
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

# Output executable
TARGET = day2-part2.c

# Default target to build and run
all: $(TARGET)

# Rule to link object files to create the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up compiled files
clean:
	rm -f $(OBJS) $(TARGET)

# Rule to run the program
run: all
	./$(TARGET)

# Phony targets to avoid conflicts with filenames
.PHONY: all clean run
