p4b1.o: p4b1.c pheader.h
	gcc -c p4b1.c

p4b2.o: p4b2.c pheader.h
	gcc -c p4b2.c

p4b3.o: p4b3.c pheader.h
	gcc -c p4b3.c

pheader: p4b1.o p4b2.o p4b3.o 
	gcc -o pheader p4b1.o p4b2.o p4b3.o 

clean:
	rm p4b1.o p4b2.o p4b3.o pheader