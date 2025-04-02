#include <iostream>
#include <fstream>
#include <sstream>
#include "Utils.hpp" // g++ requires: "src/Utils.hpp"
// #include "ClassObj.hpp" // error if pragma once is not used in ClassObj -> già incluso da "Utils.hpp"

using namespace std;

int main()
{

    string InputFile = "vectors.txt";
    size_t n;
    unsigned int *ptr1 = nullptr;
    unsigned int *ptr2 = nullptr;

    ImportVectors(InputFile, n, ptr1, ptr2);


    delete [] ptr1; // Elimino tutto il vettore con [], altrimenti solo elemento cui punta il ptr
    delete [] ptr2;

    return 0;
}


