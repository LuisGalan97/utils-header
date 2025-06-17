#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <bitset>
#include <typeinfo>
#include <cxxabi.h>

namespace utils{
    #define printMemory(var) printMemoryImp(#var, var)

    namespace {
        template<typename T>
        void showType(T& valor){
            int status;
            const char* nombre = typeid(valor).name();
            char* demangled = abi::__cxa_demangle(nombre, nullptr, nullptr, &status);
            std::cout <<"   Tipo: ("<< (status == 0 ? demangled : nombre) << ")\n";
            free(demangled); // Liberar memoria del nombre demangleado
        }
    }

    template<typename T>
    typename std::enable_if<std::is_class<T>::value, void>::type
    printMemoryImp(const char* name, T& valor){
        std::cout << "------------------- Print Memory --------------------\n";
        std::cout << "Target(#): \"" << name << "\"\n";
        std::cout << "[lvalue - Variable/Referencia/Instrucción]\nReserva " << sizeof(valor) << " bytes de memoria\n\n";
        showType(valor);
        std::cout << "   Valor: Objeto\n";
        std::cout << "  |------------|\n";
        for (int i = sizeof(valor)-1; i >= 0; i--){
            void* address = (void*)(((char*) &valor) + i);
            int byte = (int) *(((unsigned char*) &valor) + i);
            std::cout << "  | ["<< std::bitset<8>(byte) << "] | ";
            std::cout << address;
            if (i == 0){
                std::cout<<" <- Direccion principal\n";
            } else {
                std::cout<<"\n";
            }
        }
        std::cout << "  |------------|\n";
        std::cout << "   Valor: Objeto\n";
        showType(valor);
        std::cout<<"\n";
        std::cout << "-----------------------------------------------------\n";
    }

    template<typename T>
    typename std::enable_if<!std::is_class<T>::value, void>::type
    printMemoryImp(const char* name, T& valor){
        std::cout << "------------------- Print Memory --------------------\n";
        std::cout << "Target(#): \"" << name << "\"\n";
        std::cout << "[lvalue - Variable/Referencia/Instrucción]\nReserva " << sizeof(valor) << " bytes de memoria\n\n";
        showType(valor);
        std::cout << "   Valor: ";
        if (std::is_array<T>::value){
            std::cout << "Array\n";
        } else {
            std::cout << valor << "\n";
        }
        std::cout << "  |------------|\n";
        for (int i = sizeof(valor)-1; i >= 0; i--){
            void* address = (void*)(((char*) &valor) + i);
            int byte = (int) *(((unsigned char*) &valor) + i);
            std::cout << "  | ["<< std::bitset<8>(byte) << "] | ";
            std::cout << address;
            if (i == 0){
                std::cout<<" <- Direccion principal\n";
            } else {
                std::cout<<"\n";
            }
        }
        std::cout << "  |------------|\n";
        std::cout << "   Valor: ";
        if (std::is_array<T>::value){
            std::cout << "Array\n";
        } else {
            std::cout << valor << "\n";
        }
        showType(valor);
        std::cout<<"\n";
        std::cout << "-----------------------------------------------------\n";
    }

    template<typename T>
    typename std::enable_if<std::is_class<T>::value, void>::type
    printMemoryImp(const char* name, T&& valor){
        std::cout << "------------------- Print Memory --------------------\n";
        std::cout << "Target(#): \"" << name << "\"\n";
        std::cout << "[rvalue - Valor/Instrucción]\nNecesita de " << sizeof(valor) << " bytes de memoria\n\n";
        showType(valor);
        std::cout << "   Valor: Objeto\n";
        std::cout << "  |------------|\n";
        for (int i = sizeof(valor)-1; i >= 0; i--){
            int byte = (int) *(((unsigned char*) &valor) + i);
            std::cout << "  | ["<< std::bitset<8>(byte) << "] |\n";
        }
        std::cout << "  |------------|\n";
        std::cout << "   Valor: Objeto\n";
        showType(valor);
        std::cout<<"\n";
        std::cout << "-----------------------------------------------------\n";
    }

    template<typename T>
    typename std::enable_if<!std::is_class<T>::value, void>::type
    printMemoryImp(const char* name, T&& valor){
        std::cout << "------------------- Print Memory --------------------\n";
        std::cout << "Target(#): \"" << name << "\"\n";
        std::cout << "[rvalue - Valor/Instrucción]\nNecesita de " << sizeof(valor) << " bytes de memoria\n\n";
        showType(valor);
        std::cout << "   Valor: ";
        if (std::is_array<T>::value){
            std::cout << "Array\n";
        } else {
            std::cout << valor << "\n";
        }
        std::cout << "  |------------|\n";
        for (int i = sizeof(valor)-1; i >= 0; i--){
            int byte = (int) *(((unsigned char*) &valor) + i);
            std::cout << "  | ["<< std::bitset<8>(byte) << "] |\n";
        }
        std::cout << "  |------------|\n";
        std::cout << "   Valor: ";
        if (std::is_array<T>::value){
            std::cout << "Array\n";
        } else {
            std::cout << valor << "\n";
        }
        showType(valor);
        std::cout<<"\n";
        std::cout << "-----------------------------------------------------\n";
    }
}

#endif