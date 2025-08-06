CC=g++

%.o : %.cpp %.h
	$(CC) -c $< -o $@
main.exe : main.cpp fraction.o
	$(CC) $^ -o $@


.PHONY:clean
clean :
	rm -f *.o *.exe
