#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <iomanip>  
#include <algorithm>
#include <functional>

#include "Employee.h"

class HRMS
{

private:

	HRMS() {}
	//static HRMS s_HRMS;

	std::map<std::string, Employee*> employeesMap;		//<id, employees>
	std::map<std::string, std::string> departamentsMap; //<departamentID , employee id>
	std::map<std::string, double> salaryMap;			 //<id, salary>

public:

	HRMS(const HRMS&) = delete;


	static HRMS& Get();

	void AddEmployee(Employee& employee, std::string departmentId, double salary);
	void AddEmployee(Employee& employee, double salary);

	void PrintDepartment(std::string& departmentId);
	void ChangeSalary(std::string employeeId, double salary);
	void PrintEmployeeInfo(std::string ID) const;
	void PrintSalaries() const;
	void PrintSalariesSorted() const;

};

