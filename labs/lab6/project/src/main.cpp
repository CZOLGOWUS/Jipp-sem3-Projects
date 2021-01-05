#include <HRMS.h>

#include <time.h>
#include <random>
#include <string>

std::string random_string(std::size_t length)
{
	const std::string CHARACTERS = "abcdefghijklmnopqrstuvwxyz";

	std::random_device random_device;
	std::mt19937 generator(random_device());
	std::uniform_int_distribution<> distribution(0, CHARACTERS.size() - 1);

	std::string random_string;

	for (std::size_t i = 0; i < length; ++i)
	{
		random_string += CHARACTERS[distribution(generator)];
	}

	return random_string;
}



int main()
{
	srand(time(NULL));

	//std::cout << "random string of 5: " << random_string(5)<<std::endl;


	int length = 10;
	Employee* employees = new Employee[length];


	std::string depn = std::to_string(2);
	for (int i = 0; i < length; i++)
	{
		employees[i] = Employee("name" + std::to_string(i), "surrname" + std::to_string(i));
		HRMS::Get().AddEmployee(employees[i], "dep" + std::to_string(i % 3) , ((int)i + 1) * 1000 * (rand() % 10+1) );
	}

	HRMS::Get().PrintSalaries();

	std::cout << std::endl;

	HRMS::Get().PrintSalariesSorted();

	std::cout << std::endl;

	HRMS::Get().ChangeSalary(employees[1].GetId(),9999);

	HRMS::Get().PrintSalaries();


	delete[] employees;
	return 0;
}