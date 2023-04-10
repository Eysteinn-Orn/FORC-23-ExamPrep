#include "socket_helpers.h"
#include <thread>
#include <string>
#include <unistd.h>

using namespace std;

int PORT = 4893;

void handle_connect(SOCKET_TYPE socket) {
    string messages[3] = {
        "You must repeat what I say",
        "Well done, now echo",
        "Superb, now mimic"
    };

    bool all_correct = true;
    for(int i = 0; i < 3; i++){

        string message = messages[i];
        cout << "Sending: " << message << endl;
        send(socket, message.c_str(), message.length() + 1, 0);
        string response = receive_string(socket);
        cout << "Received: " << response << endl;
        if(message != response) {
            cout << "Wrong response!" << endl;
            all_correct = false;
        }
    }

    string result = all_correct ? "All correct!" : "Wrong!";
    send(socket, result.c_str(), result.length() + 1, 0);
}

int main(int argc, char *argv[]) {
    check_and_start_if_windows();

    sockaddr address;

    
    make_socket_address(&address, PORT, "");

    SOCKET_TYPE server_socket = socket(AF_INET, SOCK_STREAM, 0);

    int optval = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

    if(!bind_socket_to_address(server_socket, &address)){
        exit(1);
    }

    cout << "Listening on port " << PORT << endl;

    if(!listen_at_socket(server_socket)){
        exit(1);
    }

    while (true) {
        SOCKET_TYPE new_socket;
        sockaddr client_address;
        if(!accept_connection(new_socket, server_socket, client_address)){
            cout << "Connection failed" << endl;
            continue;
        }

        string client_ip = get_ip(&client_address);
        cout << "Client on " << client_ip << " connected" << endl;
        thread handler(handle_connect, new_socket);
        handler.detach();
    }
}