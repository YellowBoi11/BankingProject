#include "Account.h"
#include "Functions.h"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main () {
  // Allows methods to set floating-point-precisionn.
  cout.setf(std::ios::fixed);
  cout.setf(std::ios::showpoint);

  // variables 
  // Vector of account pointers to prevent leaving scope and decrease copying.
  vector<Account*> accounts;
  char cInput;
  int iInput;
  string userName;

  cout << "Welcome to your bank! Would you like to create an account? [y/n]\n";
  cin >> cInput;

  switch (cInput) {
    case 'y':
    case 'Y':
      // Fallthrough 
      break;
    case 'n':
    case 'N':
      // Ends program
      cout << "Alright. Bye!" << endl;
      return 0;
    default:
      cout << "I didn't recognize that input, ending program..." << endl;
      return 0;
  }

  cout << "Cool! What is your name?\n";
  cin.ignore();
  getline(cin, userName);
  // Capitalizes the input
  std::transform(userName.begin(), userName.end(), userName.begin(), toupper);

  // Infinite loop
  for (;;) {
    cout << "What would you like to do?\n" 
         << "[0]: List accounts\n"
         << "[1]: view an account\n"
         << "[2]: add an account\n" 
         << "[3]: remove an account\n"
         << "[4]: deposit to an account\n"
         << "[5]: withdraw from an account\n"
         << "[6]: quit\n?";

    // Ensuring proper input
    while(!(cin >> iInput)) {
      std::cin.clear(); // Reset error flags
      std::cin.ignore(); // Clear buffer
      std::cout << "Invalid input. Please enter a number.\n";
      continue;
    }

    switch (iInput) {

      // Lists the accounts and their positions
      case 0:
        for (int pos = 0; pos < accounts.size(); pos++) {
          cout << pos << ": " << accounts.at(pos)->getName() << " | " << accounts.at(pos)->getType() << endl;
        }
        break;

      // Lists an account based on their position
      case 1: {
        string passwd;
        cout << "Enter the accounts position:\n";
        while(!(cin >> iInput)) {
          std::cin.clear(); // Reset error flags
          std::cin.ignore(); // Clear buffer
          std::cout << "Invalid input. Please enter a number.\n";
          continue;
        }

        cout << "Enter the accounts password:\n";
        cin >> passwd;

        // Catching out-of-range errors
        try {
          accounts.at(iInput)->displayAccount(passwd);
        }
        catch (const std::logic_error& e) {
          cout << "Error: " << e.what() << endl;
        }
        break;
      }

      // Creates an account
      case 2:
        createAccount(accounts, userName); 
        break;

      // Removes an account 
      case 3: {
        cout << "Enter the accounts position:\n";

        while(!(cin >> iInput)) {
          std::cin.clear(); // Reset error flags
          std::cin.ignore(); // Clear buffer
          std::cout << "Invalid input. Please enter a number.\n";
          continue;
        }

        try {
          delete accounts.at(iInput);

          // Using pointer arithmatic to remove an account from the vector. 
          accounts.erase(accounts.begin() + iInput);
        }
        catch (const std::logic_error& e) {
          cout << "Error: " << e.what() << endl;
        }
        break;
      }

      // Tries to deposit to an account.
      case 4:
    }
 

  }

  return 0;
}
