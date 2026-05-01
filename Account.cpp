/**********
 * Account.cpp 
 *
 * Manages a single account (savings/checking) for a user.
 *
 * Author: Luca Pendleton
**********/

#include "Account.h"
#include <iostream>
#include <string>
#include <cmath>

using std::string;
using std::endl;
using std::cout;

// Default constructor -> offloads
Account::Account() : Account(" ", 0, " ") {}

// Holder - Password constructor -> offloads 
Account::Account(const string& inHolder, const string& inPassword) : Account(inHolder, 0, inPassword) {}

// Full constructor 
Account::Account(const string& inHolder, const int& inType, const string& inPassword) {
  setHolder(inHolder);
  setType(inType);

  // Must be manually set as there is no setter or getter for the password 
  password = inPassword;
}

// Getters 
string Account::getHolder() const {
  return holder;
}

string Account::getType() const {
  return type;
}

float Account::getIntrest() const {
  return interest;
}

float Account::getBalance(const string& pass) const {
  if (pass == password) {
    return balance;
  }
  else {
    cout << "Incorrect password.\n";
    return -1;
  }
}

// Setters 
void Account::setHolder(const string& inHolder) {
  holder = inHolder;
}

void Account::setType(const int& inType) {

  // Switch case to determine the account type
  switch(inType) {
    case 1:
      type = "CHECKING";
      interest = 0.05;
      break;
    case 2:
      type = "SAVINGS";
      interest = 3.50;
      break;
    default:
      type = "UNKNOWN";
      interest = 0;
  }
}

// Other methods 

void Account::displayAccount(const string& pass) const {
  if (pass != password) {
    cout << "Incorrect password\n";
    return;
  }
  else {
    cout.precision(2);
    cout << "------------------------------\n"
         << "HOLDER: " << getHolder() << endl
         << "TYPE: " << getType() << endl
         << "INTEREST: " << getIntrest() << endl 
         << "BALANCE: $" << getBalance(pass) << endl
         << "------------------------------\n";
  }
}

void Account::calculateInterest(const int& numYears, const string& pass) {
  if (pass != password) {
    cout << "Incorrect password.\n";
    return;
  }
  else {
    balance = balance * pow((1 + (interest / 100)), numYears);
  }
}
