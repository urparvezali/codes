#include <iostream>
using namespace std;

void solution(int T) {
    int n, k;
    cin >> n >> k;

    int cnt = 0;
    for (int i = n; i > 0; i--) {
        int a = i;
        int b = n;
        int c = 0;
        while (true) {
            int temp = a;
            a = b - a;
            b = temp;
            if (b < 0) {
                break;
            }
            c++;
        }
        if (c >= k) {
            cnt++;
        }
    }
    cout << cnt << endl;
}

int main() {
    int TT = 1;
    cin >> TT;
    for (int T = 1; T <= TT; T++) {
        solution(T);
    }
    return 0;
}
