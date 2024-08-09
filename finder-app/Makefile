# Write a Makefile which includes:

# A default target which builds the “writer” application

# A clean target which removes the “writer” application and all .o files

# Support for cross-compilation.  You should be able to generate an application for the native build platform when GNU make variable CROSS_COMPILE is not specified on the make command line.  When CROSS_COMPILE is specified with aarch64-none-linux-gnu- (note the trailing -)your makefile should compile successfully using the cross compiler installed in step 1.


# Compiler and flags
CC = $(CROSS_COMPILE)gcc
CFLAGS = -Wall -Wextra -O2

# Target executable
TARGET = writer

# Default target: Build the 'writer' application
all: $(TARGET)

# Compile the writer application
$(TARGET): writer.o
	$(CC) $(CFLAGS) -o $(TARGET) writer.o

# Compile the writer.o object file
writer.o: writer.c
	$(CC) $(CFLAGS) -c writer.c -o writer.o

# Clean target: remove the 'writer' application and all .o files
clean:
	rm -f $(TARGET) *.o

# Phony targets are not actual files
.PHONY: all clean