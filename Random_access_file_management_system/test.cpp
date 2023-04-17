#include<iostream>
#include<fstream>
#include<string>
#include"Staff.h"
int main() {
	Staff s("123", "saad", "mumbai", 2003, 10000);
	std::fstream database;
	std::string fname = "C:\\Users\\HP\\Desktop\\c++ projects\\Random_access_file_management_system\\saad_employee.txt";
	database.open(fname,  std::ios::out | std::ios::binary);
	database.seekp(0, std::ios::end);
	s.writeToFile(database);
	database.close();
	std::cout << "------printing------" << std::endl;
	database.open(fname, std::ios::in | std::ios::binary);
	while (true) {
		s.readFromFile(database);
		if (database.eof()) break;
		std::cout << s << std::endl;
	}
	database.close();
	return 0;
}
