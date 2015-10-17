CC ?= gcc
CFLAGS_common ?= -O0 -Wall -std=gnu99

EXEC = iterative recursive
all: $(EXEC)

SRCS_common = main.c

iterative: $(SRCS_common) iterative.c 
	$(CC) $(CFLAGS_common) -DITER -o $@ $(SRCS_common) $@.c

recursive: recursive.c main.c
	$(CC) $(CFLAGS_common) -DREC -o $@ $(SRCS_common) $@.c

run: $(EXEC)
	echo "echo 1 > /proc/sys/vm/drop_caches" | sudo sh
	perf stat -e cache-misses,cache-references,instructions,cycles ./iterative
	echo "echo 1 > /proc/sys/vm/drop_caches" | sudo sh
	perf  stat -e cache-misses,cache-references,instructions,cycles ./recursive
	
clean:
	$(RM) $(EXEC) *.o perf.* 
