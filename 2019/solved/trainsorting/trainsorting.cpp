#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int trainsort(int arr[], int start, int N) {
  int head = arr[start];
  vector<int> lis_arr;
  vector<int> lds_arr;

  for (int i = start + 1; i < N; i++) {
    int val = arr[i];
    if (val > head) {
      if (lis_arr.size() == 0 || lis_arr[lis_arr.size() - 1] < val) {
        lis_arr.push_back(val);
      } else if (lis_arr[0] > val) {
        lis_arr[0] = val;
      } else {
        int l = 0, h = lis_arr.size() - 1;
        while (h - 1 > l) {
          int m = (l + h) / 2;
          if (val > lis_arr[m]) {
            l = m;
          } else {
            h = m;
          }
        }
        lis_arr[h] = val;
      }
    } else {
      if (lds_arr.size() == 0 || lds_arr[lds_arr.size() - 1] > val) {
        lds_arr.push_back(val);
      } else if (lds_arr[0] < val) {
        lds_arr[0] = val;
      } else {
        int l = 0, h = lds_arr.size();
        while (h - 1 > l) {
          int m = (l + h) / 2;
          if (val < lds_arr[m]) {
            l = m;
          } else {
            h = m;
          }
        }
        lds_arr[h] = val;
      }
    }
  }
  return 1 + lis_arr.size() + lds_arr.size();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int N;
  cin >> N;
  int arr[N];
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  int maximum = 0;

  for (int i = 0; i < N; i++) {
    maximum = max(maximum, trainsort(arr, i, N));
  }

  cout << maximum << '\n';
}