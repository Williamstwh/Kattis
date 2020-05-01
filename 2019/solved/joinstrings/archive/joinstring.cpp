#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node;

class Node {
  public:
    // Constructor
    Node(string v): value(v), next_pointer(NULL) {}

    // Value
    string value;
    Node *next_pointer;

    bool hasNext() {
      return next_pointer != NULL;
    }
};

class LinkedList {
  public:
    // Constructor
    LinkedList(Node *n): first(n), last(n) {}

    Node *first;
    Node *last;
};

int main() {
  // Initialize vector storing lines
  vector<LinkedList> lists;
  Node dummyNode("");
  LinkedList dummyLinkedList(&dummyNode);
  lists.push_back(dummyLinkedList);

  // Read N
  int n;
  cin >> n;

  // For each of the N lines
  for (int i = 1; i <= n; i++) {
    // Read the line
    string line;
    cin >> line;

    // Create a node using the line and add the address to a new linkedlist
    Node *node = new Node(line);
    LinkedList *list = new LinkedList(node);

    // Add the linkedlist to the lists
    lists.push_back(*list);
  }

  // Number of queries
  int q = n - 1;
  int a, b;
  for (int i = 0; i < q; i++) {
    // Read a and b
    cin >> a >> b;

    // The next node of the last node of the first list is the first node of the second list
    (*(lists[a].last)).next_pointer = lists[b].first;
    
    // The last node of the first list changed to last node of the second list
    lists[a].last = lists[b].last;
  }

  // Start at the first node of the longest list
  Node *start = lists[a].first;
  while ((*start).hasNext()) {
    cout << (*start).value;
    start = (*start).next_pointer;
  }
  cout << (*start).value << endl;
}