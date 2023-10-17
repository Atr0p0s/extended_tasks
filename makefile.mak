SOURCES = 	task1.c \
			task2.c \
			task3.c

CC = gcc
OBJS := $(SOURCES:.c=.o)

%.o: %.c
	$(CC) -c $< -o $@

.PHONY: task1
task1:rostring
rostring: task1.o
	$(CC) task1.o -o $@

.PHONY: task2
task2:fprime
fprime: task2.o
	$(CC) task2.o -o $@

.PHONY: task3
task3:sortlist
sortlist: task3.o
	$(CC) task3.o -o $@

.PHONY: clean
clean:
	rm -f $(OBJS)

.PHONY: compile-all
compile-all: $(OBJS)