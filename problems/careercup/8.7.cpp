#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

void MakeChangeCoins(int sum, vector<int> &coins, vector<int> &method, int idx = 0) {
  if (sum < 0) return;
  if (sum == 0) {
    for (int i = 0; i < coins.size(); ++i) {
      cout << coins[i] << "(" 
           << count(method.begin(), method.end(), coins[i]) 
           << ") ";
    }
    cout << endl; 
  }
  for (int i = idx; i < coins.size(); ++i) {
    method.push_back(coins[i]);
    MakeChangeCoins(sum - coins[i], coins, method, i);
    method.pop_back();
  }
}


int main() {
  int arr[] = {1,5,10,25};
  vector<int> coins(arr, arr + sizeof(arr) / sizeof(int));
  int sum = 0;
  vector<int> method;
  while (cin) {
    cout << endl;
    cout << "Input sum: " << endl;
    cin >> sum;
    cout << "All change coins methods:" << endl;
    MakeChangeCoins(sum, coins, method);
  }
}
