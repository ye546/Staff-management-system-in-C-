#include <vector>
#include <fstream>
#include <Windows.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <ctime>

struct employee {
	int id;
	std::string name, address, role;
	double wage;
};

struct dataBase {
	std::vector<employee> v;
}db;


void createNewEmployee() {
	srand(time(NULL));

	struct employee *emp = new employee;
	std::string name, address, role;

	//enter the employees information
	printf("--New employee---\n\n");
	printf("Enter the new employees name: >");
	std::getline(std::cin, emp->name);
	printf("\nEnter the new employees role: >");
	std::getline(std::cin, emp->role);
	printf("\nEnter the new employees address: >");
	std::getline(std::cin, emp->address);
	printf("\nEnter the employees wage: >");
	std::cin >> emp->wage;
	printf("\nAssigning ID to the new employee...\n\n");
	emp->id = (1 + rand() % 99999);


	for (int i = 0; i < db.v.size(); i++) {
		if (db.v.size() <= 0) { break; }
		//if we by any unlucky chanse we would get a duplication in Id's
		if (emp->id == db.v[i].id) {
			printf("This ID already exist, assigning new id...\n");
			redo:
			emp->id = (1 + rand() % 99999);
			if (emp->id == db.v[i].id) goto redo;
		}
	}

	//save the new employee in the database
	db.v.push_back(*emp);

	delete emp;
	emp = nullptr;
}

void deleteEmployee() {
	int i;
	printf("\n\nEnter the employees ID that you'd like to delete: >");
	std::cin >> i;
	for (int i = 0; i < db.v.size(); i++) {
		if (i == db.v[i].id) {
			db.v.erase(db.v.begin() + i);
		}
	}
}

void getIdOfEmployee() {
	std::string name;
	printf("\nEnter the name you'd like to find the ID for: >");
	std::getline(std::cin, name);

	for (int i = 0; i < db.v.size(); i++) {
		if (name == db.v[i].name) {
			printf("name: %s\nid: %i\n", db.v[i].name.c_str(), db.v[i].id);
		}
	}
}

void printEmployees() {
	if (db.v.size() <= 0) {
		printf("DB is NULL\n\n\n");
	}
	else {
		for (int i = 0; i < db.v.size(); i++) {
			printf("\nEmploye %i\n{\n\tName: \t%s\n\tAddress: %s\n\tRole: \t%s\n\tWage: \t%f\n\tId: \t%i\n}\n\n", i, db.v[i].name.c_str(), db.v[i].address.c_str(), db.v[i].role.c_str(), db.v[i].wage, db.v[i].id);
		}
	}
}

int main() {
	printf("---Terminal---\n\n");
	int i;

	while (true) {
		printf("1. Add a new employee to the database.\n2. Get ID of an employee\n3. List all the employees\n4. Delete an employee\n\n>");
		std::cin >> i;
		getchar();// flush stream from \n
		switch (i) {
		case 1:
			srand(time(NULL));
			createNewEmployee();
			getchar();// flush stream from \n
			break;
		case 2:
			getIdOfEmployee();
			break;
		case 3:
			printEmployees();
			break;
		case 4:
			deleteEmployee();
			break;
		case 5:
			return EXIT_SUCCESS;
			break;
		default: 
			printf("\nThat is not an option!\n\n"); 
			break;
		}
	}

	system("PAUSE");

	return 0;
}
