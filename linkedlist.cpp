#include <bits/stdc++.h>
using namespace std;

class Link {
public:
  int data;
  Link *next;
  Link(int data) {
    this->data = data;
    this->next = nullptr;
  }
};

class LL {
  Link *head;
  Link *last;

public:
  LL() { this->head = this->last = nullptr; }
  void add(int data) {
    Link *new_link = new Link(data);
    new_link->next = head;
    head = new_link;
  }
  void print() {
    cout << "Showing Nodes:" << endl;
    Link *curr = head;
    while (curr != nullptr) {
      cout << curr->data << endl;
      curr = curr->next;
    }
  }
};

int main() {
  LL ll;
  ll.print();
  ll.add(5);
  ll.print();
  ll.add(10);
  ll.print();
  ll.add(15);
  ll.print();
}
