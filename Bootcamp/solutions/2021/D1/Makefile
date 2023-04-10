all: server client

server:
	g++ server.cpp socket_helpers.cpp -o server -lpthread

client:
	g++ client.cpp socket_helpers.cpp -o client -lpthread

clean:
	rm -f server client
