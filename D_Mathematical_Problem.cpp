#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

void solution(long T){
	long n;
	cin >> n;

	map<string,long> frequencyMap;

	for(long i=1; i <= 99999; ++i){
		string s=to_string(i * i);
		sort(s.begin(),s.end());
		if(s[0] == '0') continue;
		frequencyMap[s]++;
	}

	for(const auto& [key,value] : frequencyMap){
		if(value >= n){
			string s=key;
			do{
				long num=stoll(s);
				if(sqrt(num) == ceil(sqrt(num))){
					cout << s << endl;
					n--;
					if(n == 0) return;
				}
			} while(next_permutation(s.begin(),s.end()));
		}
	}
}
int main(){
	long TT;
	cin >> TT;

	for(long T=1; T <= TT; ++T){
		solution(T);
	}

	return 0;
}
