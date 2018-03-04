#include <vector>
#include <fstream>
#include <Windows.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#define emp_size 5
bool checkIfEmployeeAlreadyExists(employee *p);

struct employee {
	int id;
	std::string name, address, role;
	double wage;
};

struct dataBase {
	static std::vector<employee> v;
};



employee createNewEmployee() {
	srand(time(NULL));

	employee *emp = new employee;
	dataBase *db = nullptr;

	std::string name, address, role;
	int id = (1 + rand() % 99999);

	

	for (int i = 0; i < 1; i++) {
		printf("Enter the new employees name: >");
		std::getline(std::cin, emp->name);
		printf("\nEnter the new employees role: >");
		std::getline(std::cin, emp->role);
		printf("\nEnter the new employees address: >");
		std::getline(std::cin, emp->address);
		printf("\nEnter the employees wage: >\n");
		std::cin >> emp->wage;
		printf("\nAssigning ID to the new employee...\n");
		emp->id = id;
	}

	if (db->v.size() > 0) {
		for (int i = 0; i < db->v.size(); i++) {
			if (db->v[i].id == emp->id) {
				printf("This user already exist, assigning new id...\n");
				redo:
				emp->id = id;
				if (db->v[i].id == emp->id) goto redo;
			}
		}
	}



}

bool checkIfEmployeeAlreadyExists() {
	
	p = &createNewEmployee();
	bool good = true;
	dataBase *db = nullptr;


	for (int i = 0; i < db->v.size(); i++) {
		if (p == &db->v[i]) {
			printf("does this user already exist?\n");
			good = false;
		}
		if (!good) {
			return false;
		}	
	}

	db->v.push_back(*p);
	db = nullptr;
	return true;
}

void deleteEmployee() {
	dataBase *db = nullptr;
	std::string name;
	printf("Search for the employee name: >");
	std::getline(std::cin, name);

	//for (int i = 0; i < db->v.size(); i++) {
	//	if(name == db->v[i])
	//}
}

void editEmployee() {

}

void searchForEmployee() {
	std::string name;
	std::getline(std::cin, name);
	dataBase *db = nullptr;
	
	for (int i = 0; i < db->v.size(); i++) {
		if (name == db->v[i].name);
	}

}

int main() {
	
	getchar();
}
