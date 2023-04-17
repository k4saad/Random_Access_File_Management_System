#pragma once
#include<fstream>
#include<string>
class Staff {
public:
	Staff(std::string, std::string, std::string, int, double);
	void writeToFile(std::fstream&)const;
	void readFromFile(std::fstream&);
	/*void readKey();
	int size() const {
		return  30 + sizeof(year) + sizeof(salary);
	}
	bool operator==(const Staff& st) const {
		return st.id == id;
	}

	*/
protected:
	//const int idLen, nameLen, cityLen;
	std::string id, name, city;
	int year;
	double salary;
	std::ostream& writeLegibly(std::ostream&);
	friend std::ostream& operator<<(std::ostream& os, Staff& st) {
		return st.writeLegibly(os);
	}
	/*
	std::istream& readFromConsole(std::istream&);
	friend std::istream& operator>>(std::istream& in, Staff& st) {
		return st.readFromConsole(in);
	}
	*/
};