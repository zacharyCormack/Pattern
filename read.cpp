#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

char* read_file(int* size) {
    string file_loc;
    cout << "File to read: ";
    cin >> file_loc;
    FILE* file = fopen(file_loc, "r");
    if(file == NULL) {
        std::cout << "File does not exist. Please try again.\n";
        return get_file_path();
    }
    fseek(file , 0 , SEEK_END);
    long file_size = ftell(file);
    rewind(file);
    char * buffer = (char*)malloc(sizeof(char)*file_size);
    if (buffer == NULL) {
        std::cout << "File is corrupted. Choose another file.\n";
        return get_file_path();
    }
    if(buffer[0]!='G'||buffer[1]!='R'||buffer[2]!='I'||buffer[3]!='D'||buffer[4]!='.') {
        std::cout << "File is corrupted. Choose another file.\n";
        return get_file_path();
    }
    *size = file_size;
    return buffer;
}

int main() {
    int file_size;
    char* file = read_file(&file_size);
    
}
