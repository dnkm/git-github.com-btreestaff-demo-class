#include <bits/stdc++.h>

using namespace std;

vector<int> recursion(vector<int> factors, int index, int target,
                      vector<int> nums, int current, int sum) {
  // cout << index << ' ' << current << " begin" << endl;
  vector<int> back = {-1};
  int smallest = 42;
  vector<int> fail = {-1};
  for (int i = index; i < factors.size(); i++) {
    current *= factors[i];
    nums.push_back(factors[i]);
    sum += factors[i];
    // cout << index << ' ' << current << ' ' << sum << " end" << endl;
    if (sum > 41) {
      // cout << "failed" << endl;
      if (back != fail) {
        return back;
      }
      return fail;
    }
    if (current == target) {
      // cout << "success" << endl;
      return nums;
    }

    if (current > target) {
      if (back != fail) {
        return back;
      }
      return fail;
    }
    vector<int> got = recursion(factors, i, target, nums, current, sum);
    if (got != fail) {
      int added = 0;
      for (int i : got) {
        added += i;
      }
      while (added < 41) {
        got.push_back(1);
        added++;
      }
      if (got.size() < smallest) {
        back = got;
        smallest = back.size();
      }
    }
    nums.pop_back();
    current /= factors[i];
    sum -= factors[i];
  }
  if (back == fail) {
    return fail;
  } else {
    return back;
  }
}

vector<int> find_factors(int x) {
  vector<int> back = {};
  for (int i = 2; i <= 41; i++) {
    if (x % i == 0) {
      back.push_back(i);
    }
  }
  return back;
}

int main() {
  int cases;
  cin >> cases;
  for (int abc = 0; abc < cases; abc++) {
    int num;
    cin >> num;
    vector<int> factors = find_factors(num);
    vector<int> blank = {};
    vector<int> answer = recursion(factors, 0, num, blank, 1, 0);
    sort(answer.begin(), answer.end());
    vector<int> failed = {-1};
    if (answer == failed) {
      cout << "Case #" << abc + 1 << ": " << -1 << endl;
      continue;
    }
    int summed = 0;
    for (int i : answer) {
      summed += i;
    }
    if (summed != 41) {
      while (summed < 41) {
        summed++;
        answer.push_back(1);
      }
    }
    cout << "Case #" << abc + 1 << ": " << answer.size();
    for (int i : answer) {
      cout << ' ' << i;
    }
    cout << endl;
  }
}