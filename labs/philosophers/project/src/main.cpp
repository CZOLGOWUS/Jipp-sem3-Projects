
#include <philosopher.hpp>
#include <array>


Philosopher philosophers[5];


void InstanciateNewPhilosopher()
{
    static int numberOfInstanciatedPhilosophers = 0;
    philosophers[numberOfInstanciatedPhilosophers++].Dine();
}

void NewDinner()
{
    Table::Get().numberOfEatingPhilosophers.store(0);
    std::thread philosopherThread[5];

    for(int i = 0 ; i < 5 ; i++)
    {
        philosopherThread[i] = std::thread(InstanciateNewPhilosopher);
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }

    for(int i = 0 ; i < 5 ; i++)
    {
        philosopherThread[i].join();
    }

}

int main()
{
    NewDinner();


    return 0;
}

