#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Utils.hpp"

using namespace std;


int main()
{

    string inputFileName = "data.txt";

    size_t n;
    double s;
    
    // Inizializzo w, r vettori dinamici, inizialmente senza indirizzo
    double* w = nullptr; 
    double* r = nullptr;

    ImportVectors(inputFileName, n, s, w, r);

    double r_tot = DotProduct(n, w, r);
    
    // Formula per il calcolo del valore finale del portafoglio
    double v = (1+r_tot)*s;

    string outputFileName = "results.txt";
    ExportResult(outputFileName, n, w, r, r_tot, s, v);

    delete[] w;
    delete[] r;

    return 0;
    
}

