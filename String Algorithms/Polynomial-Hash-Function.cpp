/*   author: ekantchandrakar   */

#include<bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

ll poly_hash(string s){
	ll hash = 0, p = 31;
	ll p_power = 1;

	for(ll i = 0; i < s.length(); i++){
		hash += (s[i] - 'a' + 1) * p_power; // 1 based indexing
		p_power *= p;

		hash %= mod;
		p_power %= mod;
	}

	return hash;
}

void solve(){
	string s;
	cin >> s;

	cout << poly_hash(s);
}

int main() {
	fast_io;
	
	int t = 1; // cin >> t;
	while(t--){
		solve();
	}

	return 0;
}
