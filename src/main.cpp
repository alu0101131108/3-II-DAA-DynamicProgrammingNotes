#include <vector>
#include <iostream>
#include <string>
#include "./../include/MinDP.hpp"
int main(int argc, char *argv[])
{

  MinDP test(std::stoi(argv[1]), std::stoi(argv[2]), {1, 4, 6});
  test.buildTable();
  test.printTable();
  test.getValue();
  test.getSolution();
  
  return 0;
}
