CC := gcc
CFLAGS := -std=c11 -Wall -Werror -Wextra -fsanitize=leak -lm
BUILD_DIR := ../build
TARGET := graph
TARGET_PATH := $(BUILD_DIR)/$(TARGET)
SRCS := parse.c stack.c calc.c draw.c graph.c
OBJS := $(addprefix $(BUILD_DIR)/,$(SRCS:.c=.o))

.PHONY: all clean rebuild

all: $(TARGET_PATH)

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ 

$(TARGET_PATH): $(OBJS) 
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR):
	mkdir -p $@

clean: 
	rm -rf $(BUILD_DIR)

rebuild: clean all
