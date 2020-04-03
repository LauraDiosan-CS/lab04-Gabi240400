#pragma once
#include <bits/stdc++.h>
#include "Repo.h"

using namespace std;

class Service {
private:
	Repo repo;
	stack< pair<Expense*, int> >undo_stack;
public:
    Service();
	Service(Repo& repo);
	~Service();

    void clear_stack();
	int get_size_repo();
	Expense* get_all();
	void add_expense(int id, int day, int sum, char* type);
	void update_expense(int id, int new_day, int new_sum, char* new_type);
	void delete_expense(int id);

	void add_expense_on_current_day(int id, int sum, char* type);
	void delete_expense_by_day(int day);
	void delete_expense_by_type(char* type);
	void delete_expense_within_range_days(int day_start, int day_end);
	Expense* get_expenses_by_type(char* type);
	Expense* get_expenses_by_type_bigger_than_sum(char* type, int sum);
	Expense* get_expenses_by_type_equal_to_sum(char* type, int sum);
	int get_total_sum_by_type(char* type);
	int get_most_expensive_day();
	void get_cost_in_descending_order_by_days(int days[]);
	void get_cost_in_ascending_order_by_type(char* type, int days[]);
	void filter_expenses_by_type(char* type);
	void filter_expenses_by_type_smaller_than_sum(char* type, int sum);
	void filter_expenses_by_type_equal_to_sum(char* type, int sum);
	bool do_undo();
};
