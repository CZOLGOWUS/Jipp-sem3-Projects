#include <HRMS.h>

using namespace std;

HRMS& HRMS::Get()
{
	static HRMS instance;
	return instance;
}
void HRMS::AddEmployee(Employee& employee, std::string departmentId, double salary)
{
	employee.SetDepartmentID(departmentId);
	employeesMap[employee.GetId()] = &employee;
	salaryMap[employee.GetId()] = salary;
	departamentsMap[employee.GetId()] = employee.GetDepartmentID();
}
void HRMS::AddEmployee(Employee& employee, double salary)
{
	std::string newId;
	std::string newName;
	std::string newSurname;
	std::string newDepartmentID;
	std::string newPosition;

	std::map<std::string, Employee*>::iterator it;

	std::cout <<"current ID = %ld" << employee.GetId() << std::endl;
	std::cout << "if you dont want to change id enter \"!n\" \n";
	std::cout << "enter id: ";
	std::cin >> newId;
	it = employeesMap.find(newId);
	while(it != employeesMap.end())
	{
		std::cout << "id already exists, if you dont want to change id enter \"!n\"\n";
		std::cin >> newId;

		if(newId == "!n")
			break;

		it = employeesMap.find(newId);
	}
	employee.SetId(newId);

	std::cout << "enter name: ";
	std::cin >> newName;
	employee.SetName(newName);

	std::cout << "enter surrname: ";
	std::cin >> newSurname;
	employee.SetSurname(newSurname);

	std::cout << "enter departament ID to assigne Employee: ";
	std::cin >> newDepartmentID;
	employee.SetDepartmentID(newDepartmentID);

	std::cout << "assigne position: ";
	std::cin >> newPosition;
	employee.SetPosition(newPosition);
	
	employeesMap[newId] = &employee;
	salaryMap[employee.GetId()] = salary;
	departamentsMap[newId] = newDepartmentID;
	

}
void HRMS::PrintDepartment(std::string& depId)
{
	std::map<std::string, std::string>::iterator it;
	Employee* ep;

	std::cout << "Departament [" << depId << "]\n";

	for (auto &it : departamentsMap)
	{
		ep = employeesMap[it.second];
		std::cout << "ID: " << ep->GetId() << "Name: " << ep->GetName() << "Surrname: " << ep->GetSurname() << "Department: " << ep->GetDepartmentID() << std::endl;
	}
}
void HRMS::ChangeSalary(std::string employeeId, double salary)
{
	salaryMap.find(employeeId)->second = salary;
}
void HRMS::PrintEmployeeInfo(std::string ID) const
{
	auto& it = employeesMap.find(ID)->second;
	std::cout <<
		" ID: " << std::setw(6) << it->GetId() <<
		" Name: " << std::setw(6) << it->GetName() <<
		" Surrname: " << std::setw(6) << it->GetSurname() <<
		" Department: " << std::setw(6) << it->GetDepartmentID() <<
		" Position: " << std::setw(6) << it->GetPosition() <<
		" Salary: " << std::setw(6) << salaryMap.find(ID)->second << std::endl;
}
void HRMS::PrintSalaries() const
{
	for (auto& it : salaryMap)
	{
		PrintEmployeeInfo(it.first);
	}
}
void HRMS::PrintSalariesSorted() const
{
	std::vector<std::pair<double,std::string> > salaryTemp;


	for (auto& it : salaryMap)
	{
		salaryTemp.push_back(std::make_pair(it.second,it.first));
	}
	

	std::sort(salaryTemp.begin(),salaryTemp.end(),
	
		[](std::pair<double, std::string>& a, std::pair<double, std::string>& b)
		{
			return a.first != b.first ? a.first < b.first : a.first < b.first;
		}
	);

	for (auto& it : salaryTemp)
	{
		PrintEmployeeInfo(it.second);
	}

}

