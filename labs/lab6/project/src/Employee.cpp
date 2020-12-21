#include <Employee.h>

unsigned long Employee::lastAssignedID = 0;

Employee::Employee()
{
	this->id = std::to_string(lastAssignedID++);
	this->name = "not set";
	this->surname = "not set";
	this->departmentID = "not set";
	this->position = "not set";
}
Employee::Employee(  std::string name, std::string surname)
{
	this->id = std::to_string(lastAssignedID++);
	this->name = name;
	this->surname = surname;
	this->departmentID = "not set";
	this->position = "not set";
}
Employee::Employee(  std::string name, std::string surname, std::string departmentID)
{
	this->id = std::to_string(lastAssignedID++);
	this->name = name;
	this->surname = surname;
	this->departmentID = departmentID;
	this->position = "not set";
}
Employee::Employee(  std::string name, std::string surname, std::string departmentID, std::string position)
{
	this->id = std::to_string(lastAssignedID++);
	this->name = name;
	this->surname = surname;
	this->departmentID = departmentID;
	this->position = position;
}

Employee::~Employee()
{
	//delete this;
}

//getters
std::string Employee::GetId() const
{
	return this->id;
}
std::string Employee::GetName() const
{
	return this->name;
}
std::string Employee::GetSurname() const
{
	return this->surname;
}
std::string Employee::GetDepartmentID() const
{
	return this->departmentID;
}
std::string Employee::GetPosition() const
{
	return this->position;
}


//setters
void Employee::SetId(std::string s)
{
	this->id = s;
}
void Employee::SetName(std::string s)
{
	this->name = s;
}
void Employee::SetSurname(std::string s)
{
	this->surname = s;
}
void Employee::SetDepartmentID(std::string s)
{
	this->departmentID = s;
}
void Employee::SetPosition(std::string s)
{
	this->position = s;
}
void Employee::operator=(const Employee& e)
{
	this->id = e.id;
	this->name = e.name;
	this->surname = e.surname;
	this->departmentID = e.departmentID;
	this->position = e.position;
}
