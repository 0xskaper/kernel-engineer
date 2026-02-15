.PHONY: clean all

CC := gcc
CFLAGS := -Wall -Wextra 
TARGET := calc
DATE := $(shell date +%Y-%m-%d)
DEPFLAGS = -MMD -MP -MF $(BUILD_DIR)/$*.d
CPPFLAGS := -Iinclude

SRC_DIR := src
BUILD_DIR := build

SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))
DEPS := $(OBJS:.o=.d)

ifdef DEBUG
	CFLAGS += -g3 -O0 -DDEBUG
else 
	CFLAGS += -O2 -DNDEBUG
endif

CFLAGS += -DBUILD_DATE=\"$(DATE)\"

all: $(TARGET)

debug:
	$(MAKE) DEBUG=1 all

release:
	$(MAKE) all

$(TARGET): $(OBJS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(DEPFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(DEPFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $@

-include $(DEPS)

$(info [INFO] Found Sources -> $(SRCS))
$(info [INFO] Found CFLAGS -> $(CFLAGS))
$(info [INFO] Found Objects -> $(OBJS))

clean:
	rm -rf $(BUILD_DIR)
