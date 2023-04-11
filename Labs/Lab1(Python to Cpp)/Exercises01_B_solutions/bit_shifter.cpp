#include <iostream>

using namespace std;

int main(){
    char choice = 'n';
    unsigned int byte = 0xFAB3E;
    while(choice != 'q'){
        cout << "The value of the byte is " << (int)byte << endl;
        cout << "what do you want to do,\n  (a)dd one\n  set rightmost bit to (1)\n  set rightmost bit to (0)\n  shift (l)eft\n  shift (r)ight\n  (q)uit\n? ";
        cin >> choice;
        switch(choice){
            case 'a':
                ++byte;
                break;
            case 'l':
                byte = byte << 1;
                break;
            case '1':
                byte = byte | 0x01;
                break;
            case '0':
                byte = byte & 0xFE;
                break;
            case 'r':
                byte = byte >> 1;
                break;
            default:
                break;
        }
    }

    return 0;
}