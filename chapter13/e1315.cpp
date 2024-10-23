#include<vector>
#include<deque>
#include<list>
#include<string>

using std::vector;
using std::deque;
using std::list;
using std::string;


#include<iostream>
using std::istream;
using std::ostream;
using std::cin;
using std::cout;
using std::endl;

#include<fstream>
using std::ifstream;
using std::ofstream;

#include<iterator>
using std::istream_iterator;
using std::ostream_iterator;

struct numbered{
  numbered()=default;
  numbered(numbered const & n){}
  size_t mysn{reinterpret_cast<size_t>(this)};
};

void f (numbered s) { cout << s.mysn << endl; }

int main (int argc, char** argv){
numbered a, b = a, c = b;
cout << a.mysn << endl;
cout << b.mysn << endl;
cout << c.mysn << endl;
f(a); f(b); f(c);
}
