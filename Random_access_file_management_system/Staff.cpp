#include"Staff.h"

Staff::Staff(const std::string i, const std::string n, const std::string c, const int y, const double s) : id(10, '\0'), name(10, '\0'), city(10, '\0') {
	id = i;
	name = n;
	city = c;
	year = y;
	salary = s;
}
void Staff::writeToFile(std::fstream& os) const {
	os.write(id.c_str(),10);
	os.write(name.c_str(),10);
	os.write(city.c_str(), 10);
	os.write(reinterpret_cast<const char*>(&year), sizeof(int));
	os.write(reinterpret_cast<const char*>(&salary), sizeof(double));
}
void Staff::readFromFile(std::fstream& is) {
	id.resize(10); 
	name.resize(10);
	city.resize(10);
	is.read(reinterpret_cast<char*>(&id[0]), 10);
	is.read(reinterpret_cast<char*>(&name[0]), 10);
	is.read(reinterpret_cast<char*>(&city[0]), 10);
	is.read(reinterpret_cast<char*>(&year), sizeof(int));
	is.read(reinterpret_cast<char*>(&salary), sizeof(double));
}
std::ostream& Staff::writeLegibly(std::ostream& os) {
	os << "Id : " << id << ", Name : " << name <<
		", City : " << city << ", Year : " << year <<
		", Salary : " << salary;
	return os;
}