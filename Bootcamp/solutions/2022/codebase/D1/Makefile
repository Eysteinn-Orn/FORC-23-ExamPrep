
all: socket_helpers.h socket_helpers.cpp tcp_client.cpp tcp_server.cpp
	g++ -std=c++11 -o d1_client tcp_client.cpp socket_helpers.cpp -pthread
	g++ -std=c++11 -o d1_server tcp_server.cpp socket_helpers.cpp -pthread

skel:
	scp ./*.cpp ./*.h skel.ru.is:~/cpp_finalexam/D1/
