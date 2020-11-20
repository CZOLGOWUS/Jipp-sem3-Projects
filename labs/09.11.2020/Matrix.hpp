#include <iostream>


class Matrix
{
private:
    double** _matrix;
    int _n,_m;

    friend double** InstanciateMatrix(int x, int y); 



public:
    Matrix();
    Matrix(int x, int y);
    Matrix(int x);
    void set(int y, int x , int val);
    int** get(int x, int y) const;

    
};