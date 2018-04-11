#include <fstream>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

string getSymbol() {
  string symbol;
  cout << "Enter a symbol:" << endl;
  cin >> symbol;
  return (symbol);
}

string getDate() {
  string date;
  cout << "Enter a date:" << endl;
  cin >> date;
  return (date);
}

string getTime() {
  string time;
  cout << "Enter a time:" << endl;
  cin >> time;
  return (time);
}

void getIntradayData(string symbol) {
  string apikey = "UCKSYLXVDHZX3WPK";
  string interval = "1min";
  string queryString =
      "curl --GET -s -d \'function=TIME_SERIES_INTRADAY&symbol=" + symbol +
      "&apikey=" + apikey + "&interval=" + interval +
      "&datatype=csv\' https://www.alphavantage.co/query? -o output.csv";
  system(queryString.c_str());
}

void getDailyData(string symbol) {
  string apikey = "UCKSYLXVDHZX3WPK";
  string queryString =
      "curl --GET -s -d \'function=TIME_SERIES_DAILY&symbol=" + symbol +
      "&apikey=" + apikey +
      "&datatype=csv\' https://www.alphavantage.co/query? -o output.csv";
  system(queryString.c_str());
}

string readDate(string line) {
  string rstring = "";
  int i = 0;
  while (i < line.length()) {
    if (line[i] == ',') {
      break;
    }
    rstring += line[i];
    i++;
  }
  return rstring;
}

string findDate(string date) {
  string input;
  ifstream inputStream;
  inputStream.open("output.csv");
  if (date == "today") {
    getline(inputStream, input);
    getline(inputStream, input);
    return (input);
  } else {
    while (getline(inputStream, input)) {
      if (readDate(input) == date) {
        return (input);
      }
    }
  }
  return ("");
}

void readInfo(string info) {
  string splitInput[6];
  int index = 0;
  string rstring = "";
  string outputString = "";
  for (int i = 0; i < info.length(); i++) {
    if (info[i] != ',') {
      rstring += info[i];
    } else {
      splitInput[index] = rstring;
      rstring = "";
      index += 1;
    }
  }
  splitInput[5] = rstring;
  outputString += "Date: " + splitInput[0] + "\nOpen: " + splitInput[1] +
                  "\nHigh: " + splitInput[2] + "\nLow: " + splitInput[3] +
                  "\nClose: " + splitInput[4] + "\nVolume: " + splitInput[5];
  cout << outputString << endl;
}

void removeOutput() { system("rm -f output.csv"); }

void intraday() {
  string symbol = getSymbol();
  string date = getDate();
  string time = getTime();
  string timestamp = date + ' ' + time;
  string info;
  getIntradayData(symbol);
  info = findDate(timestamp);
  if (info == "") {
    cout << "Date not found." << endl;
  } else {
    cout << "Symbol: " << symbol << endl;
    readInfo(info);
  }
  removeOutput();
}

void daily() {
  string symbol = getSymbol();
  string date = getDate();
  string info;
  getDailyData(symbol);
  info = findDate(date);
  if (info == "") {
    cout << "Date not found." << endl;
  } else {
    cout << "Symbol: " << symbol << endl;
    readInfo(info);
  }
  removeOutput();
}

void weekly() {
  string symbol = getSymbol();
  string date = getDate();
  string info;
  getDailyData(symbol);
  info = findDate(date);
  if (info == "") {
    cout << "Date not found." << endl;
  } else {
    cout << "Symbol: " << symbol << endl;
    readInfo(info);
  }
  removeOutput();
}
void monthly() {
  string symbol = getSymbol();
  string date = getDate();
  string info;
  getDailyData(symbol);
  info = findDate(date);
  if (info == "") {
    cout << "Date not found." << endl;
  } else {
    cout << "Symbol: " << symbol << endl;
    readInfo(info);
  }
  removeOutput();
}
