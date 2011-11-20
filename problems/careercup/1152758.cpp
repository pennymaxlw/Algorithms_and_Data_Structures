#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

struct Constraint {
  vector<int> denoms;
  vector<int> cost;
  vector<int> limits;
  int amount;
};

void Solve(const Constraint &constraint, int curamount, int curcost, 
    int curidx, vector<int> &curlimits, vector<int> &result, int &mincost) {
  if (curamount > constraint.amount)
    return;
  else if (curamount == constraint.amount) {
    if (mincost != 0)
      mincost = min(mincost, curcost);
    else
      mincost = curcost;
    cout << "Found one candidate: ";
    for (int i = 0; i < result.size(); i++) {
      int j = result[i];
      cout << "(" << constraint.denoms[j] << ", " << constraint.cost[j] << "), ";
    }
    cout << endl;
    cout << "Total cost: " << mincost << endl;
  } else {
    if (mincost != 0 && curcost > mincost)
      return;
    for (int i = curidx; i < constraint.denoms.size(); i++) {
      if (curlimits[i] < constraint.limits[i]) {
        result.push_back(i);
        curlimits[i]++;
        Solve(constraint, curamount + constraint.denoms[i], curcost + constraint.cost[i], 
            i, curlimits, result, mincost);
        curlimits[i]--;
        result.pop_back();
      }
    }
  }
}


int main() {
  Constraint constraint;
  int denoms[] = {100,200,300,400,500,600};
  int cost[] = {125,150,425,525,625,725};
  int limits[] = {4,4,4,4,4,4};
  constraint.amount = 400;
  //int denoms[] = {2,4,5};
  //int cost[] = {10,10,1};
  //int limits[] = {1,1,1};
  //constraint.amount = 6;
  copy(denoms, denoms + sizeof(denoms) / sizeof(int), back_inserter(constraint.denoms));
  copy(cost, cost + sizeof(cost) / sizeof(int), back_inserter(constraint.cost));
  copy(limits, limits + sizeof(cost) / sizeof(int), back_inserter(constraint.limits));

  vector<int> result;
  int mincost = 0;
  vector<int> curlimits(sizeof(denoms) / sizeof(int), 0);
  Solve(constraint, 0, 0, 0, curlimits, result, mincost);
  cout << "Min cost: " << mincost << endl;
}
