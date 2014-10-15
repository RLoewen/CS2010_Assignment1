CC=g++
OBJ= Assignment1.o
BIN= prog
$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $(BIN)

.cpp.o:
	$(CC) -c $<

clean: 
	rm *.o $(BIN)
