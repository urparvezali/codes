#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


template <class T>
class SparseTable{
public:
	SparseTable(vector<T>& vec){
		size_t n = vec.size();
		log.resize(n + 1);
		log[1] = 0;
		for (size_t i = 2; i <= n; ++i){
			log[i] = log[i / 2] + 1;
		}
		size_t m = log[n] + 1;
		table.assign(n, vector<T>(m, T()));
		for (size_t i = 0; i < n; ++i){
			table[i][0] = vec[i];
		}
		for (size_t j = 1; j < m; ++j){
			for (size_t i = 0; i + (1 << j) <= n; ++i){
				table[i][j] = table[i][j - 1] + table[i + (1 << (j - 1))][j - 1];
			}
		}
	}
	T get(size_t l, size_t r){
		T sum = T();
		while (l < r){
			size_t j = log[r - l];
			sum = sum + table[l][j];
			l += 1 << j;
		}
		return sum;
	}
private:
	vector<size_t> log;
	vector<vector<T>> table;
};
typedef long long ll;
int main(){
	size_t n = 1000000;
	vector<ll> arr(n);
	for (ll i = 0; i < n; i++){
		arr[i] = i+1;
	}

	SparseTable st(arr);
	cout<<st.get(0, arr.size())<<endl;

	return 0;
}