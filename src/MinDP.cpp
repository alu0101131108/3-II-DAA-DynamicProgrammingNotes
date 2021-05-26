#include "./../include/MinDP.hpp"
MinDP::MinDP() 
{}

MinDP::MinDP(int N_, int PT_, std::vector<int> objectCosts_, std::vector<int> objectQuantities_)
{
  N = N_;
  PT = PT_;
  objectCosts = objectCosts_;
  objectQuantities = objectQuantities_;
}

void MinDP::buildTable() {
  table = Table(N + 1, PT + 1);
  for (int row = 0; row <= N; row++) {
    for (int col = 0; col <= PT; col++) {
      if (row == 0 || col == 0) {
        table.set(row, col, 0);
      } 
      else if (col < objectCosts[row - 1]) {
        int inherited = table.get(row - 1, col);
        table.set(row, col, inherited);
      }
      else {
        int inherited = table.get(row - 1, col);
        int Zk = min(objectQuantities[row - 1], int(col / objectCosts[row - 1]));
        int newValue = Zk + table.get(row - 1, col - Zk * objectCosts[row - 1]);
        table.set(row, col, min_(inherited, newValue));
      }
    }
  }
}

// Mínimo que considera 0 mayor que cualquier número.
int MinDP::min_(int a, int b)
{
  if (a == 0) {
    return b;
  }
  if (b == 0) {
    return a;
  }
  if (a > b) {
    return b;
  }
  else {
    return a;
  }
}

// Mínimo normal.
int MinDP::min(int a, int b)
{
  if (a > b)
  {
    return b;
  }
  else
  {
    return a;
  }
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

// La solución quedaría en un vector de tamaño N, cada posición corresponderia a un 
// tipo de objeto y contendría el número de veces que sería utilizado.
std::vector<int> MinDP::backtrack(int N_, int PT_) {
  std::cout << N_ << " - " << PT_ << std::endl;
  std::vector<int> partialSolution(N, 0);
  if (N_ == 0 || PT_ == 0) {
    return partialSolution;
  }
  else if (table.get(N_, PT_) == table.get(N_ - 1, PT_)) {
    return backtrack(N_ - 1, PT_);
  }
  else {
    int Z = PT_ / objectCosts[N_ - 1];
    partialSolution[N_ - 1] += Z;
    return add(partialSolution, backtrack(N_ - 1, PT_ - Z * objectCosts[N_ - 1]));
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
