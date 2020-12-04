#include <Matrix.hpp>
#include "MatrixExeptions.cpp"

//file control
std::ifstream OpenInputFile(const std::string& path)
{
    std::ifstream file;
    file.open(path,std::iostream::in);

    try
    {
        if (!file.is_open())
        {
            throw "could not open file : constructor aborted!";
        }
    }
    catch(const std::string& e)
    {
        std::cerr << e << "\n";
        exit(errno);
    }

    return file;
} 
std::ofstream OpenOutputFile(const std::string& path)
{
    std::ofstream file;
    file.open(path, std::iostream::out);

    try
    {
        if (!file.is_open())
        {
            throw "could not open file : constructor aborted!";
        }
    }
    catch(const std::string& e)
    {
        std::cerr << e << "\n";
        exit(errno);
    }

    return file;
} 

// De\- Construktors
Matrix::Matrix()
{
    _xSize = 0;
    _ySize = 0;

    _matrix = nullptr;

}
Matrix::Matrix(int x)
{
    _ySize = x;
    _xSize = x;

    _matrix = InstanciateMatrix(x, x);
    
    for (int i = 0; i < _xSize ; i++)
        for (int j = 0; j < _xSize ; j++)
            set(i, j, 0);
}
Matrix::Matrix(int x, int y)
{
    _ySize = y;
    _xSize = x;

    _matrix = InstanciateMatrix(x, y);

    for (int i = 0; i < _xSize; i++)
        for (int j = 0; j < _ySize ; j++)
        {
            set(i ,j , 0);
        }
}
Matrix::Matrix(int x, int y,double z)
{
    _ySize = y;
    _xSize = x;

    _matrix = InstanciateMatrix(x, y);

    for (int i = 0; i < _xSize; i++)
        for (int j = 0; j < _ySize; j++)
            set(i, j, z);
}
Matrix::Matrix(const std::string& path)
{
    int x = 0, y = 0;
    std::list<double> listOfMatrixNumbers;

    std::string line;
    std::string numberString;


    std::ifstream file = OpenInputFile(path);

    while (std::getline(file, line)) 
    {
        char* c = &line[0];
        char* tempCharPointer = c;
        //47 = '/' , 124 = '|'
        while(*(tempCharPointer) != '\0')
        {
            
            switch (*c)
            {
                case 47: // = '/'
                {
                    ++c;
                    while (*c != '/' && *c != '|')
                    {
                        numberString.append(std::string(1, *c));
                        c++;
                    }

                    if (*c == '/')
                        x = stoi(numberString);
                    else
                        y = stoi(numberString);

                    numberString = "";

                }
                break;

                case 124: // = '|'
                {
                    ++c;
                    while (c != nullptr && *c != '|')
                    {

                        numberString.append(std::string(1,*c));
                        c++;
                    }

                    listOfMatrixNumbers.push_back(stod(numberString));
                    numberString = "";

                }
                break;

                default:
                    break;
            }

            tempCharPointer = c;
            ++tempCharPointer;

        }
    }

        this->_xSize = x;
        this->_ySize = y;

        _matrix = InstanciateMatrix(x, y);

        for (int i = 0; i < x; i++)
            for (int j = 0; j < y; j++)
            {
                set(i, j, listOfMatrixNumbers.front());
                listOfMatrixNumbers.pop_front();
            }

    file.close();
}
Matrix::~Matrix()
{
    try
    {
        for (int i = 0; i < _xSize; i++)
        {
            delete[] _matrix[i];
        }
            delete[] _matrix;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << "\n";
    }
}

//coping constructor
Matrix::Matrix(const Matrix& m1)
{
    this->_matrix = InstanciateMatrix(m1._xSize, m1._ySize);
    this->_xSize = m1._xSize;
    this->_ySize = m1._ySize;

        for (int i = 0; i < this->_xSize; i++)
            for (int j = 0; j < this->_ySize; j++)
            {
                this->set(i,j,m1.get(i,j));
            }
}

//Matrixis in making
/*Matrix* Matrix::duplicate() const
{
    return new Matrix();
}*/

double** Matrix::InstanciateMatrix(int x, int y)
{
    double** matrix = new double*[x];
    for (int i = 0; i < x; i++)
        matrix[i] = new double[y];

    return matrix;
}

//Operations returning pointers
Matrix* Matrix::addReturnPointer(const Matrix& m2 )
{
    try
    {
        if ( !(this->_xSize == m2._xSize && this->_ySize == m2._ySize) )
        {
            throw matrix_diffrent_size();
        }
    }
    catch(const matrix_diffrent_size& e)
    {
        std::cerr << e.what() << "\n";
        return this;
    }

    Matrix* AddedM = new Matrix(this->_xSize, this->_ySize);

    for(int i = 0; i < this->_xSize; i++)
        for (int j = 0; j < this->_ySize; j++)
        {
            AddedM->set(i, j, this->get(i, j) + m2.get(i, j));
        }

    return AddedM;
}
Matrix* Matrix::subbReturnPointer(const Matrix& m2)
{
    try
    {
        if ( !(this->_xSize == m2._xSize && this->_ySize == m2._ySize) )
        {
            throw matrix_diffrent_size();
        }
    }
    catch(const matrix_diffrent_size& e)
    {
        std::cerr << e.what() << "\n";
        return this;
    }

    Matrix* SubbM = new Matrix(this->_xSize, this->_ySize);

    for (int i = 0; i < this->_xSize; i++)
        for (int j = 0; j < this->_ySize; j++)
        {
            SubbM->set(i, j, this->get(i, j) - m2.get(i, j));
        }

    return SubbM;
}
Matrix* Matrix::multiReturnPointer(const Matrix& m2 )
{
    try
    {
        if ( !(this->_xSize == m2._xSize && this->_ySize == m2._ySize) )
        {
            throw matrix_multiplication_error();
        }
    }
    catch(const matrix_multiplication_error& e)
    {
        std::cerr << e.what() << "\n";
        return this;
    }

    Matrix* MultiM = new Matrix( this->_xSize , m2._ySize , (double)0);

    for (int i = 0; i < this->_xSize; i++)
    {
        for (int j = 0; j < m2._ySize; j++)
        {
            for (int k = 0; k < this->_ySize ; k++)
                MultiM->_matrix[i][j] += this->get(i,k) * m2.get(k,j);
        }
    }
    return MultiM;
}

//Operations returning copies
Matrix Matrix::addReturnCopy(const Matrix& m2) const
{
    try
    {
        if ( !(this->_xSize == m2._xSize && this->_ySize == m2._ySize) )
        {
            throw std::invalid_argument("matrixies cannot be added : diffrent sizes");
        }
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << "\n";
        std::cerr << errno;
        exit(errno);
    }

    Matrix AddedM(this->_xSize, this->_ySize);

    for (int i = 0; i < this->_xSize; i++)
        for (int j = 0; j < this->_ySize; j++)
        {
            AddedM.set(i, j, this->get(i, j) + m2.get(i, j));
        }

    return AddedM;
}
Matrix Matrix::subbReturnCopy(const Matrix& m2) const
{
    try
    {
        if ( !(this->_xSize == m2._xSize && this->_ySize == m2._ySize) )
        {
            throw std::invalid_argument("matrixies cannot be added : diffrent sizes");
        }
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << "\n";
        std::cerr << errno;
        exit(errno);
    }

    Matrix SubbM(this->_xSize, this->_ySize);

    for (int i = 0; i < this->_xSize; i++)
        for (int j = 0; j < this->_ySize; j++)
        {
            SubbM.set(i, j, this->get(i, j) - m2.get(i, j));
        }

    return SubbM;
}
Matrix Matrix::multiReturnCopy(const Matrix& m2) const
{
    try
    {
        if (m2._xSize != this->_ySize )
        {
            throw std::invalid_argument("matrixies cannot be multiplied : this.number_of_columns is not equal to second_Matrix.number_of_rows");
        }
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << "\n";
        std::cerr << errno;
        exit(errno);
    }

    Matrix MultiM( this->_xSize , m2._ySize , (double)0);

    for (int i = 0; i < this->_xSize; i++)
    {
        for (int j = 0; j < m2._ySize; j++)
        {
            for (int k = 0; k < this->_ySize ; k++)
                MultiM._matrix[i][j] += this->get(i,k) * m2.get(k,j);
        }
    }
    return MultiM;
}

//operators
Matrix Matrix::operator-(const Matrix& m2) const
{
    try
    {
        if ( !(this->_xSize == m2._xSize && this->_ySize == m2._ySize) )
        {
            throw matrix_diffrent_size();
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << "\n";
        std::cerr << errno;
        exit(errno);
    }

    Matrix SubbMatrix(this->_xSize, this->_ySize);

    for (int i = 0; i < this->_xSize; i++)
        for (int j = 0; j < this->_ySize; j++)
        {
            SubbMatrix.set(i, j, this->get(i, j) - m2.get(i, j));
        }

    return SubbMatrix;
}
Matrix Matrix::operator+(const Matrix& m2) const 
{
    try
    {
        if ( !(this->_xSize == m2._xSize && this->_ySize == m2._ySize) )
        {
            throw matrix_diffrent_size();
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << "\n";
        std::cerr << errno;
        exit(errno);
    }

    Matrix new_mat(_xSize, _ySize);
    for (int i = 0; i < _xSize; i++) 
    {
        for (int j = 0; j < _ySize; j++) 
        {
            new_mat._matrix[i][j] = _matrix[i][j] + m2._matrix[i][j];
        }
    }
    return new_mat;
}
Matrix Matrix::operator*(const Matrix& m2) const 
{
    try
    {
        if (m2._xSize != this->_ySize )
        {
            throw matrix_multiplication_error();
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << "\n";
        return(*this);
    }

    Matrix MultiM( this->_xSize , m2._ySize , (double)0);

    for (int i = 0; i < this->_xSize; i++)
    {
        for (int j = 0; j < m2._ySize; j++)
        {
            for (int k = 0; k < this->_ySize ; k++)
                MultiM._matrix[i][j] += this->get(i,k) * m2.get(k,j);
        }
    }
    return MultiM;
}
void Matrix::operator = (const Matrix& m1)
{
    if (!(this->_xSize == m1._xSize && this->_ySize == m1._ySize))
    {
        this->_matrix = InstanciateMatrix(m1._xSize, m1._ySize);
    }

    this->_xSize = m1._xSize;
    this->_ySize = m1._ySize;

    for (int i = 0; i < this->_xSize; i++)
        for (int j = 0; j < this->_ySize; j++)
        {
            this->_matrix[i][j] = m1._matrix[i][j];
        }

}

//defult methods
void Matrix::set(int x = 0, int y = 0, double val = 0)
{
    try
    {
        if(this->_xSize < x || this->_ySize < y)
            throw std::out_of_range("Getter failed : out of range of matrix");

        _matrix[x][y] = val;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << "\n";
        std::cerr << errno;
        exit(errno);
    }
}
double Matrix::get(int x, int y) const
{
    try
    {
        if(this->_xSize < x || this->_ySize < y)
            throw std::out_of_range("Getter failed : out of range of matrix");

        return _matrix[x][y];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << "\n";
        std::cerr << errno;
        exit(errno);
    }
}
void Matrix::PrintMatrix()const
{
    int largerstNumber = 0;
    int k;
    for (int i = 0; i < _xSize; i++)
        for (int j = 0; j < _ySize; j++)
        {
            k = std::to_string(this->get(i,j)).length();
            if (k > largerstNumber)
            {
                largerstNumber = k;
            }
        }

    for (int i = 0; i < _xSize; i++)
    {
        std::cout << "| ";
        for (int j = 0; j < _ySize; j++)
        {
            std::cout << std::setw(largerstNumber - 5) << this->get(i,j) << " ";
        }
        std::cout << " |\n";
    }
    std::cout << "\n";
}
int Matrix::cols() const
{
    return this->_ySize;
}
int Matrix::rows() const
{
    return this->_xSize;
}
void Matrix::store(const std::string& filename, const std::string& path) const
{
    std::ofstream file;
#ifdef _WIN32
    file = OpenOutputFile(path + "//" + filename);
#else
    file = OpenOutputFile(path + "/" + filename);
#endif

        std::string placeHolderString;
        try
        {
            if(!(file << '/' << _xSize << '/' << _ySize <<'|'))
                throw std::ios_base::failure("could not save size of matrix to file");
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << "\n";
        }

        for (int x = 0; x < _xSize; x++)
            for (int y = 0; y < _ySize; y++)
            {
                placeHolderString.append(std::to_string(this->get(x,y)) + '|');
            }

        try
        {
            if(!(file << placeHolderString))
                throw std::ios_base::failure("could not save matrix to file");
            file.close();
            return;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << "\n";
        }

}
