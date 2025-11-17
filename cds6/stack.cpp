#include <bits/stdc++.h>
using namespace std;

class Stack {
  int *arr;
  int p;   // points to next free index
  int cap; // maximum capacity

public:
  Stack(int size = 10) {
    p = 0;
    cap = size;
    arr = new int[cap];
  }

  void push(int x) {
    if (p == cap) {
      // Resize (double the capacity)
      int newCap = cap * 2;
      int *newArr = new int[newCap];
      for (int i = 0; i < cap; i++) {
        newArr[i] = arr[i];
      }
      delete[] arr;
      arr = newArr;
      cap = newCap;
    }
    arr[p++] = x;
  }

  void pop() {
    if (p == 0) {
      cout << "Stack Underflow!" << endl;
      return;
    }
    p--;
  }

  int top() {
    if (p == 0) {
      throw runtime_error("Stack is empty!");
    }
    return arr[p - 1];
  }

  int size() { return p; }

  int capacity() { return cap; }

  bool empty() { return p == 0; }

  ~Stack() { delete[] arr; }
};

class MyStack {
  int *arr;
  int cap;
  int p;

public:
  MyStack() {
    this->p = 0;
    this->cap = 1;
    arr = new int[1];
  }
  int push(int data) {
    if (p == cap) {
      int *new_arr = new int[cap * 2];
      for (int i = 0; i < cap; i++) {
        new_arr[i] = arr[i];
      }
      delete[] arr;
      arr = new_arr;
    }
    return arr[p++] = data;
  }
  int pop() {
    if (p == 0) {
      return -1;
    }
    return arr[--p];
  }
  int top() {
    if (p == 0)
      return -1;
    return arr[p - 1];
  }
  ~MyStack() { delete[] arr; }
};

int main() {
  MyStack st;

  st.push(10);
  cout << st.top() << endl;
  st.push(20);
  cout << st.pop() << endl;
  cout << st.top() << endl;
  cout << st.pop() << endl;
  cout << st.pop() << endl;

  return 0;
}
