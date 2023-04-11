#include "socket_helpers.h"

void send_or_fail(SOCKET_TYPE sock, string message) {
    if(!send_string(sock, message)) {
        cerr << "Failed to send" << endl;
        close(sock);
        exit(1);
    }
}

string receive_str_or_fail(SOCKET_TYPE sock) {
    string received;
    try {
        received = receive_string(sock);
    } catch (...) {
        cerr << "Failed to receive" << endl;
        close(sock);
        exit(1);
    }
    return received;
}

void fail_on_neq(string expected, string received, SOCKET_TYPE sock) {
    if(expected != received) {
        cerr << "Expected " << expected << ", got " << received << endl;
        close(sock);
        exit(1);
    }
}

