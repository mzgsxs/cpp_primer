#include<vector>
#include<deque>
#include<list>
#include<string>
#include<forward_list>

using std::vector;
using std::deque;
using std::list;
using std::string;
using std::forward_list;

#include<iostream>
using std::cin;
using std::cout;
using std::endl;


template<class T>
void print(T container)
{
  auto itr = container.begin();
  auto end = container.end();
  while(itr != end){
    cout << (*itr++) << " | ";
  }
  cout << endl;
}



int main(){
/*
list<int> vi = {0,1,2,3,4,5,6,7,8,9};
auto iter = vi.begin(); 
while (iter != vi.end()) {
  if (*iter % 2) {
    iter = vi.insert(iter, *iter); 
    iter++; 
    iter++; 
    // list does not support iterator arithmetics 
  } else
    iter = vi.erase(iter); 
}

print<list<int>>(vi);
*/

forward_list<int> li = {0,1,2,3,4,5,6,7,8,9};
auto prev = li.before_begin(); 
auto iter = li.begin(); 
while (iter != li.end()) {
  if (*iter % 2) {
    iter = prev = li.insert_after(iter, *iter); 
    ++iter;
    // list does not support iterator arithmetics 
  } else
    iter = li.erase_after(prev); 
}

print<forward_list<int>>(li);





}
