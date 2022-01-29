/*   author: ekantchandrakar   */

#include<bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

#define int long long int
using namespace std;

const int P = 1e9 + 7, N = 1e5;
int fact[N];

int addMod(int x, int y){ // O(1)
	return (x + y) % P;
}

int subMod(int x, int y){// O(1)
	return ((x - y) % P + P) % P; // (x - y) can be negative number and we need positive remainder
}

int multiplyMod(int x, int y){// O(1)
	return (x * y) % P; // (x * y) % P = ((x % P) * (y % P)) % P
}

int powrm(int x, int y){ // fast exponentiation O(log(y))
	int res = 1;
	while(y){
		if(y & 1){
			res = multiplyMod(res, x);
		}	
		y >>= 1; // y /= 2
		x = multiplyMod(x, x);
	}
	return res;
}

int inv(int x){ // this will give x^-1 % P
	return powrm(x, P - 2);	 // O(log(y))
}

int divMod(int x, int y){ // O(log(y))
	return multiplyMod(x, inv(y)); // inv(y) == powrm(y, P - 2)
}

void calculate_factorial(){
	fact[0] = 1;
	for(int i = 1; i < N; i++){
		fact[i] = multiplyMod(fact[i - 1], i);  // O(n)
	}
}

int ncr(int n, int r){
	return multiplyMod(multiplyMod(fact[n], inv(fact[r])), inv(fact[n - r])); // O(log(y))
}

int npr(int n, int r){
	return multiplyMod(fact[n], inv(fact[n - r]));
}

void solve(){

	cout << addMod(3, 5) << endl;
	cout << subMod(3, 5) << endl;
	cout << multiplyMod(324, 234) << endl;
	cout << divMod(60, 2) << endl;

	calculate_factorial();
	cout << fact[5] << endl;
	cout << ncr(5, 2) << endl;
	cout << ncr(5778, 123) << endl;
	cout << npr(5, 2) << endl;
}

int32_t main() {
	fast_io;
	
	int t = 1; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}
