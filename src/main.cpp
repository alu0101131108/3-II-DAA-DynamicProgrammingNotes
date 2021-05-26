#include <vector>
#include <iostream>
#include <string>
#include "./../include/MinDP.hpp"
int main(int argc, char *argv[])
{
  int N = 5;
  int PT = 11;
  std::vector<int> objectCosts =      {1,     3,    5,    6,    7};
  std::vector<int> objectQuantities = {1000,  1000, 1000, 1000, 1000};
  
  MinDP test(N, PT, objectCosts, objectQuantities);
  test.buildTable();
  test.printTable();
  int value = test.getValue();
  std::vector<int> solution = test.getSolution();
  
  std::cout << "Total objects: " << value << std::endl;
  std::cout << "Solution: ";
  for (int i = 0; i < N; i++) {
    std::cout << "[" << i+1 << ": " << solution[i] << "] ";
  }
  std::cout << std::endl;
  
  return 0;
}
