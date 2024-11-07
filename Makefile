CC = gcc 
CFLAGS = -Wall -Wextra -Werror -std=c11 
BUILD_PATH = ./build/
GENERATOR = ./src/generator.c 
TEST = ./tests/generator_test.c 

test1: $(BUILD_PATH)generator.o $(BUILD_PATH)test.o
	$(CC) $(CFLAGS) $^ -o $(BUILD_PATH)test1

$(BUILD_PATH)generator.o: $(GENERATOR)
	$(CC) $(CFLAGS) -c $^ -o $@

$(BUILD_PATH)test.o: $(TEST)
	$(CC) $(CFLAGS) -c $^ -o $@

clean: 
	rm $(BUILD_PATH)*.o
	rm $(BUILD_PATH)test1

