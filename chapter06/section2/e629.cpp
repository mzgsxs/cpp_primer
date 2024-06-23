#include <iostream>

#include <string>
#include <cstring>
using std::string;

#include <vector>
using std::vector;

using std::cin;
using std::cout;
using std::endl;

using std::begin;
using std::end;

#include<stdexcept>
using std::exception;
using std::runtime_error;

void error_msg(ErrCode e, initializer_list<string> il) {
  cout << e.msg() << ": "; 
  for (const auto & elem : il)
  // elem have the type of string const &
  // loop control variable should be reference
  // so that there would be no copy
    cout << elem << " " ;
  cout << endl;
}



int main() 
{

  return 0;
}
