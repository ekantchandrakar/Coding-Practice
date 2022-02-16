/*   author: ekantchandrakar   */

#include<bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

const int p = 31;

ll poly_hash(string s){
	ll hash = 0;
	ll p_power = 1;

	for(ll i = 0; i < s.length(); i++){
		hash += (s[i] - 'a' + 1) * p_power; // 1 based indexing
		p_power *= p;

		hash %= mod;
		p_power %= mod;
	}

	return hash;
}

int powr(int a, int b){
	// (a^b) % mod 
	int res = 1;
	while(b){
		if(b & 1){
			res *= a;
		}
		b /= 2;
		a *= a;

		a %= mod;
		res %= mod;
	}

	return res;
}

int inv(int x){
	return powr(x, mod - 2);	
}

void solve(){
	string text = "ababbabbaba";
	string pattern = "a";

	int pat_hash = poly_hash(pattern);
	
	int n = text.length(), m = pattern.length();
	
	int text_hash = poly_hash(text.substr(0, m));

	if(pat_hash = text_hash){
		cout << 0 << " ";
	}

	for(int i = 1; i <= n - m; i++){
		// remove the last character
		text_hash = (text_hash - (text[i - 1] - 'a' + 1) + mod) % mod;
		
		// divide by p 
		text_hash = (text_hash * inv(p)) % mod;

		text_hash = (text_hash + ((text[i + m - 1] - 'a' + 1) * powr(p, m - 1))) % mod;
	
		if(text_hash == pat_hash){
			cout << i << " ";
		}
	}
}

int main() {
	fast_io;
	
	int t = 1; // cin >> t;
	while(t--){
		solve();
	}

	return 0;
}
