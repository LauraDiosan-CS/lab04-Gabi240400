#pragma once
#include <ostream>
using namespace std;

class Expense {
private:
	char* type;
	int id;
	int day;
	int sum;
public:
	Expense();
	Expense(int id, int day, int sum, char* type);
	Expense(const Expense& e);
	~Expense();

	char* get_type();
	int get_id();
	int get_day();
	int get_sum();

	void set_type(char* type);
	void set_id(int id);
	void set_day(int day);
	void set_sum(int sum);

	Expense& operator=(const Expense& e);
	bool operator==(const Expense& e);
	friend ostream& operator<<(ostream& os, const Expense& e);
};
