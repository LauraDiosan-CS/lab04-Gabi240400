#pragma once
#include "Service.h"

class Console {
private:
	 Service service;
public:
    Console();
	Console(Service service);
	~Console();

    void print_menu();
    void run_console();

    void handle_add_expense();
    void handle_delete_expense_by_id();
    void handle_update_expense_by_id();
    void handle_add_expense_on_current_day();
    void handle_delete_expenses_by_day();
    void handle_delete_expenses_within_days();
    void handle_delete_expenses_by_type();
    void handle_print_expenses_by_type();
    void handle_print_expenses_by_type_over_sum();
    void handle_print_expenses_by_type_and_sum();
    void handle_print_cost_for_type();
    void handle_most_expensive_day();
    void handle_days_descending_order();
    void handle_type_ascending_order();
    void handle_filter_expenses_by_type();
    void handle_filter_expenses_by_type_under_sum();
    void handle_filter_expenses_by_type_and_sum();
    void handle_print_all();
};
