/*********************************************************
Materia: Graficas Computacionales
Fecha: 14/08/17
Autor: A01374645 Javier Esponda
*********************************************************/
#pragma once
#include <string>

class Employee {
public:
	Employee(int id, std::string firstName, std::string lastName, int salary);

	int GetID();
	std::string GetFirstName();
	std::string GetLastName();
	std::string GetName();
	int GetSalary();
	int GetAnnualSalary();
	int RaiseSalary(int percent);
	std::string Print();

	void SetSalary(int salary);

private:
	int _id;
	std::string _firstName;
	std::string _lastName;
	int _salary;
};

