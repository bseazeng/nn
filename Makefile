all: nn
.PHONY:all clean show
CC=gcc
SRC=$(wildcard ./*.c)
SRC+=$(wildcard ./test/*.c)
OBJ+=$(patsubst %.c,%.o,$(SRC))
INC+=-I./include
LIB+=

%.o:%.c
	$(CC) -c $< $(INC) -o $@ 
clean:
	rm -rf $(OBJ) nn
nn:$(OBJ)
	@$(CC) $^ $(LIB) -o $@	

show:
	echo $(SRC)
	echo $(OBJ)
