/******************
 * Functions.cpp 
 *
 * inplementation of functions defined in Functions.h 
 *
 * Author: Luca Pendleton 
******************/
 
#include "Account.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::vector;

// Creates an Account object
void createAccount(vector<Account*>& accounts, const string& userName) {
  int iInput;
  int type;
  string accName;
  string passwd;

  cout << "What type of account do you want to create?\n"
       << "[0]: savings\n"
       << "[1]: checking\n?";
  // Ensuring proper input
  while(!(cin >> iInput)) {
    std::cin.clear(); // Reset error flags
    std::cin.ignore(); // Clear buffer
    std::cout << "Invalid input. Please enter a number.\n";
    continue;
  }

  switch (iInput) {
    case 0: 
      type = 2;
      break;
    case 1:
      type = 1;
      break;
    default:
      cout << "Bad input, exiting creation...";
      return;
  }

  cout << "What will you name this account?\n?";
  cin.ignore();
  getline(cin, accName);
  std::transform(accName.begin(), accName.end(), accName.begin(), toupper);

  cout << "What is the password for this account? (you will not be able to change this, and it's caps sensitive)" << endl;
  getline(cin, passwd);

  Account* account = new Account(userName, accName, type, passwd);
  accounts.push_back(account);

  return;
}
