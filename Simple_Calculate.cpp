#include <bits/stdc++.h>

using namespace std;

int main() {
	int acode, aunit;
	float aprice;

	int bcode, bunit;
	float bprice;

	cin >> acode >> aunit >> aprice;
	cin >> bcode >> bunit >> bprice;


	float to_be_paid = 0;
	to_be_paid = to_be_paid + aunit * aprice;
	to_be_paid = to_be_paid + bunit * bprice;

	// cout<<"VALOR A PAGAR: R$ "<<to_be_paid<<endl;

	printf("VALOR A PAGAR: R$ %.2f\n", to_be_paid);

}