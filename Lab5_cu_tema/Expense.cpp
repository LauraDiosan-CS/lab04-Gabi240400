#include "Expense.h"
#include <cstddef>
#include <string.h>
#include <ostream>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

Expense::Expense() {
    this->id = 0;
	this->day = 0;
	this->sum = 0;
	this->type = NULL;
}

Expense::Expense(int id, int day, int sum, char* type){
    this->id = id;
    this->day = day;
    this->sum = sum;
	this->type = new char[strlen(type) + 1];
	strcpy(this->type, type);
}

Expense::Expense(const Expense &e) {
	//cout << "copy constructor"<<endl;
	this->type = new char[strlen(e.type) + 1];
	strcpy(this->type, e.type);
	this->day = e.day;
	this->sum = e.sum;
	this->id = e.id;
}

Expense::~Expense() {
	if (this->type) {
		delete[] this->type;
		this->type = NULL;
	}
}

char* Expense::get_type() {
	return this->type;
}

int Expense::get_id(){
    return this->id;
}

int Expense::get_day() {
	return this->day;
}

int Expense::get_sum() {
	return this->sum;
}

void Expense::set_type(char* type)
{
	if (this->type) {
		delete[] this->type;
	}
	this->type = new char[strlen(type) + 1];
	strcpy(this->type, type);
}

void Expense::set_id(int id){
    this->id = id;
}

void Expense::set_day(int day) {
	this->day = day;
}

void Expense::set_sum(int sum) {
	this->sum = sum;
}

Expense& Expense::operator=(const Expense& e) {
	this->set_type(e.type);
	this->set_id(e.id);
	this->set_day(e.day);
	this->set_sum(e.sum);
	return *this;
}

bool Expense:: operator==(const Expense& e) {
	return strcmp(this->type, e.type) == 0 && this->day == e.day && this->sum == e.sum && this->id == e.id;
}

ostream& operator<<(ostream& os, const Expense& e){
	os << e.id <<" "<< e.day << " " <<e.sum<<" "<<e.type;
	return os;
}
