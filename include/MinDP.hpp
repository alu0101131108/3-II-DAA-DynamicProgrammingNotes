#ifndef __MINDP_H__
#define __MINDP_H__

#include <string>
#include <vector>
#include <algorithm>
#include "Table.hpp"

class MinDP
{
private:
  Table table;
  int N;
  int PT;
  std::vector<int> objectCosts;
  std::vector<int> objectQuantities;

public:
  MinDP();
  MinDP(int N_, int PT_, std::vector<int> objectCosts_, std::vector<int> objectQuantities_);
  void buildTable();
  void printTable();
  int getValue();
  std::vector<int> getSolution();
  std::vector<int> backtrack(int N_, int PT_);
  std::vector<int> add(std::vector<int> a, std::vector<int> b);
  int min(int a, int b);
  int min_(int a, int b);
  ~MinDP();
};


#endif // __MINDP_H__