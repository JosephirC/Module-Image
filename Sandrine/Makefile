all: bin/executable.out 

bin/executable.out: obj/mainExemple.o obj/Pixel.o obj/Image.o 
	g++ -ggdb -I/usr/include/SDL2  obj/mainExemple.o obj/Pixel.o obj/Image.o -o bin/executable.out
	
obj/mainExemple.o: src/mainExemple.cpp src/Image.h 
	g++ -ggdb -Wall -I/usr/include/SDL2  -c src/mainExemple.cpp -o obj/mainExemple.o
	
obj/Pixel.o: src/Pixel.cpp src/Pixel.h 
	g++ -ggdb -Wall -c src/Pixel.cpp -o obj/Pixel.o
	
obj/Image.o: src/Image.h src/Image.cpp src/Pixel.h
	g++ -ggdb -Wall -I/usr/include/SDL2 -c src/Image.cpp -o obj/Image.o

clean:
	rm obj/*.o
	
veryclean: clean
	rm *.out	