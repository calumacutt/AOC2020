run: main.exe
	.\main.exe

clean:
	del main.exe
	del main.o 
	del fileReader.o

main.exe: main.o fileReader.o
	g++ -o main.exe main.o fileReader.o

main.o: main.cpp fileReader.h
	g++ -c main.cpp

fileReader.o: fileReader.h
	g++ -c fileReader.cpp

