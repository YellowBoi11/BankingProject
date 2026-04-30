/***********
 * Account.h 
 *
 * Header file for the Account class 
 *
 * Author: Luca Pendleton
************/

#include <string>

using std::string;

class Account {
  private:
    string holder;
    string type;
    int interest;
    // Used always to edit things
    string password;
    double balance;
  public:
    // Default constructor with nothing.
    Account();

    // Holder - password constructor 
    Account(const string& inHolder, const string& inPassword);

    // Full constructor
    Account(const string& inHolder, const int& inType, const string& inPassword);

    // Getters 
    string getHolder() const;

    string getType() const;

    string getIntrest() const;

    // Setters 
    void setHolder(const string& inHolder);

    // Sets the type and interest with a switch-case
    void setType(const int& inType);

    // Other methods 

    // Will output info on the account.
    void displayAccount() const;

    // Will calculate how much interest you get and add it to the balance.
    void calculateInterest() const;

    // Deposits the money if it's positive
    void deposit(const double& deposit);

    // Withdraws the money if it's available. Returns the amount withdrawn or -1
    float withdraw(const double& withdraw);
};
