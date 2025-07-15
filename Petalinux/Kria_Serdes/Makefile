# Makefile

# Compiler
CC = gcc
# Compilation flags
CFLAGS = -Wall -fPIC -I$(INCLUDE_DIR)
# Linking flags
LDFLAGS = -shared

# Directories
SRC_DIR = src
INCLUDE_DIR = include

# Source files
SRC = hal_spi.c hal_gpio.c hal_afe5808a.c hal_ad5327.c hal_afe_cfg.c 
# Object files
OBJ = $(patsubst %.c, $(SRC_DIR)/%.o, $(SRC))
# Shared library
LIB = afe5808a_lib.so

# Default rule
all: $(LIB)

# Rule to build the shared library
$(LIB): $(OBJ)
	$(CC) $(LDFLAGS) -o $(LIB) $(OBJ)

# Rule to build object files from source files
$(OBJ): | $(SRC_DIR)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to create the source directory if it doesn't exist
$(SRC_DIR):
	mkdir -p $@

# Rule to clean generated files
clean:
	rm -f $(OBJ) $(LIB)

