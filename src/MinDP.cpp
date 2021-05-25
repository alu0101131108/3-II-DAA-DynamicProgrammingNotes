#include "./../include/MinDP.hpp"
MinDP::MinDP() 
{}

MinDP::MinDP(int N_, int PT_, std::vector<int> objectCosts_)
{
  N = N_;
  PT = PT_;
  objectCosts = objectCosts_;
}

void MinDP::buildTable()
{
}

void MinDP::printTable() 
{
  table.print();
}

int MinDP::getValue() 
{
  return table.get(N, PT);
}

std::vector<int> MinDP::getSolution() 
{
  return backtrack(N, PT);
}

std::vector<int> MinDP::backtrack(int N_, int PT_) {
  std::vector<int> partialSolution(N, 0);
  if (N_ == 0 || PT_ == 0) {
    return partialSolution;
  }
  else if (table.get(N_, PT_) == table.get(N_ - 1, PT_)) {
    return backtrack(N_ - 1, PT_);
  }
  else {
    int Z = PT_ / objectCosts[N_];
    partialSolution[N_] += Z;
    return add(partialSolution, backtrack(N_ - 1, PT_ - Z * objectCosts[N_]));
  }
}

std::vector<int> MinDP::add(std::vector<int> a, std::vector<int> b) {
  std::vector<int> sum;
  for (int i = 0; i < a.size(); i++) {
    sum.push_back(a[i] + b[i]);
  }
  return sum;
}

MinDP::~MinDP()
{}
