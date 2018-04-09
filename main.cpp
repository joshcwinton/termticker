#include <iostream>
#include <cstdlib>
#include <fstream>
// #include <curl/curl.h>
using namespace std;

void writeFile(string function, string symbol, string apikey){
  string rstring = "curl --GET -s -d \'function="+function+"&symbol="+symbol+"&apikey="+apikey+"&datatype=csv\' https://www.alphavantage.co/query? -o output.csv";
  system(rstring.c_str());
}

string readDate(string line){
  string rstring = "";
  int i = 0;
  while(i < line.length()){
    if(line[i] == ','){
      break;
    }
    rstring += line[i];
    i++;
  }
  return rstring;
}

string findDate(string date){
  string input;
  ifstream inputStream;
  inputStream.open("output.csv");
  while(getline(inputStream, input)){
    if(readDate(input) == date){
      return(input);
    }
  }
  return("Date not found.");
}

// string searchLine(string line, string searchTerm){
//   string splitInput[6];
//   int index = 0;
//   string rstring = "";
//   for(int i = 0; i < line.length(); i++){
//     if(line[i] != ','){
//       rstring += line[i];
//     } else {
//       splitInput[index] = rstring;
//       rstring = "";
//       index += 1;
//     }
//   }
//   splitInput[5] = rstring;
//   if(searchTerm == "open"){
//     return("Open: " + splitInput[1]);
//   }
//   if(searchTerm == "high"){
//     return(splitInput[2]);
//   }
//   if(searchTerm == "low"){
//     return(splitInput[3]);
//   }
//   if(searchTerm == "close"){
//     return(splitInput[4]);
//   }
//   if(searchTerm == "volume"){
//     return(splitInput[5]);
//   }
//   return("Invalid search term.");
// }

string searchLine(string line){
  string splitInput[6];
  int index = 0;
  string rstring = "";
  string outputString = "";
  for(int i = 0; i < line.length(); i++){
    if(line[i] != ','){
      rstring += line[i];
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
  return(outputString);
}

int main(){
  string apikey = "UCKSYLXVDHZX3WPK";
  string function = "TIME_SERIES_DAILY";
  string symbol;
  string date;
  string search;
  cout << "Enter a symbol: ";
  cin >> symbol;
  cout << "Enter a date (YYYY-MM-DD): ";
  cin >> date;
  // cout << "Enter a search term (open, high, low, close, volume): ";
  // cin >> search;
  writeFile(function, symbol, apikey);
  // cout << searchLine(findDate(date), search) << endl;
  cout << "Symbol: " << symbol << endl;
  cout << searchLine(findDate(date)) << endl;
  return(0);
}
