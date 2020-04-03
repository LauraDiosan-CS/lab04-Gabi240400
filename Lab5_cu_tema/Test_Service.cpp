#include"Test_Service.h"
#include"Service.h"
#include<assert.h>
#include<cstring>
#include "time.h"

void test_add_expense_s(){
	char* type1 = new char[10];
	strcpy(type1, "bills");

	Service s;

	s.add_expense(1, 12, 250, type1);
	assert(s.get_all()[0].get_id() == 1);
	assert(s.get_all()[0].get_day() == 12);
	assert(s.get_all()[0].get_sum() == 250);
	assert(strcmp(s.get_all()[0].get_type(), "bills") == 0);

	delete[] type1;
	type1 = NULL;
}

void test_get_size_repo(){
    char* type1 = new char[10];
	strcpy(type1, "bills");

	Service s;

	s.add_expense(1, 12, 250, type1);

	assert(s.get_size_repo() == 1);

	delete[] type1;
	type1 = NULL;
}

void test_update_expense_s(){
    char* type1 = new char[10];
    char* type2 = new char[10];
	strcpy(type1, "bills");
    strcpy(type2, "bills");

	Service s;

	s.add_expense(1, 12, 250, type1);
	s.update_expense(1, 11, 200, "food");

	assert(s.get_size_repo() == 1);
	assert(s.get_all()[0].get_id() == 1);
	assert(s.get_all()[0].get_day() == 11);
	assert(s.get_all()[0].get_sum() == 200);
	assert(strcmp(s.get_all()[0].get_type(), "food") == 0);

	delete[] type2;
	type2 = NULL;
	delete[] type1;
	type1 = NULL;
}

void test_delete_expense_s(){
    char* type1 = new char[10];
    char* type2 = new char[10];
	strcpy(type1, "bills");
	strcpy(type2, "others");

	Service s;

	s.add_expense(1, 12, 250, type1);
	s.add_expense(2, 11, 200, type2);

	s.delete_expense(1);
	assert(s.get_size_repo() == 1);
	assert(s.get_all()[0].get_id() == 2);
	assert(s.get_all()[0].get_day() == 11);
	assert(s.get_all()[0].get_sum() == 200);
	assert(strcmp(s.get_all()[0].get_type(), type2) == 0);

	delete[] type2;
	type2 = NULL;
	delete[] type1;
	type1 = NULL;
}

void test_add_expense_on_current_day(){
    time_t theTime = time(NULL);
    struct tm *aTime = localtime(&theTime);
    int day = aTime->tm_mday;

    char* type1 = new char[10];
	strcpy(type1, "bills");

	Service s;

	s.add_expense_on_current_day(1, 250, type1);
	assert(s.get_all()[0].get_id() == 1);
	assert(s.get_all()[0].get_day() == day);
	assert(s.get_all()[0].get_sum() == 250);
	assert(strcmp(s.get_all()[0].get_type(), "bills") == 0);

	delete[] type1;
	type1 = NULL;
}

void test_delete_expense_by_day(){
    char* type1 = new char[10];
    char* type2 = new char[10];
    char* type3 = new char[10];

    strcpy(type1, "bills");
    strcpy(type2, "food");
    strcpy(type3, "others");

    Service s;

    s.add_expense(1, 10, 100, type1);
    s.add_expense(2, 11, 10, type2);
    s.add_expense(3, 10, 110, type3);

    s.delete_expense_by_day(10);

    assert(s.get_size_repo() == 1);
    assert(s.get_all()[0].get_id() == 2);
	assert(s.get_all()[0].get_day() == 11);
	assert(s.get_all()[0].get_sum() == 10);
	assert(strcmp(s.get_all()[0].get_type(), type2) == 0);

    delete[] type3;
    type3 = NULL;
    delete[] type2;
    type2 = NULL;
    delete[] type1;
    type1 = NULL;
}

void test_delete_expense_by_type(){
    char* type1 = new char[10];
    char* type2 = new char[10];
    char* type3 = new char[10];

    strcpy(type1, "bills");
    strcpy(type2, "bills");
    strcpy(type3, "others");

    Service s;

    s.add_expense(1, 10, 100, type1);
    s.add_expense(2, 11, 10, type2);
    s.add_expense(3, 10, 110, type3);

    s.delete_expense_by_type(type1);

    assert(s.get_size_repo() == 1);
    assert(s.get_all()[0].get_id() == 3);
	assert(s.get_all()[0].get_day() == 10);
	assert(s.get_all()[0].get_sum() == 110);
	assert(strcmp(s.get_all()[0].get_type(), type3) == 0);

    delete[] type3;
    type3 = NULL;
    delete[] type2;
    type2 = NULL;
    delete[] type1;
    type1 = NULL;
}

void test_delete_expense_within_range_days(){
    char* type1 = new char[10];
    char* type2 = new char[10];
    char* type3 = new char[10];

    strcpy(type1, "bills");
    strcpy(type2, "food");
    strcpy(type3, "others");

    Service s;

    s.add_expense(1, 2, 100, type1);
    s.add_expense(2, 5, 10, type2);
    s.add_expense(3, 7, 110, type3);

    s.delete_expense_within_range_days(1, 9);

    assert(s.get_size_repo() == 0);

    delete[] type3;
    type3 = NULL;
    delete[] type2;
    type2 = NULL;
    delete[] type1;
    type1 = NULL;
}

void test_get_expenses_by_type(){
    char* type1 = new char[10];
    char* type2 = new char[10];
    char* type3 = new char[10];

    strcpy(type1, "bills");
    strcpy(type2, "food");
    strcpy(type3, "bills");

    Service s;

    s.add_expense(1, 10, 100, type1);
    s.add_expense(2, 11, 10, type2);
    s.add_expense(3, 10, 110, type3);

    assert(s.get_expenses_by_type(type1)[0].get_id() == 1);
    assert(s.get_expenses_by_type(type1)[1].get_id() == 3);

    delete[] type3;
    type3 = NULL;
    delete[] type2;
    type2 = NULL;
    delete[] type1;
    type1 = NULL;
}

void test_get_expenses_by_type_bigger_than_sum(){
    char* type1 = new char[10];
    char* type2 = new char[10];
    char* type3 = new char[10];

    strcpy(type1, "bills");
    strcpy(type2, "food");
    strcpy(type3, "bills");

    Service s;

    s.add_expense(1, 10, 5, type1);
    s.add_expense(2, 11, 10, type2);
    s.add_expense(3, 10, 110, type3);

    assert(s.get_expenses_by_type_bigger_than_sum(type1, 50)[0].get_id() == 3);

    delete[] type3;
    type3 = NULL;
    delete[] type2;
    type2 = NULL;
    delete[] type1;
    type1 = NULL;
}

void test_get_expenses_by_type_equal_to_sum(){
    char* type1 = new char[10];
    char* type2 = new char[10];
    char* type3 = new char[10];

    strcpy(type1, "bills");
    strcpy(type2, "food");
    strcpy(type3, "bills");

    Service s;

    s.add_expense(1, 10, 5, type1);
    s.add_expense(2, 11, 10, type2);
    s.add_expense(3, 10, 110, type3);

    assert(s.get_expenses_by_type_bigger_than_sum(type1, 5)[0].get_id() == 1);

    delete[] type3;
    type3 = NULL;
    delete[] type2;
    type2 = NULL;
    delete[] type1;
    type1 = NULL;
}

void test_get_total_sum_by_type(){
    char* type1 = new char[10];
    char* type2 = new char[10];
    char* type3 = new char[10];

    strcpy(type1, "bills");
    strcpy(type2, "food");
    strcpy(type3, "bills");

    Service s;

    s.add_expense(1, 10, 5, type1);
    s.add_expense(2, 11, 10, type2);
    s.add_expense(3, 10, 110, type3);

    assert(s.get_total_sum_by_type(type1) == 115);

    delete[] type3;
    type3 = NULL;
    delete[] type2;
    type2 = NULL;
    delete[] type1;
    type1 = NULL;
}

void test_get_most_expensive_day(){
    char* type1 = new char[10];
    char* type2 = new char[10];
    char* type3 = new char[10];

    strcpy(type1, "bills");
    strcpy(type2, "food");
    strcpy(type3, "bills");

    Service s;

    s.add_expense(1, 11, 5, type1);
    s.add_expense(2, 10, 10, type2);
    s.add_expense(3, 10, 110, type3);

    assert(s.get_most_expensive_day() == 10);

    delete[] type3;
    type3 = NULL;
    delete[] type2;
    type2 = NULL;
    delete[] type1;
    type1 = NULL;
}

void test_get_cost_in_descending_order_by_days(){
    char* type1 = new char[10];
    char* type2 = new char[10];
    char* type3 = new char[10];

    strcpy(type1, "bills");
    strcpy(type2, "food");
    strcpy(type3, "bills");

    Service s;

    s.add_expense(1, 11, 5, type1);
    s.add_expense(2, 10, 10, type2);
    s.add_expense(3, 10, 110, type3);

    int days[32] = {0};
    s.get_cost_in_descending_order_by_days(days);
    assert(days[1] == 120);
    assert(days[2] == 5);

    delete[] type3;
    type3 = NULL;
    delete[] type2;
    type2 = NULL;
    delete[] type1;
    type1 = NULL;
}

void test_get_cost_in_ascending_order_by_type(){
    char* type1 = new char[10];
    char* type2 = new char[10];
    char* type3 = new char[10];

    strcpy(type1, "bills");
    strcpy(type2, "food");
    strcpy(type3, "bills");

    Service s;

    s.add_expense(1, 11, 5, type1);
    s.add_expense(2, 10, 10, type2);
    s.add_expense(3, 10, 110, type3);

    int days[32] = {0};
    s.get_cost_in_ascending_order_by_type(type1, days);
    assert(days[31] == 110);
    assert(days[30] == 5);

    delete[] type3;
    type3 = NULL;
    delete[] type2;
    type2 = NULL;
    delete[] type1;
    type1 = NULL;
}

void test_filter_expenses_by_type(){
    char* type1 = new char[10];
    char* type2 = new char[10];
    char* type3 = new char[10];

    strcpy(type1, "bills");
    strcpy(type2, "food");
    strcpy(type3, "bills");

    Service s;

    s.add_expense(1, 11, 5, type1);
    s.add_expense(2, 10, 10, type2);
    s.add_expense(3, 10, 110, type3);

    s.filter_expenses_by_type(type1);
    assert(s.get_size_repo() == 2);
    assert(s.get_all()[0].get_id() == 1);
    assert(s.get_all()[1].get_id() == 3);

    delete[] type3;
    type3 = NULL;
    delete[] type2;
    type2 = NULL;
    delete[] type1;
    type1 = NULL;
}

void test_filter_expenses_by_type_smaller_than_sum(){
    char* type1 = new char[10];
    char* type2 = new char[10];
    char* type3 = new char[10];

    strcpy(type2, "bills");
    strcpy(type1, "food");
    strcpy(type3, "bills");

    Service s;

    s.add_expense(1, 11, 5, type1);
    s.add_expense(2, 10, 10, type2);
    s.add_expense(3, 10, 110, type3);

    s.filter_expenses_by_type_smaller_than_sum(type2, 120);
    assert(s.get_size_repo() == 2);
    assert(s.get_all()[0].get_id() == 3);

    delete[] type3;
    type3 = NULL;
    delete[] type2;
    type2 = NULL;
    delete[] type1;
    type1 = NULL;
}

void test_filter_expenses_by_type_equal_to_sum(){
    char* type1 = new char[10];
    char* type2 = new char[10];
    char* type3 = new char[10];

    strcpy(type1, "bills");
    strcpy(type2, "food");
    strcpy(type3, "bills");

    Service s;

    s.add_expense(1, 11, 50, type1);
    s.add_expense(2, 10, 10, type2);
    s.add_expense(3, 10, 50, type3);

    s.filter_expenses_by_type(type1);
    assert(s.get_size_repo() == 2);
    assert(s.get_all()[0].get_id() == 1);
    assert(s.get_all()[1].get_id() == 3);

    delete[] type3;
    type3 = NULL;
    delete[] type2;
    type2 = NULL;
    delete[] type1;
    type1 = NULL;
}


void test_all_service(){
    test_get_size_repo();
    test_add_expense_s();
    test_update_expense_s();
    test_delete_expense_s();
    test_add_expense_on_current_day();
    test_delete_expense_by_day();
    test_delete_expense_by_type();
    test_delete_expense_within_range_days();
    test_get_expenses_by_type();
    test_get_expenses_by_type_bigger_than_sum();
    test_get_expenses_by_type_equal_to_sum();
    test_get_total_sum_by_type();
    test_get_most_expensive_day();
    test_get_cost_in_descending_order_by_days();
    test_get_cost_in_ascending_order_by_type();
    test_filter_expenses_by_type();
    test_filter_expenses_by_type_smaller_than_sum();
    test_filter_expenses_by_type_equal_to_sum();
}
