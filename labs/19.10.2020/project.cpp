#include <iostream>
#include <string>



void CompareAndSwapIfGreater(int* a, int* b);
void SwapRef(int& a, int& b);
void SwapRefPtr(int& a, int* b);
float ReturnMultiplyAndAdd(int& a, int& b, float& iloczyn, float& suma);
template <typename T> void SwapGeneric(T& a, T& b);
void testSwapGeneric();



int main()
{

    int a = 10;
    int b = 20;
    CompareAndSwapIfGreater(&a, &b);
    std::cout << "CompareAndSwapIfGreater:";
    std::cout << " a:" << a << "  b:" << b << std::endl;

    SwapRef(a,b);
    std::cout << "SwapRef:";
    std::cout << " a:" << a << "  b:" << b << std::endl;

    SwapRefPtr(a,&b);
    std::cout << "SwapRefPtr:";
    std::cout << " a:" << a << "  b:" << b << std::endl;


    float iloczyn = 0;
    float suma = 0;

    std::cout << "ReturnMultiplyAndAdd:  iloczyn:";
    std::cout<<ReturnMultiplyAndAdd(a, b, iloczyn, suma);
    std::cout << "  suma:" << suma << std::endl;



    std::cout << "SwapGeneric: " << std::endl;
    testSwapGeneric();

    std::cout << std::endl;
    char *cx = new char('x');
    char *cy = new char('y');
    std::cout << "x = " << cx << "  y = " << cy << std::endl;
    std::swap(cx, cy);
    std::cout << "std::swap overloaded: \n";
    std::cout << "x = " << cx << "  y = " << cy << std::endl;

    delete cx, cy;

}



//zad1---------------------------------------------------------------------------------------------------------- 

void CompareAndSwapIfGreater(int* a, int* b)
{
    if (*a > *b)
    {
        int j = *a;
        *a = *b;
        *b = j;
    }
}

//zad2---------------------------------------------------------------------------------------------------------- 

void SwapRef(int& a, int& b)
{
    int j = a;
    a = b;
    b = j;
}

//zad3---------------------------------------------------------------------------------------------------------- 

void SwapRefPtr(int& a, int* b)
{
    int j = a;
    a = *b;
    *b = j;
}

//zad4---------------------------------------------------------------------------------------------------------- 

float ReturnMultiplyAndAdd(int& a,int& b, float& iloczyn, float& suma)
{
    suma = (float)a + b;
    return iloczyn = (float)a * b;
}

//zad5---------------------------------------------------------------------------------------------------------- 

template <typename T> void SwapGeneric(T& a, T& b)
{
    T  temp = a;
    a = b;
    b = temp;
}

//zad6---------------------------------------------------------------------------------------------------------- 
namespace std
{
    template <typename T> void swap(T* a, T* b)
    {
        T* temp = a;
        a = b;
        b = temp;
    }
}

void testSwapGeneric()
{
    int type = 0;

    std::cout << "what type would you like to test:" << std::endl;
    std::cout<<"1. int\n";
    std::cout<<"2. float\n";
    std::cout<<"3. double\n";
    std::cout<<"4. string\n";
    std::cout<<"5. char\nenter number 1-5" << std::endl;

    std::cin >> type;

    while (type < 1 || type > 5)
    {
        std::cout << "wrong number! pick one from 1 to 5: ";
        std::cin >> type;
    }
    


    switch (type)
    {
        case 1:
        {
            std::cout << "wprowadz dwie liczby! \n";
            int x = 0, y = 0;
            std::cout << "x :";
            std::cin >> x;
            std::cout << "y :" << std::endl;
            std::cin >> y;
            SwapGeneric(x, y);
            std::cout << "x = " << x << "  y = " << y << std::endl;
        }break;

        case 2:
        {
            std::cout << "wprowadz dwie liczby! \n";
            float x = 0, y = 0;
            std::cout << "\nx :";
            std::cin >> x;
            std::cout << "y :";
            std::cin >> y;
            SwapGeneric(x, y);
            std::cout << "x = " << x << "  y = " << y << std::endl;
        }break;

        case 3:
        {
            std::cout << "wprowadz dwie liczby!\n";
            double x = 0, y = 0;
            std::cout << "\nx :";
            std::cin >> x;
            std::cout << "y :";
            std::cin >> y;
            SwapGeneric(x, y);
            std::cout << "x = " << x << "  y = " << y << std::endl;
        }break;

        case 4:
        {
            std::cout << "wprowadz dwa stringi\n";
            std::string x = "", y = "";
            std::cout << "\nx :";
            std::cin >> x;
            std::cout << "y :";
            std::cin >> y;
            SwapGeneric(x, y);
            std::cout << "x = " << x << "  y = " << y << std::endl;
        }break;

        case 5:
        {
            std::cout << "enter two chars\n";
            char x = 0, y = 0;
            std::cout << "\nx :";
            std::cin >> x;
            std::cout << "y :";
            std::cin >> y;
            SwapGeneric(x, y);
            std::cout << "x = " << x << "  y = " << y << std::endl;
        }break;

        default:
            break;
    }

}
