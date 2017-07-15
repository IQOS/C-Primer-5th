#include <iostream>
#include <string>
using namespace std;

struct Sales_data {
	string isbn() const;
	Sales_data &combine(const Sales_data &);
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0;
};

string Sales_data::isbn() const {
	return bookNo;
}

Sales_data &Sales_data::combine(const Sales_data &rhs) {
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

int main() {
	return 0;
}
