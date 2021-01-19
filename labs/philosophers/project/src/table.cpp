#include <table.hpp>

Table& Table::Get()
{
    static Table instance;

    //instance.numberOfEatingPhilosophers = 0;

    return instance;
}

