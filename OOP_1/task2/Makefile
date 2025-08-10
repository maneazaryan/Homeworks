CC= g++
CFLAGS=-Iinc
OBJ= obj/canvas.o obj/circle.o obj/cross.o obj/getcommands.o  obj/rectangle.o
obj/%.o:src/%.cpp inc/%.h
	$(CC) $(CFLAGS) -c $< -o $@

bin/main.exe: src/main.cpp $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

.PHONY : clean 

clean:
	rm -f obj/*.o bin/*.exe
