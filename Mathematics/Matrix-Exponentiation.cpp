/*   author: ekantchandrakar   */

#include<bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

// Matrix Exponentiation 
// Solve Proble on Spoj -- SEQ, SPP, Fibosum

/* Nth Fibonacci Number */
// T^n-2.F(2) = F(n)
// We just need T matrix so just limit the size of matrix upto 2 for this eg
const int sz = 2;

struct Mat {
	int m[sz][sz];
	Mat() {
		memset(m, 0, sizeof(m));
	}

	void identity(){
		for(int i = 0; i < sz; i++){
			m[i][i] = 1;
		}
	}
	// If we use multiplication anywhere this function will be called
	// Mat r, q
	// r = r * q; (so the a will be q, and r will be m)

	Mat operator* (Mat a){
		Mat res;
		for(int i = 0; i < sz; i++){
			for (int j = 0; j < sz; j++){
				for(int k = 0; k < sz; k++){
					res.m[i][j] += m[i][k] * a.m[k][j];
					res.m[i][j] %= mod;
				}				
			}
		}

		return res;
	}
};

int Fib(int n){
	Mat res;
	res.identity();
	Mat T;
	T.m[0][0] = T.m[0][1] = T.m[1][0] = 1;

	// We have to calculate T^n-2;
	if(n <= 2){
		return 1;	
	}

	n -= 2;
	// O((sz^3)*log(n)) if sz = 2 than O(8log(n))
	while(n){
		if(n & 1){
			res = res * T;	
		}
		T = T * T;
		n >>= 1;
	}

	return (res.m[0][0] + res.m[0][1]) % mod;
}

void solve(){
	int n;
	cin >> n;
	cout << Fib(n) << endl;
}

int main() {
	fast_io;
	
	int t = 1; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}
