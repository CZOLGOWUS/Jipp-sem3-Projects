#include <Matrix.hpp>


void test()
{
    std::cout << "creating Matrixsies:\n";
    Matrix M1;
    Matrix M2(5);
    Matrix M3(4, 5,1);
    Matrix M4(4, 5,2);
    Matrix Mm1(6,14,3);
    Matrix Mm2(14,6, 4);

    std::cout << "Printing created Matrixsies:\n";
    M1.PrintMatrix();
    M2.PrintMatrix();
    M3.PrintMatrix();
    M4.PrintMatrix();
    Mm1.PrintMatrix();
    Mm2.PrintMatrix();
    std::cout << "\n\n\n\n";


    std::cout << "Adding Matrix: \n";
    M3.PrintMatrix();
    std::cout << "\n";
    M4.PrintMatrix();
    std::cout << "\n";


    Matrix* M3M4 = M3.addReturnPointer(M4); // dodaje do M3, M4
    M3M4->PrintMatrix();
    std::cout << "\n";

    std::cout << "Substracting Matrix: \n";
    M3.PrintMatrix();
    std::cout << "\n";
    M4.PrintMatrix();
    std::cout << "\n";


    Matrix* MSubstructed = M3.subbReturnPointer(M4);
    MSubstructed->PrintMatrix();
    std::cout << "\n";

    std::cout << "Operator + \n";
    Matrix M8 = M3 + M4;
    M8.PrintMatrix();

    std::cout << "Get() and set() in (0,0) Matrix:\n";
    M4.PrintMatrix();
    std::cout << "\n";
    std::cout << "setting (0,0) to 654546522231\n";
    M4.set(0, 0, 654546522231);
    M4.PrintMatrix();
    std::cout << "\n";
    std::cout << M4.get(0, 0) << std::endl;

    std::cout << "Multiplication of 2 Matrixies:\n";
    Mm1.PrintMatrix();
    std::cout << "\n";
    Mm2.PrintMatrix();
    std::cout << "\n\n\n";
    Matrix* Mm3 = Mm1.multiReturnPointer(Mm2);
    Mm3->PrintMatrix();
    std::cout << "\n\n\n";

//Zapis i odczyt macierzy:
    Matrix test(12, 32);
    for (int i = 0; i < test.rows(); i++)
        for (int j = 0; j < test.cols(); j++)
            test.set(i, j, (double)10 * i * j * 0.54);
    std::cout << "Save Matrix:\n";
    test.PrintMatrix();
    std::cout << "\n\n\n";

#ifdef _WIN32
    test.store("test.txt", "E:\\studia\\semestr 3\\JiPP\\labs\\1\\visualcommunity porject\\tests");
#else
    test.store("test.txt", "./");
#endif

    std::cout << "Load Matrix:\n";
    std::cout << "\n\n\n";

#ifdef _WIN32
    Matrix test2("E:\\studia\\semestr 3\\JiPP\\labs\\1\\visualcommunity porject\\tests\\test.txt");
#else
    Matrix test2("./test.txt");
#endif

    test2.PrintMatrix();


    std::cout << "\n\n\n";    
    std::cout << "\nTesting copying constructors:\n";

    Matrix a1(5, 7, 3);
    Matrix a2(5, 7, 1);

    std::cout << "a1: \n";
    a1.PrintMatrix();

    std::cout << "a2: \n";
    a2.PrintMatrix();



    std::cout << "\nAdding\n";
    a1 = a1 + a2;

    std::cout << "a1: \n";
    a1.PrintMatrix();

    std::cout << "a2: \n";
    a2.PrintMatrix();
    


    std::cout << "\nSubbstracting\n";
    a1 = a1 - a2;

    std::cout << "a1: \n";
    a1.PrintMatrix();

    std::cout << "a2: \n";
    a2.PrintMatrix();
    
    

    Matrix Mmmulti1(10,5,2);
    Matrix Mmmulti2(5,10,5);

    std::cout << "Mmmulti1: \n";
    Mmmulti1.PrintMatrix();

    std::cout << "Mmmulti2: \n";
    Mmmulti2.PrintMatrix();


    std::cout << "\nMultiplying\n";
    Mmmulti1 = Mmmulti1 * Mmmulti2;

    std::cout << "Mmmulti1: \n";
    Mmmulti1.PrintMatrix();

    std::cout << "Mmmulti2: \n";
    Mmmulti2.PrintMatrix();


}

int main()
{

	test();

	return 0;
}
