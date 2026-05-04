/***********
 * Account.h 
 *
 * Header file for the Account class 
 *
 * Author: Luca Pendleton
************/

#ifndef ACCOUNT_H
#define ACCOUNT_H


#include <string>

using std::string;

class Account {
  private:
    string holder;
    string name;
    string type;
    float interest;
    // Used always to edit things
    string password;
    double balance;
  public:
    // Default constructor with nothing.
    Account();

    // Holder - password constructor 
    Account(const string& inHolder, const string& inPassword);

    // Full constructor
    Account(const string& inHolder, const string& inName, const int& inType, const string& inPassword);

    // Getters 
    string getHolder() const;

    string getType() const;

    float getIntrest() const;

    string getName() const;

    // Requires password
    float getBalance(const string& pass) const;

    // Setters 
    void setHolder(const string& inHolder);

    // Sets the type and interest with a switch-case
    void setType(const int& inType);

    void setName(const string& inName);

    // Other methods 

    // Will output info on the account.
    void displayAccount(const string& pass) const;

    // Will calculate how much interest you get and add it to the balance.
    void calculateInterest(const int& numYears, const string& pass);

    // Deposits the money if it's positive
    void deposit(const double& deposit, const string& pass);

    // Withdraws the money if it's available. Returns the amount withdrawn or -1
    float withdraw(const double& withdraw, const string& pass);
};

#endif // !ACCOUNT_H
