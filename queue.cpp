#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int data;
  Node *next;
  Node(int d) : data(d), next(nullptr) {}
};
class Queue {
  Node *head, *back;

public:
  Queue() : head(nullptr), back(nullptr) {};
  void push(int d) {
    Node *newnode = new Node(d);
    if (back == nullptr) {
      head = back = newnode;
    } else {
      back->next = newnode;
      back = newnode;
    }
  }
  int pop() {
    if (head == nullptr)
      return -1;

    int data = head->data;
    Node *temp = head;
    head = head->next;
    if (head == nullptr) {
      back = nullptr;
    }
    delete temp;
    return data;
  }
};

int main() {
  Queue q;
  while (true) {
    q.push(8);
    q.pop();
  }
}
