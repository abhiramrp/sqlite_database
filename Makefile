# Compiler settings
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
CFLAGS += -I/opt/homebrew/Cellar/cunit/2.1-3/include

# Directories
SRCDIR = src
INCDIR = include
BUILDDIR = build
TARGETDIR = bin
TESTDIR = tests

# Files
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c,$(BUILDDIR)/%.o,$(SRCS))
TARGET = $(TARGETDIR)/main

TEST_SRCS = $(wildcard $(TESTDIR)/*.c)
TEST_OBJS = $(patsubst $(TESTDIR)/%.c,$(BUILDDIR)/%.o,$(TEST_SRCS))
TEST_TARGET = $(TARGETDIR)/TestDB

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


# Build target
$(TEST_TARGET): $(TEST_OBJS)
	@mkdir -p $(TARGETDIR)
	$(CC) $(CFLAGS) $^ -o $@

# Compile source files
$(BUILDDIR)/%.o: $(TESTDIR)/%.c
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@


# Clean target
clean:
	@rm -rf $(BUILDDIR) $(TARGETDIR) 

# Run
run: $(TARGET)
	$(TARGET)

test: $(TEST_TARGET)

testrun: $(TEST_TARGET)
	$(TEST_TARGET)


# Phony targets
.PHONY: all clean run test testrun

