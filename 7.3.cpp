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
	Sales_data total;
	double price;
	if (cin >> total.bookNo >> total.units_sold >> price) {
		total.revenue = total.units_sold * price;
		Sales_data trans;
		while (cin >> trans.bookNo >> trans.units_sold >> price) {
			trans.revenue = trans.units_sold * price;
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else {
				cout << total.isbn() << " " << total.units_sold << " "
					<< total.revenue << endl;
				total = trans;
			}
		}
		cout << total.isbn() << " " << total.units_sold << " "
			<< total.revenue << endl;
	}
	else {
		cerr << "No data?!" << endl;
		return -1;
	}
	return 0;
}
