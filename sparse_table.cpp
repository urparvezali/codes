#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class SparseTable{
	vector<vector<int>> table; // Stores precomputed sums
	vector<int> logValues;     // Stores log values for quick computation
	int n;                     // Size of the input array

public:
	// Constructor to build the sparse table from the input array
	SparseTable(const vector<int>& arr){
		n = arr.size();
		int maxLog = log2(n) + 1;

		// Initialize the table and logValues with appropriate sizes
		table = vector<vector<int>>(n, vector<int>(maxLog));
		logValues = vector<int>(n + 1);

		// Precompute log values
		logValues[1] = 0;
		for (int i = 2; i <= n; i++)
			logValues[i] = log2(i);

		// Initialize the table with the input array values
		for (int i = 0; i < n; i++)
			table[i][0] = arr[i];

		// Build the sparse table using dynamic programming
		for (int j = 1; pow(2, j) <= n; j++){ // j is the exponent of 2
			for (int i = 0; i + pow(2, j) - 1 < n; i++){ // i is the starting index
				// Compute the sum for the range starting at i with length 2^j
				table[i][j] = table[i][j - 1] + table[i + pow(2, j - 1)][j - 1];
			}
		}
	}

	// Query to get the sum of the segment [L, R]
	int query(int L, int R){
		int sum = 0;
		// Decompose the range into sub-ranges with lengths that are powers of two
		while (L <= R){
			// Find the largest power of 2 that fits in the range
			int j = logValues[R - L + 1];
			// Add the sum for the current sub-range
			sum += table[L][j];
			// Move L to the next position
			L += pow(2, j);
		}
		return sum;
	}

	// Print the sparse table and log values (for debugging and understanding)
	void print(){
		// cout << "Sparse Table:" << endl;
		for (auto& row : table){
			for (auto& value : row){
				cout << value << '\t';
			}
			cout << endl;
		}

		// cout << "Log Values:" << endl;
		// for(auto& value : logValues){
		// 	cout << value << ' ';
		// }
		// cout << endl;
	}
};

class Table{
	vector<vector<int>> table;
	int n;
	int m;
public:
	Table(vector<int>& v){
		n = v.size();
		m = log2(n)+1;
		table.resize(m, vector<int>(n));
		table[0] = v;

		for (int i = 1; i < m; i++){
			for (int j = 0; j < n - pow(2, i)+1; j++){
				table[i][j] = table[i-1][j]+table[i-1][j+pow(2, i-1)];
			}
		}

	}
	void print(){
		cout<<n<<' '<<m<<endl;
		for (auto& row : table){
			for (auto& value : row){
				cout << value << '\t';
			}
			cout << endl;
		}
	}
};

int main(){
	vector<int> arr(9);
	for (int i = 0; i < 9; i++){
		arr[i] = i+1;
	}

	Table st(arr);
	SparseTable sp(arr);
	sp.print();
	st.print();

	return 0;
}
