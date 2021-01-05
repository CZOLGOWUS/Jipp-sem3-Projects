#pragma once

#include <string>


class Employee
{
private:
	std::string id;
	std::string name;
	std::string surname;
	std::string departmentID;
	std::string position;

	static unsigned long lastAssignedID;

public:
	Employee();
	Employee(std::string name, std::string surname);
	Employee(std::string name, std::string surname, std::string departmentID);
	Employee(std::string name, std::string surname, std::string departmentID, std::string position);

	~Employee();

	//getters
	std::string GetId() const;
	std::string GetName() const;
	std::string GetSurname() const;
	std::string GetDepartmentID() const;
	std::string GetPosition() const;

	//setters
	void SetId(std::string);
	void SetName(std::string);
	void SetSurname(std::string);
	void SetDepartmentID(std::string);
	void SetPosition(std::string);

	//operators
	void operator=(const Employee&);
};

