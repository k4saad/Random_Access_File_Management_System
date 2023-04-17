#pragma once
#include<fstream>
#include<string>
#include<cstring>
class Staff {
public:
	Staff();
	Staff(const std::string, const std::string, const std::string, const int, const double);
	void writeToFile(std::fstream&);
	void readFromFile(std::fstream&);
	void readKey();
	int size() const {
		return  30 + sizeof(year) + sizeof(salary);
	}
	bool operator==(const Staff& st) const {
		return strncmp(st.id.c_str(), id.c_str(), 9) == 0;
	}

	
protected:
	//const int idLen, nameLen, cityLen;
	std::string id, name, city;
	int year;
	double salary;
	std::ostream& writeLegibly(std::ostream&);
	friend std::ostream& operator<<(std::ostream& os, Staff& st) {
		return st.writeLegibly(os);
	}
	std::istream& readFromConsole(std::istream&);
	friend std::istream& operator>>(std::istream& in, Staff& st) {
		return st.readFromConsole(in);
	}
};