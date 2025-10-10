#include <iostream>
using namespace std;
int i=0, j=0, k=0, e[5][5];
int main(){
	for (; i++ < 3; j = 0)
		for (; j++ < 3; e[i - 1][j] ^= (k %= 2), e[i][j - 1] ^= k, e[i][j] ^= k, e[i][j + 1] ^= k, e[i + 1][j] ^= k)
			cin >> k;
	for (; j++ < 3; cout << '\n')
		for (i = 0; i++ < 3;)
			cout << !e[j][i];
}