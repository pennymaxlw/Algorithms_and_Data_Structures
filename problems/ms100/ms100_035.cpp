#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int MaxSubArraySum(vector<int> v) {
  int sz = v.size();
  if (sz == 0) return 0;
  int max = 0, sum = 0;
  for (int i = 0; i < sz; ++i) {
    if (sum >= 0) sum += v[i];
    else sum = i;
    if (sum > max) max = sum;
  }
  cout << endl;
  return max;
}

typedef vector<vector<int> > Matrix;

int MaxSubMatrixSum(Matrix &matrix) {
  int m = matrix.size();    //row
  int n = matrix[0].size(); //column
  if (m == 0 || n == 0) return 0;
  int i = 0, j = 0, k = 0;
  int max = 0, sum = 0;
  vector<int> record(n, 0);
  for (; i < m; ++i) {
    fill(record.begin(), record.end(), 0);
    for (j = i; j < m; ++j) {
      for (k = 0; k < n; ++k) {
        record[k] += matrix[j][k];
      }
      sum = MaxSubArraySum(record);
      if (sum > max) max = sum; 
    }
  }
  return max;
}


int main() {
  int row = 4, column = 4;
  int row0[] = {0,-2,-7,0};
  int row1[] = {9,2,-6,2};
  int row2[] = {-4,1,-4,1};
  int row3[] = {-1,8,0,-2};
  Matrix matrix(row, vector<int>(column, 0));
  copy(row0, row0 + column, matrix[0].begin());
  copy(row1, row1 + column, matrix[1].begin());
  copy(row2, row2 + column, matrix[2].begin());
  copy(row3, row3 + column, matrix[3].begin());
  //int max = MaxSubArraySum(matrix[1]);
  int max = MaxSubMatrixSum(matrix);
  cout << "The max sum: " << max << endl;
}
