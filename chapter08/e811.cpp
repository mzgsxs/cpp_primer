
#include<string>
using std::string;

#include<vector>
using std::vector;

#include<iostream>
#include<sstream>
using std::cin;
using std::cout;
using std::endl;
using std::istringstream;

struct PersonInfo {
  string name;
  vector<string> phones;
};

int main(){
  string line, word; // will hold a line and word from input, respectively
  vector<PersonInfo> people; // will hold all the records from the input
  // read the input a line at a time until cinhits end-of-file (or another error)
  istringstream record; // bind recordto the linewe just read
  while (getline(cin, line)) {
    record.str(line);
    cout << "new person" << endl;
    PersonInfo info; // create an object to hold this record’s data
    record >> info.name; // read the name
    while (record >> word) // read the phone numbers
      info.phones.push_back(word); // and store them
    people.push_back(info); // append this record to people
    record.clear();
  }
}
