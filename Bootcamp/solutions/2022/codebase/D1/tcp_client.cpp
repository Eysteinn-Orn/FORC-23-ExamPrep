#include <iostream>

#include "socket_helpers.h"
#include "common.h"

int PORT = 4061;
string IP = "127.0.0.1";


using namespace std;

void echo_exchange(SOCKET_TYPE sock) {
    string received = receive_str_or_fail(sock);
    fail_on_neq("Hello", received, sock);
    
    string message = "Good day";
    send_or_fail(sock, message);
}

void message_exchange(SOCKET_TYPE sock) {
    string received = receive_str_or_fail(sock);
    cout << "Received: " << received << endl;
    send_or_fail(sock, "Hello, this is the client responding");
}

int main(){
    cout << MY_OS << endl;
    if(!check_and_start_if_windows()){ return 0; }

    //TODO: Write client and connect to ip: 127.0.0.1 (localhost) and port: 4061 (or other)

    SOCKET_TYPE sockfd = make_tcp_socket();

    sockaddr addr;
    make_socket_address(&addr, PORT, IP);
    if(!connect_to_server(sockfd, addr)){
        cerr << "failed to connect" << endl;
        exit(1);
    }

    echo_exchange(sockfd);
    message_exchange(sockfd);

    cout << "Done" << endl;
    close(sockfd);

    return 0;
}