#include<algorithm>

using std::begin;
using std::end;

#include<vector>
#include<deque>
#include<list>
#include<string>

using std::vector;
using std::deque;
using std::list;
using std::string;



#include<iostream>
using std::cin;
using std::cout;
using std::endl;


#include<iterator>
using std::istream_iterator;
using std::ostream_iterator;


#include"my_utils.h"


int main(){

vector<int> vi{1,2,3,4};
auto it = vi.end()-1;
while( it != vi.begin()){
  cout << *it-- << endl;
}
cout << *it << endl;

}