#include"Test_Repo.h"
#include"Repo.h"
#include"Expense.h"
#include<assert.h>
#include<cstring>

void test_get_size(){
	char* type1 = new char[10];
	char* type2 = new char[10];

	strcpy(type1, "bills");
	Expense e1(1, 11, 250, type1);

	strcpy(type2, "food");
	Expense e2(2, 14, 100, type2);

	Repo r;
	r.add_expense(e1);
	assert(r.get_size() == 1);

	r.add_expense(e2);
	assert(r.get_size() == 2);

    assert(r.get_all()[0] == e1);
    assert(r.get_all()[1] == e2);

    delete[] type2;
    type2 = NULL;
    delete[] type1;
    type1 = NULL;
}

void test_add_expense(){
    char* type1 = new char[10];
	char* type2 = new char[10];

	strcpy(type1, "bills");
	Expense e1(1, 11, 250, type1);

	strcpy(type2, "food");
	Expense e2(2, 14, 100, type2);

	Repo r;
	r.add_expense(e1);
	r.add_expense(e2);

    assert(r.get_all()[0] == e1);
    assert(r.get_all()[1] == e2);

    delete[] type2;
    type2 = NULL;
    delete[] type1;
    type1 = NULL;
}


void test_update_expense(){
    char* type1 = new char[10];
    char* type2 = new char[10];

	strcpy(type1, "bills");
	Expense e1(1, 11, 250, type1);
    strcpy(type2, "food");
    Expense e2(1, 12, 200, type2);

	Repo r;
	r.add_expense(e1);

    r.update_expense(1, e2);

    assert(r.get_all()[0].get_day() == 12);
    assert(r.get_all()[0].get_sum() == 200);
    assert(strcmp(r.get_all()[0].get_type(), "food") == 0);

    delete[] type2;
    type2 = NULL;
    delete[] type1;
    type1 = NULL;
}

void test_delete_expense(){
    char* type1 = new char[10];
	char* type2 = new char[10];

	strcpy(type1, "bills");
	Expense e1(1, 11, 250, type1);

	strcpy(type2, "food");
	Expense e2(2, 14, 100, type2);

	Repo r;
	r.add_expense(e1);
	r.add_expense(e2);

	r.delete_expense(1);
	assert(r.get_size() == 1);

	delete[] type2;
	type2 = NULL;
	delete[] type1;
	type1 = NULL;

}

void test_read_by_id(){
    char* type1 = new char[10];
	char* type2 = new char[10];

	strcpy(type1, "bills");
	Expense e1(1, 11, 250, type1);

	strcpy(type2, "food");
	Expense e2(2, 14, 100, type2);

	Repo r;
	r.add_expense(e1);
	r.add_expense(e2);

	assert(r.read_by_id(2) == e2);

	delete[] type2;
	type2 = NULL;
	delete[] type1;
	type1 = NULL;
}

void test_all_repo(){
    test_get_size();
    test_add_expense();
    test_update_expense();
    test_delete_expense();
    test_read_by_id();
}


