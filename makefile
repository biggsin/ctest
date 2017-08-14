SOURCES = $(wildcard *.c)
OBJS = $(patsubst %.c,%.o,$(SOURCES))
CC = gcc
CFLAGS = -Wall -g
INC = 
LIBS = -lm
TARGET = out

all: $(OBJS)
	${CC} $(OBJS) $(LIBS) -o $(TARGET)
%.o: %.c
	${CC} $< ${CFLAGS} -c
clean:
	rm -rf $(OBJS)
	rm -rf $(TARGET)
