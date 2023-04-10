#ifndef SOCKET_HELPERS_23874924
#define SOCKET_HELPERS_23874924

#include <iostream>
#include <string.h>
#include <thread>

#ifdef _WIN32
    #define MY_OS "Windows"
    #include <WinSock2.h>
    typedef SOCKET SOCKET_TYPE;
    typedef int ADDRESS_SIZE;
    #define ON_WINDOWS
#else
    #define MY_OS "NOT Windows"
    typedef int SOCKET_TYPE;
    typedef unsigned int ADDRESS_SIZE;
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <errno.h>
#endif

#define TCP_PORT 4037 //IPEN TCP PORTS ON SKEL: 4000-4100
#define UDP_PORT 4101 //IPEN UDP PORTS ON SKEL: 4100-4200

using namespace std;

bool check_and_start_if_windows();

void make_socket_address(sockaddr *address, int port, std::string ip_address = "");
bool bind_socket_to_address(SOCKET_TYPE &my_socket, sockaddr *p_address);
bool listen_at_socket(SOCKET_TYPE &my_socket);
bool accept_connection(SOCKET_TYPE &new_socket, SOCKET_TYPE &my_socket, sockaddr &socket_address);
bool connect_to_server(SOCKET_TYPE &my_socket, sockaddr &socket_address);

string receive_string(SOCKET_TYPE &socket);

string get_ip(sockaddr *address);
#endif //SOCKET_HELPERS_23874924