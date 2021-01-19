#include <table.hpp>
#include <thread>
#include <chrono>


class Philosopher
{
private:
    
    int number;

public:
    Philosopher();
    //Philosopher(int phisolopherNumber);


    void Dine();
    void Eat();
    void Think();
};