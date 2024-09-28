CC = gcc
CFLAGS = -std=c11 -g -Wall -Wshadow --pedantic -Wvla -Werror
EXEC = wordgen

SRC_DIR = .
TEST_DIR = textFiles
SRCS = main.c generate.c
OBJS = $(SRCS:%.c=%.o)
GENERATED_WORDS = 200

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

testall: $(EXEC)
	@for file in $(TEST_DIR)/*.txt; do \
		# Running test on $$file"; \
		./$(EXEC) $$file $(GENERATED_WORDS); \
	done

test1: $(EXEC)
	# Running test on Jane Eyre
	./$(EXEC) $(TEST_DIR)/JaneEyre.txt $(GENERATED_WORDS)

test2: $(EXEC)
	# Running test on Men At Arms
	./$(EXEC) $(TEST_DIR)/BootsTheory.txt $(GENERATED_WORDS)

test3: $(EXEC)
	# Running test on Commandments
	./$(EXEC) $(TEST_DIR)/Commandments.txt $(GENERATED_WORDS)

test4: $(EXEC)
	# Running test on Treasure Island
	./$(EXEC) $(TEST_DIR)/TreasureIsland.txt $(GENERATED_WORDS)

test5: $(EXEC)
	# Running test on War of the Worlds
	./$(EXEC) $(TEST_DIR)/WarOfWorlds.txt $(GENERATED_WORDS)

testbig: $(EXEC)
	# Running test on The Time Machine
	./$(EXEC) $(TEST_DIR)/TimeMachine.txt $(GENERATED_WORDS)

memcheck:
	valgrind --leak-check=full --show-leak-kinds=all ./$(EXEC) $(TEST_DIR)/TimeMachine.txt $(GENERATED_WORDS)

clean: 
	rm -f hw03 *.o output?? *~