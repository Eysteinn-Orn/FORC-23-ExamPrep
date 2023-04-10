#include "socket_helpers.h"

using namespace std;

bool check_and_start_if_windows(){
    #ifdef ON_WINDOWS
        WSADATA wsa_data;
        if(WSAStartup(MAKEWORD(2, 2), &wsa_data) != 0){
            cout << "failed at WSAStartup()" << endl;
            return false;
        }
    #endif
    return true;
}


void make_socket_address(sockaddr *address, int port, std::string ip_address){
    sockaddr_in *socket_address = (sockaddr_in*)address;
    socket_address->sin_family = AF_INET;
    socket_address->sin_port = htons(port);
    if(ip_address == ""){
        socket_address->sin_addr.s_addr = INADDR_ANY;
    }
    else{
        socket_address->sin_addr.s_addr = inet_addr(ip_address.c_str());
    }
}

bool bind_socket_to_address(SOCKET_TYPE &my_socket, sockaddr *p_address){

    if(bind(my_socket, p_address, sizeof(*p_address)) < 0){
        cout << "bind() failed" << endl;
        return false;
    }
    return true;
}

bool listen_at_socket(SOCKET_TYPE &my_socket){

    if(listen(my_socket, 1) < 0){
        cout << "listen() failed: " << endl;
        return false;
    }
    return true;
}

bool accept_connection(SOCKET_TYPE &new_socket, SOCKET_TYPE &my_socket, sockaddr &socket_address){
    ADDRESS_SIZE addr_size = sizeof(socket_address);

    new_socket = accept(my_socket, (sockaddr *)&socket_address, &addr_size);
    if(new_socket == -1 || new_socket == ~0){
        cout << "invalid socket" << endl;
        return false;
    }
    return true;
}

bool connect_to_server(SOCKET_TYPE &my_socket, sockaddr &socket_address){
    if(connect(my_socket, (sockaddr *)&socket_address, sizeof(socket_address)) < 0){
        cout << "connect() failed: " << endl;
        return false;
    }
    return true;
}


string get_ip(sockaddr *address) {
    sockaddr_in *socket_address = (sockaddr_in *) address;

    char client_ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &socket_address->sin_addr, client_ip, INET_ADDRSTRLEN);

    return string(client_ip);
}

std::string receive_string(int &socket) {
    std::string result;
    char buffer;

    while (true) {
        int bytes_received = recv(socket, &buffer, 1, 0);

        if (bytes_received == -1) {
            throw std::runtime_error("Error while receiving data");
        }

        if (bytes_received == 0 || buffer == '\0') {
            break;
        }

        result += buffer;
    }

    return result;
}

SOCKET_TYPE make_tcp_socket() {
    SOCKET_TYPE sockfd = socket(AF_INET, SOCK_STREAM, 0);

    int optval = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

    return sockfd;

}


bool send_string(SOCKET_TYPE sock, string message) {
    int sent = send(sock, message.c_str(), message.length() + 1, 0);
    if(sent == -1) {
        return false;
    }
    return true;
}

