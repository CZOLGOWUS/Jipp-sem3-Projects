#include <iostream>
#include "Matrix.hpp"

Matrix::Matrix()
{
    _n = 0;
    _m = 0;

    _matrix = InstanciateMatrix(_n,_m);
}

Matrix::Matrix(int x)
{
    _n = x;
    _m = x;
}

Matrix::Matrix(int x, int y)
{
    _n = x;
    _m = y;
}

Matrix::InstanciateMatrix(int x, int y)
{
    double** matrix = new double*[y];

    for(int i = 0 ;i<y;i++)
        matrix[i] = new double[y];

    return matrix;
}