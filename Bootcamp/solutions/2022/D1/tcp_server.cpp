#include <iostream>

#include "socket_helpers.h"
#include "common.h"

int PORT = 4061;

using namespace std;

void echo_exchange(SOCKET_TYPE sock) {
    string message = "Hello";
    send_or_fail(sock, message);

    string received = receive_str_or_fail(sock);
    fail_on_neq("Good day", received, sock);
}

void message_exchange(SOCKET_TYPE sock) {
    send_string(sock, "Hello, this is the server speaking");
    string received = receive_string(sock);
    cout << "Received: " << received << endl;
}

int main(){
    cout << MY_OS << endl;
    if(!check_and_start_if_windows()){ return 0; }

    //TODO: Write server and connect to port: 4061

    sockaddr address;
    make_socket_address(&address, PORT, "");

    SOCKET_TYPE sockfd = make_tcp_socket();

    if(!bind_socket_to_address(sockfd, &address)){
        cerr << "Failed to bind" << endl;
        exit(1);
    }

    if(!listen_at_socket(sockfd)){
        cerr << "Failed to listen" << endl;
        exit(1);
    }

    SOCKET_TYPE cli_sock;

    sockaddr cli_addr;
    if(!accept_connection(cli_sock, sockfd, cli_addr)){
        cerr << "Failed to accept" << endl;
        exit(1);
    }

    // don't need the listening socket anymore
    close(sockfd);

    echo_exchange(cli_sock);
    message_exchange(cli_sock);

    cout << "done" << endl;

    close(cli_sock);
    close(sockfd);

    return 0;
}