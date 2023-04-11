#include <iostream>

#include <fstream>

#include <string.h>

using namespace std;

int main(){

    char answer[16];
    cout << "Do you want to read or write? ";
    cin >> answer;

    if(strcmp(answer, "read") == 0){

        cout << "READING" << endl;

        ifstream fin;
        fin.open("binaryfile.fic", ios::binary);

        char int_reader[4];

        fin.read(int_reader, 4);

        int string_count = 
            (unsigned int)((unsigned char)int_reader[0]) << 24
            | (unsigned int)((unsigned char)int_reader[1]) << 16
            | (unsigned int)((unsigned char)int_reader[2]) << 8
            | (unsigned int)((unsigned char)int_reader[3]);

        cout << "string_count: " << string_count << endl;

        for(int i = 0; i < string_count; i++){

            fin.read(int_reader, 4);

            int the_integer = 
                (unsigned int)((unsigned char)int_reader[0]) << 24
                | (unsigned int)((unsigned char)int_reader[1]) << 16
                | (unsigned int)((unsigned char)int_reader[2]) << 8
                | (unsigned int)((unsigned char)int_reader[3]);

            cout << "the integer: " << the_integer << endl;

            char the_string[128];

            fin.read(the_string, the_integer);
            the_string[the_integer] = '\0';

            cout << the_string << endl;
        }
        fin.close();
    }
    else if(strcmp(answer, "write") == 0){

        cout << "WRITING" << endl;

        ofstream fout;
        fout.open("binaryfile.fic", ios::binary);

        char int_writer[4];
        char string_var[64];
        int string_count = 5;
        int string_size;

        int_writer[0] = (unsigned char)(((unsigned int)string_count & 0xFF000000) >> 24);
        int_writer[1] = (unsigned char)(((unsigned int)string_count & 0x00FF0000) >> 16);
        int_writer[2] = (unsigned char)(((unsigned int)string_count & 0x0000FF00) >> 8);
        int_writer[3] = (unsigned char)(((unsigned int)string_count & 0x000000FF));

        fout.write(int_writer, 4);

        for(int i = 0; i < string_count; i++){
            switch(i){
                case 0:
                    strcpy(string_var, "Forritun i C++ er skemmtileg!");
                    break;
                case 1:
                    strcpy(string_var, "Strengir i C++ eru floknir!");
                    break;
                case 2:
                    strcpy(string_var, "Fylki eru mikilvaeg.");
                    break;
                default:
                    strcpy(string_var, "There is no spoon...");
                    break;
                
            }
            string_size = strlen(string_var);

            int_writer[0] = (unsigned char)(((unsigned int)string_size & 0xFF000000) >> 24);
            int_writer[1] = (unsigned char)(((unsigned int)string_size & 0x00FF0000) >> 16);
            int_writer[2] = (unsigned char)(((unsigned int)string_size & 0x0000FF00) >> 8);
            int_writer[3] = (unsigned char)(((unsigned int)string_size & 0x000000FF));

            fout.write(int_writer, 4);

            fout.write(string_var, string_size);
        }

        fout.close();

    }
    else{
        cout << "Nevermind!" << endl;
    }


    return 0;
}