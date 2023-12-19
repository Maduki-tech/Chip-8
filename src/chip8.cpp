#include "../includes/chip8.h"
#include <fstream>
#include <iosfwd>
const unsigned int START_ADDRESS = 0x200;

Chip8::Chip8(){
    pc = START_ADDRESS;
}


void Chip8::LoadRoam(char const* filename){
    std::ifstream file(filename, std::ios::binary | std::ios::ate);
    if(file.is_open()){

        // Get size of file and allocate a buffer to hold the contents
        std::streampos size = file.tellg();
        char* buffer = new char[size];

        // go to the beginning of the file
        file.seekg(0, std::ios::beg);
        // read the file into the buffer
        file.read(buffer,size);
        // close the file
        file.close();

        // Load ROM into memory
        for (long i = 0; i < size; ++i){
            memory[START_ADDRESS + i] = buffer[i];
        }

        // FREE Buffer
        delete[] buffer;
    }

}
