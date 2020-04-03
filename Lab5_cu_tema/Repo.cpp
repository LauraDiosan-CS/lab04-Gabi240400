#include "Repo.h"
#include "Expense.h"

Repo::Repo() {
	this->n = 0;
}

Repo::~Repo() {
	this->n = 0;
}

Repo::Repo(const Repo& repo){
    this->n = n;
    for (int i = 0; i < n; i++)
        this->expenses[i] = repo.expenses[i];
}

void Repo::set_vector(Expense* expenses, int length){
    for(int i = 0; i < length; i++)
        this->expenses[i] = expenses[i];
    this->n = length;
}

int Repo::get_size(){
    return this->n;
}

void Repo::add_expense(Expense& e) {
	this->expenses[this->n++] = e;
}

void Repo::update_expense(int id, Expense& e){
    for (int i = 0; i < this->n; i++)
        if(this->expenses[i].get_id() == id)
            this->expenses[i] = e;
}

void Repo::delete_expense(int id){
    int ok = 0;
    for(int i = 0; i< this->n; i++)
        if(this->expenses[i].get_id() == id){
            this->expenses[i] = this->expenses[n-1];
            ok = 1;}
    if(ok == 1)
        this->n--;
}

Expense* Repo::get_all() {
	return this->expenses;
}

Expense Repo::read_by_id(int id){
    for (int i = 0; i < this->n; i++)
        if(this->expenses[i].get_id() == id)
            return this->expenses[i];
}

