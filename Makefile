CC = gcc
CFLAGS = -g -Wall -std=c99
OBJECTS = *.c
OUT = farm
BUILD_DIR = build

all:
	rm -rf $(BUILD_DIR)
	mkdir -v $(BUILD_DIR)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(BUILD_DIR)/$(OUT)

clean:
	rm -rf $(BUILD_DIR)