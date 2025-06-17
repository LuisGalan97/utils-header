#include "Utils.h"

int main() {
    int posNumber = 10;
    int negNumber = -10;
    char letra = 'a';
    int* address = new int(50);
    int& ref = *address;
    int array[] = {10, 20, 30}; 
    
    class Clase{
        int value1 = 50;
        int value2 = -50;
    };
    
    utils::printMemory(10);
    utils::printMemory(posNumber);
    utils::printMemory(negNumber);
    utils::printMemory(letra);
    utils::printMemory(address);
    utils::printMemory(ref);
    utils::printMemory(array);
    utils::printMemory(new Clase());
    utils::printMemory(*(new Clase()));
}