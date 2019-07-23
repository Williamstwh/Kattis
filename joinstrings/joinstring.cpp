#include <iostream>
#include <string>
using namespace std;

int main() {
  // Read N
  int n;
  cin >> n;

  // Initialize vector storing lines
  string words[n + 1];
  int graph[n + 1];
  int ends[n + 1];

  // For each of the N lines
  for (int i = 1; i <= n; i++) {
    // Read the line
    string line;
    cin >> line;
    words[i] = line;
    graph[i] = 0;
    ends[i] = i;
  }

  // Number of queries
  int q = n - 1;
  int a, b;
  for (int i = 0; i < q; i++) {
    cin >> a >> b;
    graph[ends[a]] = b;
    ends[a] = ends[b];
  }

  while (a != 0) {
    cout << words[a];
    a = graph[a];
  }
  cout << endl;
}