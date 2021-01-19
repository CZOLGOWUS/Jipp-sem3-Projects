#include <philosopher.hpp>
#include <time.h>

using namespace std;

Philosopher::Philosopher()
{
    static int numberOfAllPhilosophers = 0;
    this->number = numberOfAllPhilosophers++;
}

void Philosopher::Eat()
{
    cout << "eating...[" << number << "]\n"; // << "numberOfPhilosophersEating:"<< Table::Get().numberOfEatingPhilosophers;
    this_thread::sleep_for( chrono::milliseconds(1000));
}

void Philosopher::Think()
{
    cout << "thinking..." << "[" << number << "]\n";
    this_thread::sleep_for( chrono::milliseconds(1000));
}

void Philosopher::Dine()
{
    cout << "filozofs number ------------ " << this->number << endl;
    //wait for next mutext to be initialized
    this_thread::sleep_for( chrono::milliseconds(300));

    while(1)
    {
        
        (Table::Get().numberOfEatingPhilosophers)++;

        if( Table::Get().numberOfEatingPhilosophers > 4 )
        {
            Table::Get().butler.lock();
        }

        Think();
        Table::Get().forks[this->number].lock();
        Table::Get().forks[ (this->number+1) % 5 ].lock();
        
        Eat();
        Table::Get().forks[this->number].unlock();
        Table::Get().forks[ (this->number+1) % 5 ].unlock();

        Table::Get().butler.unlock();

        (Table::Get().numberOfEatingPhilosophers)--;

    }
}
