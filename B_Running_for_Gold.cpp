#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 5 * 1e4 + 5;

int standing[MAXN][6];

// Function to determine if player p1 is better than player p2
int isBetter(int p1, int p2){
	int score_p1 = 0, score_p2 = 0;

	for (int i = 1; i < 6; ++i){
		score_p1 += standing[p1][i] < standing[p2][i];
		score_p2 += standing[p2][i] < standing[p1][i];
	}

	return (score_p1 > score_p2) ? p1 : p2;
}

void solve(){
	int n;
	cin >> n;

	// Input player standings
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j < 6; ++j){
			cin >> standing[i][j];
		}
	}

	// Start with the first player as the current best
	int currBest = 1;

	// Compare the current best with every other player
	for (int i = 2; i <= n; ++i){
		currBest = isBetter(currBest, i);
	}

	// Check if the current best can defeat all other players
	int defeated = 0;
	for (int i = 1; i <= n; ++i){
		if (i != currBest){
			int best = isBetter(currBest, i);
			defeated += (best == currBest);
		}
	}
	cout << ((defeated == n - 1) ? currBest : -1) << '\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--){
		solve();
	}

	return 0;
}
