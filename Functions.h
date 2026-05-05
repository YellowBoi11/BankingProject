/******************
 * Functions.h 
 *
 * File for additional functions to keep main clean 
 *
 * Author: Luca Pendleton 
*******************/

#include "Account.h"
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::vector;

// Creates an Account object
void createAccount(vector<Account*>& accounts, const string& userName);
