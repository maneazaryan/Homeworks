CC = g++
CFLAG=-Iinc 

obj/%.o: src/%.cpp inc/%.h
	$(CC) $(CFLAG) -c  $< -o $@

bin/main.exe : src/main.cpp obj/person.o obj/student.o obj/teacher.o
	$(CC) $(CFLAG) $^ -o $@

.PHONY : clean 

clean:
	rm -f obj/*.o bin/*.exe
