PROJECT := tempo
VERSION := 0.0.1

CC := gcc
CFLAGS := -Wall -Wextra -Wpedantic -std=c11
CPPFLAGS := -Iinclude

SRC_DIR := src
BUILD_DIR := build

SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))
DEPS := $(OBJS:.o=.d)
TARGET := $(BUILD_DIR)/$(PROJECT)

DEPFLAGS = -MMD -MP -MF $(BUILD_DIR)/$*.d

ifdef DEBUG
	CFLAGS += -g3 -O0 -DDEBUG
else
	CFLAGS += -O2 -DNDEBUG
endif

ifdef VERBOSE
	Q :=
else
	Q := @
endif

.PHONY: all debug release clean run help

all: $(TARGET)
	@echo "---BUILD COMPLETE: $(TARGET)"

debug: 
	$(MAKE) DEBUG=1 all

release:
	$(MAKE) all

run: $(TARGET)
	@echo "---RUNNING $(PROJECT)---"
	@./$(TARGET)

$(TARGET): $(OBJS) | $(BUILD_DIR)
	@echo "  LINK   $@"
	$(Q)$(CC) -o $@ $^ 

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	@echo "  CC  $<"
	$(Q)$(CC) $(CPPFLAGS) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

$(BUILD_DIR):
	@mkdir -p $@

-include $(DEPS)

clean:
	@echo "  CLEAN"
	$(Q)rm -rf $(BUILD_DIR)
