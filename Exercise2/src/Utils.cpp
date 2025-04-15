#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Utils.hpp"

using namespace std;

// Funzione per leggere i dati dal file e memorizzarli nelle variabili S, n e nei vettori w e r

bool ImportVectors(const string& inputFilePath,
    size_t& n,
    double& S,
    double*& w,
    double*& r)
{
    // Controllo l'apertura corretta del file
    ifstream file;
    file.open(inputFilePath);

    if (file.fail())
    {
        cerr<< "Apertura del file errata" << endl;
        return false;
    }

    // Memorizzo il valore del capitale iniziale
    std::string tmp;
    getline(file, tmp, ';'); // Elimino dalla riga i caratteri superflui 
    file >> S;
    file.ignore();

    getline(file, tmp, ';');
    file >> n;
    file.ignore();
    getline(file, tmp);

    // Allocazione manuale dei vettori w e r 
    w = new double[n];
	r = new double[n];

    for(unsigned int i = 0; i < n; i++)
    {
        getline(file, tmp);

        unsigned int pos = tmp.find(";");

        w[i] = stod(tmp.substr(0, pos));
        r[i] = stod(tmp.substr(pos + 1)); // Estraggo sottostringhe da tmp, in w metto i valori prima di ';', in r quelli dopo

    }

    file.close(); // Chiudo il file e restituisco un valore di tipo bool

return true;

}


// Funzione che calcola il prodotto scalare tra vettori

double DotProduct(const size_t& n,
    const double* const& v1,
    const double* const& v2) // Passaggio per riferimento costante -> costanti sia l'indirizzo che il valore
{

    double dotProduct = 0;
    for (unsigned int i = 0; i < n; i++)
    dotProduct += v1[i] * v2[i];

    return dotProduct;

}

// Funzione per stampare output

bool ExportResult(const string& outputFilePath,
    const size_t& n,
    const double* const& w,
    const double* const& r,
    const double& rate,
    const double& s,
    const double& v)
{


ofstream file;
file.open(outputFilePath);

if (file.fail())
{
cerr<< "errore apertura file" << endl;
return false;
}

file << "S = " << fixed << setprecision(2) << s << ", n = " << n << endl;

// Resetto la precisione a 4 cifre
file.unsetf(ios::fixed);		
file << setprecision(4);

file << "w = " << ArrayToString(n, w) << endl;
file << "r = " << ArrayToString(n, r) << endl;


file << "Rate of return of the portfolio: " << rate << endl;
file << "V: " << fixed << setprecision(2) << v << endl;

// Close File
file.close();

return true;
}


// Da array a stringa per poterlo stampare
string ArrayToString(const size_t& n,
       const double* const& v)
{
    string str;
    ostringstream toString;
    toString << "[ ";

    for (unsigned int i = 0; i < n; i++)
        toString<< v[i]<< " ";
    
    toString << "]";

    return toString.str();
}
