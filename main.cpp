#include <iostream>
#include "test.h"
#include "model/model.h"
int get_num(int a, int b);
std::string get_name();

int main(int argc, char* argv[])
{
  // suppress warnings
  (void)argc; (void)argv;

  std::cout << "Hello World!" << std::endl;
  std::cout << get_num(21, 14) << std::endl;
  std::cout << get_name() << std::endl;
  return 0;
}