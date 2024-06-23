#include "Sales_data_revised.h"
#include <iostream>


int process_data() 
{
  // read needs to change datas
  Sales_data datas(std::cin);
  if (std::cin){
    while (std::cin){
      Sales_data data(std::cin);
      if (datas.isbn() == data.isbn()){
        datas = add(datas, data);
      } else {
        // print do not need to alter datas
        print(std::cout, datas);
        datas = data;
      }
    }
    //print(std::cout, datas);
  } else {
    std::cerr << " no data !? " << std::endl;
    return -1;
  }
  return 0;
}
int main() 
{
  process_data();
}
