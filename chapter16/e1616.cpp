
#include <iostream>

#include <memory>
#include <vector>
#include <initializer_list>



template <typename T> 
class Vector {
public:
  Vector(): // the allocatormember is default initialized
  elements(nullptr), first_free(nullptr), cap(nullptr) { }
  Vector(const Vector&); // copy constructor
  Vector &operator=(const Vector&); // copy assignment
  ~Vector(); // destructor
  void push_back(const std::string&); // copy the element
  size_t size() const { return first_free - elements; }
  size_t capacity() const { return cap - elements; }
  std::string *begin() const { return elements; }
  std::string *end() const { return first_free; }
  //. . .
private:
  static std::allocator<T> alloc; // allocates the elements
  void chk_n_alloc() // used by functions that add elements to a Vector
  { if (size() == capacity()) reallocate(); }
  // utilities used by the copy constructor, assignment operator, and destructor
  std::pair<T *, T *> alloc_n_copy
    (const T *, const T *);
  void free(); // destroy the elements and free the space
  void reallocate(); // get more space and copy the existing elements
  T * elements; // pointer to the first element in the array
  T * first_free; // pointer to the first free element in the array
  T * cap; // pointer to one past the end of the array
};


int 
main(int argc, char** argv)
{
  Vector<std::string> vs;
  return 0;
}

