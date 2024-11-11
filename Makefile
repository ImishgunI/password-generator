CC = gcc 
CFLAGS = -Wall -Wextra -Werror -std=c11 
BUILD_PATH = ./build/
GENERATOR = ./src/generator.c 
TEST = ./tests/generator_test.c 
BUFFER_FILE = ./src/buffer_file.c
TEST2 = ./tests/save_to_buffer_file_test.c 
SAVE_COMMAND = ./src/save.c 
TEST3 = ./tests/save_command_test.c
MAIN_FILE = ./src/main.c 
SEARCH = ./src/search.c 
TEST4 = ./tests/search_test.c 

password_generator: $(BUILD_PATH)generator.o $(BUILD_PATH)buffer_file.o $(BUILD_PATH)save.o $(BUILD_PATH)search.o $(BUILD_PATH)main.o
	$(CC) $(CFLAGS) $^ -o $(BUILD_PATH)$@

$(BUILD_PATH)main.o: $(MAIN_FILE)
	$(CC) $(CFLAGS) -c $^ -o $@

test1: $(BUILD_PATH)generator.o $(BUILD_PATH)test.o
	$(CC) $(CFLAGS) $^ -o $(BUILD_PATH)test1

$(BUILD_PATH)generator.o: $(GENERATOR)
	$(CC) $(CFLAGS) -c $^ -o $@

$(BUILD_PATH)test.o: $(TEST)
	$(CC) $(CFLAGS) -c $^ -o $@

buffer: $(BUILD_PATH)buffer_file.o $(BUILD_PATH)save_test.o $(BUILD_PATH)generator.o
	$(CC) $(CFLAGS) $^ -o $(BUILD_PATH)$@

$(BUILD_PATH)buffer_file.o: $(BUFFER_FILE)
	$(CC) $(CFLAGS) -c $^ -o $@

$(BUILD_PATH)save_test.o: $(TEST2)
	$(CC) $(CFLAGS) -c $^ -o $@

save_file: $(BUILD_PATH)generator.o $(BUILD_PATH)save.o $(BUILD_PATH)save_command.o
	$(CC) $(CFLAGS) $^ -o $(BUILD_PATH)$@

$(BUILD_PATH)save.o: $(SAVE_COMMAND)
	$(CC) $(CFLAGS) -c $^ -o $@

$(BUILD_PATH)save_command.o: $(TEST3)
	$(CC) $(CFLAGS) -c $^ -o $@

s_test: $(BUILD_PATH)search.o $(BUILD_PATH)test4.o
	$(CC) $(CFLAGS) $^ -o $(BUILD_PATH)$@

$(BUILD_PATH)search.o: $(SEARCH)
	$(CC) $(CFLAGS) -c $^ -o $@

$(BUILD_PATH)test4.o: $(TEST4)
	$(CC) $(CFLAGS) -c $^ -o $@
dir:
	mkdir -p $(BUILD_PATH)

clean: 
	rm $(BUILD_PATH)*.o
	rm $(BUILD_PATH)test1

clang-format:
	clang-format -i ./src/*.c
	clang-format -i ./includes/*.h
	clang-format -i ./tests/*.c

