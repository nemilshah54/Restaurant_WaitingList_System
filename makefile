proj6: nshah213Proj6.o  nshah213Proj6TravelNetwork.o
	g++ -o proj6 nshah213Proj6.o nshah213Proj6TravelNetwork.o

nshah213Proj6.o: nshah213Proj6.cpp nshah213Proj6.h
	g++ -c nshah213Proj6.cpp

nshah213Proj6TravelNetwork.o: nshah213Proj6TravelNetwork.cpp nshah213Proj6.h
	g++ -c nshah213Proj6TravelNetwork.cpp

clean:
	rm proj6 nshah213Proj6.o nshah213Proj6TravelNetwork.o