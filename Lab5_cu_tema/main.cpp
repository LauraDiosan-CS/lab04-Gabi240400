#include"Test_Expense.h"
#include"Test_Repo.h"
#include"Test_Service.h"
#include "UI.h"
#include "Service.h"
#include "Repo.h"
#include "Expense.h"

#include <iostream>

using namespace std;


int main(){
    test_all_domain();
    test_all_repo();
    test_all_service();

    Console c;

    c.run_console();
    return 0;
}
