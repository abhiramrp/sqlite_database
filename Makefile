# Compiler settings
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

# Directories
SRCDIR = src
INCDIR = include
BUILDDIR = build
TARGETDIR = bin

# Files
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c,$(BUILDDIR)/%.o,$(SRCS))
TARGET = $(TARGETDIR)/main

# Default target
all: $(TARGET)

# Build target
$(TARGET): $(OBJS)
	@mkdir -p $(TARGETDIR)
	$(CC) $(CFLAGS) $^ -o $@

# Compile source files
$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target
clean:
	@rm -rf $(BUILDDIR) $(TARGETDIR)

# Run
run: $(TARGET)
	$(TARGET)

# Phony targets
.PHONY: all clean run

