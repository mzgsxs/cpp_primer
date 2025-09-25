
#include <iostream>

#include <memory>
#include <vector>
#include <initializer_list>






template <typename T> 
class Screen {
public:
  typedef T pos;
  Screen() = default; 
  Screen(pos ht, pos wd, char c): height(ht), width(wd),
  contents(ht * wd, c) { }
  char get() const 
    { return contents[cursor]; } 
  inline char get(pos ht, pos wd) const; 
  Screen &move(pos r, pos c); 
private:
  pos cursor = 0;
  pos height = 0, width = 0;
  std::string contents;
};

int 
main(int argc, char** argv)
{
  Screen<int> s{100,200,'c'};
  return 0;
}

