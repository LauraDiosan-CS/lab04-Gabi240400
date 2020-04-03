#include "UI.h"
#include "Service.h"
#include<iostream>

using namespace std;

Console::Console(){
}

Console::Console(Service service){
    this->service = service;
}


Console::~Console(){
};

void Console::print_menu(){
    cout << "Choose an option:" << endl;
    cout << "01  -> Add expense" << endl;
    cout << "02  -> Delete an expense by id" << endl;
    cout << "03  -> Update an expense by id" << endl;
    cout << "04  -> Add an expense today" << endl;
    cout << "05  -> Delete expenses on a given day" << endl;
    cout << "06  -> Delete expenses within a given range of days" << endl;
    cout << "07  -> Delete expenses with a given type" << endl;
    cout << "08  -> Print all expenses with a given type" << endl;
    cout << "09  -> Print all expenses with a given type over a given sum" << endl;
    cout << "10  -> Print all expenses with a given type and a given sum" << endl;
    cout << "11  -> Print the total cost for a given type of expense" << endl;
    cout << "12  -> Print the most expensive day" << endl;
    cout << "13  -> The days in descending order by cost" << endl;
    cout << "14  -> A given type in ascending order by cost" << endl;
    cout << "15  -> Filter expenses with a given type" << endl;
    cout << "16  -> Filter expenses with a given type under a given sum" << endl;
    cout << "17  -> Filter expenses with a given type and a given sum" << endl;
    cout << "18  -> Undo" << endl;
    cout << "19  -> Print all expenses" << endl;
    cout << "Press anything else to exit" << endl;
}

void Console::run_console(){
    int option = 0;
    print_menu();
    cin >> option;
    while (option >= 1 && option <= 19){
        if (option == 1){
            handle_add_expense();
            //this->service.add_to_undo_stack(undo_stack, length_stack);
        }
        else if(option == 2){
            handle_delete_expense_by_id();
            //this->service.add_to_undo_stack(undo_stack, length_stack);
        }
        else if(option == 3){
            handle_update_expense_by_id();
            //this->service.add_to_undo_stack(undo_stack, length_stack);
        }
        else if(option == 4){
            handle_add_expense_on_current_day();
            //this->service.add_to_undo_stack(undo_stack, length_stack);
        }
        else if(option == 5){
            handle_delete_expenses_by_day();
            //this->service.add_to_undo_stack(undo_stack, length_stack);
        }
        else if(option == 6){
            handle_delete_expenses_within_days();
            //this->service.add_to_undo_stack(undo_stack, length_stack);
        }
        else if(option == 7){
            handle_delete_expenses_by_type();
            //this->service.add_to_undo_stack(undo_stack, length_stack);
        }
        else if(option == 8)
            handle_print_expenses_by_type();
        else if(option == 9)
            handle_print_expenses_by_type_over_sum();
        else if(option == 10)
            handle_print_expenses_by_type_and_sum();
        else if(option == 11)
            handle_print_cost_for_type();
        else if(option == 12)
            handle_most_expensive_day();
        else if(option == 13)
            handle_days_descending_order();
        else if(option == 14)
            handle_type_ascending_order();
        else if(option == 15){
            handle_filter_expenses_by_type();
            //this->service.add_to_undo_stack(undo_stack, length_stack);
        }
        else if(option == 16){
            handle_filter_expenses_by_type_under_sum();
            //this->service.add_to_undo_stack(undo_stack, length_stack);
        }
        else if(option == 17){
            handle_filter_expenses_by_type_and_sum();
            //this->service.add_to_undo_stack(undo_stack, length_stack);
        }
        else if(option == 18){
                bool res = this->service.do_undo();
                if(res)
                    cout << "Succes" << endl;
                else
                    cout << "Failed" << endl;
        }
        else if(option == 19)
            handle_print_all();
        else
            return;
        print_menu();
        cin >> option;
    }
    cout << "Goodbye!";
}


void Console::handle_add_expense(){
    int id = 0, sum = 0, day = 0;
    char* type = new char[20];
    cout << "Write id: ";
    cin >> id;
    cout << "Write day: ";
    cin >> day;
    cout << "Write sum: ";
    cin >> sum;
    cout << "Write type: ";
    cin >> type;
    this->service.add_expense(id, day, sum, type);
    delete[] type;
}

void Console::handle_delete_expense_by_id(){
    int id = 0;
    cout << "Write the id for the expense you want to delete: ";
    cin >> id;
    this->service.delete_expense(id);
}

void Console::handle_update_expense_by_id(){
    int id = 0, new_sum = 0, new_day = 0;
    char* new_type = new char[20];
    cout << "Write the id for the expense you want to update: ";
    cin >> id;
    cout << "Write new day: ";
    cin >> new_day;
    cout << "Write new sum: ";
    cin >> new_sum;
    cout << "Write new type: ";
    cin >> new_type;
    this->service.add_expense(id, new_day, new_sum, new_type);
    delete[] new_type;
}

void Console::handle_add_expense_on_current_day(){
    int id = 0, sum = 0;
    char* type = new char[20];
    cout << "Write id: ";
    cin >> id;
    cout << "Write sum: ";
    cin >> sum;
    cout << "Write type: ";
    cin >> type;
    this->service.add_expense_on_current_day(id, sum, type);
    delete[] type;
}

void Console::handle_delete_expenses_by_day(){
    int day = 0;
    cout << "Write day: ";
    cin >> day;
    this->service.delete_expense_by_day(day);
}

void Console::handle_delete_expenses_within_days(){
    int day_start = 0, day_end = 0;
    cout << "Write the first day: ";
    cin >> day_start;
    cout << "Write the last day: ";
    cin >> day_end;
    this->service.delete_expense_within_range_days(day_start, day_end);
}

void Console::handle_delete_expenses_by_type(){
    char* type = new char[20];
    cout << "Write the type of expenses you want to be deleted: ";
    cin >> type;
    this->service.delete_expense_by_type(type);
    delete[] type;
}

void Console::handle_print_expenses_by_type(){
    char* type = new char[20];
    cout << "Write the type of expenses you want to be shown: ";
    cin >> type;
    for(int i = 0;i < this->service.get_size_repo(); i++ )
        cout << this->service.get_expenses_by_type(type)[i]<< endl;
    delete[] type;
}

void Console::handle_print_expenses_by_type_over_sum(){
    char* type = new char[20];
    int sum = 0;
    cout << "Write the type of expenses you want to be shown: ";
    cin >> type;
    cout << "Print expenses over this sum: ";
    cin >> sum;
    for(int i = 0;i < this->service.get_size_repo(); i++ )
        cout << this->service.get_expenses_by_type_bigger_than_sum(type, sum)[i]<< endl;
    delete[] type;
}

void Console::handle_print_expenses_by_type_and_sum(){
    char* type = new char[20];
    int sum = 0;
    cout << "Write the type of expenses you want to be shown: ";
    cin >> type;
    cout << "Print expenses equal to this sum: ";
    cin >> sum;
    for(int i = 0;i < this->service.get_size_repo(); i++ )
        cout << this->service.get_expenses_by_type_equal_to_sum(type, sum)[i]<< endl;
    delete[] type;
}

void Console::handle_print_cost_for_type(){
    char* type = new char[20];
    int sum = 0;
    cout << "Write the type of expense: ";
    cin >> type;
    cout << this->service.get_total_sum_by_type(type);
    delete[] type;
}

void Console::handle_most_expensive_day(){
    cout << this->service.get_most_expensive_day();
}

void Console::handle_days_descending_order(){
    int days[32] = {0};
    this->service.get_cost_in_descending_order_by_days(days);
    for (int i = 1; i < 32; i++)
        if(days[i] != 0)
            cout << days[i] << " ";
    cout << endl;
}

void Console::handle_type_ascending_order(){
    char* type = new char[20];
    int days[32] = {0};
    cout << "Write a type: ";
    cin >> type;
    this->service.get_cost_in_ascending_order_by_type(type, days);
    for (int i = 1; i < 32; i++)
        if(days[i] != 0)
            cout << days[i] << " ";
    cout << endl;
    delete[] type;
}

void Console::handle_filter_expenses_by_type(){
    char* type = new char[20];
    cout << "Write the type of expenses you want to keep: ";
    cin >> type;
    this->service.filter_expenses_by_type(type);
    delete[] type;
}

void Console::handle_filter_expenses_by_type_under_sum(){
    char* type = new char[20];
    int sum = 0;
    cout << "Write the type of expenses you want to keep";
    cin >> type;
    cout << "Write the maximum cost of the expenses you want to keep: ";
    cin >> sum;
    this->service.filter_expenses_by_type_smaller_than_sum(type, sum);
    delete[] type;
}

void Console::handle_filter_expenses_by_type_and_sum(){
    char* type = new char[20];
    int sum = 0;
    cout << "Write the type of expenses you want to keep";
    cin >> type;
    cout << "Write the cost of the expenses you want to keep: ";
    cin >> sum;
    this->service.filter_expenses_by_type_equal_to_sum(type, sum);
    delete[] type;
}


void Console::handle_print_all(){
    for(int i = 0;i < this->service.get_size_repo(); i++ )
        cout << this->service.get_all()[i]<< endl;
}





