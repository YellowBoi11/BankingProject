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
         << "[6]: calculate interest\n"
         << "[7]: quit\n?";

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
        catch (const std::out_of_range& e) {
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

        // Catching out-of-range errors
        try {
          delete accounts.at(iInput);

          // Using pointer arithmatic to remove an account from the vector. 
          accounts.erase(accounts.begin() + iInput);
        }
        catch (const std::out_of_range& e) {
          cout << "Error: " << e.what() << endl;
        }
        break;
      }

      // Tries to deposit to an account.
      case 4: {
        double deposit;
        string passwd;
        cout << "Enter the accounts position:\n";

        while(!(cin >> iInput)) {
          std::cin.clear(); // Reset error flags
          std::cin.ignore(); // Clear buffer
          std::cout << "Invalid input. Please enter a number.\n";
          continue;
        }

        cout << "Enter how much you would like to deposit.\n";
        while(!(cin >> deposit)) {
          std::cin.clear(); // Reset error flags
          std::cin.ignore(); // Clear buffer
          std::cout << "Invalid input. Please enter a float.\n";
          continue;
        }

        cout << "Enter your password.\n";
        cin.ignore();
        getline(cin, passwd);

        // Catching out-of-range errors
        try {
          accounts.at(iInput)->deposit(deposit, passwd);
          accounts.at(iInput)->displayAccount(passwd);
        }
        catch (const std::out_of_range& e) {
          cout << "Error: " << e.what() << endl;
        }
        break;
      }

      // Tries to withdraw from an account.
      case 5: {
        double withdraw;
        string passwd;
        cout << "Enter the accounts position:\n";

        while(!(cin >> iInput)) {
          std::cin.clear(); // Reset error flags
          std::cin.ignore(); // Clear buffer
          std::cout << "Invalid input. Please enter a number.\n";
          continue;
        }

        cout << "Enter how much you would like to withdraw.\n";
        while(!(cin >> withdraw)) {
          std::cin.clear(); // Reset error flags
          std::cin.ignore(); // Clear buffer
          std::cout << "Invalid input. Please enter a float.\n";
          continue;
        }

        cout << "Enter your password.\n";
        cin.ignore();
        getline(cin, passwd);

        // Catching out-of-range errors
        try {
          accounts.at(iInput)->withdraw(withdraw, passwd);
          accounts.at(iInput)->displayAccount(passwd);
        }
        catch (const std::out_of_range& e) {
          cout << "Error: " << e.what() << endl;
        }

        break;
      }

    // Calculates all interest 
    case 6: {
      string passwd;
      int years;

      cout << "How many years of interest are you calculating\n?";
      while(!(cin >> years)) {
        std::cin.clear(); // Reset error flags
        std::cin.ignore(); // Clear buffer
        std::cout << "Invalid input. Please enter a float.\n";
        continue;
      }
      

      for (int pos = 0; pos < accounts.size(); pos++) {
        cout << "Enter your password for account " << accounts.at(pos)->getName() << endl;;

        // Ignores last cin input buffer only on the first pass
        if (pos == 0){
          cin.ignore();
        }
        getline(cin, passwd);
        accounts.at(pos)->calculateInterest(years, passwd);
        accounts.at(pos)->displayAccount(passwd);
      }

      break;
    }
    // Confirms quit 
    case 7: 
      cout << "Are you sure you would like to quit? [y/n]" << endl;
      cin >> cInput;

      switch (cInput) {
        case 'y':
        case 'Y':
          cout << "Exiting program..." << endl;
          return 0;
        case 'n':
        case 'N':
          cout << "Canceling exit.\n";
          break;
        default:
          cout << "Invalid input. Try again.\n";
      }

      break;
    default:
      cout << "Unrecognized input. Try again.\n";
    }
  }
  return 0;
}
