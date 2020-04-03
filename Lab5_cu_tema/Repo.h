#pragma once
#include "Expense.h"

class Repo {
private:
	Expense expenses[20];
	int n;
public:
	Repo();
	~Repo();
	Repo(const Repo& repo);
	void set_vector(Expense* expenses, int length);
	int get_size();
	void add_expense(Expense& e);
	void update_expense(int id, Expense& e);
	void delete_expense(int id);
	Expense* get_all();
	Expense read_by_id(int id);
};
