/*   author: ekantchandrakar   */

#include<bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

// to ease the process
#define int long long int

using namespace std;
// 1. brute force solution O(b)
// finding pow(a, b) in O(log(b)) using binary exponentiation
int powr(int a, int b){
	int res = 1;
	while(b){
		if(b & 1){
			res *= a;
			res %= mod;	
		}
		a *= a; a %= mod;
		b >>= 1; // b /= 2; right shifting
	}
	return res;
}

void solve(){
	int a, b;
	cin >> a >> b;
	cout << powr(a, b) << endl;
}

int32_t main() {
	fast_io;
	
	int t = 1; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}
