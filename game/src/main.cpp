#include <iostream>

#include "core.hpp"

int
main(void)
{
  std::cout << "Hello world!" << std::endl;
  int a = 4;
  int b = 2;
  int c = add_numbers(4, 2);
  
  std::cout << "Result = " << c << std::endl;
  
  return 0;
}
