#include <bits/stdc++.h>
using namespace std;

int main() {
	size_t n = 100000000;
	size_t sum = 0;
	for (size_t i = 0; i < n; i++) {
		sum += rand()%10;
	}
	cout << sum << endl;
}