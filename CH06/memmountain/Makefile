TARGET = main
CC = gcc

SRCS := $(wildcard *.c)
OBJDIR = build
OBJS := $(SRCS:%.c=$(OBJDIR)/%.o)

DEPDIR = dep
DEPS := $(SRCS:%.c=$(DEPDIR)/%.d)
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.d

CFLAGS = -Wall -Werror -g
DUP_DIR = mkdir -p $(@D)

.PHONY:
	clean

all: $(TARGET)

$(OBJDIR)/%.o: %.c | $(OBJDIR) $(DEPDIR)
	$(CC) -c $(CFLAGS) $(DEPFLAGS) -o $@ $<

$(TARGET): $(OBJS)
	$(CC) -o $@ $^

clean:
	rm -rf $(OBJDIR) $(DEPDIR) $(TARGET)

$(OBJDIR) $(DEPDIR):
	mkdir -p $@

$(DEPFILES):

-include $(wildcard $(DEPS))
