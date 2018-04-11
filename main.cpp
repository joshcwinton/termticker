#include <algorithm>
#include <iostream>
#include <string>
#include "funcs.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
  string query;
  do {
    cout << "Enter a query type (intraday, daily, weekly, monthly):" << endl;
    cin >> query;
    std::transform(query.begin(), query.end(), query.begin(), ::tolower);
    if (query == "intraday") {
      intraday();
    } else if (query == "daily") {
      daily();
    } else if (query == "weekly") {
      weekly();
    } else if (query == "monthly") {
      monthly();
    } else {
      cout << "Invalid query type try again." << endl;
    }
  } while (query != ("intraday") && query != ("daily") &&
           query != ("weekly") && query != ("monthly"));
}
