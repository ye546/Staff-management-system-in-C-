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
	std::string name, lastName, address, role;
	double wage;
};

struct dataBase {
	std::vector<employee> v;
}db;


void createNewEmployee() {
	srand(time(NULL));
	struct employee *emp = new employee;

	//enter the employees information
	printf("--New employee---\n\n");
	printf("Enter the new employees firstname: >");
	std::getline(std::cin, emp->name);
	printf("Enter the new employees lastname: >");
	std::getline(std::cin, emp->lastName);
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
	int x;
	printf("\n\nEnter the employees ID that you'd like to delete: >");
	std::cin >> x;
	for (int i = 0; i < db.v.size(); i++) {
		if (x == db.v[i].id) {
			printf("Employee %i has been deleted\n", db.v[i].id);
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
			printf("\nName: %s\nID: %i\n\n", db.v[i].name.c_str(), db.v[i].id);
		}
	}
}

void printEmployees() {
	if (db.v.size() <= 0) {
		printf("DB is NULL\n\n\n");
	}
	else {
		for (int i = 0; i < db.v.size(); i++) {
			printf("\nEmploye %i\n{\n\tFirstname: \t%s\n\tAddress: %s\n\tRole: \t%s\n\tLastname: \t%s\n\tWage: \t%f\n\tId: \t%i\n}\n\n", i, db.v[i].name.c_str(), db.v[i].lastName, db.v[i].address.c_str(), db.v[i].role.c_str(), db.v[i].wage, db.v[i].id);
		}
	}
}

void editAnEmployee() {
	std::string newName, lastName, newAddress, newRole;
	int id, x;
	double newWage;
	bool running = true;
	if (db.v.size() <= 0) {
		printf("The database is NULL\n\n");
		return;
	}

	printf("\nEnter the ID of the employee you'd like to edit: >");
	std::cin >> id;
	while (running) {
		for (int i = 0; i < db.v.size(); i++) {
			if (id == db.v[i].id) {
				printf("To exit edit mode, press 6\n\n");
				printf("\nPress 1 to edit firstname, 2 to edit lastname, 3 for address, 4 for role and 5 for wage\n>");

				std::cin >> x;
				getchar();// flush stream from \n

				if (x == 1) {
					printf("Enter the new employees new firstname: >");
					std::getline(std::cin, newName);
					db.v[i].name = newName;
					break;
				}
				else if (x == 2) {
					printf("\nEnter the new lastname: >");
					std::getline(std::cin, lastName);
					db.v[i].lastName = newName;
				}
				else if (x == 3) {
					printf("\nEnter the new address: >");
					std::getline(std::cin, newAddress);
					db.v[i].address = newAddress;
					break;
				}
				else if (x == 4) {
					printf("\nEnter the new role for the employee: >");
					std::getline(std::cin, newRole);
					db.v[i].role = newRole;
					break;
				}
				else if (x == 5) {
					printf("\nEnter thew new wage for the employee: >");
					std::cin >> newWage;
					db.v[i].wage = newWage;
					break;
				}
				else if (x == 6) {
					running = false;
					break;
				}
				else if (x != 1 || x != 2 || x != 3 || x != 4 || x != 5 || x != 6) {
					printf("Not a valid option!\n");
				}
				getchar(); // flush stream
			}
		}
	}
}

int main() {
	printf("---Terminal---\n\n");
	int i;

	while (true) {
		printf("1. Add a new employee to the database.\n2. Get ID of an employee\n3. List all the employees\n4. Delete an employee\n5. Edit an employee\n6. Exit the terminal\n\n>");
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
			editAnEmployee();
			break;
		case 6:
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
