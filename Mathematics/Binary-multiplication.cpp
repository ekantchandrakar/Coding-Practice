/*   author: ekantchandrakar   */

#include<bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

// to ease the process
#define int long long int

using namespace std;
// Binary Multiplication
// find (a * b) % c where a, b, c are <= 10^15

int fastMultiplication(int a, int b, int c){
	int res = 0;
	while(b){
		if(b & 1){
			res += a;
			res %= c;
		}
		a += a; // a = 2 * a;
		a %= c;
		b >>= 1;
	}
	return res;
}

void solve(){
	int a, b, c;
	cin >> a >> b >> c;
	cout << fastMultiplication(a, b, c) << endl;
}

int32_t main() {
	fast_io;
	
	int t = 1; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}
