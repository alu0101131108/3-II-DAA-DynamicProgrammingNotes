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

public:
  MinDP();
  MinDP(int N_, int PT_, std::vector<int> Pks_);
  void buildTable();
  void printTable();
  int getValue();
  std::vector<int> getSolution();
  std::vector<int> backtrack(int N_, int PT_);
  std::vector<int> add(std::vector<int> a, std::vector<int> b);
  ~MinDP();
};


#endif // __MINDP_H__