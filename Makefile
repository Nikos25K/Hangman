OBJS = fingiv.o check.o main.o
EXEC = hang
CC = gcc
$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC)
run: $(EXEC)
	./$(EXEC)