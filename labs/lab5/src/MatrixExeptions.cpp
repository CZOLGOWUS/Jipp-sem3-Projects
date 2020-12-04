#include <iostream>
#include <exception>

class matrix_diffrent_size : public std::exception
{
    public:
    virtual const char *what() const throw()
    {
        return "Sizes of matrixies are not equal\n";
    }
};

class matrix_multiplication_error : public std::exception
{
    public:
    virtual const char *what() const throw()
    {
        return "number of columns in one matrix is not equal to number of rows in the other\n";
    }
};
