
#include <iostream>

#include <memory>
#include <vector>
#include <initializer_list>



template <typename T> 
class Screen;

template <typename T> 
std::istream & 
operator>>(std::istream &, Screen<T> &);


template <typename T> 
class Screen {
friend std::istream & operator>><T>(std::istream &, Screen<T> &);

public:
  typedef T pos;
  Screen() = default; 
  Screen(pos ht, pos wd, char c): 
  height(ht), width(wd), contents(ht * wd, c) 
  {}
  char get() const 
  { return contents[cursor]; } 
  inline char get(pos r, pos c) const 
  {
    pos row = r * width; 
    return contents[row + c];
  }
  Screen & move(pos r, pos c) 
  {
    pos row = r * width; // compute the row location
    cursor = row + c; // move cursorto the column within that row
    return *this; // return this object as an lvalue
  }
  inline Screen & set(char c)
  {
    contents[cursor] = c; // set the new value at the current cursor location
    return *this; // return this object as an lvalue
  }

  inline Screen & set(pos r, pos col, char ch)
  {
    contents[r*width + col] = ch; // set specified location to given value
    return *this; // return this object as an lvalue
  }

private:
  pos cursor = 0;
  pos height = 0, width = 0;
  std::string contents;
};



template <typename T> 
std::istream &
operator>>(std::istream & is , Screen<T> & s)
{
  return is >> s.contents;
}


template <typename T> 
std::ostream &
operator<<(std::ostream & os , Screen<T> const & s)
{
  return os << s.get();
}



int 
main(int argc, char** argv)
{
  Screen<int> s{100,200,'c'};
  std::cout << s << std::endl;
  std::cin >> s;
  std::cout << s << std::endl;
  return 0;
}

