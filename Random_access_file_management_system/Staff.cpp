#include"Staff.h"

Staff::Staff(const std::string i, const std::string n, const std::string c, const int y, const double s) : id(10, '\0'), name(10, '\0'), city(10, '\0') {
	id = i;
	name = n;
	city = c;
	year = y;
	salary = s;
}
void Staff::writeToFile(std::fstream& os) const {
	os.write(id.c_str(), sizeof(char) * id.size());
	os.write(name.c_str(), sizeof(char) * name.size());
	os.write(city.c_str(), sizeof(char) * city.size());
	os.write(reinterpret_cast<const char*>(&year), sizeof(int));
	os.write(reinterpret_cast<const char*>(&salary), sizeof(double));
}

