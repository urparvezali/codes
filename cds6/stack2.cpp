#include <bits/stdc++.h>
using namespace std;

class Stack {
  int* arr;
  int p;
  int cap;

public:
  Stack() {
    cap = 1;
    p = 0;
    arr = new int[1];
  }
  void push(int data) {
    if (cap == p) {
      cap = 2 * cap;
      int* newarr = new int[cap];
      for (int i = 0; i < cap; i++) {
        newarr[i] = arr[i];
      }
      delete arr;
      arr = newarr;
    }
    arr[p] = data;
    p++;
  }
  void pop() {
    if (p == 0) {
      cout << "POP is not allowed with zero element" << endl;
      return;
    }
    p--;
  }
  int top() {
    if (p == 0) {
      return -1;
    }
    return arr[p - 1];
  }
  bool empty() {
    if (p == 0) {
      return true;
    }
    return false;
  }
};
int main() {

  Stack st;
  st.push(5);
  st.push(10);
  st.push(15);
  st.push(100);
  st.push(0);

  while (!st.empty()) {
    cout << st.top() << endl;
    st.pop();
  }
}
