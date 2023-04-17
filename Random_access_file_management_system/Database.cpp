#include<iostream>

#include"Staff.h" 
#include"Database.h"

template<class T>
Database<T>::Database() = default;
template<class T>
void Database<T>::add(T& d) {
	database.open(fname, std::ios::app | std::ios::binary);
	database.seekp(0, std::ios::end);
	d.writeToFile(database);
	database.close();
}
template<class T>
void Database<T>::modify(const T& d) {
	T tmp;
	database.open(fname, std::ios::in | std::ios::out | std::ios::binary);
	while (!database.eof()) {
		tmp.readFromFile(database);
		if (tmp == d) {
			std::cin >> tmp;
			database.seekp(-d.size(), std::ios::cur);
			tmp.writeToFile(database);
			database.close();
			return;
		}
	}
	database.close();
	std::cout << "The record to be modified is not in the database\n";
}
template<class T>
bool Database<T>::find(const T& d) {
	T tmp;
	database.open(fname, std::ios::in | std::ios::binary);
	while (!database.eof()) {
		tmp.readFromFile(database);
		if (tmp == d) {
			database.close();
			return true;
		}
	}
	database.close();
	return false;
}
template<class T>
std::ostream& Database<T>::print(std::ostream& os) {
	T tmp;
	database.open(fname, std::ios::in | std::ios::binary);
	while (true) {
		tmp.readFromFile(database);
		if (database.eof()) break;
		os << tmp << std::endl;
	}
	database.close();
	return os;
}

template<class T>
void Database<T>::run() {
	std::cout << "File Name : ";
	std::cin >> fname;
	int option = 1;
	T rec;
	while (option != 5) {
		std::cout << "1. Add 2. Find 3. Modify a record 4. Print all record 5. Exit\n";
		std::cout << "Enter an option: ";
		if (std::cin >> option);
		else std::cout << "Invalid input" << std::endl;
		if (option == 1) {
			std::cin >> rec;
			add(rec);
		}
		else if (option == 2) {
			rec.readKey();
			std::cout << "The record is ";
			if (find(rec) == false) {
				std::cout << "not ";
				std::cout << "in the database\n";
			}
		}
		else if (option == 3) {
			rec.readKey();
			modify(rec);
		}
		else if (option == 4) {
			print(std::cout);
		}
		else if (option != 5) std::cout << "Wrong option\n";
		else return;
		std::cout << *this;
		std::cout << "Enter an option: ";
	}
}
int main() {
	Database<Staff>().run();
	return 0;
}