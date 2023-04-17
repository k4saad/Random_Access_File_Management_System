#pragma once
#include<string>
#include<fstream> 
#include"Staff.h"
template<class T>
class Database {

public:
	Database();
	void run();
private:
	std::fstream database;
	std::string fname;
	std::ostream& print(std::ostream&);
	void add(T&);
	bool find(const T&);
	void modify(const T&);
	friend std::ostream& operator<<(std::ostream& os, Database& db) {
		return db.print(os);
	}
};