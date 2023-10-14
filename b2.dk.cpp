#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int P;
vector<int> factors;
vector<int> current;
vector<int> answer;
int minSize = 1e9 + 1;

void rec(int sum, ll prod) {
  if (current.size() > minSize)
    return;
  if (sum > 41 || prod > P) {
    return;
  }
  if (prod == P) {
    int cnt1 = 41 - sum; // how many "1"s to be added
    if (current.size() + cnt1 < minSize) {
      answer = current;
      minSize = current.size() + cnt1;
    }
    return;
  }

  for (int v : factors) {
    current.push_back(v);
    rec(sum + v, prod * v);
    current.pop_back();
  }
}

void solve() {
  cin >> P;

  factors.clear();
  current.clear();
  answer.clear();
  minSize = 1e9 + 1;

  // find all factors of n into factors
  for (int i = 2; i <= 41; i++) {
    if (P % i == 0) {
      factors.push_back(i);
    }
  }

  // sort(factors.begin(), factors.end(), greater<>());
  sort(factors.begin(), factors.end());
  rec(0, 1L);

  // print answer
  if (answer.empty() && minSize == 1e9 + 1) {
    cout << "-1\n";
    return;
  }

  int cnt1 = 41;
  for (int v : answer)
    cnt1 -= v;

  cout << (cnt1 + answer.size()) << ' ';

  for (int i = 0; i < cnt1; i++)
    cout << 1 << ' ';

  for (int i = 0; i < answer.size(); i++) {
    cout << answer[i];
    if (i < answer.size() - 1)
      cout << ' ';
    else
      cout << endl;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  for (size_t i = 0; i < t; i++) {
    cout << "Case #" << i + 1 << ": ";
    solve();
  }

  return 0;
}