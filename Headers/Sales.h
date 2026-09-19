#ifndef VISUALAPP_SALES_H
#define VISUALAPP_SALES_H
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

struct sales {
	std::string ID;
	std::string Price;
	std::string TotalSales;
	static std::vector<sales> checkSaleFile();
};


inline std::vector<sales> sales::checkSaleFile() {
	std::vector<sales> sale;
	std::stringstream ss;
	std::string line;
	std::ifstream file("Data/Sales.csv");

	while (std::getline(file, line)) {
		sales s;
		ss.str(line);
		ss.clear();
		std::getline(ss, s.ID, '|');
		std::getline(ss, s.Price, '|');
		std::getline(ss, s.TotalSales, '|');
		sale.push_back(s);
	}
	return sale;
}

#endif //VISUALAPP_SALES_H