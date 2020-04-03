#include"Test_Expense.h"
#include"Expense.h"
#include<assert.h>
#include<cstring>

void test_getter(){
	char* type1 = new char[10];
	char* type2 = new char[10];

	strcpy(type1, "bills");
	Expense e1(1, 11, 250, type1);

	strcpy(type2, "food");
	Expense e2(2, 14, 100, type2);

	assert(e1.get_id() == 1);
	assert(e2.get_id() == 2);
	assert(e1.get_day() == 11);
	assert(e2.get_day() == 14);
	assert(e1.get_sum() == 250);
	assert(e2.get_sum() == 100);
	assert(strcmp(e1.get_type(), "bills") == 0);
	assert(strcmp(e2.get_type(), "food")==0);

	delete[] type2;
	type2 = NULL;
	delete[] type1;
	type1 = NULL;
}

void test_setter(){
	char* type1 = new char[10];

	strcpy(type1, "bills");
	Expense e1(1, 11, 250, type1);

	e1.set_id(2);
	assert(e1.get_id() == 2);

    e1.set_day(12);
    assert(e1.get_day() == 12);

    e1.set_sum(175);
    assert(e1.get_sum() == 175);

    e1.set_type("clothes");
    assert(strcmp(e1.get_type(), "clothes") == 0);

    delete[] type1;
    type1 = NULL;
}

void test_eq(){
	char* type1 = new char[10];
	char* type2 = new char[10];

	strcpy(type1, "bills");
	Expense e1(1, 11, 250, type1);

	strcpy(type2, "bills");
	Expense e2(1, 11, 250, type1);

	assert(e1 == e2);
	delete[] type2;
	type2 = NULL;
	delete[] type1;
	type1 = NULL;
}

void test_assignment(){
    char* type1 = new char[10];
    strcpy(type1, "bills");
    Expense e1(1, 11, 250, type1);
    Expense e2;
    e2 = e1;

    assert(e2.get_id() == 1);
    assert(e2.get_day() == 11);
    assert(e2.get_sum() == 250);
    assert(strcmp(e2.get_type(), "bills") == 0);

    delete[] type1;
    type1 = NULL;
}

void test_all_domain(){
    test_getter();
    test_setter();
    test_eq();
    test_assignment();
}


