#pragma once

#include <iostream>
#include <string>

using namespace std;

bool ImportVectors(const string& inputFilePath,
    size_t& n,
    double& S,
    double*& w,
    double*& r);

double DotProduct(const size_t& n,        
    const double* const& v1,
    const double* const& v2);

bool ExportResult(const string& outputFilePath,
    const size_t& n,
    const double* const& w,
    const double* const& r,
    const double& rate,
    const double& s,
    const double& v);

string ArrayToString(const size_t& n,
    const double* const& v);

