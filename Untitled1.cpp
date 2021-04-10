#include <iostream>
using namespace std;
typedef long long ll;

void sinh(int *B, int n, bool &OK){ //tao mang 1 chieu n^2 dong co gia tri tu 0-24
	int i = n; //i=5
	while ( i> 0 && B[i] == 1){
		B[i] = 0;
		i--;
	}
	if (i>0) B[i] = 1;
	else OK = 0;
}

void result(ll *A, int *B, int n, ll k, int &dem){
	ll sum = 0;
	for (int i = 1; i <= n; ++i){
		if (B[i] == 1){
			sum+=A[i];
		}
	}
	if (sum == k){
		for (int i = 1; i <= n; ++i)
			if (B[i] == 1)
				cout <<A[i]<<" ";
		cout<<"\n";
		dem++;
	}
}

int main(){
	int n;
	ll k;
	cin>> n>> k;
	bool OK = 1;
	int dem = 0;
	ll *A = new ll[n+1];
	int *B = new int [n+1];
	for (int i = 1; i <= n; ++i){
		cin>> A[i];
		B[i] = 0;
	}
	do {
		result(A, B, n, k, dem);
		sinh(B, n, OK);
	} while (OK);
	cout<< dem;
	delete [] A;
	delete [] B;
	return 0;
}
