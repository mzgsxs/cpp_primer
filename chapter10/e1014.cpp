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


int main(){
int k{2};

auto foo = [](int const & i, int const & j){return i+j;};

cout << foo(2, 3);
cout << endl;

}