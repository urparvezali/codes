#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(int case_num) {
	int n, m, k;
	cin >> n >> m >> k;

	vector<int> app(n), avl(m);
	for (int i = 0; i < n; i++) {
		cin >> app[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> avl[i];
	}

	sort(app.begin(), app.end());
	sort(avl.begin(), avl.end());

	int idx = 0;
	int ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = idx; j < m; j++) {
			if (avl[j] > app[i] + k) {
				break;
			}
			if (avl[j] >= app[i] - k && avl[j] <= app[i] + k) {
				ans++;
				idx = j + 1;
				break;
			}
		}
	}

	cout << ans << endl;
}

int main() {
	int t = 1; // Number of test cases (fixed to 1 as in the Rust code)
	// cin >> t; // Uncomment if multiple test cases are needed

	for (int case_num = 1; case_num <= t; case_num++) {
		solve(case_num);
	}

	return 0;
}
