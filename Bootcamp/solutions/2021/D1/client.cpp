#include "socket_helpers.h"
#include <string>

int PORT = 4893;

int main(int argc, char *argv[]) {
    sockaddr addr;
    make_socket_address(&addr, PORT, "127.0.0.1");

    SOCKET_TYPE sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(!connect_to_server(sockfd, addr)){
        cout << "Failed to connect to server" << endl;
        exit(1);
    }

    cout << "Connected to server" << endl;

    for(int i = 0; i < 3; i++) {
        string msg = receive_string(sockfd);
        cout << "Received: " << msg << endl;
        send(sockfd, msg.c_str(), msg.length() + 1, 0);
    }

    string praise = receive_string(sockfd);
    cout << "Received: " << praise << endl;
}