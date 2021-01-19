#include <iostream>
#include <mutex>
#include <atomic>


class Table
{
private:
    Table() {};

public:
    //ensuring singleton
    Table(const Table&) = delete;
    static Table& Get();


    //variables
    std::mutex forks[5];
    std::mutex butler;
    std::atomic<int> numberOfEatingPhilosophers;

};