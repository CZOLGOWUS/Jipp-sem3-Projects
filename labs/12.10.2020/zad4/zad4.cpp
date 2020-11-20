#include <iostream>
#include <list>



int AddElementsOfListIntFrom(std::list<int>* list, std::list<int>::iterator i)
{
    if (i != list->end()) return *i + AddElementsOfListIntFrom(list,++i);
    else
        return 0;

}


int main()
{

    int a = 0;
    int b = 0;
    std::list<int>* alist = new std::list<int>();
    std::list<int>* blist = new std::list<int>();
    int sumOfListA = 0;
    int sumOfListB = 0;


    std::cout << "please insert 2 numbers to check if they are associated: ";
    std::cin >> a;
    std::cin >> b;
    std::cout << "\n\n";


    for (int i = 1; i < (a - b < 0 ? b / 2 + 1 : a / 2 + 1); i++)
    {
        if (a % i == 0) alist->push_back(i);
        if (b % i == 0) blist->push_back(i);
    }
    
    sumOfListA = AddElementsOfListIntFrom(alist , alist->begin());
    sumOfListB = AddElementsOfListIntFrom(blist , blist->begin());

    if (sumOfListA == b + 1 && sumOfListB == a + 1) std::cout << "assosiated!\n";
    else
        std::cout << "not assosiated\n";
    
    delete alist;
    delete blist;

    return 0;
}



