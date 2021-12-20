CC=gcc
AR=ar
OBJECTS_MAIN=main.o
FLAGS= -Wall -g

all:.stringProg
.stringProg: $(OBJECTS_MAIN)
	$(CC) $(FLAGS) -o .stringProg $(OBJECTS_MAIN) ./libmy_mat.so -lm	

.PHONY: clean all

clean:
	rm -f *.o *.a *.so .connections