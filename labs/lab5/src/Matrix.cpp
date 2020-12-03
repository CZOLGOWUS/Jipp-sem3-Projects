#include <Matrix.hpp>

// De\- Construktors
Matrix::Matrix()
{
    _xSize = 1;
    _ySize = 1;

    _matrix = InstanciateMatrix(1, 1);
    _matrix[0][0] = 1;
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
Matrix::Matrix(std::string path)
{
    int x = 0, y = 0;
    std::list<double> listOfMatrixNumbers;

    std::ifstream file;

    std::string line;
    std::string numberString;

    file.open(path, std::iostream::out);
    if (!file.is_open())
    {
        std::cout << "could not open file : constructor aborted\n";
        exit(-1);
    }

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

    try
    {
        for (int i = 0; i < this->_xSize; i++)
            for (int j = 0; j < this->_ySize; j++)
            {
                this->_matrix[i][j] = m1._matrix[i][j];
            }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
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
Matrix* Matrix::addReturnPointer(const Matrix& m2 ) const
{
    try
    {
        if ( !(this->_xSize == m2._xSize && this->_ySize == m2._ySize) )
        {
            throw std::invalid_argument("matrixies cannot be added : diffrent sizes");
        }
    }
    catch(const std::out_of_range& e)
    {
        std::cerr << e.what() << "\n";
    }

    Matrix* AddedM = new Matrix(this->_xSize, this->_ySize);

    for(int i = 0; i < this->_xSize; i++)
        for (int j = 0; j < this->_ySize; j++)
        {
            AddedM->set(i, j, this->get(i, j) + m2.get(i, j));
        }

    return AddedM;
}
Matrix* Matrix::subbReturnPointer(const Matrix& m2) const
{
    try
    {
        if ( !(this->_xSize == m2._xSize && this->_ySize == m2._ySize) )
        {
            throw std::invalid_argument("matrixies cannot be added : diffrent sizes");
        }
    }
    catch(const std::out_of_range& e)
    {
        std::cerr << e.what() << "\n";
    }

    Matrix* SubbM = new Matrix(this->_xSize, this->_ySize);

    for (int i = 0; i < this->_xSize; i++)
        for (int j = 0; j < this->_ySize; j++)
        {
            SubbM->set(i, j, this->get(i, j) - m2.get(i, j));
        }

    return SubbM;
}
Matrix* Matrix::multiReturnPointer(const  Matrix& m2 ) const
{
    try
    {
        if (m2._xSize != this->_ySize )
        {
            throw std::invalid_argument("matrixies cannot be added : this.number_of_columns is not equal to secondMatrix.number_of_rows");
        }
    }
    catch(const std::out_of_range& e)
    {
        std::cerr << e.what() << "\n";
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
    catch(const std::out_of_range& e)
    {
        std::cerr << e.what() << "\n";
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
    catch(const std::out_of_range& e)
    {
        std::cerr << e.what() << "\n";
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
            throw std::invalid_argument("matrixies cannot be added : this.number_of_columns is not equal to secondMatrix.number_of_rows");
        }
    }
    catch(const std::out_of_range& e)
    {
        std::cerr << e.what() << "\n";
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
            throw std::invalid_argument("matrixies cannot be added : diffrent sizes");
        }
    }
    catch(const std::out_of_range& e)
    {
        std::cerr << e.what() << "\n";
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
            throw std::invalid_argument("matrixies cannot be added : diffrent sizes");
        }
    }
    catch(const std::out_of_range& e)
    {
        std::cerr << e.what() << "\n";
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
            throw std::invalid_argument("matrixies cannot be added : this.number_of_columns is not equal to secondMatrix.number_of_rows");
        }
    }
    catch(const std::out_of_range& e)
    {
        std::cerr << e.what() << "\n";
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
        _matrix[x][y] = val;
    }
    catch(const std::out_of_range& e)
    {
        std::cerr << e.what() << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << "\n";
    }
}
double Matrix::get(int x, int y) const
{
    try
    {
        return _matrix[x][y];
    }
    catch(const std::out_of_range& e)
    {
        std::cerr << e.what() << "\n";

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << "\n";
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
void Matrix::store(std::string filename, std::string path) const
{
    std::ofstream file;
#ifdef _WIN32
try
{
    file.open(path + "//" + filename );
}
catch(const std::exception& e)
{
    std::cerr << e.what() << "\n";
}
#else
try
{
    file.open(path + "/" + filename );
}
catch(const std::exception& e)
{
    std::cerr << e.what() << "\n";
}
#endif

        std::string placeHolderString;
        try
        {
            file << '/' << _xSize << '/' << _ySize <<'|';
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
            file << placeHolderString;
            file.close();
            return;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << "\n";
        }

    std::cout << "file : " << filename << " could not be opened\n";
    exit(-1);

}
