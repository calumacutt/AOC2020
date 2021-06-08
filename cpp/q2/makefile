run: clean main.exe
	.\main.exe

clean:
	del main.exe
	del main.o 
	del fileReader.o
	del policy.o

main.exe: main.o fileReader.o policy.o
	g++ -o main.exe main.o fileReader.o policy.o

main.o: main.cpp fileReader.h policy.h
	g++ -c main.cpp

fileReader.o: fileReader.h policy.h
	g++ -c fileReader.cpp

policy.o: policy.h
	g++ -c policy.cpp

