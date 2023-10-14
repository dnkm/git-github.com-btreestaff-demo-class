#include <bits/stdc++.h>
using namespace std;

void fn(vector<int> v, int i) {
  if (i == 5)
    return;

  v[0]++;
  fn(v, i + 1);

  for (int vv : v)
    cout << vv << " ";
  cout << endl;
}

int main() {
  vector<int> v = {1, 2, 3, 4, 5};
  fn(v, 1);
}