#ifndef TEST_SERVICE
#define TEST_SERVICE

void test_get_size_repo();
void test_add_expense_s();
void test_update_expense_s();
void test_delete_expense_s();
void test_add_expense_on_current_day();
void test_delete_expense_by_day();
void test_delete_expense_by_type();
void test_delete_expense_within_range_days();
void test_get_expenses_by_type();
void test_get_expenses_by_type_bigger_than_sum();
void test_get_expenses_by_type_equal_to_sum();
void test_get_total_sum_by_type();
void test_get_most_expensive_day();
void test_get_cost_in_descending_order_by_days();
void test_get_cost_in_ascending_order_by_type();
void test_filter_expenses_by_type();
void test_filter_expenses_by_type_smaller_than_sum();
void test_filter_expenses_by_type_equal_to_sum();


void test_all_service();

#endif // TEST_SERVICE
